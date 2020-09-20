package com.john;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.UnknownHostException;

public class LabelPro extends Frame implements ActionListener {
    JTextField tf;
    JLabel l;
    JButton b;

    LabelPro() {
        tf = new JTextField();
        l = new JLabel();
        b = new JButton("Find IP");
        tf.setBounds(50, 50, 150, 20);
        l.setBounds(50, 100, 400, 20);
        b.setBounds(50, 150, 100, 30);
        b.addActionListener(this);
        add(b);
        add(tf);
        add(l);
        setSize(400, 400);
        setLayout(null);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String host = tf.getText();
        try {
            String ip = java.net.InetAddress.getByName(host).getHostAddress();
            l.setText("IP of \"" + host + "\" is: " + ip);
        } catch (UnknownHostException unknownHostException) {
            unknownHostException.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new LabelPro();
    }
}