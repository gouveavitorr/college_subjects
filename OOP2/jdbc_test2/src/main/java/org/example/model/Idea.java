package org.example.model;

import org.example.ConnectionFactory;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Objects;

public class Idea {

    private int id;
    private String title;
    private String description;
    private int urgency;

    public Idea() {
    }

    public Idea(String title, String description, int urgency) {
        this.title = title;
        this.description = description;
        this.urgency = urgency;
    }

    public void insert(String title, String description, int urgency){
        String sql = "INSERT INTO Idea values(?,?,?);";

        Connection c = ConnectionFactory.getConnection();
        try {
            PreparedStatement prepState = c.prepareStatement(sql);

            prepState.setString(1, title);
            prepState.setString(2, description);
            prepState.setInt(3, urgency);

            prepState.executeUpdate();

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void delete(int id){
        String sql = "DELETE FROM Idea where id=?;";

        Connection c = ConnectionFactory.getConnection();
        try{
            PreparedStatement prepState = c.prepareStatement(sql);

            prepState.setInt(1,id);

            prepState.executeUpdate();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public static ArrayList list(){
        String sql = "SELECT * FROM Idea";
        ArrayList<Idea> ideas = new ArrayList<>();

        Connection c = ConnectionFactory.getConnection();

        try{
            PreparedStatement prepState = c.prepareStatement(sql);

            ResultSet rs = prepState.executeQuery();

            while(rs.next()){
                rs.getInt();
            }

        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return ideas;
    }


    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public int getUrgency() {
        return urgency;
    }

    public void setUrgency(int urgency) {
        this.urgency = urgency;
    }

    @Override
    public boolean equals(Object o) {
        if (o == null || getClass() != o.getClass()) return false;
        Idea idea = (Idea) o;
        return getId() == idea.getId() && getUrgency() == idea.getUrgency() && Objects.equals(getTitle(), idea.getTitle()) && Objects.equals(getDescription(), idea.getDescription());
    }

    @Override
    public int hashCode() {
        return Objects.hash(getId(), getTitle(), getDescription(), getUrgency());
    }

    @Override
    public String toString() {
        return "Idea{" +
                "id=" + id +
                ", title='" + title + '\'' +
                ", description='" + description + '\'' +
                ", urgency=" + urgency +
                '}';
    }
}
