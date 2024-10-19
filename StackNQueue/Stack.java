public class Stack<T> {

    private class Node {
        T data;
        Node nxt;

        Node(T x) {
            data = x;
            nxt = null;
        }
    }

    private Node top;

    public Stack() {
        top = null;
    }

    public void push(T x) {
        Node newN = new Node(x);
        newN.nxt = top;
        top = newN;
    }

    public void pop() {
        if (top != null) {
            top = top.nxt;
        }
    }

    public T top() {
        return top != null ? top.data : null; // Return null if the stack is empty
    }

    public boolean empty() {
        return top == null;
    }
}
