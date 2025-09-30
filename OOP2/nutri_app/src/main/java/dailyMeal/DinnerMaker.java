package dailyMeal;

import model.Meal;
import model.NutritionalValue;

public class DinnerMaker extends Meal {

    public DinnerMaker() {
        super(new NutritionalValue(7, 30, 5));
    }

    @Override
    public DailyMeal prepareMeal() {
        return new Dinner();
    }
}
