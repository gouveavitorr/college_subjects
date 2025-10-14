package model;
import java.lang.*;
import java.util.ArrayList;

public class Order implements Subject {

    private Status status;
    private ArrayList<Observer> staffList = new ArrayList<>();

    @Override
    public void register(Observer o) {
        staffList.add(o);
    }

    @Override
    public void unregister(Observer o) {
        staffList.remove(o);
    }

    @Override
    public void notifySubscribers() {
        for(Observer o: staffList){
            o.update();
        }
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
        this.notifySubscribers();
    }
}
