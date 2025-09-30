package model;

public class NutritionalValue {

    private double protein;
    private double carbs;
    private double fats;

    public NutritionalValue(double p, double c, double f){
        this.protein = p;
        this.carbs = c;
        this.fats = f;
    }

    public double getEnergyValue(){
        return (protein * 4) + (carbs * 4) + (fats * 9);
    }

    public double getProtein() {
        return protein;
    }

    public void setProtein(double protein) {
        this.protein = protein;
    }

    public double getCarbs() {
        return carbs;
    }

    public void setCarbs(double carbs) {
        this.carbs = carbs;
    }

    public double getFats() {
        return fats;
    }

    public void setFats(double fats) {
        this.fats = fats;
    }
}