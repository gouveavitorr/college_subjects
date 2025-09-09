package org.example;

import org.example.interfaces.Observer;
import org.example.model.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        ConcreteSubject topic = new ConcreteSubject();

        Observer firstObserver = new BinaryObserver("First observer");
        Observer secondObserver = new HexaObserver("Second observer");
        Observer thirdObserver = new OctalObserver("Third observer");
        topic.register(firstObserver);
        topic.register(secondObserver);
        topic.register(thirdObserver);

        firstObserver.setSubject(topic);
        secondObserver.setSubject(topic);
        thirdObserver.setSubject(topic);

        firstObserver.update();
        secondObserver.update();
        thirdObserver.update();

        topic.updateState(125);

        topic.unregister(firstObserver);
        topic.updateState(180);
    }
}