# Heap Data Structure (Max and Min Heap)

## Introduction

A **Heap** is a specialized binary tree-based data structure that satisfies the heap property. In a **Max Heap**, for any given node `N`, the value of `N` is greater than or equal to the values of its children. In a **Min Heap**, the value of `N` is less than or equal to its children. This property makes heaps useful in implementing priority queues and efficient sorting algorithms like **Heapsort**.

### Key Characteristics:
- Heaps are typically implemented using arrays or `ArrayList` (Java) or `vector` (C++) to store the tree.
- It provides efficient insertion and removal of the largest (Max Heap) or smallest (Min Heap) element.
- Every heap has a "root" element, which is always the largest (Max Heap) or smallest (Min Heap) element in the tree.

## Heap Operations and Time Complexity

### 1. **Insertion (`push`)**
   Inserting a new element into the heap involves placing the new element at the end of the array and "bubbling up" to restore the heap property if violated.

   **Time Complexity:** O(log n)

### 2. **Removal (`pop`)**
   Removing the root element (maximum for Max Heap, minimum for Min Heap) involves replacing it with the last element in the array, then "bubbling down" to restore the heap property.

   **Time Complexity:** O(log n)

### 3. **Heapify**
   Converts an unordered array into a heap. This is used to maintain the heap structure after multiple insertions or deletions.

   **Time Complexity:** O(n) for building the heap from an unordered array.

### 4. **Display**
   Traverses the heap and prints the elements in order.

   **Time Complexity:** O(n)

## Usage

### C++ Version

This heap implementation in C++ uses a custom comparator function that allows defining the behavior of the heap (Max Heap or Min Heap).

### Java Version

The Java implementation uses a functional interface (`BiFunction`) for comparisons, making it easy to define custom heap behavior like Max Heap or Min Heap during initialization.

---

## How to Use

### Java

#### Initialization

1. Create a **Max Heap** by passing a comparator that checks if one element is greater than another.
2. Create a **Min Heap** by passing a comparator that checks if one element is less than another.

```java
Heap<Integer> maxHeap = new Heap<>((a, b) -> a > b);
Heap<Integer> minHeap = new Heap<>((a, b) -> a < b);
```

#### Insertion

To insert an element into the heap, use the `push` method:

```java
maxHeap.push(10);
minHeap.push(5);
```

#### Removal

To remove the maximum (Max Heap) or minimum (Min Heap) element, use the `pop` method:

```java
int max = maxHeap.pop();  // Removes and returns the maximum element
int min = minHeap.pop();  // Removes and returns the minimum element
```

#### Display

You can display the elements of the heap by calling the `display` method:

```java
maxHeap.display();
minHeap.display();
```

#### Full Example

```java
public static void main(String[] args) {
    Heap<Integer> maxHeap = new Heap<>((a, b) -> a > b);
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.display();
    System.out.println("Popped: " + maxHeap.pop());
    maxHeap.display();
}
```

### C++

#### Initialization

Create the heap with a custom comparator function in the constructor to define whether it is a **Max Heap** or **Min Heap**.

```cpp
auto maxHeap = MaxHeap([](int a, int b) { return a > b; });
auto minHeap = MaxHeap([](int a, int b) { return a < b; });
```

#### Insertion

Insert an element into the heap using the `push` method:

```cpp
maxHeap.push(10);
minHeap.push(5);
```

#### Removal

Remove the maximum (Max Heap) or minimum (Min Heap) element using the `pop` method:

```cpp
int max = maxHeap.pop();  // Removes and returns the maximum element
int min = minHeap.pop();  // Removes and returns the minimum element
```

#### Display

Display the heap elements using the `display` method:

```cpp
maxHeap.display();
minHeap.display();
```

#### Full Example

```cpp
int main() {
    MaxHeap<int> maxHeap([](int a, int b) { return a > b; });
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(5);
    maxHeap.display();
    cout << "Popped: " << maxHeap.pop() << endl;
    maxHeap.display();
    return 0;
}
```
