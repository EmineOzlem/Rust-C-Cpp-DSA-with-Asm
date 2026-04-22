# Two Sum: Project Overview & Analysis

### Approach: Brute Force with Pointer Arithmetic
In this solution, I implemented a robust search algorithm using **C pointers** rather than standard array indexing. This low-level approach allows for direct memory access, minimizing the overhead of index-to-address calculations.

---

### Complexity Analysis
* **Time Complexity:** $O(n^2)$
    * Although the algorithm uses nested loops to check all possible pairs, the native performance of C ensures rapid execution.
* **Space Complexity:** $O(1)$
    * Memory usage is strictly controlled by allocating only the necessary space for the output array (`malloc(2 * sizeof(int))`). No additional data structures were used, keeping the memory footprint minimal.

---

### Performance Metrics
* **Runtime:** **99 ms** (Beats **78.81%** of C submissions)
* **Memory:** **9.49 MB** (Efficiently managed heap allocation)

---

### Engineering Philosophy: Beyond Just Performance
While high-speed execution at the kernel level is a priority, performance should not be evaluated through the lens of time complexity alone. Sustainable development requires code that is maintainable, readable, and prepared for future enhancements. For this reason, I embrace **Clean Code** principles and strive to eliminate unnecessary complexity (**KISS**).

While this approach is perfectly sufficient for small-to-medium datasets, I acknowledge that system latency may increase as data scales. Therefore, it is crucial to keep the codebase simple and transparent, ensuring it remains **"optimization-ready"** whenever scaling requirements necessitate a shift to more complex algorithms.
