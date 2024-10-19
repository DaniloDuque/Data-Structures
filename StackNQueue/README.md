# Stack and Queue Implementation

This repository contains implementations of two fundamental data structures: Stack and Queue. These structures are essential in computer science and have various applications in algorithm design, simulation, and solving problems in a wide range of domains. Both implementations support generic types, allowing them to store any type of data.

## Stack

### Overview

A Stack is a Last In, First Out (LIFO) data structure, where the last element added is the first one to be removed. It follows the principle of "push" to add an element and "pop" to remove the top element.

### Implementation Details

#### `Stack<T>` Class

The `Stack<T>` class encapsulates the stack implementation for any data type. It provides the following methods:

- `push(T x)`: Adds element `x` to the top of the stack.
- `pop()`: Removes the top element from the stack.
- `top()`: Returns the value of the top element without removing it.
- `empty()`: Checks if the stack is empty.

### Usage

```cpp
Stack<int> stack;
stack.push(5);
stack.push(10);
int topValue = stack.top(); // Returns 10
stack.pop();
bool isEmpty = stack.empty(); // Returns false
```

## Queue

### Overview

A Queue is a First In, First Out (FIFO) data structure, where the first element added is the first one to be removed. It follows the principle of "enqueue" to add an element and "dequeue" to remove the front element.

### Implementation Details

#### `Queue<T>` Class

The `Queue<T>` class encapsulates the queue implementation for any data type. It provides the following methods:

- `push(T x)`: Adds element `x` to the rear of the queue.
- `pop()`: Removes the front element from the queue.
- `front()`: Returns the value of the front element without removing it.
- `empty()`: Checks if the queue is empty.

### Usage

```cpp
Queue<int> queue;
queue.push(3);
queue.push(7);
int frontValue = queue.front(); // Returns 3
queue.pop();
bool isEmpty = queue.empty(); // Returns false
```

## Complexity Analysis

### Stack

- **Push Operation**: O(1) - Constant time complexity.
- **Pop Operation**: O(1) - Constant time complexity.
- **Top Operation**: O(1) - Constant time complexity.

### Queue

- **Enqueue Operation**: O(1) - Constant time complexity.
- **Dequeue Operation**: O(1) - Constant time complexity.
- **Front Operation**: O(1) - Constant time complexity.

## Applications

- **Stack**: Function call management (call stack), expression evaluation, undo mechanisms in applications, and backtracking algorithms.

- **Queue**: Task scheduling, breadth-first search algorithms, print queue management, and simulation systems.

## Contributing

Feel free to contribute to this repository by submitting bug reports, feature requests, or pull requests. Your contributions are highly appreciated!
