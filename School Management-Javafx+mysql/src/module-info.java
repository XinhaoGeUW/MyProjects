module School.Management {
    requires javafx.controls;
    requires javafx.graphics;
    requires javafx.fxml;
    requires java.sql;
    opens logsystem;
    opens admin;
    opens student;
}