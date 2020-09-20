package dbUtil;

import java.sql.*;

public class dbConnection {
    private static String url = "jdbc:mysql://localhost:3306/schoolmangement.";
    private static String username = "root", password = "Xinhg7273@$";

    public static Connection getConnection() {
        try {
            Class.forName("com.mysql.jdbc.Driver");
            return DriverManager.getConnection(url, username, password);
        } catch (ClassNotFoundException | SQLException e) { e.printStackTrace(); }

        return null;
    }
}
