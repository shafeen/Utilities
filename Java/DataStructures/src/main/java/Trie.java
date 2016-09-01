import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

// TODO: this is still incomplete
// TODO: create tests for this class
public class Trie {

    boolean isWord = false;
    public HashMap<Character, Trie> edges = new HashMap<>();

    public Trie() {
    }

    public void addWord(String word) {
        char firstChar = word.charAt(0);
        // check if this trie already has an edge for the firstChar
        Trie charNode = this.edges.get(firstChar);
        if (charNode == null) {
            charNode = new Trie();
            this.edges.put(firstChar, charNode);
        }

        boolean wordEndsHere = word.length() == 1;
        if (wordEndsHere) {
            charNode.setAsWord();
        } else {
            charNode.addWord(word.substring(1));
        }
    }

    private void setAsWord() {
        this.isWord = true;
    }

    public List<String> getAllWordsWithPrefix(String prefix) {
        // walk the tree until the prefix ends
        char[] prefixChars = prefix.toCharArray();
        Trie curNode = this;
        for (int i = 0; curNode != null && i < prefixChars.length; i++) {
            curNode = curNode.edges.get(prefixChars[i]);
        }

        if (curNode != null) {
            return curNode.getAllWordsFromTrie(prefix);
        } else {
            return new LinkedList<>();
        }
    }

    private List<String> getAllWordsFromTrie(String prefix) {
        // TODO: complete this to walk the trie and get all words
        // TODO: note that the prefix has to be passed in
        List<String> allWords = new LinkedList<>();
        if (this.isWord) {
            allWords.add(prefix);
        }
        for (Character edgeChar : this.edges.keySet()) {
            Trie childTrie = this.edges.get(edgeChar);
            List<String> words = childTrie.getAllWordsFromTrie(prefix + edgeChar); // TODO: use stringbuilder instead of string-concat
            allWords.addAll(words);
        }
        return allWords;
    }

}
