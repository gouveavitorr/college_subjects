package model;

public class WholeRice extends Food{
    private double proteins;
    private double carbs;
    private double fats;

    public WholeRice(double weight) {
        super(weight);
        this.proteins = 2.6;
        this.carbs = 25.8;
        this.fats = 0.8;
    }

    public double energyValue(){
        return this.getEnergyValue() * super.getWeight();
    }

    @Override
    public double getEnergyValue() {
        return ((this.getProteins() * 4) + (this.getCarbs() * 4) + (this.getFats() * 9));
    }

    @Override
    public double getProteins() {
        return this.proteins;
    }

    @Override
    public double getCarbs() {
        return this.carbs;
    }

    @Override
    public double getFats() {
        return this.fats;
    }
}
