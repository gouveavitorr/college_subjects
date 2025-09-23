package model;

import observer.Observer;
import observer.Subject;

import java.util.ArrayList;

public class Patient implements Person, Subject<Patient> {
    private String name;
    private double weight;
    private ArrayList<Doctor> doctors = new ArrayList<>();

    public Patient(String name, double weight, Doctor doctors) {
        this.name = name;
        this.weight = weight;
        this.doctors.add(doctors);
    }

    public void eat(Food food){
        this.weight += food.getWeight();
        checkHealth();
        System.out.println("I just ate a " + food.getClass().getName() + " of " + food.getWeight() + "g :)");
    }

    private void checkHealth(){
        if(this.weight > 100){
            notifyDoctors();
        }
    }

    @Override
    public void changeName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }

    @Override
    public void addDoctor(Observer o) {
        this.doctors.add((Doctor) o);
    }

    @Override
    public void removeDoctor(Observer o) {
        this.doctors.remove((Doctor) o);
    }

    @Override
    public void notifyDoctors() {
        for(Doctor d : this.doctors){
            d.makeAppointment();
        }
    }

    @Override
    public Patient getCurrentWeight() {
        return this;
    }
}
