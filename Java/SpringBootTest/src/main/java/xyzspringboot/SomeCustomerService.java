package xyzspringboot;

import org.springframework.stereotype.Component;

public class SomeCustomerService {
    String name;

    public SomeCustomerService() {
        this.name = "name not set";
    }

    public SomeCustomerService(Customer customer) {
        this.name = customer.getName();
    }

    public String getName() {
        return name;
    }
}
