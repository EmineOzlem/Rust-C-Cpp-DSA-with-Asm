# Rust-C-Cpp-DSA-with-Asm

A high-performance implementation library of Data Structures and Algorithms (DSA) developed in **Rust, C, and C++**. This project goes beyond standard implementations by providing deep-dive **Assembly (ASM) analysis** and comparative benchmarks to understand compiler optimizations and memory efficiency.

## Key Features

* **Multi-Language Implementation:** Every algorithm is implemented in C, C++, and Rust.
* **Assembly Analysis:** Side-by-side comparison of generated ASM code to analyze overhead and optimization levels (O2, O3, LTO).
* **Performance Benchmarking:** Real-world execution time and memory footprint comparisons.
* **Systems Focus:** Built with a systems engineering mindset, focusing on cache locality and instruction-level efficiency.

## Project Structure

.
├── 📂 data-structures/             # Core Data Structures
│   ├── 📂 01-linked-list/
│   │   ├── linked_list.c
│   │   ├── linked_list.cpp
│   │   ├── linked_list.rs
│   │   └── README.md               # Structure Analysis + ASM Deep-Dive
│   └── 📂 02-stack/
│
├── 📂 algorithms/                  # Core Algorithms (Sorting, Searching, etc.)
│   ├── 📂 sorting/
│   │   ├── 📂 quick-sort/
│   │   │   ├── quick_sort.c
│   │   │   ├── quick_sort.rs
│   │   │   └── README.md           # Logic + ASM Benchmarks
│
├── 📂 leetcode/                    # LeetCode Solutions
│   ├── 📂 0001-two-sum/
│   │   ├── solution.c
│   │   ├── solution.cpp
│   │   ├── solution.rs
│   │   └── README.md               # Performance Analysis
│
├── 📂 hackerrank/                  # HackerRank Solutions (Category Based)
│   ├── 📂 algorithms/
│   │   └── 📂 warm-up/
│
├── 📜 LICENSE                      # MIT or Apache 2.0
└── 📜 README.md                    # MAIN DASHBOARD (Global Project Overview)
