//This AVL implements a SET, which means, that there's no pair of elements with equal value

#include <iostream>
using namespace std;

// Node structure for AVL tree
struct node {
    int data, height;
    node *par, *right, *left;
    node(int str) : data(str), height(0), par(nullptr), right(nullptr), left(nullptr) {}
    ~node() {}
};

// AVL Tree class
class AVL {

    private:

        node* root;
        node* insert(node*, node*);
        node* successor(node*);
        node* remove(node*, node*);
        node* remove(node*);
        node* rotateRight(node*);
        node* rotateLeft(node*);
        node* balance(node*);
        bool search(node*, node*);
        int height(node*);
        void display(node*, string, bool);

    public:

        AVL() : root(nullptr) {}

        // Public method to insert a value into the AVL tree
        bool insert(int x) {
            node* newN = new node(x);
            if(search(root, newN)) return false; // If a node with value x exists, return false
            root = insert(root, newN);
            return true;
        }

        // Public method to remove a value from the AVL tree
        bool remove(int x) {
            node* newN = new node(x);
            if (!search(root, newN)) return false; // If there's no node with value x, return false
            root = remove(root, newN);
            return true;
        }

        // Public method to check if a value exists in the AVL tree
        bool search(int str) {
            return search(root, new node(str));
        }

        // Public method to display the AVL tree structure
        void display() { return display(root, "", true); }

};












// Right rotation operation
node* AVL::rotateLeft(node* r) {
    node* n = r->right;
    n->par = r->par;
    r->par = n;
    r->right = n->left;
    if (n->left) n->left->par = r;
    n->left = r;
    r->height = max(height(r->left), height(r->right)) + 1;
    n->height = max(height(n->left), height(n->right)) + 1;
    return n;
}

// Left rotation operation
node* AVL::rotateRight(node* r) {
    node* n = r->left;
    n->par = r->par;
    r->par = n;
    r->left = n->right;
    if (n->right) n->right->par = r;
    n->right = r;
    r->height = max(height(r->left), height(r->right)) + 1;
    n->height = max(height(n->left), height(n->right)) + 1;
    return n;
}










// Balancing operation to maintain AVL property
node* AVL::balance(node* r) {
    int bf = height(r->left) - height(r->right);
    if (bf > 1) {
        if (height(r->left->left) - height(r->left->right) >= 1) return r = rotateRight(r);
        r->left = rotateLeft(r->left);
        return r = rotateRight(r);
    }
    if (bf < -1) {
        if (height(r->right->left) - height(r->right->right) <= -1) return r = rotateLeft(r);
        r->right = rotateRight(r->right);
        return r = rotateLeft(r);
    }
    return r;
}








// Insertion operation
node* AVL::insert(node* r, node* newN) {
    if (!r) return newN;
    if (r->data < newN->data) {
        r->right = insert(r->right, newN);
        r->right->par = r;
    } else {
        r->left = insert(r->left, newN);
        r->left->par = r;
    }
    r->height = max(height(r->left), height(r->right)) + 1;
    return balance(r);
}









// Finding the most right node from r
node* AVL::successor(node* r) {
    if (!r->right) return new node(r->data);
    return successor(r->right);
}







// Removal operation
node* AVL::remove(node* r) {
    if (!r->right && !r->left) {
        delete r;
        return nullptr;
    }
    if (r->right && !r->left) {
        r->right->par = r->par;
        return r->right;
    }
    if (!r->right && r->left) {
        r->left->par = r->par;
        return r->left;
    }
    node* temp = successor(r->left);
    r->data = temp->data;
    r->left = remove(r->left, temp);
    return r;
}







// Removal operation (overloaded)
node* AVL::remove(node* r, node* str) {
    if (!r) return r;
    if (r->data == str->data) return r = remove(r);
    (r->data < str->data) ? r->right = remove(r->right, str) : r->left = remove(r->left, str);
    r->height = max(height(r->left), height(r->right)) + 1;
    return balance(r);
}








// Height calculation
int AVL::height(node* r) {
    if (!r) return -1;
    return r->height;
}










// Search operation
bool AVL::search(node* r, node* newN) {
    if (!r || !newN) return false;
    if (r->data == newN->data) return true;
    if (r->data < newN->data) return search(r->right, newN);
    return search(r->left, newN);
}








// Display the AVL tree structure
void AVL::display(node* r, string prefix, bool isLeft) {
    if (!r) return;
    cout << prefix;
    cout << (isLeft ? "├──" : "└──");
    cout << r->data << "\n";
    display(r->left, prefix + (isLeft ? "│   " : "     "), true);
    display(r->right, prefix + (isLeft ? "│   " : "     "), false);
}
