package model;

public class Drone implements Transport {
    @Override
    public double estimateDeliveryTime(double kmDistance) {
        return kmDistance/100.0;
    }

    @Override
    public double calculateCost(double kmDistance) {
        return kmDistance * 5.0;
    }

    @Override
    public void deliver(String destination) {
        System.out.println("Package sent by drone to " + destination + " (direct air route)");
    }
}
