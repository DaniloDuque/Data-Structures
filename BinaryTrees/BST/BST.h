#include <iostream>
using namespace std;

// Node structure for the Binary Search Tree
struct node {
    int data;
    node *left, *right;
    node(int x) : data(x), left(NULL), right(NULL) {}
    ~node() {}
};

// Binary Search Tree class
class BST {
    private:
        node *root;

        // Private helper functions
        node *insert(node *r, node *newN);
        node *remove(node *r, int x);
        int getMinValue(node *r);
        void display(node *r, string prefix, bool isLeft);
        bool search(node *r, int x);

    public:
        // Constructor
        BST() : root(NULL) {}

        // Public methods
        void insert(int x) { root = insert(root, new node(x)); }
        void remove(int x) { root = remove(root, x); }
        void display() { display(root, "", true); }
        bool search(int x) { return search(root, x); }
};









// Private helper function to insert a node into the BST
node *BST::insert(node *r, node *newN) {
    if (!r) return newN;
    if (r->data < newN->data)
        r->right = insert(r->right, newN);
    else
        r->left = insert(r->left, newN);
    return r;
}












// Private helper function to get the minimum value from a subtree
int BST::getMinValue(node *r) {
    if (!r->left)
        return r->data;
    return getMinValue(r->left);
}











// Private helper function to remove a node with a given value from the BST
node *BST::remove(node *r, int x) {
    if (!r) return NULL;
    if (r->data == x) {
        if (r->right && r->left) {
            int temp = getMinValue(r->right);
            r->data = temp;
            r->right = remove(r->right, temp);
        } else {
            node *temp = r->right ? r->right : r->left;
            delete r;
            return temp;
        }
    } else if (r->data < x) {
        r->right = remove(r->right, x);
    } else {
        r->left = remove(r->left, x);
    }
    return r;
}












// Private helper function to search for a value in the BST
bool BST::search(node *r, int x) {
    if (!r)
        return false;
    if (r->data == x)
        return true;
    if (r->data < x)
        return search(r->right, x);
    return search(r->left, x);
}














// Private helper function to display the BST structure
void BST::display(node *r, string prefix, bool isLeft) {
    if (!r)
        return;
    cout << prefix;
    cout << (isLeft ? "|---" : "---");
    cout << r->data << '\n';
    display(r->right, prefix + (isLeft ? "|    " : "     "), true);
    display(r->left, prefix + (isLeft ? "|    " : "     "), false);
}
