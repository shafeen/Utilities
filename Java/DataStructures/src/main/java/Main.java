public class Main {

    public static void main(String[] args) {
        Trie radixTree = new Trie();

        radixTree.addWord("sam");
        radixTree.addWord("shafeen");
        radixTree.addWord("sandals");
        radixTree.addWord("shoe");
        radixTree.addWord("sheikh");

        System.out.println(radixTree.getAllWordsWithPrefix("s"));
    }
}
