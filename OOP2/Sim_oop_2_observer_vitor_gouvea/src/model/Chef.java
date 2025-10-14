package model;

public class Chef implements Observer {

    private Order order;

    @Override
    public void update() {
        if(order.getStatus() == Status.WAITING){
            System.out.println("Order is being prepared by the chef!");
            order.setStatus(Status.DONE);
        }
    }

    @Override
    public void setSubject(Subject s) {
        this.order = (Order) s;
    }
}
