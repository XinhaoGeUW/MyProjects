package com.john;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class TextAreaPro implements ActionListener {
    JLabel l1, l2;
    JTextArea ta;
    JButton b, b2;

    TextAreaPro() {
        JFrame f = new JFrame("TextAreaPro");
        l1 = new JLabel();
        l2 = new JLabel();
        l1.setBounds(50, 50, 100, 30);
        l2.setBounds(350, 50, 100, 30);
        ta = new JTextArea();
        ta.setBounds(50, 100, 400, 250);
        b = new JButton("Count Words");
        b2 = new JButton("Count Chars");
        b.setBounds(50, 400, 150, 50);
        b2.setBounds(300, 400, 150, 50);
        b.addActionListener(this);
        b2.addActionListener(this);
        f.add(l1);
        f.add(l2);
        f.add(ta);
        f.add(b);
        f.add(b2);
        f.setSize(500, 500);
        f.setLayout(null);
        f.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String text = ta.getText();
        String[] words = text.split(" ");

        if (e.getSource() == b) {
            if (text.length() == 0) l1.setText("Words: 0");
            else l1.setText("Words: " + words.length);
        } else l2.setText("Characters: " + text.length());
    }

    public static void main(String args[]) {
        new TextAreaPro();
    }

}
