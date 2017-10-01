package xyz.shafeen.spring;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class AppConfig {

    @Bean(name = "customerList1")
    public CustomerList getCustomerList() {
        // return new CustomerList(getCustomer()); // <-- notice the constructor injection
        return new CustomerList();
    }

    @Bean(name = "customer1")
    public Customer getCustomer() {
        return new Customer();
    }
}
