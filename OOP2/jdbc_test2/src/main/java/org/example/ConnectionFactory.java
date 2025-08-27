package org.example;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class ConnectionFactory {

    private static final String url = "jdbc:mysql://107.161.183.247/humbertomo_aula";
    private static final String user = "humbertomo_aula";
    private static final String password = "humbertomo_aula";

    public ConnectionFactory(){}

    static{
        try{
            Class.forName("com.mysql.cj.jdbc.Driver");
        } catch (ClassNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public static Connection getConnection(){
        Connection connection;
        try{
            connection = DriverManager.getConnection(url, user, password);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return connection;
    }
}
