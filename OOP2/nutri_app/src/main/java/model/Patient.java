package model;

public class Patient implements Person{
    private String name;
    private double weight;
    private Doctor doctor;

    public Patient(String name, double weight, Doctor doctor) {
        this.name = name;
        this.weight = weight;
        this.doctor = doctor;
    }

    public void eat(Food food){
        this.weight += food.getWeight();
        checkHealth(this.getWeight(), this);
        System.out.println("I just ate a " + " of " + food.getWeight() + "g :)");
    }

    private void checkHealth(double weight, Patient p){
        if(weight > 100){
            doctor.makeAppointment(p);
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
}
