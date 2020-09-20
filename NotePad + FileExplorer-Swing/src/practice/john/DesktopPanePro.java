package com.john;

import com.sun.source.tree.CatchTree;
import com.sun.source.tree.NewArrayTree;

import javax.swing.*;
import java.awt.*;

public class DesktopPanePro extends JFrame {
    DesktopPanePro() {
        CustomDesktopPane desktopPane = new CustomDesktopPane();
        getContentPane().add(desktopPane, BorderLayout.CENTER);
        desktopPane.display(desktopPane);

        setTitle("DesktopPane Ex");
        setVisible(true);
        setSize(450,400);
    }

    public static void main(String[] args) {
        new DesktopPanePro();
    }


    class CustomDesktopPane extends JDesktopPane {
        int numFrames = 3, x = 30, y = 30;
        public void display(CustomDesktopPane dp) {
            for (int i = 0; i < numFrames; i++) {
                JInternalFrame internalFrame = new JInternalFrame("Internal Frame " + i, true, true, true, true);

                internalFrame.setContentPane(new JLabel("#" + i + " love you"));
                dp.add(internalFrame);
                internalFrame.setVisible(true);
                internalFrame.setBounds(x, y, 250, 85);
                y += 90;
            }
        }
    }
}
