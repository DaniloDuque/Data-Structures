public class Heap<T> {
    private ArrayList<T> tree;
    private BiFunction<T, T, Boolean> oper;

    public Heap(BiFunction<T, T, Boolean> oper) {
        this.oper = oper;
        this.tree = new ArrayList<>();
        tree.add(null); 
    }

    private void swap(int i, int j) {
        T temp = tree.get(i);
        tree.set(i, tree.get(j));
        tree.set(j, temp);
    }

    private void heapify(int r) {
        int m = r, left = r * 2, right = r * 2 + 1;
        if (left < tree.size() && oper.apply(tree.get(left), tree.get(m))) m = left;
        if (right < tree.size() && oper.apply(tree.get(right), tree.get(m))) m = right;
        if (r == m) return;
        swap(m, r);
        heapify(m);
    }

    public void heapify() {
        for (int i = tree.size() - 1; i > 0; i--) heapify(i);
    }

    public void display() {
        for (int i = 1; i < tree.size(); i++) {
            System.out.print(tree.get(i) + " ");
        }
        System.out.println();
    }

    public void push(T x) {
        tree.add(x);
        for (int i = tree.size() - 1; i > 1; i /= 2) {
            if (!oper.apply(tree.get(i), tree.get(i / 2))) return;
            swap(i, i / 2);
        }
    }

    public T pop() {
      
        T max = tree.get(1);
        tree.set(1, tree.get(tree.size() - 1));
        tree.remove(tree.size() - 1);

        int i = 1;
        while (i * 2 < tree.size()) {
            int left = i * 2;
            int right = i * 2 + 1;

            if (right < tree.size() && oper.apply(tree.get(right), tree.get(i))) {
                if (oper.apply(tree.get(left), tree.get(right))) {
                    swap(left, i);
                    i = left;
                } else {
                    swap(right, i);
                    i = right;
                }
            } else if (oper.apply(tree.get(left), tree.get(i))) {
                swap(left, i);
                i = left;
            } else {
                break;
            }
        }

        return max;
    }

}
