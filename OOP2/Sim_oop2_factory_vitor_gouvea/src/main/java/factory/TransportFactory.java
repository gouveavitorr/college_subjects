package factory;

import model.*;

public abstract class TransportFactory {
    public Transport deliverPackage(String destination){
        Transport transport = assignTransport();
        transport.deliver(destination);
        return transport;
    }

    public abstract Transport assignTransport();
}
