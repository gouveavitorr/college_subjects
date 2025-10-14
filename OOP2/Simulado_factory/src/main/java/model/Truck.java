package model;

public class Truck implements Transport {

    @Override
    public double estimateDeliveryTime(double kmDistance) {
        return kmDistance/60.0;
    }

    @Override
    public double calculateCost(double kmDistance) {
        return (1.8 * kmDistance) + 200;
    }

    @Override
    public void deliver(String destination) {
        System.out.println("Package sent by truck to " + destination + " (ground)");
    }
}
