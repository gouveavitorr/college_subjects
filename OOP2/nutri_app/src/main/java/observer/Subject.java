package observer;

public interface Subject<T> {
    public void addDoctor(Observer o);
    public void removeDoctor(Observer o);
    public void notifyDoctors();
    public T getCurrentWeight();
}
