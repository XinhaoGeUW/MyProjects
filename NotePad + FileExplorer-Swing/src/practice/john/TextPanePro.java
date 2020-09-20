package com.john;

import javax.swing.*;
import javax.swing.text.BadLocationException;
import javax.swing.text.Document;
import javax.swing.text.SimpleAttributeSet;
import javax.swing.text.StyleConstants;
import java.awt.*;

public class TextPanePro {
    public static void main(String[] args) throws BadLocationException {
        JFrame frame = new JFrame("TextPane java");
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        JTextPane tp = new JTextPane();
        SimpleAttributeSet attributeSet = new SimpleAttributeSet();
        StyleConstants.setBold(attributeSet, true);

        tp.setCharacterAttributes(attributeSet, true);
        tp.setText("Welcome");

        attributeSet = new SimpleAttributeSet();
        StyleConstants.setItalic(attributeSet, true);
        StyleConstants.setForeground(attributeSet, Color.red);
        StyleConstants.setBackground(attributeSet, Color.gray);
        Document doc = tp.getStyledDocument();
        doc.insertString(doc.getLength(), "to java", attributeSet);

        attributeSet = new SimpleAttributeSet();
        doc.insertString(doc.getLength(), "World", attributeSet);

        JScrollPane scrollPane = new JScrollPane(tp);
        frame.getContentPane().add(scrollPane, BorderLayout.CENTER);

        frame.setVisible(true);
        frame.setSize(400,400);
    }
}
