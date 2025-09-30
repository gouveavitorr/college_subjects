package dailyMeal;

public class Breakfast implements DailyMeal {

    @Override
    public void prepare() {
        System.out.println("Preparing breakfast! Woohoo");
    }
}
