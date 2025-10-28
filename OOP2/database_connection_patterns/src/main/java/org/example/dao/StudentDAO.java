package org.example.dao;

import org.example.model.Student;

import java.util.List;

public interface StudentDAO {
    public Student findById(int id);
    public List<Student> findAll();
    public void insert(Student student);
    public void update(Student student);
    public void delete(int id);
}
