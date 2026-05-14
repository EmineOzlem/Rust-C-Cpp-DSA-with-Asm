# Longest Common Prefix

## Project Overview
This project provides a robust **C implementation** for finding the longest common prefix among an array of strings. It is designed with a focus on low-level system efficiency and direct memory management.

## Technical Architecture

### 1. Vertical Scanning Logic
Instead of comparing strings one by one, the implementation scans the character at index **j** across all strings at the same time. This approach ensures that the algorithm stops the moment it detects a mismatch.

### 2. Multi-Level Loop Termination (The **goto** Pattern)
**Why I used `goto` in this code:**
* I used **goto** to terminate the nested loops **without using flags**.
* I have learned that this is a common practice in **system programming** to exit complex loops efficiently.
* It keeps the code clean by jumping directly to the result processing stage once the prefix is identified, a pattern often seen in kernel-level development[cite: 1].

### 3. Dynamic Memory Management
The result buffer is not fixed in size. The program calculates the exact prefix length and uses **malloc** to allocate only the necessary memory, ensuring no space is wasted.

## Function Specifications

### `char* longestCommonPrefix(char** strs, int strsSize)`
* **Input:** An array of pointers to strings and the total number of strings.
* **Mechanism:**
    * Validates the input size.
    * Scans characters vertically across the string array.
    * Employs **goto** to exit the loops immediately upon mismatch.
    * Uses **memcpy** to copy the final prefix into the newly allocated memory block.
* **Returns:** A dynamically allocated, null-terminated string.

## Complexity Analysis
* **Time Complexity:** $O(S)$, where $S$ is the sum of all characters in all strings.
* **Space Complexity:** $O(1)$ auxiliary space, as the comparison is performed in-place.

## Compilation and Execution
To compile the module using **gcc**:
```bash
gcc -o prefix_finder main.c
