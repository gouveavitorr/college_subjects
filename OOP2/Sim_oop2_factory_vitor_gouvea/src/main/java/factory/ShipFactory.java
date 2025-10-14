package factory;

import model.Ship;
import model.Transport;

public class ShipFactory extends TransportFactory {
    @Override
    public Transport assignTransport() {
        return new Ship();
    }
}
