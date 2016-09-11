package xyzspringboot;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class GreetingController {

    private SomeCustomerService someCustomerService;

    @Autowired
    public void setSomeCustomerService(SomeCustomerService someCustomerService) {
        this.someCustomerService = someCustomerService;
    }


    @RequestMapping("/")
    public String index() {
        return "Hi there! My name is " + this.someCustomerService.getName();
    }
}
