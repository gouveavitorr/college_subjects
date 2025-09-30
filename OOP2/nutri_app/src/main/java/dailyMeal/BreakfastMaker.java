package dailyMeal;

import model.Meal;
import model.NutritionalValue;

public class BreakfastMaker extends Meal {

    public BreakfastMaker(){
        super(new NutritionalValue(20, 50, 10));
    }

    @Override
    public DailyMeal prepareMeal() {
         return new Breakfast();
    }
}
