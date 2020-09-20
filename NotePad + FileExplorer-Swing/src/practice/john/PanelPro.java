package com.john;

import javax.swing.*;
import java.awt.*;

public class PanelPro {
    PanelPro() {
        JFrame f = new JFrame("PanelPro");
        JPanel p = new JPanel();
        p.setBounds(40, 80, 200, 200);
        p.setBackground(Color.gray);
        JButton b1 = new JButton("b1");
        JButton b2 = new JButton("b2");
        b1.setBounds(50, 100, 80, 30);
        b1.setBackground(Color.yellow);
        b2.setBounds(100, 100, 80, 30);
        b2.setBackground(Color.black);
        p.add(b1);
        p.add(b2);
        f.add(p);
        f.setSize(400, 400);
        f.setVisible(true);
        f.setLayout(null);
    }

    public static void main(String[] args) {
        new PanelPro();
    }
}
