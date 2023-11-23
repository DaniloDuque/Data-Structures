public class Queue {

    private class node {

        int data;
        node next;

        node(int x) {
            data = x;
            next = null;
        }
    }

    private node front;
    private node back;

    public Queue() {

        front = null;
        back = null;
    }


    public void push(int x) {

        node newnode = new node(x);
        if (front == null) {
            front = newnode;
            back = newnode;
            return;
        }
        
        back.next = newnode;
        back = newnode;
        
    }

    public void pop() {

        if (front != null) {
            node temp = front.next;
            front = temp;
        }
    }

    public int front() {
        return front != null ? front.data : -1; // Return -1 if the Queue is empty
    }

    public boolean isEmpty() {
        return front == null;
    }


}
