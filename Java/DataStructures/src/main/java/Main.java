public class Main {

    public static void main(String[] args) {
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
