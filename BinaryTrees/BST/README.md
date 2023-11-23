

# Binary Search Tree (BST)

## Overview

This repository contains a C++ implementation of a Binary Search Tree (BST). A BST is a binary tree data structure that maintains the properties of a search tree, where the left subtree of a node contains only nodes with keys less than the node's key, and the right subtree only nodes with keys greater than the node's key.

## Implementation Details

### `node` Structure

The `node` structure represents a node in the BST. It contains the following fields:

- `data`: The value stored in the node.
- `left`: Pointer to the left child node.
- `right`: Pointer to the right child node.

### `BST` Class

The `BST` class encapsulates the Binary Search Tree. It provides methods for inserting, removing, searching, and displaying the tree structure.

#### Methods:

- `insert(int x)`: Inserts a new node with value `x` into the BST.

- `remove(int x)`: Removes the node with value `x` from the BST.

- `search(int x)`: Checks if a node with value `x` exists in the BST.

- `display()`: Displays the structure of the BST.

## Usage

1. **Insertion:**
    ```cpp
    BST bst;
    bst.insert(5);
    bst.insert(3);
    bst.insert(7);
    ```

2. **Removal:**
    ```cpp
    bst.remove(3);
    ```

3. **Search:**
    ```cpp
    bool found = bst.search(7);
    ```

4. **Display:**
    ```cpp
    bst.display();
    ```

## Complexity Analysis

### Time Complexity

- **Insertion**: O(log n) - Each insertion operation involves traversing the height of the tree in the average case in case of balance.

- **Deletion**: O(log n) - Similar to insertion, deletion operations involve traversing the height of the tree in case of balance.

- **Search**: O(log n) - Searching in the BST is efficient due to its logarithmic height in case of balance.

### Space Complexity

- O(n) - The space complexity of the BST is linear with respect to the number of nodes.

## Applications

- **Searching and Sorting**: BSTs are commonly used for searching and sorting operations.

- **Symbol Tables**: BSTs can be employed in symbol tables for efficient key-value pair storage.

## Contributing

Feel free to contribute to this BST implementation by submitting bug reports, feature requests, or pull requests. Your contributions are highly appreciated!

