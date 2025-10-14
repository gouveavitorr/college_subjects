package model;

public interface Transport {

    public double estimateDeliveryTime(double kmDistance);
    public double calculateCost(double kmDistance);
    public void deliver(String destination);

}
