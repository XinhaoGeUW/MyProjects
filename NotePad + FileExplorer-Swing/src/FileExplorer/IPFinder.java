package OtherApps;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.net.InetAddress;
import java.net.UnknownHostException;

class IPFinder extends JFrame implements ActionListener {
    JLabel l;
    JTextField tf;
    JButton b;

    IPFinder() {
        super("IP Finder Program :)");
        l = new JLabel("Enter Your URL:");
        tf = new JTextField();
        b = new JButton("Search IP");
        l.setBounds(50, 70, 150, 20);
        tf.setBounds(50, 100, 200, 20);
        b.setBounds(100, 150, 100, 40);
        b.addActionListener(this);

        add(l);
        add(b);
        add(tf);
        setSize(400, 400);
        setLayout(null);
        setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        String url = tf.getText();
        try {
            InetAddress ia = InetAddress.getByName(url);
            String ip = ia.getHostAddress();
            JOptionPane.showMessageDialog(this, ip);
        } catch (UnknownHostException unknownHostException) {
            unknownHostException.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new IPFinder();
    }
}
