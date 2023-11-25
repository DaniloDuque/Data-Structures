import java.util.Random;

class Node {
    int data;
    Node next;

    public Node(int x) {
        data = x;
        next = null;
    }
}

public class SingleLinkedList {

    private Node head;

    public SingleLinkedList() {
        head = null;
    }

    public void freeList() {
        if (head == null) return;
        Node current = head.next;
        while (current != null) {
            Node temp = current;
            current = current.next;
            temp = null;
        }
        head = null; // Important: mark the head as null after freeing the nodes
    }

    // if asc != 0, sort in ascending order, else descending order
    public void sort(int asc) {
        if (head == null || head.next == null) return; // Check for empty or single-node list
        SingleLinkedList less = new SingleLinkedList();
        SingleLinkedList greater = new SingleLinkedList();
        int x = head.data;
        Node current = head.next;
        while (current != null) {
            if (current.data < x) {
                less.appendNode(new Node(current.data));
            } else {
                greater.appendNode(new Node(current.data));
            }
            current = current.next;
        }
        if (asc != 0) {
            less.sort(asc);
            less.appendNode(new Node(x));
            greater.sort(asc);
            less.appendNode(greater.getFirst());
            head = less.getFirst();
        } else {
            greater.sort(asc);
            greater.appendNode(new Node(x));
            less.sort(asc);
            greater.appendNode(less.getFirst());
            head = greater.getFirst();
        }
    }

    public void appendNode(Node newNode) {
        if (head == null) {
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    public Node getFirst() {
        return head;
    }

    public void shuffle() {
        int count = size();
        Node current;
        Random random = new Random();
        int times = random.nextInt(count);
        times *= 20;
        for (int i = 0; i < times; i++) {
            current = head;
            int randomNumber = random.nextInt(count);
            for (int j = randomNumber; j > 0; j--) {
                if (current.next == null) {
                    head.data ^= current.data;
                    current.data ^= head.data;
                    head.data ^= current.data;
                } else {
                    current.data ^= current.next.data;
                    current.next.data ^= current.data;
                    current.data ^= current.next.data;
                }
                current = current.next;
            }
        }
    }

    public int remove(int index) {
        if (head == null) return -1; // Check for empty list
        int value;
        Node toRemove, current = head;
        if (index == 0) {
            value = current.data;
            toRemove = current;
            head = current.next;
            toRemove = null;
            return value;
        }
        for (int i = 0; i < index - 1; i++) {
            if (current.next == null) {
                return -1;
            }
            current = current.next;
        }
        toRemove = current.next;
        if (toRemove == null) {
            return -1;
        }
        value = toRemove.data;
        current.next = current.next.next;
        toRemove = null;
        return value;
    }

    public void push(int value) {
        Node newNode = new Node(value);
        newNode.next = head;
        head = newNode;
    }

    public void insert(int index, int value) {
        if (index == 0) {
            push(value);
            return;
        }
        Node newNode = new Node(value);
        Node current = head;
        for (int i = 0; i < index - 1; i++) {
            if (current.next == null) {
                current.next = newNode;
                return;
            }
            current = current.next;
        }
        newNode.next = current.next;
        current.next = newNode;
    }

    public int size() {
        int count = 0;
        Node current = head;
        while (current != null) {
            count++;
            current = current.next;
        }
        return count;
    }

    

    public void append(int value) {
        Node newNode = new Node(value);
        if (head == null) {
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    public void display() {
        if (head == null) return;
        Node current = head;
        while (current.next != null) {
            System.out.print(current.data + " ");
            current = current.next;
        }
        System.out.println(current.data);
    }






    public static void main(String[] args) {
        SingleLinkedList list = new SingleLinkedList();
        list.append(3);
        list.append(1);
        list.append(4);
        list.append(1);
        list.append(5);
        System.out.println("Original List:");
        list.display();

        list.shuffle();
        System.out.println("\nShuffled List:");
        list.display();

        list.sort(1);
        System.out.println("\nSorted List (Ascending):");
        list.display();

        list.sort(0);
        System.out.println("\nSorted List (Descending):");
        list.display();
    }


  
}
