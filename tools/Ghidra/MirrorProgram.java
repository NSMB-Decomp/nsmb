// Export programs from a read-only shared project for import into an independent project.
// Run only with analyzeHeadless -readOnly against the approved shared NSMBDS repository.
// @category NSMB

import ghidra.app.script.GhidraScript;
import ghidra.framework.model.DomainFile;

import java.io.File;

public class MirrorProgram extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) {
            throw new IllegalArgumentException(
                "usage: MirrorProgram.java PACKED_ARCHIVE_DIR");
        }
        File packedArchiveDirectory = new File(args[0]);
        packedArchiveDirectory.mkdirs();

        DomainFile source = currentProgram.getDomainFile();
        String sourcePath = source.getPathname();
        File packedFile = packedFile(packedArchiveDirectory, sourcePath);
        File parent = packedFile.getParentFile();
        if (parent != null) parent.mkdirs();
        if (packedFile.exists()) {
            throw new IllegalStateException(
                "Refusing to overwrite packed program archive: " + packedFile);
        }
        // Ghidra runs each script inside a program transaction, while packing requires an
        // unlocked program.  Balance the transaction exactly as FlatProgramAPI.saveProgram does.
        end(true);
        try {
            currentProgram.saveToPackedFile(packedFile, monitor);
        }
        finally {
            start();
        }
        println("Exported " + sourcePath + " -> " + packedFile);
    }

    private static File packedFile(File root, String sourcePath) {
        String normalized = sourcePath.startsWith("/") ? sourcePath.substring(1) : sourcePath;
        return new File(root, normalized + ".gzf");
    }
}
