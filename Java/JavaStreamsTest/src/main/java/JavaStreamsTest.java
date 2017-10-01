import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class JavaStreamsTest {

    public static void collectionsStreamExample() {
        List<String> brokenSentence = new ArrayList<>(5) ;
        brokenSentence.add("Hello ");
        brokenSentence.add("there, ");
        brokenSentence.add("brave ");
        brokenSentence.add("new ");
        brokenSentence.add("World!");

        String sentence = brokenSentence.stream().reduce("", (p, c) -> p + c);
        System.out.println(sentence);

    }

    public static void arrayStreamExample() {
        String[] brokenSentence = {"Hello ", "there, ", "brave ", "new ", "World!"};
        String sentence = Arrays.stream(brokenSentence)
                .reduce("", (p, c) -> p + c);
        System.out.println(sentence);
    }

    public static void main(String[] args) {
        collectionsStreamExample();
        arrayStreamExample();
    }
}
