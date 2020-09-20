package AllNotepad;

import javax.swing.filechooser.FileFilter;
import java.io.File;

public class MyFileFilter extends FileFilter {
    private String extension;
    private String description;

    public MyFileFilter() {
        setExtension(null);
        setDescription(null);
    }
    public MyFileFilter(String ext, String desc) {
        setExtension(ext);
        setDescription(desc);
    }
    @Override
    public boolean accept(File f) {
        String filename = f.getName();
        if (f.isDirectory() || extension == null || filename.toUpperCase().endsWith(extension.toUpperCase())) return true;
        return false;
    }
    @Override
    public String getDescription() { return description; }
    public void setDescription(String desc) {
        if (desc == null) description = "All Files(*.*)";
        else description = desc;
    }
    public void setExtension(String ext) {
        if (ext == null) {
            extension = null;
            return;
        }
        extension = ext.toLowerCase();
        if (!ext.startsWith(".")) extension = extension + ".";
    }
}
