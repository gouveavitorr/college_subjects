package org.example.model;

public class BinaryObserver extends ConcreteObserver {

    public BinaryObserver(String name) {
        super(name);
    }

    @Override
    public void printState(Integer state){
        System.out.println("New state in binary is " + Integer.toBinaryString(state));
    }

}
