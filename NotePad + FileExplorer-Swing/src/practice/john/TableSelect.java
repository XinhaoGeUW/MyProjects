package com.john;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

public class TableSelect {
    JTable jt;
    JFrame f;

    TableSelect() {
        f = new JFrame("Table Selection");
        String [][]data = {{"101","Amit","670000"}, {"102","Jai","780000"}, {"101","Sachin","700000"}};
        String []colums = {"ID", "NAME", "SALARY"};
        jt = new JTable(data, colums);
        jt.setCellSelectionEnabled(true);
        ListSelectionModel select = jt.getSelectionModel();
        select.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        select.addListSelectionListener(new ListSelectionListener() {
            @Override
            public void valueChanged(ListSelectionEvent e) {
                String ddata = null;
                int r = jt.getSelectedRow();
                int c = jt.getSelectedColumn();
                ddata = (String) jt.getValueAt(r, c);
                System.out.println("Table element selected is: " + ddata);
            }
        });
        JScrollPane jsp = new JScrollPane(jt);
        f.add(jsp);
        f.setSize(400,400);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        new TableSelect();

    }
}



