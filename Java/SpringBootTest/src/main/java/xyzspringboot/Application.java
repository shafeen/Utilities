package xyzspringboot;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.Bean;

import java.util.Arrays;

@SpringBootApplication
public class Application {
    public static void main(String[] args) {
        ApplicationContext context = SpringApplication.run(Application.class, args);
        displayBeansAvailable(context);
    }

    public static void displayBeansAvailable(ApplicationContext context) {
        System.out.println("These are the beans we have available:");

        String[] beanNames = context.getBeanDefinitionNames();
        Arrays.sort(beanNames);
        for (String beanName : beanNames) {
            System.out.println(beanName);
        }
    }

    @Bean
    public SomeCustomerService someCustomerService(Customer customer1) {
        return new SomeCustomerService(customer1);
    }

    @Bean
    public Customer customer1() {
        return new Customer("Sylvanas Windrunner");
    }

    @Bean
    public Customer customer2() {
        return new Customer("Banshee Queen");
    }

}
