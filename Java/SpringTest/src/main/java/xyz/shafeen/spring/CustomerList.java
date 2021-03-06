package xyz.shafeen.spring;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.List;

@Component("customerList1")
public class CustomerList {
    String customer;

    public CustomerList(String customer) {
        this.customer = customer;
    }

    public CustomerList(CustomerList customer) {
        this.customer = customer.getCustomer();
    }

    @Autowired // <-- this is for the xml anno config
    public CustomerList(Customer customer) {
        System.out.println("Constructor called with Customer");
        this.customer = customer.getName();
    }

    public CustomerList() {
        this.customer = "John Doe";
    }

    public String getCustomer() {
        return customer;
    }

    public void setCustomer(String customer) {
        System.out.println("Constructor called with Customer");
        this.customer = customer;
    }

    @Autowired // <-- this is for the java based config
    public void setCustomer(Customer customer) {
        System.out.println("Setter called with Customer");
        this.customer = customer.getName();
    }
}
