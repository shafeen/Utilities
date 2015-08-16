import org.codehaus.jackson.map.ObjectMapper;

import java.io.*;
import java.net.URISyntaxException;

public class Main {
    public static void main(String[] args) throws IOException, URISyntaxException {

        File file = new File(Main.class.getResource("employee.json").toURI());
        ObjectMapper mapper = new ObjectMapper();
        Employee e = mapper.readValue(file, Employee.class);
        System.out.println(e);
    }


}
