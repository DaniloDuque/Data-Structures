import java.util.List;
import java.util.ArrayList;

public class MaxHeap {

    private ArrayList<Integer> heap;

    private void swap(int i, int j) {
        int temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }

    private void heapify(int index) {

        int m = index, left = index << 1, right = (index << 1) + 1;
        if (left < heap.size() && heap.get(left) > heap.get(m)) m = left;
        if (right < heap.size() && heap.get(right) > heap.get(m)) m = right;
        if (index == m) return;
        swap(m, index);
        heapify(m);

    }

    public MaxHeap() {
        heap = new ArrayList<>();
        heap.add(1 << 30);  // This is to index the vector, starting from 1
    }


    // this method creates a maxheap out of a vector in O(n)
    public void heapify() {
        for (int i = heap.size() - 1; i > 0; i--) heapify(i);
    }




    public void push(int x) {
        heap.add(x);
        for (int i = heap.size() - 1; i > 0; i >>= 1) {
            if (heap.get(i >> 1) >= heap.get(i)) return;
            swap(i >> 1, i);
        }
    }




    public void pop() {
        int i = 1;
        heap.set(1, heap.get(heap.size() - 1));  // modify the top of the heap to be the last element
        heap.remove(heap.size() - 1);
        while ((i << 1) + 1 < heap.size()) {    
            if (heap.get(i << 1) > heap.get(i)) {
                swap(i << 1, i);
                i <<= 1;
            } else if (heap.get((i << 1) + 1) > heap.get(i)) {
                swap((i << 1) + 1, i);
                i = (i << 1) + 1;
            } else return;
        }
    }
}
