public class Queue<T> {

    private class Node {
        T data;
        Node next;

        Node(T x) {
            data = x;
            next = null;
        }
    }

    private Node front;
    private Node back;

    public Queue() {
        front = null;
        back = null;
    }

    public void push(T x) {
        Node newNode = new Node(x);
        if (front == null) {
            front = newNode;
            back = newNode;
            return;
        }
        back.next = newNode;
        back = newNode;
    }

    public void pop() {
        if (front != null) {
            Node temp = front.next;
            front = temp;
        }
    }

    public T front() {
        return front != null ? front.data : null; // Return null if the Queue is empty
    }

    public boolean isEmpty() {
        return front == null;
    }
}
