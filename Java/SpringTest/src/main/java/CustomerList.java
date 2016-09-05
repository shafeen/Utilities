import java.util.List;

public class CustomerList {
    String customer;

    public CustomerList(String customer) {
        this.customer = customer;
    }

    public CustomerList(CustomerList customer) {
        this.customer = customer.getCustomer();
    }

    public CustomerList() {
        this.customer = "John Doe";
    }

    public String getCustomer() {
        return customer;
    }

    public void setCustomer(String customer) {
        this.customer = customer;
    }
}
