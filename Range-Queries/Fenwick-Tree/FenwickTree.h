#include <iostream>
#include <vector>
using namespace std;









class FenwickTree {

    private:
        int* Tree;
        int size;
        int sumRange(int);

    public:
        FenwickTree(vector<int>&);
        void build();
        void add(int, int);
        void display();
        int sumRange(int i, int f) { return sumRange(f) - sumRange(i - 1); }
};





FenwickTree::FenwickTree(vector<int>& values) {

    size = values.size() + 1;
        
    Tree = (int*)calloc(size, sizeof(int));

    for (int i = 1; i <= size; i++) Tree[i] = values[i - 1]; // Copy values to the FenwickTree

    this->build();
}






//builds the fenwick tree
void FenwickTree::build() {
    int par;
    for (int i = 1; i <= size; i++) {
        par = i + (i & -i);
        if (par <= size) Tree[par] += Tree[i];
    }
}







//adds the value 'x' to the i'th element in the vector also updating the path
void FenwickTree::add(int i, int x) {
    while (i <= size) {
        Tree[i] += x;
        i += (i & -i);
    }
}








//returns the sum of the vector from index 0 to i
int FenwickTree::sumRange(int i) {
    int s = 0;
    while (i > 0) {
        s += Tree[i];
        i -= i & -i;
    }
    return s;
}











void FenwickTree::display() {
    for (int i = 1; i <= size; i++) cout << Tree[i] << " ";
    cout << '\n';
}
