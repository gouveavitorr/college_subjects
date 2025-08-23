package entity.demo.repository;

import java.util.List;

import org.springframework.data.repository.CrudRepository;

import entity.demo.model.Order;

public interface OrderRepository extends CrudRepository<Order, Long> {
    Order findById(long id);

    List<Order> findByCustomerId(long id);
}
