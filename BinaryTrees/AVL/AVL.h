
//This AVL implements a SET, so there's no pair of nodes with equal data in the tree


#include <iostream>
using namespace std;

// Node structure for AVL tree
struct node {
    int data, height;
    node *par, *right, *left;
    
    // Constructor
    node(int x) : data(x), height(0), par(nullptr), right(nullptr), left(nullptr) {}
};

// AVL tree class
class AVL {
    private:
        node* root;

        // Private helper functions
        node* insert(node*, node*);
        node* remove(node*, node*);
        node* remove(node*);
        node* successor(node*);
        node* rotateRight(node*);
        node* rotateLeft(node*);
        node* balance(node*);
        bool search(node*, node*);
        int height(node*);
        void display(node*, string, bool);
    
    public:
        AVL() : root(nullptr) {}

        // Destructor
        ~AVL() {
            clear(root);
        }

        // Clears the AVL tree
        void clear(node* r) {
            if (r) {
                clear(r->left);
                clear(r->right);
                delete r;
            }
        }

        // Public interface for inserting a value into the AVL tree
        bool insert(int x) {
            node* newN = new node(x);
            if (search(root, newN)) {
                delete newN;
                return false;
            }
            root = insert(root, newN);
            return true;
        }

        // Public interface for removing a value from the AVL tree
        bool remove(int x) {
            node* newN = new node(x);
            if (!search(root, newN)) {
                delete newN;
                return false;
            }
            root = remove(root, newN);
            return true;
        }

        // Public interface for searching a value in the AVL tree
        bool search(int x) {
            return search(root, new node(x));
        }

        // Public interface for displaying the AVL tree
        void display() {
            display(root, "", true);
        }
};







// Rotation to the left
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

// Rotation to the right
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












// Balancing the AVL tree
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












// Inserting a node into the AVL tree
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







// Finding the successor of a node
node* AVL::successor(node* r) {
    if (!r->right) return new node(r->data);
    return successor(r->right);
}










// Removing a node from the AVL tree
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










// Removing a node with a specific value from the AVL tree
node* AVL::remove(node* r, node* newN) {
    if (!r) return r;
    if (r->data == newN->data) return r = remove(r);
    (r->data < newN->data) ? r->right = remove(r->right, newN) : r->left = remove(r->left, newN);
    r->height = max(height(r->left), height(r->right)) + 1;
    return balance(r);
}

// Finding the height of a node
int AVL::height(node* r) {
    if (!r) return -1;
    return r->height;
}












// Searching for a node with a specific value in the AVL tree
bool AVL::search(node* r, node* newN) {
    if (!r || !newN) return false;
    if (r->data == newN->data) return true;
    if (r->data < newN->data) return search(r->right, newN);
    return search(r->left, newN);
}











// Displaying the AVL tree in a tree-like structure
void AVL::display(node* r, string prefix, bool isLeft) {
    if (!r) return;
    cout << prefix;
    cout << (isLeft ? "├──" : "└──");
    cout << r->data << "\n";
    display(r->left, prefix + (isLeft ? "│   " : "     "), true);
    display(r->right, prefix + (isLeft ? "│   " : "     "), false);
}
