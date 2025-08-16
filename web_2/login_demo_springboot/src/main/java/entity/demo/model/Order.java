package entity.demo.model;

import java.util.ArrayList;

public class Order {
    
    private int id;
    private ArrayList<Product> productList;
    private double totalPrice;

    public Order(int id, ArrayList<Product> productList, double totalPrice) {
        this.id = id;
        this.productList = productList;
        this.totalPrice = totalPrice;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public ArrayList<Product> getProductList() {
        return productList;
    }

    public void setProductList(ArrayList<Product> productList) {
        this.productList = productList;
    }

    public double getTotalPrice() {
        return totalPrice;
    }

    public void setTotalPrice(double totalPrice) {
        this.totalPrice = totalPrice;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + id;
        result = prime * result + ((productList == null) ? 0 : productList.hashCode());
        long temp;
        temp = Double.doubleToLongBits(totalPrice);
        result = prime * result + (int) (temp ^ (temp >>> 32));
        return result;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj)
            return true;
        if (obj == null)
            return false;
        if (getClass() != obj.getClass())
            return false;
        Order other = (Order) obj;
        if (id != other.id)
            return false;
        if (productList == null) {
            if (other.productList != null)
                return false;
        } else if (!productList.equals(other.productList))
            return false;
        if (Double.doubleToLongBits(totalPrice) != Double.doubleToLongBits(other.totalPrice))
            return false;
        return true;
    }

    @Override
    public String toString() {
        return "Order [id=" + id + ", productList=" + productList + ", totalPrice=" + totalPrice + "]";
    }
}
