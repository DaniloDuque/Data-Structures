
# AVL Tree

## Overview

This repository contains an implementation of an AVL (Adelson-Velsky and Landis) tree, a self-balancing binary search tree. AVL trees maintain balance during insertions and deletions, ensuring efficient search, insertion, and deletion operations.

## Implementation Details

### `node` Structure

The `node` structure represents a node in the AVL tree. It contains the following fields:

- `data`: The value stored in the node.
- `height`: The height of the node in the tree.
- `par`: Pointer to the parent node.
- `left`: Pointer to the left child node.
- `right`: Pointer to the right child node.

### `AVL` Class

The `AVL` class encapsulates the AVL tree. It provides methods for inserting, removing, searching, and displaying the tree structure.

#### Methods:

- `insert(int x)`: Inserts a new node with value `x` into the AVL tree.

- `remove(int x)`: Removes the node with value `x` from the AVL tree.

- `search(int x)`: Checks if a node with value `x` exists in the AVL tree.

- `display()`: Displays the structure of the AVL tree.

## Complexity Analysis

### Time Complexity

- **Insertion**: O(log n) - Each insertion operation involves traversing the height of the tree, and the AVL tree's self-balancing property ensures logarithmic height.

- **Deletion**: O(log n) - Similar to insertion, deletion operations involve traversing the height of the tree.

- **Search**: O(log n) - Searching in the AVL tree is efficient due to its balanced nature, resulting in logarithmic search time.

### Space Complexity

- O(n) - The space complexity of the AVL tree is linear with respect to the number of nodes.

## Applications

- **Database Indexing**: AVL trees are used in database systems for efficient indexing.

- **File System**: AVL trees can be employed in file systems to maintain a sorted directory structure.

- **Compiler Optimizations**: AVL trees are utilized in compilers for optimizing symbol tables.

## Contributing

Feel free to contribute to this AVL tree implementation by submitting bug reports, feature requests, or pull requests. Your contributions are highly appreciated!

