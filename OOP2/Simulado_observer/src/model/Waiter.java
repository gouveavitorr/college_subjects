package model;

public class Waiter implements Observer {

    private Order order;

    @Override
    public void update() {
        if(order.getStatus() == Status.DONE){
            System.out.println("Order is being delivered by the waiter!");
            order.setStatus(Status.DELIVERED);
        }
    }

    @Override
    public void setSubject(Subject s) {
        this.order = (Order) s;
    }
}
