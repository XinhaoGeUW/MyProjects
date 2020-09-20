package admin;

import dbUtil.dbConnection;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.DatePicker;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;

import java.net.URL;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ResourceBundle;

public class AdminController implements Initializable {
    @FXML
    private TextField id;
    @FXML
    private TextField fname;
    @FXML
    private TextField lname;
    @FXML
    private TextField email;
    @FXML
    private DatePicker datestart;

    @FXML
    private TableView<StudentData> studenttable;
    @FXML
    private TableColumn<StudentData, String> studentid;
    @FXML
    private TableColumn<StudentData, String> studentfname;
    @FXML
    private TableColumn<StudentData, String> studentlname;
    @FXML
    private TableColumn<StudentData, String> studentemail;
    @FXML
    private TableColumn<StudentData, String> studentdatestart;

    private dbConnection connection;
    private ObservableList<StudentData> dataTable;
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        this.connection = new dbConnection();
    }

    private String sqlSelect = "SELECT * FROM students";
    public void LoadData(ActionEvent event) {
        try {
            Connection conn = dbConnection.getConnection();
            this.dataTable = FXCollections.observableArrayList();

            ResultSet rs = conn.createStatement().executeQuery(sqlSelect);
            while (rs.next()) {
                this.dataTable.add(new StudentData(rs.getString(1), rs.getString(2),
                                                     rs.getString(3), rs.getString(4),
                                                     rs.getString(5)));
            }
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
        this.studentid.setCellValueFactory(new PropertyValueFactory<StudentData, String>("ID"));
        this.studentfname.setCellValueFactory(new PropertyValueFactory<StudentData, String>("FirstName"));
        this.studentlname.setCellValueFactory(new PropertyValueFactory<StudentData, String>("LastName"));
        this.studentemail.setCellValueFactory(new PropertyValueFactory<StudentData, String>("Email"));
        this.studentdatestart.setCellValueFactory(new PropertyValueFactory<StudentData, String>("Date"));

        this.studenttable.setItems(null);
        this.studenttable.setItems(dataTable);
    }

    @FXML
    public void addStudent(ActionEvent event) {
        String sqlInsert = "insert into students (id, fname, lname, email, date) values (?,?,?,?,?)";

        try {
            Connection conn = dbConnection.getConnection();

            PreparedStatement ps = conn.prepareStatement(sqlInsert);

            ps.setString(1, this.id.getText());
            ps.setString(2, this.fname.getText());
            ps.setString(3, this.lname.getText());
            ps.setString(4, this.email.getText());
            ps.setString(5, this.datestart.getEditor().getText());

            ps.execute(); // Remember to Execute ps !!
            conn.close();
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }

    @FXML
    public void clearForm(ActionEvent event) {
        this.id.setText("");
        this.fname.setText("");
        this.lname.setText("");
        this.email.setText("");
        this.datestart.getEditor().setText("");
    }

}

















