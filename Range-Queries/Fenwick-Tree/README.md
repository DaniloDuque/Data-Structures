# Fenwick Tree (Binary Indexed Tree)

The Fenwick Tree, also known as Binary Indexed Tree (BIT), is a data structure designed for efficiently calculating and maintaining cumulative information over an array of values. It offers logarithmic time complexity for both updates and queries, making it a versatile tool for various applications.

## Introduction

The Fenwick Tree is particularly useful when dealing with problems that involve frequent updates to elements and queries for cumulative information within a range. It efficiently handles these operations, providing a balance between simplicity and performance.

## How It Works

The Fenwick Tree leverages the binary representation of indices to efficiently store and update cumulative information. Each index represents a range of elements, and bitwise operations are employed for navigation and updates.

## Binary Representation

### Binary Indexing

- Each index in the Fenwick Tree corresponds to a range of elements in the original array.
- The least significant bit (LSB) of the binary representation of an index determines the range it represents.

### Bitwise Operations

- To find the next index in the sequence, bitwise AND (&) is employed with the two's complement of the current index.
  Example: i & -i isolates the rightmost set bit in the binary representation of i.

## Update Operation

### Adding a Value

- When updating the Fenwick Tree, the algorithm starts at the given index i and updates elements based on their binary representation.
- For each node visited, the value is incremented by the update value (x).
- The process continues by moving to the next index, obtained using the bitwise AND operation.

### Binary Increment

- The binary representation of i determines the sequence of updates needed.
- The rightmost set bit (LSB) indicates the first node to be updated.
- Subsequent updates involve toggling the next set bit in the binary representation.

## Retrieval Operation

### Summation Operation

- Calculating the cumulative sum involves traversing the Fenwick Tree based on the binary representation of the index.
- Starting from the given index i, the algorithm moves to ancestors by flipping the rightmost set bit.
- The sum is accumulated as each node is visited.

## Advantages of Bitwise Representation

### Efficient Indexing

- The binary representation allows for efficient navigation through the tree using bitwise operations.
- Updates and queries involve a logarithmic number of operations, making them fast.

### Compact Storage

- The Fenwick Tree stores cumulative information compactly in an array, requiring only a linear amount of space.

## Key Operations

1. **Build:**
   - Initializes the Fenwick Tree with the given array of values.

2. **Update (Add):**
   - Increments the value at a specific index and updates the cumulative information.

3. **Query (Sum Range):**
   - Retrieves the cumulative sum of elements within a given range.

## Applications

1. **Prefix Sum:**
   - Efficiently computes prefix sums in an array.

2. **Range Queries:**
   - Handles cumulative queries within a specified range.

3. **Dynamic Frequency Counting:**
   - Tracks frequency counts dynamically with efficient updates and queries.

## Complexities

- **Time Complexity:**
  - Update: O(log n)
  - Query: O(log n)
  - Build: O(n log n)

- **Space Complexity:**
  - O(n)

## Why Invertible Operation?

The Fenwick Tree relies on the property of invertibility, ensuring that each update operation has a corresponding inverse operation. This property is essential for correct cumulative calculations during updates and queries. Common examples of invertible operations include addition (`+` with subtraction) and bitwise XOR (`^` with itself).

Feel free to explore the implementation and adapt it to suit your specific use cases!
