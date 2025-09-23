package org.example;

import model.*;

public class Nourishment {

    public Nourishment() {
    }

    public static void execute(){

        Doctor d1 = new Doctor("Goro");
        Doctor d2 = new Doctor("Kitana");
        Patient p1 = new Patient("Joseph", 90, d1);
        Food f1 = new WholeRice(2);
        d1.setSubject(p1);
        d2.setSubject(p1);
        p1.addDoctor(d2);

        p1.eat(f1);
        p1.eat(f1);
        p1.eat(f1);
        p1.eat(f1);
        p1.eat(f1);
        p1.eat(f1);
        p1.eat(f1);
        p1.eat(f1);
    }
}
