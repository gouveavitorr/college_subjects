package org.example.model;

import org.example.interfaces.Observer;
import org.example.interfaces.Subject;

import java.util.ArrayList;
import java.util.List;

public class ConcreteSubject implements Subject {
    private List<Observer> observers;
    private Integer state = 0;

    public ConcreteSubject() {
        this.observers = new ArrayList<>();
    }
    @Override
    public void register(Observer observer) {
        if (observer == null) throw new NullPointerException("Null object/Observer");
        if(!observers.contains(observer)) observers.add(observer);
    }

    @Override
    public void unregister(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers() {
        for (Observer observer: observers) {
            observer.update();
        }
    }
    @Override
    public Object getUpdate(Observer observer) {
        return this.state;
    }

    public void updateState(Integer state){
        System.out.println("State updated to " + state);
        this.state = state;
        notifyObservers();
    }
}
