package com.john;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PassWordPro implements ActionListener {
    JLabel un, pw, info;
    JPasswordField password;
    JTextField tf;
    JButton b;
    PassWordPro() {
        JFrame f = new JFrame("Login");
        un = new JLabel("Username:");
        pw = new JLabel("Password");
        info = new JLabel();
        un.setBounds(20, 20, 80, 30);
        pw.setBounds(20, 75, 80, 30);
        info.setBounds(20, 150, 400, 30);
        tf = new JTextField();
        tf.setBounds(100,20,100,30);
        password = new JPasswordField();
        password.setBounds(100, 75, 100, 30);
        b = new JButton("Login");
        b.setBounds(70, 120, 80, 30);
        b.addActionListener(this);
        f.add(un);
        f.add(pw);
        f.add(info);
        f.add(password);
        f.add(tf);
        f.add(b);
        f.setSize(300,300);
        f.setLayout(null);
        f.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String uname = tf.getText();
        String pword = String.valueOf(password.getPassword());
        info.setText("Username: " + uname + " | " + "Password: " + pword);
    }

    public static void main(String[] args) {
        new PassWordPro();
    }
}
