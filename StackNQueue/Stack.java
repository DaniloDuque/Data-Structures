public class Stack{

    private class node{

        int data;
        node nxt;
        node(int x){
            data = x;
            nxt = null;
        }

    }

    private node top;

    public Stack(){
        top = null;
    }

    public void push(int x){

        node newN = new node(x);
        newN.nxt = top;
        top = newN;
    }

    public void pop(){

        top = top.nxt;

    }


    public int top(){
        return top.data;
    }


    public boolean empty(){
        return top == null;
    }




}