/*
Cheat Sheet: Memory Management - Stack vs Heap in C
================================================================

Table of Contents:
1. Overview and Historical Context
2. Syntax, Key Concepts, and Code Examples
3. Best Practices, Common Pitfalls, and Advanced Tips
4. Integration and Real-World Applications
5. Advanced Concepts and Emerging Trends
6. FAQs and Troubleshooting
7. Recommended Tools, Libraries, and Resources
8. Performance Analysis and Optimization
9. How to Contribute

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>

// Function prototypes
void section1_overview();
void section2_syntax_and_examples();
void section3_best_practices();
void section4_real_world_applications();
void section5_advanced_concepts();
void section6_faqs_and_troubleshooting();
void section7_tools_and_resources();
void section8_performance_analysis();
void section9_how_to_contribute();

// Example functions for demonstration
void stack_example();
int* heap_example();
void memory_leak_example();
void compare_stack_heap_performance();

int main() {
    printf("Cheat Sheet: Memory Management - Stack vs Heap in C\n");
    printf("==============================================================\n\n");

    section1_overview();
    section2_syntax_and_examples();
    section3_best_practices();
    section4_real_world_applications();
    section5_advanced_concepts();
    section6_faqs_and_troubleshooting();
    section7_tools_and_resources();
    section8_performance_analysis();
    section9_how_to_contribute();

    return 0;
}

void section1_overview() {
    printf("1. Overview and Historical Context\n");
    printf("----------------------------------\n");
    printf("Memory management in C involves two main areas: the stack and the heap.\n");
    printf("Understanding their differences is crucial for efficient and correct program execution.\n\n");
    
    printf("Stack:\n");
    printf("- Fast, automatic memory allocation and deallocation.\n");
    printf("- Used for local variables, function parameters, and return addresses.\n");
    printf("- Limited in size, typically determined at compile-time.\n\n");
    
    printf("Heap:\n");
    printf("- Dynamic memory allocation, managed by the programmer.\n");
    printf("- Used for data with a lifetime not tied to the current function call.\n");
    printf("- Larger in size, limited by available system memory.\n\n");
    
    printf("Historical Context:\n");
    printf("- Concept of stack dates back to the 1950s with LIFO data structures.\n");
    printf("- Heap allocation emerged in the 1960s with the need for dynamic data structures.\n");
    printf("- C formalized these concepts in the 1970s, influencing modern languages.\n\n");
    
    printf("Modern Relevance:\n");
    printf("- Critical for performance optimization and memory-constrained systems.\n");
    printf("- Fundamental to understanding memory-related bugs and security vulnerabilities.\n");
    printf("- Basis for memory models in higher-level languages and garbage collection.\n\n");
}

void section2_syntax_and_examples() {
    printf("2. Syntax, Key Concepts, and Code Examples\n");
    printf("------------------------------------------\n");

    printf("Stack Allocation:\n");
    stack_example();

    printf("\nHeap Allocation:\n");
    int* heap_ptr = heap_example();
    printf("Value from heap: %d\n", *heap_ptr);
    free(heap_ptr);  // Don't forget to free heap memory

    printf("\nMemory Leak Example:\n");
    memory_leak_example();

    printf("\nComparing Stack and Heap Performance:\n");
    compare_stack_heap_performance();
}

void section3_best_practices() {
    printf("3. Best Practices, Common Pitfalls, and Advanced Tips\n");
    printf("----------------------------------------------------\n");
    
    printf("Best Practices:\n");
    printf("1. Use stack allocation for small, short-lived objects.\n");
    printf("2. Always free dynamically allocated memory to prevent leaks.\n");
    printf("3. Check the return value of malloc() for NULL.\n");
    printf("4. Use tools like Valgrind to detect memory errors.\n");
    printf("5. Implement proper error handling for memory allocation failures.\n\n");

    printf("Common Pitfalls:\n");
    printf("1. Stack overflow from excessive recursion or large local variables.\n");
    printf("2. Memory leaks from forgetting to free heap-allocated memory.\n");
    printf("3. Dangling pointers from using freed memory.\n");
    printf("4. Buffer overflows from writing beyond allocated memory.\n");
    printf("5. Double free errors from freeing memory multiple times.\n\n");

    printf("Advanced Tips:\n");
    printf("1. Use flexible array members for variable-sized structures.\n");
    printf("2. Implement custom memory pools for frequent allocations.\n");
    printf("3. Utilize memory-mapped files for large datasets.\n");
    printf("4. Employ cache-friendly data structures and access patterns.\n");
    printf("5. Use static analysis tools to catch memory-related bugs early.\n\n");

    // Example: Custom memory pool
    #define POOL_SIZE 1024
    static char memory_pool[POOL_SIZE];
    static size_t pool_index = 0;

    void* pool_alloc(size_t size) {
        if (pool_index + size > POOL_SIZE) return NULL;
        void* ptr = &memory_pool[pool_index];
        pool_index += size;
        return ptr;
    }

    printf("Custom memory pool example:\n");
    int* pool_int = (int*)pool_alloc(sizeof(int));
    if (pool_int) {
        *pool_int = 42;
        printf("Value from memory pool: %d\n", *pool_int);
    }
    printf("\n");
}

void section4_real_world_applications() {
    printf("4. Integration and Real-World Applications\n");
    printf("------------------------------------------\n");
    
    printf("Real-world applications of stack vs heap memory management:\n");
    printf("1. Embedded systems with limited resources\n");
    printf("2. High-performance computing and real-time systems\n");
    printf("3. Memory-intensive applications like databases and caches\n");
    printf("4. Operating system kernel development\n");
    printf("5. Game development for efficient resource management\n\n");

    // Example: Simple memory manager for a game engine
    typedef struct {
        void* start;
        size_t size;
        size_t used;
    } MemoryArena;

    MemoryArena create_arena(size_t size) {
        MemoryArena arena;
        arena.start = malloc(size);
        arena.size = size;
        arena.used = 0;
        return arena;
    }

    void* arena_alloc(MemoryArena* arena, size_t size) {
        if (arena->used + size > arena->size) return NULL;
        void* ptr = (char*)arena->start + arena->used;
        arena->used += size;
        return ptr;
    }

    void destroy_arena(MemoryArena* arena) {
        free(arena->start);
        arena->start = NULL;
        arena->size = 0;
        arena->used = 0;
    }

    printf("Game engine memory arena example:\n");
    MemoryArena game_arena = create_arena(1024);
    int* game_object = arena_alloc(&game_arena, sizeof(int));
    if (game_object) {
        *game_object = 100;
        printf("Game object value: %d\n", *game_object);
    }
    destroy_arena(&game_arena);
    printf("\n");
}

void section5_advanced_concepts() {
    printf("5. Advanced Concepts and Emerging Trends\n");
    printf("----------------------------------------\n");
    
    printf("Advanced concepts:\n");
    printf("1. Thread-local storage for multi-threaded applications\n");
    printf("2. Memory-mapped I/O for efficient file handling\n");
    printf("3. Custom allocators for specific use cases\n");
    printf("4. Garbage collection techniques in C\n\n");

    printf("Emerging trends:\n");
    printf("1. Rust's ownership model as an alternative to manual memory management\n");
    printf("2. Advanced static analysis tools for detecting memory issues\n");
    printf("3. Hardware-assisted memory protection mechanisms\n");
    printf("4. Non-volatile memory and its impact on memory management\n\n");

    // Example: Simple reference counting
    typedef struct {
        int value;
        int ref_count;
    } RefCounted;

    RefCounted* create_ref_counted(int value) {
        RefCounted* obj = (RefCounted*)malloc(sizeof(RefCounted));
        if (obj) {
            obj->value = value;
            obj->ref_count = 1;
        }
        return obj;
    }

    void increase_ref(RefCounted* obj) {
        if (obj) obj->ref_count++;
    }

    void decrease_ref(RefCounted** obj) {
        if (*obj) {
            (*obj)->ref_count--;
            if ((*obj)->ref_count == 0) {
                free(*obj);
                *obj = NULL;
            }
        }
    }

    printf("Reference counting example:\n");
    RefCounted* shared_obj = create_ref_counted(42);
    increase_ref(shared_obj);
    printf("Ref count: %d\n", shared_obj->ref_count);
    decrease_ref(&shared_obj);
    printf("Ref count: %d\n", shared_obj->ref_count);
    decrease_ref(&shared_obj);
    printf("Object freed: %s\n", shared_obj ? "No" : "Yes");
    printf("\n");
}

void section6_faqs_and_troubleshooting() {
    printf("6. FAQs and Troubleshooting\n");
    printf("---------------------------\n");
    
    printf("FAQs:\n");
    printf("Q: When should I use stack vs heap allocation?\n");
    printf("A: Use stack for small, short-lived objects; heap for large or long-lived objects.\n\n");

    printf("Q: How can I detect memory leaks?\n");
    printf("A: Use tools like Valgrind or AddressSanitizer to detect memory leaks.\n\n");

    printf("Q: What causes a stack overflow?\n");
    printf("A: Excessive recursion or allocating too much memory on the stack.\n\n");

    printf("Troubleshooting:\n");
    printf("1. Segmentation fault: Check for null pointer dereferences and buffer overflows.\n");
    printf("2. Memory leaks: Ensure all dynamically allocated memory is freed.\n");
    printf("3. Corrupted data: Look for buffer overruns and use-after-free errors.\n");
    printf("4. Performance issues: Profile memory usage and optimize allocation patterns.\n\n");

    // Example: Debugging memory corruption
    int* debug_array = (int*)malloc(5 * sizeof(int));
    if (debug_array) {
        for (int i = 0; i <= 5; i++) {  // Intentional buffer overrun
            debug_array[i] = i;
        }
        // Use AddressSanitizer or Valgrind to detect this error
        free(debug_array);
    }
}

void section7_tools_and_resources() {
    printf("7. Recommended Tools, Libraries, and Resources\n");
    printf("----------------------------------------------\n");
    
    printf("Tools:\n");
    printf("1. Valgrind: Comprehensive memory debugging and profiling\n");
    printf("2. AddressSanitizer: Fast memory error detector\n");
    printf("3. Electric Fence: Debugging malloc() and free() errors\n");
    printf("4. Memcheck: Part of Valgrind, for detecting memory-related errors\n\n");

    printf("Libraries:\n");
    printf("1. jemalloc: General-purpose malloc implementation\n");
    printf("2. tcmalloc: Google's fast, multi-threaded malloc implementation\n");
    printf("3. Boehm GC: Conservative garbage collector for C\n\n");

    printf("Resources:\n");
    printf("1. 'Expert C Programming' by Peter van der Linden\n");
    printf("2. 'Advanced Programming in the UNIX Environment' by W. Richard Stevens\n");
    printf("3. 'C Interfaces and Implementations' by David R. Hanson\n");
    printf("4. Online course: 'Memory Management in C' on platforms like Coursera or edX\n\n");
}

void section8_performance_analysis() {
    printf("8. Performance Analysis and Optimization\n");
    printf("----------------------------------------\n");
    
    printf("Performance considerations:\n");
    printf("1. Stack allocation is generally faster than heap allocation\n");
    printf("2. Frequent small allocations can lead to fragmentation\n");
    printf("3. Cache locality affects performance significantly\n");
    printf("4. Memory alignment can impact access speed\n\n");

    printf("Optimization strategies:\n");
    printf("1. Use stack allocation for small, fixed-size objects\n");
    printf("2. Implement object pools for frequently allocated objects\n");
    printf("3. Align data structures to cache line boundaries\n");
    printf("4. Use memory profilers to identify bottlenecks\n\n");

    // Performance comparison example
    compare_stack_heap_performance();
}

void section9_how_to_contribute() {
    printf("9. How to Contribute\n");
    printf("--------------------\n");
    
    printf("We welcome contributions to improve and extend this cheat sheet. Here's how you can contribute:\n\n");
    
    printf("1. Fork the repository on GitHub.\n");
    printf("2. Create a new branch for your feature or bug fix.\n");
    printf("3. Make your changes, ensuring they follow the existing style and format.\n");
    printf("4. Add new examples or improve existing ones.\n");
    printf("5. Update the table of contents if you add new sections.\n");
    printf("6. Write clear commit messages describing your changes.\n");
    printf("7. Create a pull request with a description of your changes.\n");
    printf("8. Respond to any feedback or questions during the review process.\n\n");
    
    printf("Guidelines for contributions:\n");
    printf("- Ensure all code examples are correct, follow best practices, and compile without warnings.\n");
    printf("- Provide clear explanations for complex concepts related to memory management.\n");
    printf("- Include practical, real-world examples that demonstrate stack and heap usage.\n");
    printf("- Maintain a balance between beginner-friendly content and advanced topics.\n");
    printf("- Consider adding or updating performance benchmarks for memory operations.\n");
    printf("- Keep the content up-to-date with the latest C standards and best practices.\n\n");
    
    printf("Thank you for helping to improve this resource for the C programming community!\n");
}

// Helper functions used in the examples

void stack_example() {
    int stack_var = 5;
    printf("Stack variable value: %d\n", stack_var);
}

int* heap_example() {
    int* heap_var = (int*)malloc(sizeof(int));
    if (heap_var == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    *heap_var = 10;
    return heap_var;
}

void memory_leak_example() {
    int* leak = (int*)malloc(sizeof(int));
    if (leak == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    *leak = 42;
    printf("Leaked value: %d\n", *leak);
    // Intentionally not freeing 'leak' to demonstrate a memory leak
}

void compare_stack_heap_performance() {
    const int iterations = 1000000;
    clock_t start, end;
    double cpu_time_used;

    // Stack allocation
    start = clock();
    for (int i = 0; i < iterations; i++) {
        int stack_var = i;
        (void)stack_var;  // Prevent optimization
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Stack allocation time: %f seconds\n", cpu_time_used);

    // Heap allocation
    start = clock();
    for (int i = 0; i < iterations; i++) {
        int* heap_var = (int*)malloc(sizeof(int));
        if (heap_var == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            return;
        }
        *heap_var = i;
        free(heap_var);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Heap allocation time: %f seconds\n", cpu_time_used);
}
