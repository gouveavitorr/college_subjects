package org.example.database;

import java.io.FileInputStream;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;

public abstract class ConnectionFactory {

    private static final String CONFIG_PATH = "src/main/resources/db.properties";
    private static final Properties props = new Properties();

    static {
        try {
            props.load(new FileInputStream(CONFIG_PATH));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static Connection getConnection(String banco) throws SQLException {
        return DriverManager.getConnection(
                props.getProperty("db." + banco + ".url"),
                props.getProperty("db." + banco + ".user"),
                props.getProperty("db." + banco + ".password"));
    }

    public static Connection getConnection() throws SQLException {
        return DriverManager.getConnection(
                props.getProperty("db.postgres.url"),
                props.getProperty("db.postgres.user"),
                props.getProperty("db.postgres.password"));
    }
}