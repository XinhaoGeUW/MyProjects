package com.john;

import javax.swing.*;

public class RootPanePro {
    public static void main(String[] args) {
        JFrame f = new JFrame();
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JRootPane rootPane = f.getRootPane();

        JMenuBar bar = new JMenuBar();
        JMenu menu = new JMenu("File");
        bar.add(menu);
        menu.add("Open");
        menu.add("Close");
        rootPane.setJMenuBar(bar);
        rootPane.getContentPane().add(new JButton("press me"));

        f.setVisible(true);
        f.pack();
    }
}
