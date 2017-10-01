import org.junit.Before;
import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

import static org.junit.Assert.assertEquals;

public class TrieTest {

    private Trie trie;

    @Before
    public void setUp() throws Exception {
        trie = new Trie();
    }

    @Test
    public void testTrieBasic() throws Exception {
        List<String> wordList = new ArrayList<>(Arrays.asList("banana", "banal", "banned"));
        wordList.stream().forEach(w -> this.trie.addWord(w));
        wordList.sort(String::compareTo);

        List<String> testList = this.trie.getAllWordsWithPrefix("ban");
        testList.sort(String::compareTo);
        assertEquals(wordList.size(), testList.size());

        for (int i = 0; i < wordList.size(); i++) {
            // System.out.printf("Comparing %s to %s\n", wordList.get(i), testList.get(i));
            assertEquals(wordList.get(i), testList.get(i));
        }
    }
}
