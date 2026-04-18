# Rust-C-Cpp-DSA-with-Asm

A high-performance research laboratory for Data Structures and Algorithms (DSA) led by **Rust**, with comparative implementations in **C and C++**. This project bridges the gap between high-level abstractions and low-level execution through deep **Assembly (ASM) analysis**.

> **The Systems Philosophy:** Performance is not an accident; it is the result of conscious design. By analyzing how modern **Rust** generics compare to traditional C macros and C++ templates at the instruction level, we uncover the true mechanics of modern computing.

---

## Project Structure

The repository follows a unified, flat hierarchical structure to ensure perfect symmetry across all research modules.

```text
.
├── 📂 data-structures/               # High-Performance Data Structures
│   └── 📂 01-bag/                    # Generic Multiset Implementation
│       ├── 📜 README.md              # Comparative Analysis (Rust vs C vs C++)
│       ├── 📂 Rust-implementation/
│       ├── 📂 Cpp-implementation/
│       └── 📂 C-implementation/
│
├── 📂 algorithms/                    # Algorithm Design & ASM Benchmarking
│   └── 📂 01-quick-sort/             # Divide & Conquer Analysis
│       ├── 📜 README.md              # Logic Analysis & ASM Benchmarks
│       ├── 📂 Rust-implementation/
│       ├── 📂 Cpp-implementation/
│       └── 📂 C-implementation/
│
├── 📂 leetcode/                      # Comparative Logic Labs
│   └── 📂 0001-two-sum/
│       ├── 📜 README.md              # Optimization & Big-O Analysis
│       ├── 📂 Rust-implementation/
│       ├── 📂 Cpp-implementation/
│       └── 📂 C-implementation/
│
└── 📜 LICENSE

---

## Systems Audit Methodology

Every module undergoes a rigorous three-stage **Systems Audit** to ensure code efficiency and hardware alignment:

* **The Abstraction:** Define the logic using **Rust’s Trait-bounded Generics** as the safety baseline, then port the logic to C++ Templates and C Macros.
* **The Binary:** Generate Assembly outputs (`objdump` or `cargo rustc -- --emit asm`) to inspect the "Safety Tax" of Rust versus the "Manual Risk" of C.
* **The Profiling:** Utilize **Valgrind** for memory audits and **Perf** for monitoring cache misses and branch mispredictions.

---

## Performance Metrics

* **Temporal Complexity:** Verification of $O(f(n))$ for every implementation.
* **Spatial Complexity:** Analyzing memory overhead, alignment, and padding across different compilers.
* **Throughput:** Measuring operations per second (OPS) in high-load scenarios.

---

## How to Build

Detailed build instructions are provided within each implementation's subdirectory. Generally:

* **Rust:** `cargo run --release`
* **C/C++:** `gcc src/main.c -o output -I include -Wall -Wextra -O3`

---

**Developer:** Emine Ozlem Kaygas
**Motto:** *"Safety by Rust, Speed by Design, Clarity by Assembly."*
