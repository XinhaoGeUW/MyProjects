package com.john;

import javax.swing.*;
import java.awt.*;
import java.awt.Label;

public class DialogPro {
    JDialog d;
    DialogPro() {
        JFrame f = new JFrame("DialogPro");
        d = new JDialog(f, "dialogg", true);
        d.setLayout(new FlowLayout());
        JButton b = new JButton("OK");
        b.addActionListener(e -> d.setVisible(false));
        d.add(new Label("click here to continue"));
        d.add(b);
        d.setSize(300, 300);
        d.setVisible(true);
    }

    public static void main(String[] args) {
        new DialogPro();
    }


}
