import java.util.PriorityQueue;
import java.util.Queue;

public class Main {

    public static class Person implements Comparable {
        final String name;

        public int getPriority() {
            return priority;
        }

        final int priority;

        public Person(String name, int priority) {
            this.name = name;
            this.priority = priority;
        }


        @Override
        public int compareTo(Object o) {
            if (this.priority > ((Person)o).getPriority()) {
                return 1;
            } else if (this.priority == ((Person) o).getPriority()) {
                return 0;
            } else {
                return -1;
            }
        }
    }


    public static void main(String[] args) {
        // testTrie();

        // Testing use of a PriorityQueue
        Queue<Person> priorityQueue = new PriorityQueue<>();
        priorityQueue.add(new Person("Employee", 2));
        priorityQueue.add(new Person("Boss", 1));

        while (priorityQueue.size() > 0) {
            System.out.println(priorityQueue.remove().name);
        }
    }

    private static void testTrie() {
        Trie radixTree = new Trie();

        radixTree.addWord("samsonite");
        radixTree.addWord("shaving");
        radixTree.addWord("shishkabob");
        radixTree.addWord("sandals");
        radixTree.addWord("shoe");
        radixTree.addWord("shake");

        System.out.println(radixTree.getAllWordsWithPrefix("sh"));
    }
}
