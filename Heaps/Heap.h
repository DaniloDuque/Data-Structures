template <typename T>
class Heap {
private:
    vector<T> Tree;
    function<bool(T, T)> oper;

    void swap(int i, int j) {
        T temp = Tree[i];
        Tree[i] = Tree[j];
        Tree[j] = temp;
    }

    void heapify(int r) {
        int m = r, left = r << 1, right = (r << 1) + 1;
        if (left < Tree.size() && oper(Tree[left], Tree[m])) m = left;
        if (right < Tree.size() && oper(Tree[right], Tree[m])) m = right;
        if (r == m) return;
        swap(m, r);
        heapify(m);
    }

public:
    Heap(function<bool(T, T)> op) : oper(op) { Tree.push_back(T()); }

    void heapify() {
        for (int i = Tree.size() - 1; i; i--) heapify(i);
    }

    void display() {
        for (int i = 1; i < Tree.size(); i++) cout << Tree[i] << " ";
        cout << '\n';
    }

    void push(T x) {
        Tree.push_back(x);
        for (int i = Tree.size() - 1; i; i >>= 1) {
            if (!oper(Tree[i], Tree[i >> 1])) return;
            swap(i >> 1, i);
        }
    }

    T pop() {
        T max = Tree[1], i = 1;
        Tree[1] = Tree[Tree.size() - 1];
        Tree.pop_back();
        while ((i << 1) + 1 < Tree.size()) {
            if (oper(Tree[i << 1], Tree[i])) {
                swap(i << 1, i);
                i <<= 1;
            } else if (oper(Tree[(i << 1) + 1], Tree[i])) {
                swap((i << 1) + 1, i);
                i = (i << 1) + 1;
            } else {
                return max;
            }
        }
        return max;
    }
};
