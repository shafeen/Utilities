import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;

public class Application {

    public static void main(String[] args) {
        ApplicationContext applicationContext = new ClassPathXmlApplicationContext("spring-config.xml");

        // bean created using default constructor
        CustomerList customerList1 = applicationContext.getBean("customerList1", CustomerList.class);
        System.out.println(customerList1.getCustomer());

        // bean created with constructor injection
        CustomerList customerList2 = applicationContext.getBean("customerList2", CustomerList.class);
        System.out.println(customerList2.getCustomer());

        // bean created using setter injection
        CustomerList customerList3 = applicationContext.getBean("customerList3", CustomerList.class);
        System.out.println(customerList3.getCustomer());

    }
}
