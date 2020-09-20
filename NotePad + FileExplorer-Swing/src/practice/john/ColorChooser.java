package com.john;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class ColorChooser implements ActionListener {
    JFrame f;
    JButton b;
    JTextArea ta;
    ColorChooser() {
        f = new JFrame("ColorChooser");
        b = new JButton("COLOR");
        b.setBounds(200,250,100,30);
        b.addActionListener(this);
        ta = new JTextArea();
        ta.setBounds(10,20,300,200);
        f.add(b);f.add(ta);
        f.setLayout(null);
        f.setSize(400,400);
        f.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        Color color = JColorChooser.showDialog(f, "s electa color", Color.BLACK);
        ta.setBackground(color);
    }

    public static void main(String[] args) {
        new ColorChooser();

    }
}
