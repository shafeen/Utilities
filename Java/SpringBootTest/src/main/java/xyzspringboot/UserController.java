package xyzspringboot;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.util.LinkedList;
import java.util.List;

@RestController
public class UserController {
    private class User {
        String name;
        // TODO: add more details later

        public User(String name) {
            this.name = name;
        }

        public String getName() {
            return name;
        }
    }

    private class CreationStatus {
        private boolean userCreated;
        private User user;

        public CreationStatus(boolean userCreated, User user) {
            this.userCreated = userCreated;
            this.user = user;
        }

        public boolean isUserCreated() {
            return userCreated;
        }

        public User getUser() {
            return user;
        }
    }

    private List<User> userList = new LinkedList<>();

    @RequestMapping("/user/create")
    public CreationStatus createUser(@RequestParam(value="name") String name) {
        if (name.length() != 0) {
            User newUser = new User(name);
            this.userList.add(newUser);
            return new CreationStatus(true, newUser);
        }
        return new CreationStatus(false, null);
    }

    @RequestMapping("/user/showall")
    public List<User> showUsers() {
        return this.userList;
    }




}
