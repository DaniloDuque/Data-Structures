template <typename T>
struct Node {
    T data;
    Node* nxt;
    Node(T x) : data(x), nxt(nullptr) {}
    ~Node() {}
};

template <typename T>
class Stack {
private:
    Node<T>* Top;

public:
    Stack() : Top(nullptr) {}

    void push(T x) {
        Node<T>* newN = new Node<T>(x);
        newN->nxt = Top;
        Top = newN;
    }

    void pop() {
        if (Top) {
            Node<T>* aux = Top->nxt;
            delete Top;
            Top = aux;
        }
    }

    T top() {
        return Top ? Top->data : T(); // Return default value of T if stack is empty
    }

    bool empty() {
        return !Top;
    }
};
