package com.john;

import com.sun.source.tree.LambdaExpressionTree;

import javax.swing.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class CheckBoxItemListener {
    CheckBoxItemListener(){
        JFrame f= new JFrame("CheckBox AddListener");
        final JLabel label = new JLabel();
        label.setHorizontalAlignment(JLabel.CENTER);
        label.setSize(400,100);
        JCheckBox cbox1 = new JCheckBox("C++");
        JCheckBox cbox2 = new JCheckBox("Java");
        cbox1.setBounds(150,100, 50, 50);
        cbox2.setBounds(150, 150,50, 50 );
        f.add(cbox1);
        f.add(cbox2);
        f.add(label);
        f.setSize(400,400);
        f.setLayout(null);
        f.setVisible(true);
        cbox1.addItemListener(e -> label.setText("C++ CheckBox: " + (e.getStateChange() == 1 ? "checked" : "unchecked")));
        cbox2.addItemListener(e -> label.setText("Java CheckBox: " + (e.getStateChange() == 1 ? "checked" : "unchecked")));
    }
    public static void main(String args[])
    {
        new CheckBoxItemListener();
    }
}
