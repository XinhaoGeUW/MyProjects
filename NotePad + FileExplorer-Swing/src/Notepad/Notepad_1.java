package AllNotepad;

import javax.swing.*;
import javax.swing.text.BadLocationException;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.util.Scanner;


public class Notepad_1 extends JFrame implements ActionListener {
    JTextArea txt = new JTextArea();
    FontChooser fontDialog = null;

    public Notepad_1() {
        Font font = new Font("Arial", Font.PLAIN, 16);

        JMenuBar menuBar = new JMenuBar();
        String[] menus = {"File", "Edit", "Format", "Help"};
        String[][] menuItems = {{"New", "Open", "Save", "-","Print", "-", "Exit"}, {"Cut", "Copy", "Paste", "Delete", "-", "Go to", "-", "Select All"}, {"Font"}, {"About The Notepad"}};
        for (int i = 0; i < menus.length; i++) {
            String title = menus[i];
            String[] elems = menuItems[i];
            JMenu menu = new JMenu(title);
            for (String element : elems) {
                if (element == "-") menu.addSeparator();
                else {
                    JMenuItem menuItem = new JMenuItem(element);
                    menuItem.addActionListener(this);
                    menu.add(menuItem);
                }
            }
            menuBar.add(menu);
        }
        setJMenuBar(menuBar);

        JScrollPane scrollPane = new JScrollPane(txt);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        scrollPane.setVisible(true);

        txt.setFont(font);
        txt.setLineWrap(true);
        txt.setWrapStyleWord(true);

        add(scrollPane);
        setSize(600, 600);
        setVisible(true);
        setTitle("Unlimited.txt - Notepad");
        setDefaultCloseOperation(EXIT_ON_CLOSE);

        try { UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());  /*basically gives it the system themeik*/ }
        catch (ClassNotFoundException | InstantiationException | UnsupportedLookAndFeelException | IllegalAccessException e) { e.printStackTrace(); }
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        JFileChooser fileChooser = new JFileChooser();
        fileChooser.addChoosableFileFilter(new MyFileFilter(".java","Java Source Files(*.java)"));
        fileChooser.addChoosableFileFilter(new MyFileFilter(".txt","Text Files(*.txt)"));
        // fileChooser.setCurrentDirectory(new File(".")); always open the current directory

        if (e.getActionCommand().equals("New")) {
            this.setTitle("Unlimited.txt - Notepad");
            txt.setText("");
        } else if (e.getActionCommand().equals("Open")) {
            int openOption = fileChooser.showOpenDialog(this);
            if (openOption == JFileChooser.APPROVE_OPTION) {
                /*try (Scanner scanner = new Scanner(fileChooser.getSelectedFile())) {
                    while (scanner.hasNextLine()) {
                        txt.setText(scanner.nextLine() + '\n');
                    }*/
                try (BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream(fileChooser.getSelectedFile())))) {
                    String input;
                    while ((input = reader.readLine()) != null) txt.setText(txt.getText() + input + "\n");
                    setTitle(fileChooser.getSelectedFile().getName());
                } catch (IOException ioException) { ioException.printStackTrace(); }
            }
        } else if (e.getActionCommand().equals("Save")) {
            int saveOption = fileChooser.showSaveDialog(this);
            if (saveOption == JFileChooser.APPROVE_OPTION) {
                try (FileWriter fileWriter = new FileWriter(fileChooser.getSelectedFile().getAbsoluteFile())) {
                    fileWriter.write(txt.getText());
                    setTitle(fileChooser.getSelectedFile().getName());
                } catch (IOException ioException) { ioException.printStackTrace(); }
            }
        } else if (e.getActionCommand().equals("Print")) {
            JOptionPane.showMessageDialog(this, "We can't find a printer. Make sure u have a printer connected to", "No Printer", JOptionPane.INFORMATION_MESSAGE);
        } else if (e.getActionCommand().equals("Exit")) System.exit(0);
          else if (e.getActionCommand().equals("Copy")) txt.copy();
          else if (e.getActionCommand().equals("Cut")) txt.cut();
          else if (e.getActionCommand().equals("Paste")) txt.paste();
          else if (e.getActionCommand().equals("Delete")) txt.replaceSelection("");
          else if (e.getActionCommand().equals("Go to")) {
              if (this.txt.getText() == "") return;
              goTo();
        }
          else if (e.getActionCommand().equals("Select All")) txt.selectAll();
          else if (e.getActionCommand().equals("Font")) {
            if (fontDialog == null) fontDialog = new FontChooser(txt.getFont());
            if (fontDialog.showDialog(Notepad_1.this, "Choose a font")) this.txt.setFont(fontDialog.createFont());
        } else if (e.getActionCommand().equals("About The Notepad")) {
            JOptionPane.showMessageDialog(this, "Created by John Ge", "NOTEPAD", JOptionPane.INFORMATION_MESSAGE);
        }
    }

    private void goTo() {
        int lineNum = 0;
        try {
            lineNum = txt.getLineOfOffset(txt.getCaretPosition()) + 1;
            String lineStr = JOptionPane.showInputDialog(this, "Enter the line you want to go to", "" + lineNum);
            if (lineStr == null) return;
            lineNum = Integer.parseInt(lineStr);
            txt.setCaretPosition(txt.getLineOfOffset(lineNum-1));
        } catch (BadLocationException e) { e.printStackTrace(); }
    }
    public static void main(String[] args) { new Notepad_1(); }
}
