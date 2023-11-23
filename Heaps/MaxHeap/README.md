# Max Heap Implementation

This repository contains a implementation of a Max Heap, a specialized binary tree-based data structure. A Max Heap is a complete binary tree where the value of each node is greater than or equal to the values of its children.

## Implementation Details

### `MaxHeap` Class

The `MaxHeap` class encapsulates the Max Heap implementation. It provides the following methods:

- `push(int x)`: Inserts an element `x` into the Max Heap.
- `pop()`: Removes and returns the maximum element from the Max Heap.
- `display()`: Displays the elements of the Max Heap.
- `heapify()`: Converts a vector into a Max Heap in O(n) time.
- `swap(int i, int j)`: Swaps two elements in the Max Heap.

### Usage

```cpp
int main() {
    MaxHeap maxHeap;

    maxHeap.push(5);
    maxHeap.push(10);
    maxHeap.push(3);

    cout << "Max element: " << maxHeap.pop() << endl; // Output: 10
    maxHeap.display(); // Output: 5 3
    cout << "Is the Max Heap empty? " << (maxHeap.pop() ? "No" : "Yes") << endl; // Output: No

    return 0;
}
```

This example demonstrates the usage of the `MaxHeap` class in C++ with a simple `main` function. It pushes elements, pops the maximum element, displays the elements, and checks if the Max Heap is empty.

## Use Cases

Max Heaps are commonly used in scenarios where quick retrieval of the maximum element is essential. Some common use cases include:

1. **Priority Queues:** Max Heaps are used to implement priority queues where elements with higher priority (larger values) are dequeued before elements with lower priority.

2. **Heap Sort:** The heap data structure is a vital component of the heap sort algorithm, which efficiently sorts an array in ascending order.

3. **Job Scheduling:** Max Heaps are employed in job scheduling algorithms, where jobs with higher priority (lower execution times or greater importance) are processed first.

## Complexity

- **Time Complexity:**
  - `push(int x)`: O(log n)
  - `pop()`: O(log n)
  - `heapify()`: O(n)

- **Space Complexity:**
  - O(n) for storing the elements in the vector.

## Limitations

- The Max Heap implementation assumes that the elements being added are integers. Modifications may be needed for other data types.
- The implementation uses a vector to store the heap elements, which might lead to resizing overhead.

Feel free to use this Max Heap implementation in your projects or explore ways to adapt it to specific requirements!
