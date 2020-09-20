package com.john;

import javax.swing.*;
import javax.swing.event.*;

public class SpinnerPro {
    public static void main(String[] args) {
        JFrame f = new JFrame("SpinnerPro");
        final JLabel label = new JLabel();
        label.setHorizontalAlignment(JLabel.CENTER);
        label.setSize(250, 100);
        SpinnerModel value = new SpinnerNumberModel(5, 0, 10, 1);
        JSpinner spinner = new JSpinner(value);
        spinner.setBounds(100, 100, 50, 30);
        f.add(spinner);
        f.add(label);
        f.setSize(400, 400);
        f.setLayout(null);
        f.setVisible(true);

        spinner.addChangeListener(new ChangeListener() {
            @Override
            public void stateChanged(ChangeEvent e) {
                label.setText("Value: " + ((JSpinner)e.getSource()).getValue());
            }
        });
    }
}
