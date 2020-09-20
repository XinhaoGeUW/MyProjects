package com.john;

import javax.swing.*;


public class EditorPanePro extends JFrame {
    public static void main(String[] args) {
        (new EditorPanePro()).test();
    }

    void test() {
        setTitle("Editor Test");
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setSize(400, 400);
        setVisible(true);
        JEditorPane editorPane = new JEditorPane();
        editorPane.setContentType("text/html");
        editorPane.setText("<h1>Sleeping</h1><p>Sleeping is necessary for a healthy body."
                + " But sleeping in unnecessary times may spoil our health, wealth and studies."
                + " Doctors advise that the sleeping at improper timings may lead for obesity during the students days.</p>");
        setContentPane(editorPane);

    }
}
