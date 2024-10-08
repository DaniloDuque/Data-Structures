class MinHeap {
    private:
        vector<int> Tree;
        void heapify(int);
        void swap(int, int);
    public:
        MinHeap();
        void heapify() { for (int i = Tree.size() - 1; i; i--) heapify(i); }
        void display();
        void push(int);
        int pop();
};

void MinHeap::swap(int i, int j) {
    Tree[i] ^= Tree[j];
    Tree[j] ^= Tree[i];
    Tree[i] ^= Tree[j];
}

MinHeap::MinHeap() {
    Tree.push_back(-(1 << 30)); // This is to index the vector, starting from 1
}

//this method creates a minHeap out of a vector in O(n)
void MinHeap::heapify(int r) {
    int m = r, left = r << 1, right = (r << 1) + 1;
    if (left < Tree.size() && Tree[left] < Tree[m]) m = left;
    if (right < Tree.size() && Tree[right] < Tree[m]) m = right;
    if (r == m) return;
    swap(m, r);
    this->heapify(m);
}

void MinHeap::push(int x) {
    Tree.push_back(x); //inserts the new element in the last position of the vector
    for (int i = Tree.size() - 1; i; i >>= 1) {  //While the predecesor of the new element is greater swap them
        if (Tree[i >> 1] <= Tree[i]) return;
        swap(i >> 1, i);
    }
}

int MinHeap::pop() {
    int min = Tree[1], i = 1;
    Tree[1] = Tree[Tree.size() - 1];  //modify the top of the heap, to be the last element, and pop the last element
    Tree.pop_back();
    while ((i << 1) + 1 < Tree.size()) {    //while our new top has a smaller succesor, keep swapping
        if (Tree[i << 1] < Tree[i]) {
            swap(i << 1, i);
            i <<= 1;
        }
        else if (Tree[(i << 1) + 1] < Tree[i]) {
            swap((i << 1) + 1, i);
            i = (i << 1) + 1;
        }
        else
            return min;  //return the top value
    }return min;
}

void MinHeap::display() {
    for (int i = 1; i < Tree.size(); i++)
        cout << Tree[i] << " ";
    cout << '\n';
}
