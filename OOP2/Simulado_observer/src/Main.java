import model.*;

import java.lang.*;

public class Main {
    public static void main(String[] args) {

        Chef c1 = new Chef();
        Waiter w1 = new Waiter();
        Order o1 = new Order();

        o1.register(c1);
        o1.register(w1);
        c1.setSubject(o1);
        w1.setSubject(o1);

        o1.setStatus(Status.WAITING);

        Order o2 = new Order();

        o2.register(c1);
        o2.register(w1);
        c1.setSubject(o2);
        w1.setSubject(o2);

        o2.setStatus(Status.WAITING);
    }
}