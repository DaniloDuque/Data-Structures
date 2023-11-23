#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {

    private:
        vector<int> Tree;
        int size;

    public:
        SegmentTree(vector<int>&);
        void build();
        void display();
        void update(int, int);
        int Max(int, int);

};









SegmentTree::SegmentTree(vector<int>& values) {

    size = values.size();
    Tree.resize(2 * size);

    for (int i = size; i < 2 * size; i++) Tree[i] = values[i - size];  //copies each value to the leaves of the segment tree

    this->build();
}








void SegmentTree::build() {

    for (int i = size - 1; i > 0; i--) 
        Tree[i] = max(Tree[2 * i], Tree[2 * i + 1]); // makes the predecessor of Tree[2i] and Tree[2i+1] = maximum between both
    
}



//updates the i'th value of the segment tree, also updating the path   O(logn)
void SegmentTree::update(int i, int x) {

    i += size;
    Tree[i] = x;

    while (i > 0){

        i >>= 1;
        int newV = max(Tree[2 * i], Tree[2 * i + 1]);

        if(Tree[i] == newV) return;
        
        Tree[i] = newV;
        
    }
}












//returns the max value between i and f indexes
int SegmentTree::Max(int i, int f){

    int m = -(1 << 30);
    i += size;
    f += size;

    while (i < f) {

        if (i & 1) {
            m = max(m, Tree[i]);
            i++;
        }
        if (f & 1) {
            f--;
            m = max(m, Tree[f]);
        }
        i >>= 1;
        f >>= 1;
        
    }return m;

}










void SegmentTree::display() {

    for (int i = 1; i < 2 * size; i++) cout << Tree[i] << " ";
    cout << endl;

}

