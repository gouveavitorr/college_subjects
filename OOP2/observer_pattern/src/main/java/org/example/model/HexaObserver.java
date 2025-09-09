package org.example.model;

public class HexaObserver extends ConcreteObserver {
    public HexaObserver(String name) {
        super(name);
    }

    @Override
    public void printState(Integer state) {
        System.out.println("New state in hex is " + Integer.toHexString(state));
    }
}
