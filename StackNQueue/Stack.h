#include <iostream>
using namespace std;




struct node{

    int data;
    node * nxt;
    node(int x): data(x), nxt(nullptr){}
    ~node(){}

};



class stack{

    private:

        node * Top;

    
    public:

        void push(int);
        void pop();
        int top();
        bool empty();

};




void stack::push(int x){

    node * newN = new node(x);
    newN->nxt = Top;
    Top = newN;
    
}


void stack::pop(){

    node * aux = Top->nxt;
    delete Top;
    Top = aux;

}


int stack::top(){

    return Top->data;

}

bool stack::empty(){

    return !Top;

}
