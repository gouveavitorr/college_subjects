package model;

public class Doctor implements Person {
    private String name;

    public Doctor(String name){
        this.name = name;
    }

    public void makeAppointment(Patient patient){
        System.out.println(patient.getName() + "has a new appointment with Dr." + this.name);
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
}
