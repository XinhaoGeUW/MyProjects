package com.john;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.util.Scanner;

public class FileChooserPro extends JFrame implements ActionListener
{
    JMenuBar mb;
    JMenu file;
    JMenuItem open;
    JTextArea ta;
    FileChooserPro() {
        open = new JMenuItem("open file");
        file = new JMenu("File");
        mb = new JMenuBar();
        open.addActionListener(this);
        file.add(open);
        mb.add(file);
        mb.setBounds(0, 0, 800, 20);
        ta = new JTextArea(800, 800);
        ta.setBounds(0, 20, 800, 800);
        add(mb);
        add(ta);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == open) {
            JFileChooser fileChooser = new JFileChooser();
            int i = fileChooser.showOpenDialog(this);
            if (i == JFileChooser.APPROVE_OPTION) {
                File f = fileChooser.getSelectedFile();
                String filepath = f.getPath();
                try (Scanner scanner = new Scanner(new File(filepath))) {
                    String txt = "";
                    while (scanner.hasNextLine()) {
                        txt += scanner.nextLine() + '\n';
                    }
                    ta.setText(txt);
                } catch (Exception ioe) {
                    ioe.printStackTrace();
                }
            }
        }
    }

    public static void main(String[] args) {
        FileChooserPro fileChooserPro = new FileChooserPro();
        fileChooserPro.setLayout(null);
        fileChooserPro.setVisible(true);
        fileChooserPro.setSize(500, 500);
        fileChooserPro.setDefaultCloseOperation(EXIT_ON_CLOSE);
    }
}

