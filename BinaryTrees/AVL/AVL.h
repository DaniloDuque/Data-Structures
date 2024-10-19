template<typename T>
class AVL {
private:
    struct node {
        T data;
        int height;
        node* par, *right, *left;

        node(T x) : data(x), height(0), par(nullptr), right(nullptr), left(nullptr) {}
    };

    node* root;

    node* rotateLeft(node* r) {
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

    node* rotateRight(node* r) {
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

    node* balance(node* r) {
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

    node* insert(node* r, node* newN) {
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

    node* successor(node* r) {
        if (!r->right) return new node(r->data);
        return successor(r->right);
    }

    node* remove(node* r) {
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

    node* remove(node* r, node* newN) {
        if (!r) return r;
        if (r->data == newN->data) return r = remove(r);
        (r->data < newN->data) ? r->right = remove(r->right, newN) : r->left = remove(r->left, newN);
        r->height = max(height(r->left), height(r->right)) + 1;
        return balance(r);
    }

    int height(node* r) {
        if (!r) return -1;
        return r->height;
    }

    bool search(node* r, node* newN) {
        if (!r || !newN) return false;
        if (r->data == newN->data) return true;
        if (r->data < newN->data) return search(r->right, newN);
        return search(r->left, newN);
    }

    void display(node* r, string prefix, bool isLeft) {
        if (!r) return;
        cout << prefix;
        cout << (isLeft ? "├──" : "└──");
        cout << r->data << "\n";
        display(r->left, prefix + (isLeft ? "│   " : "     "), true);
        display(r->right, prefix + (isLeft ? "│   " : "     "), false);
    }

public:
    AVL() : root(nullptr) {}

    ~AVL() {
        clear(root);
    }

    void clear(node* r) {
        if (r) {
            clear(r->left);
            clear(r->right);
            delete r;
        }
    }

    bool insert(T x) {
        node* newN = new node(x);
        if (search(root, newN)) {
            delete newN;
            return false;
        }
        root = insert(root, newN);
        return true;
    }

    bool remove(T x) {
        node* newN = new node(x);
        if (!search(root, newN)) {
            delete newN;
            return false;
        }
        root = remove(root, newN);
        return true;
    }

    bool search(T x) {
        return search(root, new node(x));
    }

    void display() {
        display(root, "", true);
    }
};
