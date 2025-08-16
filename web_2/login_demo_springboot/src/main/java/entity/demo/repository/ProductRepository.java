package entity.demo.repository;

import entity.demo.model.*;

import java.util.ArrayList;
import java.util.List;

import org.springframework.stereotype.Repository;

@Repository
public class ProductRepository {
    private final List<Product> products = new ArrayList<>();
    private long counter = 1;

    public List<Product> findAll(){
        return products;
    }

    public Product findById(long id){
        for (Product p : products) {
            if(p.getId().equals(id)){
                return p;
            }
        }
        return null;
    }

    public void save(Product product){
        if(product.getId() == null){
            product.setId(counter++);
            products.add(product);
        }
        else {
            Product p = findById(counter);
            if(p != null){
                p.setName(product.getName());
                p.setPrice(product.getPrice());
            }
        }
    }

    public void deleteById(Long id){
        products.removeIf(p -> p.getId().equals(id));
    }

}
