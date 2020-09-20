package com.john;

import javax.swing.*;

public class Slider extends JFrame {
    Slider() {
        JSlider s = new JSlider(JSlider.VERTICAL, 0, 100, 20);
        s.setMinorTickSpacing(2);
        s.setMajorTickSpacing(10);
        s.setPaintTicks(true);
        s.setPaintLabels(true);

        JPanel p = new JPanel();
        p.add(s);
        add(p);
    }

    public static void main(String[] args) {
        Slider slider  = new Slider();
        slider.pack();
        slider.setVisible(true);
        slider.setSize(200,400);
    }

}
