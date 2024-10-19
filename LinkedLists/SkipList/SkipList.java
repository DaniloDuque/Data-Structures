import java.util.Random;

public class SkipList<T extends Comparable<T>> {

    private class Node {
        T data;
        int level;
        Node[] next;

        Node(T value, int level) {
            data = value;
            next = new Node[level + 1]; // Size of the array is the height of the node in the skip list
        }
    }

    private static final int MAX_LEVEL = 32;
    private Node head;
    private int level;
    private Random random;

    public SkipList() {
        head = new Node(null, MAX_LEVEL); // Head is a sentinel node
        level = 0; 
        this.random = new Random();
    }

    private int getNewLevel() {
        int newLevel = 0;
        while (random.nextBoolean() && newLevel < MAX_LEVEL) newLevel++;
        return newLevel;
    }

    public void insert(T x) {
        int newLevel = getNewLevel();
        Node newN = new Node(x, newLevel);
        Node curr = head;

        for (int i = newLevel; i >= 0; --i) {
            while (curr.next[i] != null && curr.next[i].data.compareTo(x) < 0) {
                curr = curr.next[i];
            }
            newN.next[i] = curr.next[i]; 
            curr.next[i] = newN;
        }
        if (newLevel > level) level = newLevel; 
    }

    public void remove(T x) {
        Node curr = head;

        for (int i = level; i >= 0; --i) {
            while (curr.next[i] != null && curr.next[i].data.compareTo(x) < 0) {
                curr = curr.next[i];
            }
            if (curr.next[i] != null && curr.next[i].data.equals(x)) {
                curr.next[i] = curr.next[i].next[i]; 
            }
        }
        while (level > 0 && head.next[level] == null) --level; 
    }

    public boolean search(T x) {
        Node curr = head;

        for (int i = level; i >= 0; --i) {
            while (curr.next[i] != null && curr.next[i].data.compareTo(x) < 0) {
                curr = curr.next[i];
            }
            if (curr.next[i] != null && curr.next[i].data.equals(x)) {
                return true;
            }
        }
        return false;
    }

    public void display() {
        System.out.println("Skip List:");

        for (int i = level; i >= 0; i--) {
            Node current = head;
            System.out.print("level " + i + ": ");
            while (current.next[i] != null) {
                System.out.print(current.next[i].data + " -> ");
                current = current.next[i];
            }
            System.out.println();
        }
        System.out.println();
    }
}
