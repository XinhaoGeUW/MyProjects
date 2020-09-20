package logsystem;

import admin.AdminController;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import student.StudentController;

import java.io.IOException;
import java.net.URL;
import java.sql.SQLException;
import java.util.ResourceBundle;

public class LoginController implements Initializable {
    LoginModel loginModel = new LoginModel();
    @FXML
    private Label dbstatus;
    @FXML
    private TextField user;
    @FXML
    private PasswordField pass;
    @FXML
    private ComboBox combo;
    @FXML
    private Button button;
    @FXML
    private Label loginStatus;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        if (this.loginModel.isConnected()) this.dbstatus.setText("Connected Successfully ^_^");
        else this.dbstatus.setText("Connection Failed <_>");

        this.combo.setItems(FXCollections.observableArrayList(option.values()));
    }

    @FXML
    public void login(ActionEvent event) {
        try {
            if (this.loginModel.isLogin(user.getText(), pass.getText(), combo.getValue().toString())) {
                Stage stage = (Stage) this.button.getScene().getWindow();
                stage.close();
                switch (combo.getValue().toString()) {
                    case "Admin":
                        adminLogin();
                        break;
                    case "Student":
                        studentLogin();
                        break;
                }
            } else {
                loginStatus.setText("Wrong Credentials <_>");
            }
        } catch (SQLException throwables) {
            throwables.printStackTrace();
        }
    }

    public void studentLogin() {
        try {
            Stage studentStage = new Stage();
            Parent root = FXMLLoader.load(getClass().getResource("/student/student.fxml"));
            studentStage.setScene(new Scene(root));
            studentStage.setTitle("Student DashBoard");
            studentStage.show();
        } catch (IOException e) { e.printStackTrace(); }
    }

    public void adminLogin() {
        try {
            Stage adminStage = new Stage();
            FXMLLoader loader = new FXMLLoader();
            Pane root = loader.load(getClass().getResource("/admin/admin.fxml").openStream());

            //AdminController adminController = (AdminController) loader.getController();
            adminStage.setScene(new Scene(root));
            adminStage.setTitle("Admin DashBoard");
            adminStage.setResizable(false);
            adminStage.show();
        } catch (IOException e) { e.printStackTrace(); }
    }
}
