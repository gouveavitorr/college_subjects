package org.example.model;

public class OctalObserver extends ConcreteObserver {
    public OctalObserver(String name) {
        super(name);
    }

    @Override
    public void printState(Integer state) {
        System.out.println("New state in octal is " + Integer.toOctalString(state));
    }
}
