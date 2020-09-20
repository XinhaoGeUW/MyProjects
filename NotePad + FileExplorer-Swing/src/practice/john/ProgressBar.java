package com.john;

import javax.swing.*;

public class ProgressBar {
    JProgressBar pb;
    JFrame f;
    int num = 0, i = 0;

    ProgressBar() {
        pb = new JProgressBar(0,1000);
        pb.setBounds(40,40,160,30);
        pb.setValue(0);
        pb.setStringPainted(true);
        f = new JFrame("Prograssing");
        f.add(pb);
        f.setSize(300, 300);
        f.setLayout(null);
        f.setVisible(true);
    }
    public void iterate() {
        while (i<=1000) {
            pb.setValue(i);
            i+=10;
            try {Thread.sleep(500);} catch (Exception e) {}
        }
    }

    public static void main(String[] args) {
        ProgressBar p = new ProgressBar();
        p.iterate();
    }

}
