## Memory Backed Data Structures in C

This project implements a dynamic array and a singly linked list in C using a simulated memory allocator.



Instead of relying on native C pointers directly, both data structures operate on integer-based memory addresses returned by a custom allocator. This simulates low-level memory management and reinforces understanding of how data structures interact with memory internally.



The memory system (mem.c) was provided as part of the project specification. The array and list implementations were developed independently using the provided API.

