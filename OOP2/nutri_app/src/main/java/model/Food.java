package model;

import java.util.Objects;

public abstract class Food extends NutritionalValue {
    private double weight;

    public Food(double weight) {
        this.weight = weight;
    }

    public double getWeight() {
        return weight;
    }

    public void setWeight(double weight) {
        this.weight = weight;
    }
}
