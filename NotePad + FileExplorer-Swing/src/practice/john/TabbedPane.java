package com.john;

import javax.swing.*;

public class TabbedPane {
    JFrame f;
    TabbedPane() {
        f = new JFrame();
        JTextArea ta = new JTextArea(200,200);
        JPanel p1 = new JPanel();
        JPanel p2 = new JPanel();
        JPanel p3 = new JPanel();
        p1.add(ta);

        JTabbedPane tp = new JTabbedPane();
        tp.setBounds(100,50,200,200);
        tp.add("main", p1);
        tp.add("visit", p2);
        tp.add("help", p3);
        f.add(tp);
        f.setSize(400, 400);
        f.setVisible(true);
        f.setLayout(null);
    }

    public static void main(String[] args) {
        new TabbedPane();
    }
}
