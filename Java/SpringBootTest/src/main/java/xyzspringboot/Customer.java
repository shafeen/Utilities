package xyzspringboot;

public class Customer {
    String name;

    public Customer() {
        this.name = "John Doe";
    }

    public Customer(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}
