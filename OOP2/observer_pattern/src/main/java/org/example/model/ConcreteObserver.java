package org.example.model;


import org.example.interfaces.Observer;
import org.example.interfaces.Subject;

/*
* a listener or observer
* */
public class ConcreteObserver implements Observer {
    private String name;
    //ref to the Subject class
    private Subject topic;

    public ConcreteObserver(String name) {
        this.name = name;
    }

    @Override
    public void update() {
        Integer state = (Integer) topic.getUpdate(this);

        if(state == null) throw new NullPointerException();

        this.printState(state);
    }

    @Override
    public void setSubject(Subject subject) {
        this.topic = subject;
    }

    public void printState(Integer state){
        System.out.println("New state is " + state);
    }
}
