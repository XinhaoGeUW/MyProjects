package com.john;

import javax.swing.*;
import javax.swing.plaf.SliderUI;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class MenuNotepad implements ActionListener {
    JFrame f;
    JMenuBar mb;
    JMenu file, edit, help;
    JMenuItem copy, paste, cut, seletall, save;
    JTextArea ta;

    MenuNotepad() {
        f = new JFrame("Notepad");
        mb = new JMenuBar();
        file = new JMenu("File");
        edit = new JMenu("Menu");
        help = new JMenu("Help");
        copy = new JMenuItem("copy");
        paste = new JMenuItem("paste");
        cut = new JMenuItem("cut");
        seletall = new JMenuItem("selectall");
        save = new JMenuItem("Save");
        cut.addActionListener(this);
        copy.addActionListener(this);
        paste.addActionListener(this);
        seletall.addActionListener(this);
        edit.add(cut);edit.addSeparator();edit.add(copy);edit.add(paste);edit.add(seletall);file.add(save);

        mb.add(file);mb.add(edit);mb.add(help);

        ta = new JTextArea();
        ta.setBounds(5, 5, 360, 320);
        f.add(ta);

        f.setJMenuBar(mb);
        f.add(ta);
        f.setLayout(null);
        f.setSize(400, 400);
        f.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == cut) { ta.cut(); }
        if (e.getSource() == copy) { ta.copy(); }
        if (e.getSource() == paste) { ta.paste(); }
        if (e.getSource() == seletall) { ta.selectAll(); }
    }

    public static void main(String[] args) {
        new MenuNotepad();
    }
}
