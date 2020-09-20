package com.john;

import javax.security.auth.login.CredentialException;
import javax.swing.*;
import java.awt.*;

public class ScrollPanePro extends JFrame {
    void createAndShowGUI() {
        setTitle("Scroll Pane");
        setSize(400, 400);
        setVisible(true);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        getContentPane().setLayout(new FlowLayout());
        JTextArea area = new JTextArea(30, 30);
        JScrollPane scrollPane = new JScrollPane(area);

        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        getContentPane().add(scrollPane);
    }

    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                ScrollPanePro sp = new ScrollPanePro();
                sp.createAndShowGUI();
            }
        });
    }
}
