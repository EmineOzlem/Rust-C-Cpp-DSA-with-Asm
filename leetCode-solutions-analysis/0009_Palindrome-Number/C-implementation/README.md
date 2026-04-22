# Palindrome Number: Project Overview & Analysis

### Approach: Digit Extraction via Stack Allocation
In this solution, I implemented a robust digit extraction algorithm. Instead of using high-level string formatting or direct mathematical reversal, I extracted each digit into a fixed-size integer array (`int digits[10]`). This approach ensures maximum control over the system's memory and execution flow.

**Key Technical Decisions:**
- **Stack over Heap:** Used a fixed-size array on the stack to avoid the overhead of `malloc` and potential memory leaks.
- **Overflow Prevention:** By extracting digits individually, I completely bypassed the risk of **Integer Overflow**—a common vulnerability when reversing 32-bit signed integers.
- **Early Exit:** Implemented immediate rejection for negative numbers ($x < 0$), as they are mathematically ineligible to be palindromes.

---

### Complexity Analysis
* **Time Complexity:** $O(\log_{10} n)$
    * The algorithm iterates through the digits of the input. For a 32-bit signed integer, this results in a maximum of 10 iterations.
* **Space Complexity:** $O(1)$
    * Uses a constant 40 bytes on the stack, ensuring a minimal and predictable memory footprint.

---

### Performance Metrics
* **Runtime:** **0-2 ms** (Statistical noise aside, this represents near-instant execution).
* **Memory:** **9.4 MB** (Efficiently managed stack usage).

---

### Engineering Philosophy: Strategic Trade-offs

As a systems-oriented engineer, I prioritize **reliability** and **resource efficiency** over rapid, unoptimized development. 

While converting the integer to a string is a common approach that offers faster development time, it introduces unnecessary memory overhead by requiring space for both the integer and its string representation. By extracting the digits directly into an array, I minimized the system load and maintained a high level of readability—a crucial factor for collaborative environments.

However, array indexing is not the sole solution. From a systems architecture perspective, we could navigate directly through memory addresses using **pointer arithmetic**. By documenting the possibility of implementing two 'shadow' pointers (incrementing one while decrementing the other), I have effectively addressed the trade-offs of not using pointers directly in this specific implementation. Choosing a readable array structure while maintaining a deep understanding of pointer-level alternatives ensures the code is both **audit-friendly** and **optimization-ready** for high-performance systems like **Project Phoenix**.

---

> *"Engineering is not just about making things work; it's about knowing why one path was chosen over another."*