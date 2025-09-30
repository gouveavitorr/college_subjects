package model;

import dailyMeal.DailyMeal;

public abstract class Meal {
    private NutritionalValue nutritionalValue;

    public Meal(NutritionalValue n){
        this.nutritionalValue = n;
    }

    public void orderMeal(){
        System.out.println("Preparing meal...");
        DailyMeal meal = prepareMeal();
        meal.prepare();
    }

    public abstract DailyMeal prepareMeal();

    public NutritionalValue getNutritionalValue() {
        return nutritionalValue;
    }
}
