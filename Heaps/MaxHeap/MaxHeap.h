#include <iostream>
#include <vector>
using namespace std;














class MaxHeap{

    private:

        vector<int> Tree;
        void heapify(int);
        void swap(int, int);


    public:

        MaxHeap();
        void heapify(){for(int i = Tree.size()-1; i; i--) heapify(i);}
        void display();
        void push(int);
        int pop();



};




void MaxHeap::swap(int i, int j){

    Tree[i] ^= Tree[j];
    Tree[j] ^= Tree[i];
    Tree[i] ^= Tree[j];

}







MaxHeap::MaxHeap(){
    
    Tree.push_back(1<<30); //This is to index the vector, starting from 1
    
}




//this method makes a heap out a vector in O(n)
void MaxHeap::heapify(int r){

    int m = r, left = r<<1, right = (r<<1)+1;
    if(left < Tree.size() && Tree[left] > Tree[m]) m=left;
    if(right < Tree.size() && Tree[right] > Tree[m]) m=right;
    if(r==m) return;
    swap(m, r);
    this->heapify(m);

}







void MaxHeap::push(int x){

    Tree.push_back(x); //inserts the new element in the last position of the vector
    for(int i = Tree.size()-1; i; i>>=1){ 

        if(Tree[i>>1] >= Tree[i]) return; //While the predecesor of the new element is less swap them
        swap(i>>1, i);
        
    }

}








int MaxHeap::pop(){

    int max = Tree[1], i=1;
    Tree[1] = Tree[Tree.size()-1];  //modify the top of the heap, to be the last element, and pop the last element
    Tree.pop_back();
    while((i<<1)+1 < Tree.size()){  //while our new top has a greater succesor, keep swapping

        if(Tree[i<<1] > Tree[i]) {

            swap(i << 1, i);
            i <<= 1;

        }else if(Tree[(i<<1)+1] > Tree[i]){

            swap((i<<1)+1, i);
            i = (i<<1)+1;

        }else return max; //if left and right succesor is less, then return the value that was popped

    }return max;
    
}










void MaxHeap::display(){

    for(int i = 1; i<Tree.size(); i++) cout<<Tree[i]<<" ";
    cout<<'\n';

}
