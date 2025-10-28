package org.example;

import org.example.database.ConnectionFactory;
import java.sql.Connection;

public class School {

    public void exec(){
        testConnection();
    }

    public static void testConnection(){
        try (Connection connection = ConnectionFactory.getConnection("postgres")){
            System.out.println("Conection established successfully");

        } catch (Exception e){
            e.printStackTrace();
        }
    }
}
