package logsystem;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

import dbUtil.dbConnection;

public class LoginModel {
    Connection connection;

    public LoginModel() {
        connection = dbConnection.getConnection();
        if (this.connection == null) { System.exit(1); }
    }

    public Boolean isConnected() { return connection!=null; }

    public Boolean isLogin(String username, String password, String div) throws SQLException {
        PreparedStatement ps = null;
        ResultSet rs = null;
        String sql = "select * from login where username = ? and password = ? and division = ?";

        try {
            ps = this.connection.prepareStatement(sql);
            ps.setString(1, username);
            ps.setString(2, password);
            ps.setString(3, div);

            rs = ps.executeQuery();
            if(rs.next()) { return true; }
            return false;
        } catch (SQLException throwables) {
            throwables.printStackTrace();
            return false;
        } finally {
            ps.close();
            rs.close();
        }
    }
}
