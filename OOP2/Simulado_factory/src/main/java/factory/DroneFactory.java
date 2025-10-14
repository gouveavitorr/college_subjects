package factory;

import model.Drone;
import model.Transport;

public class DroneFactory extends TransportFactory {
    @Override
    public Transport assignTransport() {
        return new Drone();
    }
}
