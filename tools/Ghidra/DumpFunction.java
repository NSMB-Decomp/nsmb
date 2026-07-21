// Export decompilation and reference context without modifying the current program.
// @category NSMB

import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Set;

public class DumpFunction extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 2) {
            throw new IllegalArgumentException("usage: DumpFunction.java OUTPUT_DIRECTORY ADDRESS");
        }
        Path outputDirectory = Path.of(args[0]);
        Files.createDirectories(outputDirectory);

        Address address = currentProgram.getAddressFactory().getAddress(args[1]);
        if (address == null) {
            throw new IllegalArgumentException("Invalid address: " + args[1]);
        }
        Function function = currentProgram.getFunctionManager().getFunctionAt(address);
        if (function == null) {
            function = currentProgram.getFunctionManager().getFunctionContaining(address);
        }
        if (function == null) {
            throw new IllegalArgumentException("No function at address: " + address);
        }

        writeDecompilation(outputDirectory.resolve("decompile.c"), function);
        writeListing(outputDirectory.resolve("listing.txt"), function);
        writeFunction(outputDirectory.resolve("function.json"), function);
        writeReferences(outputDirectory.resolve("references.json"), function);
        println("Dumped " + function.getName(true) + " at " + function.getEntryPoint());
    }

    private void writeDecompilation(Path output, Function function) throws Exception {
        DecompInterface decompiler = new DecompInterface();
        try {
            if (!decompiler.openProgram(currentProgram)) {
                throw new IllegalStateException("Could not open program in decompiler");
            }
            DecompileResults results = decompiler.decompileFunction(function, 120, monitor);
            if (!results.decompileCompleted() || results.getDecompiledFunction() == null) {
                throw new IllegalStateException("Decompilation failed: " + results.getErrorMessage());
            }
            Files.writeString(
                output,
                results.getDecompiledFunction().getC() + "\n",
                StandardCharsets.UTF_8);
        }
        finally {
            decompiler.dispose();
        }
    }

    private void writeListing(Path output, Function function) throws Exception {
        try (BufferedWriter writer = Files.newBufferedWriter(output, StandardCharsets.UTF_8)) {
            InstructionIterator instructions = currentProgram.getListing()
                .getInstructions(function.getBody(), true);
            while (instructions.hasNext() && !monitor.isCancelled()) {
                Instruction instruction = instructions.next();
                writer.write(instruction.getAddress() + "  " + bytes(instruction.getBytes()) +
                    "  " + instruction + "\n");
            }
        }
    }

    private void writeFunction(Path output, Function function) throws Exception {
        List<Function> callers = sorted(function.getCallingFunctions(monitor));
        List<Function> callees = sorted(function.getCalledFunctions(monitor));
        try (BufferedWriter writer = Files.newBufferedWriter(output, StandardCharsets.UTF_8)) {
            writer.write("{\n");
            field(writer, "program", currentProgram.getDomainFile().getPathname(), true);
            field(writer, "name", function.getName(), true);
            field(writer, "qualified_name", function.getName(true), true);
            field(writer, "entry", function.getEntryPoint().toString(), true);
            field(writer, "signature", function.getSignature().toString(), true);
            writer.write("  \"callers\": ");
            writeFunctions(writer, callers);
            writer.write(",\n  \"callees\": ");
            writeFunctions(writer, callees);
            writer.write("\n}\n");
        }
    }

    private void writeReferences(Path output, Function function) throws Exception {
        List<Reference> incoming = new ArrayList<>();
        ReferenceIterator incomingIterator = currentProgram.getReferenceManager()
            .getReferencesTo(function.getEntryPoint());
        while (incomingIterator.hasNext()) {
            incoming.add(incomingIterator.next());
        }

        List<Reference> outgoing = new ArrayList<>();
        InstructionIterator instructions = currentProgram.getListing()
            .getInstructions(function.getBody(), true);
        while (instructions.hasNext() && !monitor.isCancelled()) {
            for (Reference reference : instructions.next().getReferencesFrom()) {
                outgoing.add(reference);
            }
        }
        Comparator<Reference> comparator = Comparator
            .comparing((Reference reference) -> reference.getFromAddress().toString())
            .thenComparing(reference -> reference.getToAddress().toString())
            .thenComparing(reference -> reference.getReferenceType().getName());
        incoming.sort(comparator);
        outgoing.sort(comparator);

        try (BufferedWriter writer = Files.newBufferedWriter(output, StandardCharsets.UTF_8)) {
            writer.write("{\n  \"incoming\": ");
            writeReferencesArray(writer, incoming);
            writer.write(",\n  \"outgoing\": ");
            writeReferencesArray(writer, outgoing);
            writer.write("\n}\n");
        }
    }

    private static List<Function> sorted(Set<Function> functions) {
        List<Function> result = new ArrayList<>(functions);
        result.sort(Comparator
            .comparing((Function function) -> function.getEntryPoint().toString())
            .thenComparing(function -> function.getName()));
        return result;
    }

    private static void writeFunctions(BufferedWriter writer, List<Function> functions)
            throws Exception {
        writer.write("[");
        for (int index = 0; index < functions.size(); index++) {
            if (index > 0) writer.write(",");
            Function function = functions.get(index);
            writer.write("{\"entry\":\"" + escape(function.getEntryPoint().toString()) +
                "\",\"name\":\"" + escape(function.getName(true)) + "\"}");
        }
        writer.write("]");
    }

    private static void writeReferencesArray(BufferedWriter writer, List<Reference> references)
            throws Exception {
        writer.write("[");
        for (int index = 0; index < references.size(); index++) {
            if (index > 0) writer.write(",");
            Reference reference = references.get(index);
            writer.write("{\"from\":\"" + escape(reference.getFromAddress().toString()) +
                "\",\"to\":\"" + escape(reference.getToAddress().toString()) +
                "\",\"type\":\"" + escape(reference.getReferenceType().getName()) + "\"}");
        }
        writer.write("]");
    }

    private static void field(BufferedWriter writer, String key, String value, boolean comma)
            throws Exception {
        writer.write("  \"" + escape(key) + "\": \"" + escape(value) + "\"" +
            (comma ? "," : "") + "\n");
    }

    private static String bytes(byte[] bytes) {
        StringBuilder result = new StringBuilder();
        for (byte value : bytes) {
            result.append(String.format("%02x", value & 0xff));
        }
        return result.toString();
    }

    private static String escape(String value) {
        return value.replace("\\", "\\\\")
            .replace("\"", "\\\"")
            .replace("\n", "\\n")
            .replace("\r", "\\r")
            .replace("\t", "\\t");
    }
}
