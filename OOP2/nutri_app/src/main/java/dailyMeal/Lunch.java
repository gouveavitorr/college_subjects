package dailyMeal;

public class Lunch implements DailyMeal {

    @Override
    public void prepare() {
        System.out.println("Preparing lunch! Yum :)");
    }
}
