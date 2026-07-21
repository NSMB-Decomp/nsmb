// Create a Ghidra-compatible .gar snapshot of the current local project.
// @category NSMB

import generic.io.JarWriter;
import ghidra.app.script.GhidraScript;
import ghidra.framework.model.Project;
import ghidra.framework.model.ProjectLocator;

import java.io.File;
import java.io.FileOutputStream;
import java.util.jar.JarOutputStream;
import java.util.zip.ZipEntry;

public class ArchiveLocalProject extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1 || !args[0].endsWith(".gar")) {
            throw new IllegalArgumentException("usage: ArchiveLocalProject.java OUTPUT.gar");
        }
        File archive = new File(args[0]);
        if (archive.exists()) {
            throw new IllegalStateException("Refusing to overwrite archive: " + archive);
        }
        File parent = archive.getParentFile();
        if (parent != null) parent.mkdirs();

        Project project = state.getProject();
        ProjectLocator locator = project.getProjectLocator();
        try (JarOutputStream output = new JarOutputStream(new FileOutputStream(archive))) {
            output.setComment(project.getName() + " project archive");
            JarWriter writer = new JarWriter(output, new String[] { ".ulock" });
            if (!writer.outputFile(locator.getMarkerFile(), "", monitor)) {
                throw new IllegalStateException("Could not archive project marker");
            }
            output.putNextEntry(new ZipEntry("JAR_FORMAT"));
            output.closeEntry();
            File projectDirectory = locator.getProjectDir();
            File[] files = projectDirectory.listFiles();
            if (files == null) {
                throw new IllegalStateException("Could not list project directory");
            }
            for (File file : files) {
                if (monitor.isCancelled()) {
                    throw new IllegalStateException("Archive cancelled");
                }
                if (file.isDirectory() && !writer.outputRecursively(file, "", monitor)) {
                    throw new IllegalStateException("Could not archive " + file);
                }
            }
        }
        println("Archived " + project.getName() + " -> " + archive);
    }
}
