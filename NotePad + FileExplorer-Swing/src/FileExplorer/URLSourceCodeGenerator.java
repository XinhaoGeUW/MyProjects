package OtherApps;

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.net.*;
class URLSourceCodeGenerator extends Frame implements ActionListener{
    TextField tf;
    TextArea ta;
    Button b;
    Label l;
    URLSourceCodeGenerator(){
        super("Source Getter Tool - Javatpoint");
        l=new Label("Enter URL:");
        l.setBounds(50,50,50,20);

        tf=new TextField();
        tf.setBounds(120,50,250,20);

        b=new Button("Get Source Code");
        b.setBounds(120, 100,120,30);
        b.addActionListener(this);

        ta=new TextArea();
        ta.setBounds(120,150,250,150);

        add(l);add(tf);add(b);add(ta);
        setSize(400,400);
        setLayout(null);
        setVisible(true);
    }
    public void actionPerformed(ActionEvent e){
        String urlStr = tf.getText();
        if (urlStr != null) {
            try {
                URL url = new URL(urlStr);
                URLConnection urlcon = url.openConnection();
                BufferedReader br = new BufferedReader(new InputStreamReader(urlcon.getInputStream()));
                String input;
                while ((input = br.readLine()) != null) ta.setText(ta.getText() + input + '\n');
            }catch (MalformedURLException malformedURLException) { malformedURLException.printStackTrace(); }
             catch (IOException ioException) { ioException.printStackTrace(); }
        }
    }
    public static void main(String[] args) {
        new URLSourceCodeGenerator();
    }
}
