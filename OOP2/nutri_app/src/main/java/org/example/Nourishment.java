package org.example;

import model.*;

public class Nourishment {

    public Nourishment() {
    }

    public static void execute(){

        Doctor d1 = new Doctor("Grey");
        Patient p1 = new Patient("Joseph", 90, d1);
        Food f1 = new WholeRice(2);

        p1.eat(f1);
        p1.eat(f1);
        p1.eat(f1);
        p1.eat(f1);
        p1.eat(f1);
        p1.eat(f1);
    }
}
