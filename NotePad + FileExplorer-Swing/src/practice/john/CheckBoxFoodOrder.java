package com.john;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

public class CheckBoxFoodOrder implements ActionListener {
    JLabel l;
    JCheckBox cb1, cb2, cb3;
    JButton b;
    JTextField tf1, tf2, tf3;
    JFrame f = new JFrame("FoodOrder");

    CheckBoxFoodOrder() {
        l = new JLabel("Food Ordering System");
        l.setBounds(50, 50, 300, 20);
        cb1 = new JCheckBox("Pizza @ 100");
        cb2 = new JCheckBox("Burger @ 30");
        cb3 = new JCheckBox("Tea @ 10");
        cb1.setBounds(100, 100, 150, 20);
        cb2.setBounds(100, 150, 150, 20);
        cb3.setBounds(100, 200, 150, 20);

        tf1 = new JTextField();
        tf1.setBounds(300,100,100,20);
        tf1.setVisible(false);
        tf2 = new JTextField();
        tf2.setBounds(300, 150, 100, 20);
        tf2.setVisible(false);
        tf3 = new JTextField();
        tf3.setBounds(300, 200, 100, 20);
        tf3.setVisible(false);

        cb1.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                if (cb1.isSelected()) {
                    tf1.setVisible(true);
                    tf1.revalidate();
                    tf1.repaint();
                }
            }
        });
        cb2.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                if (cb2.isSelected()) {
                    tf2.setVisible(true);
                    tf2.revalidate();
                    tf2.repaint();
                }
            }
        });
        cb3.addItemListener(new ItemListener() {
            @Override
            public void itemStateChanged(ItemEvent e) {
                if (cb3.isSelected()) {
                    tf3.setVisible(true);
                    tf3.revalidate();
                    tf3.repaint();
                }
            }
        });

        b = new JButton("Order");
        b.setBounds(100, 250, 80, 30);
        b.addActionListener(this);
        f.add(l);
        f.add(cb1);
        f.add(cb2);
        f.add(cb3);
        f.add(tf1);
        f.add(tf2);
        f.add(tf3);
        f.add(b);
        f.setSize(500, 500);
        f.setLayout(null);
        f.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        float amount = 0;
        String mess = "";
        int subAmount1, subAmount2, subAmount;
        if (cb1.isSelected()) {
            String s1 = tf1.getText();
            try {
                subAmount = 100 * (Integer.parseInt(s1));
            } catch (Exception e1) { System.out.println("invalid number of pizza"); }
            amount += 100 * (Integer.parseInt(s1));
            mess += "Pizza: " + amount + '\n';
        }
        if (cb2.isSelected()) {
            String s2 = tf2.getText();
            try {
                subAmount1 = 30 * (Integer.parseInt(s2));
            } catch (Exception e2) { System.out.println("invalid number of burgers"); }
            amount += 30 * (Integer.parseInt(s2));
            mess += "Burger: " + 30 * (Integer.parseInt(s2)) + '\n';
        }
        if (cb3.isSelected()) {
            String s3 = tf3.getText();
            try {
                subAmount2 = 10 * (Integer.parseInt(s3));
            } catch (Exception e3) { System.out.println("invalid number of tea"); }
            amount += 10 * (Integer.parseInt(s3));
            mess += "Tea: " + 10 * (Integer.parseInt(s3)) + '\n';
        }
        mess += "------------------------\n" + "Total: " + amount;
        JOptionPane.showMessageDialog(f, mess);
    }

    public static void main(String[] args) {
        new CheckBoxFoodOrder();
    }
}
