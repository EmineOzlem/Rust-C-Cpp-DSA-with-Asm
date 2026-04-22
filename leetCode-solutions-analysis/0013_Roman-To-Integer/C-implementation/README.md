# Roman to Integer

## Project Overview
This project provides a robust C implementation for converting Roman numerals into decimal integers. Instead of the conventional array-indexing approach, this module leverages **direct pointer arithmetic** and **pass-by-reference** patterns to achieve efficient memory traversal and look-ahead logic.

## Technical Architecture

### 1. Direct Memory Traversal
The algorithm minimizes the overhead associated with index calculations. By utilizing a `char* p` pointer, the program navigates the string buffer directly. This is a common design pattern in kernel-level programming and low-level system utilities where performance and memory control are paramount.

### 2. Look-Ahead Subtraction Logic
To handle the unique subtractive rules of the Roman system (e.g., `IV` = 4, `XC` = 90), the implementation employs a "look-ahead" strategy:
* The current memory address value (`*p`) is compared against the value at the subsequent address (`*(p + 1)`).
* If the current value is strictly less than the next, it is subtracted from the accumulator; otherwise, it is added.

### 3. Pass-by-Reference (Pointer) Integration
The utility function `getIntValue(char* ch)` is designed to accept a memory address rather than a character copy. This design choice maintains architectural consistency with "Linked Implementation" principles, ensuring that the function interacts with the original memory block directly.

## Function Specifications

### `int getIntValue(char* ch)`
- **Input:** A pointer to a character in the memory block.
- **Mechanism:** Dereferences the pointer and maps the character to its integer weight using a high-performance `switch` statement.
- **Returns:** The integer weight (1 to 1000) or 0 for null terminators/invalid inputs.

### `int romanToInt(char* s)`
- **Input:** The starting address of the Roman numeral string.
- **Workflow:** - Validates string length and traverses until the null terminator (`\0`).
    - Implements conditional branching for additive and subtractive operations.
    - Manages pointer increments to ensure $O(n)$ efficiency.
- **Returns:** The computed integer value.

## Complexity Analysis
- **Time Complexity:** $O(n)$, where $n$ is the length of the string. Every memory address is accessed exactly once.
- **Space Complexity:** $O(1)$, as the conversion is performed in-place with a constant memory footprint.

## Compilation and Execution
To compile the module using `gcc`:
```bash
gcc -o roman_converter main.c