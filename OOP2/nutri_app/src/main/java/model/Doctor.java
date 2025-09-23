package model;

import observer.Observer;
import observer.Subject;

public class Doctor implements Person, Observer {
    private String name;
    private String specialty;
    private Patient patient;

    public Doctor(String name){
        this.name = name;
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

    @Override
    public void makeAppointment() {
        System.out.println("Doctor" + this.name + " calling patient " + this.patient.getName());
    }

    @Override
    public void setSubject(Subject s) {
        this.patient = (Patient) s;
    }
}
