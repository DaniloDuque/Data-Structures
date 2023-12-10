# SkipList Implementation

## Introduction

A Skip List is a probabilistic data structure designed for efficient search, insertion, and deletion operations. It leverages multiple layers of linked lists to create express lanes, enhancing the speed of search operations compared to traditional linked lists.

## Complexities

### Time Complexity

- **Search (Average and Worst Case):** Θ(log n)   O(n)
- **Insertion (Average Case and Worst Case):** Θ(log n)   O(n)
- **Deletion (Average and Worst Case):** Θ(log n)   O(n)

### Space Complexity

- **O(n):** The average space complexity of a Skip List is 2n (where n is the cardinality of level 0). On average, each level contains half the number of nodes as its previous level, represented by the formula &Sigma; from i=0 to &infin; of (1/(2^i))*n, which equals 2n, assuming an infinite number of levels.

## How it Works

A Skip List consists of multiple layers, forming a linked list structure. The bottom layer includes all elements, and each subsequent layer holds a subset of elements from the layer below, creating express lanes for faster search operations.

### Insertion

1. When inserting an element, a random number of levels are chosen for the new element.
2. For each level, the element is inserted into the appropriate position in that level's linked list.

### Deletion

1. To delete an element, the corresponding node is removed from each level where it exists.
2. After deletion, the structure is adjusted to maintain Skip List properties.

### Search

1. Searching involves starting from the top-left corner and traversing down and to the right until finding the target value or reaching the end of the list.
2. This process is efficient due to the express lanes created by multiple levels.

### Space Complexity Considerations

- In the worst case, when the maximum number of levels is assigned to all elements, the space complexity can be O(n^2). This occurs when each element has the maximum possible number of levels.

## Applications

1. **Database Indexing:** Skip Lists are employed in databases to accelerate search operations, particularly when data is sorted or requires efficient searching.
   
2. **In-memory Databases:** Suitable for in-memory databases where the dataset fits in memory, providing efficient search and insertion operations.

3. **Concurrency Control:** Useful in concurrent data structures where multiple threads need to access and modify data concurrently, supporting parallel access.

4. **File Systems:** Suitable for implementing file systems to maintain an efficient directory structure, facilitating quick file retrieval.

5. **Networking Algorithms:** Utilized in networking algorithms to optimize routing and searching for efficient data transmission.

## Utilities

### `insert(int x)`

Inserts a new element with value `x` into the Skip List.

### `remove(int x)`

Removes the element with value `x` from the Skip List.

### `search(int x)`

Returns `true` if the Skip List contains an element with value `x`, and `false` otherwise.

### `display()`

Prints the current state of the Skip List, showing each level and the elements in that level.

## Challenges in Implementation

1. **Random Level Generation:** The effectiveness of a Skip List heavily relies on the proper generation of random levels for new elements. The distribution of levels impacts the overall structure and performance.

2. **Maintaining Skip List Properties:** Ensuring that the Skip List remains balanced and maintains its properties during insertions and deletions can be challenging. Adjustments are needed to keep the express lanes effective.

3. **Handling Edge Cases:** Special attention is required when dealing with scenarios such as the removal of the last element in a level or adjusting the overall level of the Skip List.

Feel free to experiment with the Skip List implementation and explore ways to optimize its performance or extend its functionality based on specific use cases.
