package com.john;

import javax.swing.*;

public class Label {
    public static void main(String[] args) {
        JFrame f = new JFrame("Label ex");
        JLabel l1, l2;
        l1 = new JLabel("first label");
        l2 = new JLabel("second label");
        l1.setBounds(60, 50, 100, 30);
        l2.setBounds(60, 80,100, 30);
        f.add(l1);f.add(l2);
        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);
    }

}
