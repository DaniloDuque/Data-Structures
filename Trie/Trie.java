import java.util.HashMap;

public class Trie {

    private static final char ROOT_CHAR = '\0';

    private static class Node {
        private char data;
        private boolean isEndOfWord;
        private HashMap<Character, Node> children;

        public Node(char data) {
            this.data = data;
            this.isEndOfWord = false;
            this.children = new HashMap<>();
        }
    }

    private Node root;

    public Trie() {
        this.root = new Node(ROOT_CHAR);
    }

    public void insert(String word) {
        Node currentNode = root;
        for (char ch : word.toCharArray()) {
            currentNode = currentNode.children.computeIfAbsent(ch, c -> new Node(c));
        }
        currentNode.isEndOfWord = true;
    }

    public boolean search(String word) {
        Node currentNode = findNode(word);
        return currentNode != null && currentNode.isEndOfWord;
    }

    private Node findNode(String word) {
        Node currentNode = root;
        for (char ch : word.toCharArray()) {
            currentNode = currentNode.children.get(ch);
            if (currentNode == null) {
                return null;
            }
        }
        return currentNode;
    }
}
