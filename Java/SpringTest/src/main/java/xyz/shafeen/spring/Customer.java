package xyz.shafeen.spring;

import org.springframework.stereotype.Component;

@Component("customer1")
public class Customer {

    String name;

    public Customer() {
        this.name = "Customer Doe";
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
