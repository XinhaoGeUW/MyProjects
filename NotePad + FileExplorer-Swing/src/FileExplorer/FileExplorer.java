package OtherApps;

import javax.swing.*;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.TreePath;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.File;
import java.util.Arrays;

public class FileExplorer extends JPanel implements ActionListener {
    JTextField jtf;
    JTextArea jta;
    JTree tree;
    JButton refresh;
    JTable jtb;
    JScrollPane jsp;
    JScrollPane jspTable;

    String[] colHeads = {"File Name", "SIZE(int Bytes)", "Read Only", "Hidden"};
    String[][] data = {{"", "", "", "",}};

    FileExplorer(String path) {
        jtf = new JTextField();
        jta = new JTextArea(5, 30);
        refresh = new JButton("Refresh");

        File temp = new File(path);
        DefaultMutableTreeNode top = createTree(temp);
        tree = new JTree(top);
        jsp = new JScrollPane(tree);
        jtb = new JTable(data, colHeads);
        jspTable = new JScrollPane(jtb);

        setLayout(new BorderLayout());
        add(jtf, BorderLayout.NORTH);
        add(jsp, BorderLayout.WEST);
        add(jspTable, BorderLayout.CENTER);
        add(refresh, BorderLayout.SOUTH);
        tree.addMouseListener(new MouseAdapter() {@Override public void mouseClicked(MouseEvent me) { doMouseClicked(me); }});
        jtf.addActionListener(this);
        refresh.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        File temp = new File(jtf.getText());
        DefaultMutableTreeNode newTop = createTree(temp);
        if (newTop != null) tree = new JTree(newTop);
        remove(jsp);
        jsp = new JScrollPane(tree);
        setVisible(false);
        add(jsp, BorderLayout.WEST);
        tree.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent me) {
                doMouseClicked(me);
            }
        });
        setVisible(true);
    }

    private DefaultMutableTreeNode createTree(File temp) {
        DefaultMutableTreeNode top = new DefaultMutableTreeNode(temp.getPath());
        if (!(temp.exists() && temp.isDirectory())) return top;
        fillTree(top, temp.getPath());
        return top;
    }

    private void fillTree(DefaultMutableTreeNode root, String filepath) {
        File temp = new File(filepath);
        if (!(temp.exists() && temp.isDirectory())) return;
        File[] files = temp.listFiles();
        for (File file : files) {
            if (!file.isDirectory()) continue;
            DefaultMutableTreeNode tempNode = new DefaultMutableTreeNode(file.getName());
            root.add(tempNode);
            String newFilePath = filepath + "\\" + file.getName();
            Thread thread = new Thread(() -> fillTree(tempNode, newFilePath));
            thread.start();
        }
    }

    private void doMouseClicked(MouseEvent me) {
        TreePath treePath = tree.getPathForLocation(me.getX(), me.getY());
        if (treePath == null) return;
        String path = treePath.toString();
        path = path.replace("[", "");
        path = path.replace("]", "");
        path = path.replace(", ", "\\");
        jtf.setText(path);
        showFiles(path);
    }

    private void showFiles(String filepath) {
        File temp = new File(filepath);
        if (!temp.exists() || !temp.isDirectory()) return;

        File[] files = temp.listFiles();
        int fileCounter = 0;
        data = new String[files.length][4];
        for (File file : files) {
            if (file.isDirectory()) continue;
            data[fileCounter][0] = file.getName();
            data[fileCounter][1] = file.length() + "";
            data[fileCounter][2] = file.canWrite() + "";
            data[fileCounter][3] = file.isHidden() + "";
            fileCounter++;
        }
        String[][] dataTemp = new String[fileCounter][4];
        if (fileCounter >= 0) System.arraycopy(data, 0, dataTemp, 0, fileCounter);
        data = dataTemp;

        remove(jspTable);
        jtb = new JTable(data, colHeads);
        jspTable = new JScrollPane(jtb);
        setVisible(false);
        add(jspTable, BorderLayout.CENTER);
        setVisible(true);
    }
}

    class ExplorerTest extends JFrame {
        ExplorerTest(String path) {
            super("Windows Exploder - Javatpoint");
            add(new FileExplorer(path), "Center");
            setDefaultCloseOperation(EXIT_ON_CLOSE);
            setSize(600, 500);
            setVisible(true);
            try { UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());  /*basically gives it the system themeik*/ }
            catch (ClassNotFoundException | InstantiationException | UnsupportedLookAndFeelException | IllegalAccessException e) { e.printStackTrace(); }
        }

        public static void main(String[] args) {
            new ExplorerTest(".");
        }
    }
















