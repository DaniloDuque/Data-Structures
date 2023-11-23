# Min Heap Implementation

This repository contains a implementation of a Min Heap, a specialized binary tree-based data structure. A Min Heap is a complete binary tree where the value of each node is less than or equal to the values of its children.

## Implementation Details

### `MinHeap` Class

The `MinHeap` class encapsulates the Min Heap implementation. It provides the following methods:

- `push(int x)`: Inserts an element `x` into the Min Heap.
- `pop()`: Removes and returns the minimum element from the Min Heap.
- `display()`: Displays the elements of the Min Heap.
- `heapify()`: Converts a vector into a Min Heap in O(n) time.
- `swap(int i, int j)`: Swaps two elements in the Min Heap.

### Usage

```cpp
int main() {
    MinHeap minHeap;

    minHeap.push(5);
    minHeap.push(10);
    minHeap.push(3);

    cout << "Min element: " << minHeap.pop() << endl; // Output: 3
    minHeap.display(); // Output: 5 10
    cout << "Is the Min Heap empty? " << (minHeap.pop() ? "No" : "Yes") << endl; // Output: No

    return 0;
}
```

This example demonstrates the usage of the `MinHeap` class in C++ with a simple `main` function. It pushes elements, pops the minimum element, displays the elements, and checks if the Min Heap is empty.

## Use Cases

Min Heaps are commonly used in scenarios where quick retrieval of the minimum element is essential. Some common use cases include:

1. **Priority Queues:** Min Heaps are used to implement priority queues where elements with lower priority (smaller values) are dequeued before elements with higher priority.

2. **Dijkstra's Algorithm:** Min Heaps are employed in Dijkstra's algorithm for finding the shortest path in a graph.

3. **Huffman Coding:** Min Heaps are used in Huffman coding, a widely used algorithm for lossless data compression.

## Complexity

- **Time Complexity:**
  - `push(int x)`: O(log n)
  - `pop()`: O(log n)
  - `heapify()`: O(n)

- **Space Complexity:**
  - O(n) for storing the elements in the vector.

## Limitations

- The Min Heap implementation assumes that the elements being added are integers. Modifications may be needed for other data types.
- The implementation uses a vector to store the heap elements, which might lead to resizing overhead.

Feel free to use this Min Heap implementation in your projects or explore ways to adapt it to specific requirements!
