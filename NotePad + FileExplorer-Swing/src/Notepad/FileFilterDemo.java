package AllNotepad;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class FileFilterDemo extends JFrame {
    JLabel label;
    JButton button;
    JFileChooser chooser;

    FileFilterDemo() {
        super("Choose Your File");
        label = new JLabel("No file are choses now");
        button = new JButton("Click to Open File");

        button.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (FileFilterDemo.this.chooser == null) chooser = new JFileChooser();
                chooser.addChoosableFileFilter(new MyFileFilter(".java", "Java Source Files(*.java)"));
                chooser.addChoosableFileFilter(new MyFileFilter(".txt", "Text Files(*.txt"));
                if (chooser.showDialog(FileFilterDemo.this, "open") == JFileChooser.APPROVE_OPTION)
                    FileFilterDemo.this.label.setText(chooser.getSelectedFile().getAbsolutePath());
            }
        });
        add(label, "Center");
        add(button, "South");
        setSize(500, 500);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
        try { UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());  /*basically gives it the system themeik*/ }
        catch (ClassNotFoundException | InstantiationException | UnsupportedLookAndFeelException | IllegalAccessException e) { e.printStackTrace(); }
    }

    public static void main(String[] args) { FileFilterDemo filterMain = new FileFilterDemo(); }
}

