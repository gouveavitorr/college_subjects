package model;

public class Ship implements Transport {
    @Override
    public double estimateDeliveryTime(double kmDistance) {
        return (kmDistance/30.0) + 24;
    }

    @Override
    public double calculateCost(double kmDistance) {
        return (0.9 * kmDistance) + 800;
    }

    @Override
    public void deliver(String destination) {
        System.out.println("Package sent by ship to " + destination + " (sea)");
    }
}
