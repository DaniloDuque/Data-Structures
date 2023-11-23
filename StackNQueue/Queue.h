#include <iostream>
using namespace std;



struct node{

    int data;
    node *nxt;
    node(int x): data(x), nxt(nullptr){}
    ~node() {}

};



class queue{


    private:

        node * Front;
        node * Back;


    public:

        queue(): Front(nullptr), Back(nullptr){}
        void push(int);
        void pop();
        int front();
        bool empty(){return !Front;}

};



void queue::push(int x){

    node * newN = new node(x);
    if(!Front){

        Front = newN;
        Back = newN;
        return;

    }Back->nxt = newN;
    Back = newN;
    return;

}


void queue::pop() {

    node * aux = Front->nxt;
    delete Front;
    Front = aux;

}


int queue::front(){

    return Front->data;
    
}
