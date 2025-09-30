package dailyMeal;

import model.Meal;
import model.NutritionalValue;

public class LunchMaker extends Meal {

    public LunchMaker() {
        super(new NutritionalValue(10, 60, 10));
    }

    @Override
    public DailyMeal prepareMeal() {
        return new Lunch();
    }
}
