package AllNotepad;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

class FontChooserDemo extends JFrame {
    FontChooser fontChooser = null;
    JTextArea ta;
    JButton fontButton;

    FontChooserDemo() {
        super("Font");
        ta = new JTextArea(7, 20);
        fontButton = new JButton("Set Font");

        fontButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (fontChooser == null) fontChooser = new FontChooser(ta.getFont());
                if (fontChooser.showDialog(FontChooserDemo.this, "Choose a Font"))
                    FontChooserDemo.this.ta.setFont(fontChooser.createFont());
            }
        });

        add(ta, BorderLayout.CENTER);
        add(fontButton, BorderLayout.SOUTH);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(500, 500);
        setVisible(true);
        ta.append("Hello dear. how r u?");
        ta.append("\n\n A quick brown fox jumps over the lazy dog.");
        ta.append("\n\n0123456789");
        ta.append("\n~!@#$%^&*()_+|?><");

        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());  //basically gives it the system themeik
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (InstantiationException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        } catch (UnsupportedLookAndFeelException e) {
            e.printStackTrace();
        }

    }
    public static void main(String[] args) { new FontChooserDemo(); }
}








