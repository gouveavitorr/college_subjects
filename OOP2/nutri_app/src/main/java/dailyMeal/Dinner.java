package dailyMeal;

import model.Meal;

public class Dinner implements DailyMeal {

    @Override
    public void prepare() {
        System.out.println("Preparing dinner! Sleepy sleepy");
    }
}
