# Generic Bag Abstract Data Type (ADT) Library in C

A high-performance, type-safe, and memory-secure **Bag (Multiset)** implementation for C. This library provides a robust container for handling high-throughput data and metadata in systems programming.

## Why Macros? (The Engineering Behind)

Unlike modern high-level languages, **ANSI C** does not natively support Generics. This library chooses a Macro-based Code Generation approach over `void*` pointers for the following reasons:

1. **Static Type Safety:** Macros generate specific code for each type (e.g., `Bag_int`, `Bag_string`), allowing the compiler to catch type mismatches at compile-time.
2. **Zero Runtime Overhead:** Since macros are processed before compilation, there are no function pointer lookups or manual type-casting during execution.
3. **Code Reusability (DRY):** Logic is defined once and "instantiated" as needed, maintaining a clean and maintainable codebase.
4. **Compile-Time Dispatch:** Utilizes **C11 `_Generic`** to automatically select the most efficient comparison algorithm (e.g., `strcmp` for strings vs. `==` for primitives).

## Features

* **Generic Architecture:** Type-agnostic interface that adapts its comparison logic at compile-time.
* **O(1) Efficiency:** Removal operations utilize a **swap-with-last** strategy, eliminating the performance hit of array shifts.
* **Cryptographically Secure Randomness:** Direct interface with the Linux kernel **`getrandom()`** system call for high-entropy random selections.
* **Memory Integrity:** Features a `const size_t capacity` member, locked at initialization via pointer-casting to prevent accidental resizing.
* **Precision:** Fully implemented with `size_t` to ensure 64-bit compatibility and prevent integer-overflow bugs.

## API Reference

| Function | Signature | Description |
| :--- | :--- | :--- |
| `create_bag_T` | `(size_t capacity)` | Allocates a bag with a fixed capacity. |
| `add_T` | `(Bag_T*, T)` | Inserts an element ($O(1)$). |
| `remove_random_T` | `(Bag_T*, T*)` | Removes a random element using secure RNG ($O(1)$). |
| `remove_entry_T` | `(Bag_T*, T)` | Finds and removes a specific entry ($O(1)$). |
| `contains_T` | `(Bag_T*, T)` | Checks for existence using type-aware logic. |
| `get_frequency_T`| `(Bag_T*, T)` | Counts occurrences of an entry. |
| `release_bag_T` | `(Bag_T*)` | Deallocates all heap memory. |