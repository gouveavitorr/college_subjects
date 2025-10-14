package org.example;

import factory.*;
import model.*;

public class Main {
    public static void main(String[] args) {

        TransportFactory TF = new TruckFactory();
        TransportFactory SF = new ShipFactory();
        TransportFactory DF = new DroneFactory();

        Truck t1 = (Truck) TF.deliverPackage("Porto Alegre");
        System.out.println("Estimate time: " + t1.estimateDeliveryTime(99.0) + "hours");
        System.out.println("Cost: " + t1.calculateCost(99.0));

        Ship s1 = (Ship) SF.deliverPackage("Hong Kong");
        System.out.println("Estimate time: " + s1.estimateDeliveryTime(8000) + "hours");
        System.out.println("Cost: " + s1.calculateCost(8000));

        Drone d1 = (Drone) DF.deliverPackage("Tramandai");
        System.out.println("Estimate time: " + d1.estimateDeliveryTime(25) + "hours");
        System.out.println("Cost: " + d1.calculateCost(25));
    }
}