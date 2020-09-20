package com.john;
import javax.swing.*;
import java.awt.event.*;


public class Button1 {
    public static void main(String[] args) {
        JFrame f = new JFrame("Button1");
        JTextField tf = new JTextField();
        tf.setBounds(200, 100, 200, 100);
        JButton b = new JButton(new ImageIcon("C:\\Users\\GEJO\\OneDrive - Government of Ontario\\Documents\\My Pictures\\Camera Roll\\Hykr7by.jpg"));
        b.setBounds(100, 260, 800, 700);
        b.addActionListener(e -> tf.setText("first action listener added here~"));
        f.add(b);f.add(tf);
        f.setSize(400, 600);
        f.setLayout(null);
        f.setVisible(true);

    }
}
