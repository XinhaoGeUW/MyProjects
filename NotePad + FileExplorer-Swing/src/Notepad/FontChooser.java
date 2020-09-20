package AllNotepad;

import javax.swing.*;
import java.awt.*;

public class FontChooser extends JPanel {
    private Font font;
    private JList jFace, jStyle, jSize;
    private JDialog dialog;
    private JButton okb;

    JTextArea ta;
    private boolean isok;

    public FontChooser(Font f) {
        font = f;

        JPanel labelPanel = new JPanel();
        labelPanel.setLayout(new GridLayout(1, 3));
        labelPanel.add(new JLabel("Font", JLabel.CENTER));
        labelPanel.add(new JLabel("Font Style", JLabel.CENTER));
        labelPanel.add(new JLabel("Size", JLabel.CENTER));

        String[] fontNames = GraphicsEnvironment.getLocalGraphicsEnvironment().getAvailableFontFamilyNames();
        jFace = new JList(fontNames);
        jFace.setSelectedIndex(0);
        jFace.addListSelectionListener(e -> ta.setFont(createFont()));
        String[] fontStyles = {"Regular", "Bold", "Italic", "Bold Italic"};
        jStyle = new JList(fontStyles);
        jStyle.setSelectedIndex(0);
        jStyle.addListSelectionListener(e -> ta.setFont(createFont()));
        String[] fontSizes = new String[30];
        for (int i = 0; i < 30; i++) fontSizes[i] = 10 + i * 2 + "";
        jSize = new JList(fontSizes);
        jSize.setSelectedIndex(0);
        jSize.addListSelectionListener(e -> ta.setFont(createFont()));
        JPanel listPanel = new JPanel();
        listPanel.setLayout(new GridLayout(1, 3));
        listPanel.add(new JScrollPane(jFace));
        listPanel.add(new JScrollPane(jStyle));
        listPanel.add(new JScrollPane(jSize));

        ta = new JTextArea(5, 30);
        JPanel taPanel = new JPanel();
        taPanel.add(new JScrollPane(ta));

        JPanel centerPanel = new JPanel();
        centerPanel.setLayout(new GridLayout(2,1));
        centerPanel.add(listPanel);
        centerPanel.add(taPanel);

        okb = new JButton("OK");
        okb.addActionListener(e -> {
            isok = true;
            font = createFont();
            dialog.setVisible(false);
        });
        JButton cancelButton = new JButton("Cancel");
        cancelButton.addActionListener(e -> dialog.setVisible(false));
        JPanel buttonPanel = new JPanel();
        buttonPanel.setLayout(new FlowLayout());
        buttonPanel.add(okb);
        buttonPanel.add(new JLabel("             "));
        buttonPanel.add(cancelButton);

        setLayout(new BorderLayout());
        add(labelPanel, BorderLayout.NORTH);
        add(centerPanel, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);
        add(new JLabel("  "), BorderLayout.WEST);
        add(new JLabel("  "), BorderLayout.EAST);

        ta.setFont(font);
        ta.append("\nA quick brown fox jumps over the lazy dog.");
        ta.append("\n0123456789");
        ta.append("\n~!@#$%^&*()_+|?><\n");
    }

    public Font createFont() {
        Font font;
        int fontStyle = Font.PLAIN;
        int style = jStyle.getSelectedIndex();
        switch (style) {
            case 0: fontStyle = Font.PLAIN; break;
            case 1: fontStyle = Font.BOLD; break;
            case 2: fontStyle = Font.ITALIC; break;
            case 3: fontStyle = Font.BOLD + Font.ITALIC; break;
        }

        int fontSize = Integer.parseInt((String) jSize.getSelectedValue());
        String fontName = (String) jFace.getSelectedValue();

        font = new Font(fontName, fontStyle, fontSize);
        return font;
    }

    public boolean showDialog(Component parent, String title) {
        isok = false;
        Frame owner;
        if (parent instanceof Frame) owner = (Frame) parent;
        else owner = (Frame) SwingUtilities.getAncestorOfClass(Frame.class, parent);
        if (dialog == null || dialog.getOwner() != owner) {
            dialog = new JDialog(owner, true);
            dialog.add(this);
            dialog.getRootPane().setDefaultButton(okb);
            dialog.setSize(400, 325);
        }
        dialog.setTitle(title);
        dialog.setVisible(true);
        return isok;
    }

}
