# Sparse Table

The Sparse Table is a data structure used to efficiently solve range queries on static arrays. It's particularly useful for problems involving frequent range queries on data that doesn't change.

## Introduction

The Sparse Table allows for range queries in O(1) time after O(n log n) preprocessing. It's ideal for situations where many fast queries are needed and the underlying data doesn't change.

## How It Works

The Sparse Table precomputes and stores the results of range queries for all intervals whose length is a power of 2. It then uses these precomputed results to answer any range query in constant time.

## Accepted Operators

The Sparse Table can work with any operator that is:

1. **Associative**: (a * b) * c = a * (b * c)
2. **Idempotent**: a * a = a

Some common examples of operators that meet these properties are:

- Minimum (min)
- Maximum (max)
- Bitwise AND
- Bitwise OR
- Bitwise XOR
- GCD (Greatest Common Divisor)

Note: Sum and multiplication, while associative, are not idempotent and therefore not suitable for the standard Sparse Table.

## Key Operations

1. **Build:**
   - Initializes the Sparse Table with the given values.
   - Time complexity: O(n log n)

2. **Query:**
   - Retrieves the result of the operation over a given range.
   - Time complexity: O(1)

## Implementation

The Sparse Table is typically implemented as a 2D array where:
- `st[i][j]` stores the result of the operation for the range [i, i + 2^j - 1]

## Advantages

1. **Fast queries:** O(1) for range queries.
2. **Versatility:** Can work with various operators that meet the necessary properties.
3. **Space efficiency:** Requires O(n log n) space, which is acceptable for many applications.

## Limitations

1. **Static data:** Not efficient for arrays that change frequently.
2. **Preprocessing:** Requires initial build time of O(n log n).
3. **Limited operators:** Not all operators are compatible.

## Applications

1. **RMQ (Range Minimum Query):** Finding the minimum in a range.
2. **Optimization problems:** Where fast queries over fixed ranges are needed.
3. **String processing:** In some applications of string algorithms.

## Complexities

- **Time Complexity:**
  - Build: O(n log n)
  - Query: O(1)
- **Space Complexity:**
  - O(n log n)

## Why Idempotent Operators Are Needed

The idempotent property is crucial for the Sparse Table because it allows combining overlapping results without double-counting elements in the intersection. This is what enables constant-time queries without worrying about overcounting.

Feel free to explore the implementation and adapt it to suit your specific use cases!
