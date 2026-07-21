// Index functions without modifying the current program.
// @category NSMB

import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionIterator;

import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.StandardCopyOption;
import java.security.MessageDigest;

public class IndexFunctions extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) {
            throw new IllegalArgumentException("usage: IndexFunctions.java OUTPUT_DIRECTORY");
        }

        Path outputDirectory = Path.of(args[0]);
        Files.createDirectories(outputDirectory);
        String programPath = currentProgram.getDomainFile().getPathname();
        String outputName = digest(programPath) + "-" + sanitize(currentProgram.getName()) + ".json";
        Path output = outputDirectory.resolve(outputName);
        Path temporary = output.resolveSibling(output.getFileName() + ".tmp");

        try (BufferedWriter writer = Files.newBufferedWriter(temporary, StandardCharsets.UTF_8)) {
            writer.write("{\n");
            field(writer, "program", programPath, true);
            field(writer, "name", currentProgram.getName(), true);
            field(writer, "image_base", currentProgram.getImageBase().toString(), true);
            writer.write("  \"functions\": [\n");

            FunctionIterator functions = currentProgram.getFunctionManager().getFunctions(true);
            boolean first = true;
            while (functions.hasNext() && !monitor.isCancelled()) {
                Function function = functions.next();
                if (!first) {
                    writer.write(",\n");
                }
                first = false;
                writer.write("    {");
                inlineField(writer, "program", programPath, true);
                inlineField(writer, "name", function.getName(), true);
                inlineField(writer, "qualified_name", function.getName(true), true);
                inlineField(writer, "entry", function.getEntryPoint().toString(), true);
                inlineField(writer, "body_min", function.getBody().getMinAddress().toString(), true);
                inlineField(writer, "body_max", function.getBody().getMaxAddress().toString(), false);
                writer.write("}");
            }
            writer.write("\n  ]\n}\n");
        }
        Files.move(temporary, output, StandardCopyOption.REPLACE_EXISTING,
            StandardCopyOption.ATOMIC_MOVE);
        println("Indexed " + programPath + " -> " + output);
    }

    private static void field(BufferedWriter writer, String key, String value, boolean comma)
            throws Exception {
        writer.write("  \"" + escape(key) + "\": \"" + escape(value) + "\"" +
            (comma ? "," : "") + "\n");
    }

    private static void inlineField(
            BufferedWriter writer, String key, String value, boolean comma) throws Exception {
        writer.write("\"" + escape(key) + "\":\"" + escape(value) + "\"" +
            (comma ? "," : ""));
    }

    private static String escape(String value) {
        StringBuilder result = new StringBuilder();
        for (int index = 0; index < value.length(); index++) {
            char character = value.charAt(index);
            switch (character) {
                case '\\': result.append("\\\\"); break;
                case '"': result.append("\\\""); break;
                case '\n': result.append("\\n"); break;
                case '\r': result.append("\\r"); break;
                case '\t': result.append("\\t"); break;
                default:
                    if (character < 0x20) {
                        result.append(String.format("\\u%04x", (int) character));
                    }
                    else {
                        result.append(character);
                    }
            }
        }
        return result.toString();
    }

    private static String sanitize(String value) {
        return value.replaceAll("[^A-Za-z0-9_.-]+", "_");
    }

    private static String digest(String value) throws Exception {
        byte[] bytes = MessageDigest.getInstance("SHA-256")
            .digest(value.getBytes(StandardCharsets.UTF_8));
        StringBuilder result = new StringBuilder();
        for (int index = 0; index < 8; index++) {
            result.append(String.format("%02x", bytes[index]));
        }
        return result.toString();
    }
}
