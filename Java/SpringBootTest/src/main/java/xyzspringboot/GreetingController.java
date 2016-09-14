package xyzspringboot;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class GreetingController {

    private SomeCustomerService someCustomerService;

    @Autowired
    public void setSomeCustomerService(SomeCustomerService someCustomerService) {
        this.someCustomerService = someCustomerService;
    }


    // [RestController] Returning a string just returns data as plaintext html
    @RequestMapping("/")
    public String indexPlain() {
        return "Hi there! My name is " + this.someCustomerService.getName();
    }

    // [RestController] Returning an object will spit out the data as json
    @RequestMapping("/json")
    public Greeting indexJson() {
        return new Greeting("Hi there! My name is " + this.someCustomerService.getName());
    }

}
