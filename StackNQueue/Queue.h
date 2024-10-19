template <typename T>
struct node {
    T data;
    node* nxt;
    node(T x) : data(x), nxt(nullptr) {}
    ~node() {}
};

template <typename T>
class Queue {
private:
    node<T>* Front;
    node<T>* Back;

public:
    Queue() : Front(nullptr), Back(nullptr) {}

    void push(T x) {
        node<T>* newN = new node<T>(x);
        if (!Front) {
            Front = newN;
            Back = newN;
            return;
        }
        Back->nxt = newN;
        Back = newN;
    }

    void pop() {
        if (Front) {
            node<T>* aux = Front->nxt;
            delete Front;
            Front = aux;
        }
    }

    T front() {
        if (Front) {
            return Front->data;
        }
        throw std::runtime_error("Queue is empty");
    }

    bool empty() {
        return !Front;
    }
};
