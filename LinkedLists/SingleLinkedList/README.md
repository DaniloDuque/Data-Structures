# Single Linked List

A single linked list is a dynamic data structure that allows efficient insertion and removal of elements. Each element in the list is represented by a node, containing data and a reference (or link) to the next node in the sequence. The last node's link points to `null`, indicating the end of the list.

## Introduction

Single linked lists provide a flexible and efficient way to manage data, particularly when the size of the data is not known in advance or when frequent insertions and deletions are expected. Unlike arrays, linked lists do not have a fixed size, and memory can be allocated dynamically as needed.

### Advantages:

- **Dynamic Size:** Linked lists can dynamically adjust in size as elements are added or removed, without the need to pre-allocate memory.
  
- **Efficient Insertions and Deletions:** Inserting or removing elements in a linked list involves updating pointers, making these operations faster compared to arrays where elements may need to be shifted.

- **Memory Utilization:** Memory is used efficiently since each element only requires memory for data and a reference, avoiding the need for a fixed-size block of memory.

### Disadvantages:

- **Random Access:** Accessing elements in a linked list is not as efficient as in arrays. To access an element, you need to traverse the list from the beginning, making random access slower.

- **Memory Overhead:** Each node in a linked list requires additional memory for storing the reference to the next node, leading to a slight increase in memory overhead.

## Time and Space Complexity

The time complexity for common operations in a single linked list is as follows:

- **Append:** O(n), where n is the number of elements in the list. Appending involves traversing the list to find the last node.

- **Insert:** O(n), where n is the number of elements in the list. Inserting at a specific position requires traversing the list to find the insertion point.

- **Remove:** O(n), where n is the number of elements in the list. Removing an element involves traversing the list to find the element.

- **Search:** O(n), where n is the number of elements in the list. Searching requires traversing the list until the desired element is found.

- **Size:** O(1). The size operation involves returning the count of elements in the list, which can be tracked as elements are added or removed.

The space complexity is O(n), where n is the number of elements in the list. This accounts for the memory required to store the data and references in each node.

## Usages

Single linked lists are used in various scenarios, including:

- **Dynamic Data Storage:** When the size of the data is not known in advance or can change dynamically.

- **Frequent Insertions and Deletions:** When there is a need for efficient insertion and deletion operations.

- **Implementation of Other Data Structures:** Linked lists are fundamental in implementing more complex data structures like stacks, queues, and symbol tables.

- **Undo Functionality:** In applications where users can undo actions, a linked list can be used to maintain a history of changes.

- **Memory Allocation:** In systems programming, linked lists are used in memory allocation and deallocation.

