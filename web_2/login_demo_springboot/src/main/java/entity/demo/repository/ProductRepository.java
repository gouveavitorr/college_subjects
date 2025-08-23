package entity.demo.repository;

import entity.demo.model.Product;

import java.util.List;

import org.springframework.data.repository.CrudRepository;

public interface ProductRepository extends CrudRepository<Product, Long> {
    
    List<Product> findByName(String name);

    List<Product> findByPrice(double price);
    
    Product findById(long id);

}
