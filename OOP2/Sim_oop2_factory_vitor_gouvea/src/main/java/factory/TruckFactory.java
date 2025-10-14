package factory;

import model.Transport;
import model.Truck;

public class TruckFactory extends TransportFactory {
    @Override
    public Transport assignTransport() {
        return new Truck();
    }
}
