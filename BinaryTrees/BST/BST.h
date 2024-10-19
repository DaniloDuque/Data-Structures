template<typename T>
class BST {
private:
    struct node {
        T data;
        node *left, *right;

        node(T x) : data(x), left(nullptr), right(nullptr) {}
        ~node() {}
    };

    node *root;

    node *insert(node *r, node *newN) {
        if (!r) return newN;
        if (r->data < newN->data)
            r->right = insert(r->right, newN);
        else
            r->left = insert(r->left, newN);
        return r;
    }

    node *remove(node *r, T x) {
        if (!r) return nullptr;
        if (r->data == x) {
            if (r->right && r->left) {
                T temp = getMinValue(r->right);
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

    T getMinValue(node *r) {
        if (!r->left)
            return r->data;
        return getMinValue(r->left);
    }

    bool search(node *r, T x) {
        if (!r)
            return false;
        if (r->data == x)
            return true;
        if (r->data < x)
            return search(r->right, x);
        return search(r->left, x);
    }

    void display(node *r, string prefix, bool isLeft) {
        if (!r)
            return;
        cout << prefix;
        cout << (isLeft ? "|---" : "---");
        cout << r->data << '\n';
        display(r->right, prefix + (isLeft ? "|    " : "     "), true);
        display(r->left, prefix + (isLeft ? "|    " : "     "), false);
    }

public:
    BST() : root(nullptr) {}
    void insert(T x) { root = insert(root, new node(x)); }
    void remove(T x) { root = remove(root, x); }
    void display() { display(root, "", true); }
    bool search(T x) { return search(root, x); }
};
