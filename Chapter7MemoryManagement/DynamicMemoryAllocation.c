/*
Cheat Sheet: Dynamic Memory Allocation in C
========================================================

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
#include <assert.h>
#include <time.h>

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
void* safe_malloc(size_t size);
void* safe_calloc(size_t nmemb, size_t size);
void* safe_realloc(void* ptr, size_t size);
void demonstrate_malloc();
void demonstrate_calloc();
void demonstrate_realloc();
void demonstrate_free();

int main() {
    printf("Cheat Sheet: Dynamic Memory Allocation in C\n");
    printf("=======================================================\n\n");

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
    printf("Dynamic memory allocation in C allows programs to request memory at runtime,\n");
    printf("enabling flexible and efficient use of system resources.\n\n");
    
    printf("Key functions:\n");
    printf("- malloc(): Allocates uninitialized memory\n");
    printf("- calloc(): Allocates and initializes memory to zero\n");
    printf("- realloc(): Resizes previously allocated memory\n");
    printf("- free(): Deallocates previously allocated memory\n\n");
    
    printf("Historical Context:\n");
    printf("- Introduced in early versions of C (1970s) to support dynamic data structures\n");
    printf("- Evolved from simpler memory models in earlier languages\n");
    printf("- Fundamental to C's philosophy of providing low-level control to programmers\n\n");
    
    printf("Modern Relevance:\n");
    printf("- Essential for implementing complex data structures and algorithms\n");
    printf("- Critical for memory-efficient programs and systems programming\n");
    printf("- Basis for memory management in higher-level languages and runtimes\n");
    printf("- Important for understanding memory-related security vulnerabilities\n\n");
}

void section2_syntax_and_examples() {
    printf("2. Syntax, Key Concepts, and Code Examples\n");
    printf("------------------------------------------\n");

    printf("malloc() example:\n");
    demonstrate_malloc();

    printf("\ncalloc() example:\n");
    demonstrate_calloc();

    printf("\nrealloc() example:\n");
    demonstrate_realloc();

    printf("\nfree() example:\n");
    demonstrate_free();
}

void section3_best_practices() {
    printf("3. Best Practices, Common Pitfalls, and Advanced Tips\n");
    printf("----------------------------------------------------\n");
    
    printf("Best Practices:\n");
    printf("1. Always check the return value of allocation functions for NULL.\n");
    printf("2. Use sizeof() operator instead of hard-coding sizes.\n");
    printf("3. Free memory as soon as it's no longer needed.\n");
    printf("4. Set pointers to NULL after freeing to avoid dangling pointers.\n");
    printf("5. Use calloc() when you need zero-initialized memory.\n\n");

    printf("Common Pitfalls:\n");
    printf("1. Memory leaks: Forgetting to free allocated memory.\n");
    printf("2. Double free: Freeing the same memory multiple times.\n");
    printf("3. Use after free: Accessing memory after it has been freed.\n");
    printf("4. Buffer overflow: Writing beyond allocated memory bounds.\n");
    printf("5. Integer overflow in size calculations for allocation.\n\n");

    printf("Advanced Tips:\n");
    printf("1. Implement custom allocators for specific use cases.\n");
    printf("2. Use tools like Valgrind or AddressSanitizer for memory debugging.\n");
    printf("3. Consider using memory pools for frequent small allocations.\n");
    printf("4. Be aware of alignment requirements for different data types.\n");
    printf("5. Use flexible array members for variable-length structures.\n\n");

    // Example: Custom allocator
    typedef struct {
        void* memory;
        size_t used;
        size_t capacity;
    } MemoryPool;

    MemoryPool* create_pool(size_t capacity) {
        MemoryPool* pool = (MemoryPool*)malloc(sizeof(MemoryPool));
        if (pool) {
            pool->memory = malloc(capacity);
            pool->used = 0;
            pool->capacity = capacity;
        }
        return pool;
    }

    void* pool_alloc(MemoryPool* pool, size_t size) {
        if (pool->used + size > pool->capacity) return NULL;
        void* ptr = (char*)pool->memory + pool->used;
        pool->used += size;
        return ptr;
    }

    void destroy_pool(MemoryPool* pool) {
        free(pool->memory);
        free(pool);
    }

    printf("Custom memory pool example:\n");
    MemoryPool* pool = create_pool(1024);
    if (pool) {
        int* numbers = (int*)pool_alloc(pool, 10 * sizeof(int));
        if (numbers) {
            for (int i = 0; i < 10; i++) numbers[i] = i;
            printf("First number: %d, Last number: %d\n", numbers[0], numbers[9]);
        }
        destroy_pool(pool);
    }
    printf("\n");
}

void section4_real_world_applications() {
    printf("4. Integration and Real-World Applications\n");
    printf("------------------------------------------\n");
    
    printf("Real-world applications of dynamic memory allocation:\n");
    printf("1. Implementing data structures (e.g., linked lists, trees, graphs)\n");
    printf("2. Managing resources in operating systems\n");
    printf("3. Image and video processing applications\n");
    printf("4. Database management systems for efficient data handling\n");
    printf("5. Game development for dynamic object creation and destruction\n\n");

    // Example: Simple database record system
    typedef struct {
        int id;
        char* name;
        int age;
    } Record;

    typedef struct {
        Record** records;
        int count;
        int capacity;
    } Database;

    Database* create_database(int initial_capacity) {
        Database* db = (Database*)malloc(sizeof(Database));
        if (db) {
            db->records = (Record**)calloc(initial_capacity, sizeof(Record*));
            db->count = 0;
            db->capacity = initial_capacity;
        }
        return db;
    }

    void add_record(Database* db, int id, const char* name, int age) {
        if (db->count == db->capacity) {
            db->capacity *= 2;
            db->records = (Record**)realloc(db->records, db->capacity * sizeof(Record*));
        }
        Record* record = (Record*)malloc(sizeof(Record));
        record->id = id;
        record->name = strdup(name);
        record->age = age;
        db->records[db->count++] = record;
    }

    void destroy_database(Database* db) {
        for (int i = 0; i < db->count; i++) {
            free(db->records[i]->name);
            free(db->records[i]);
        }
        free(db->records);
        free(db);
    }

    printf("Simple database example:\n");
    Database* db = create_database(10);
    if (db) {
        add_record(db, 1, "Alice", 30);
        add_record(db, 2, "Bob", 25);
        printf("Database records: %d\n", db->count);
        printf("First record: ID=%d, Name=%s, Age=%d\n", 
               db->records[0]->id, db->records[0]->name, db->records[0]->age);
        destroy_database(db);
    }
    printf("\n");
}

void section5_advanced_concepts() {
    printf("5. Advanced Concepts and Emerging Trends\n");
    printf("----------------------------------------\n");
    
    printf("Advanced concepts:\n");
    printf("1. Garbage collection techniques in C\n");
    printf("2. Memory-mapped files for large datasets\n");
    printf("3. Custom allocators for specific memory patterns\n");
    printf("4. Lock-free memory allocation for concurrent programs\n\n");

    printf("Emerging trends:\n");
    printf("1. Rust's ownership model as an alternative to manual memory management\n");
    printf("2. Static analysis tools with AI for detecting memory issues\n");
    printf("3. Hardware-assisted memory safety features\n");
    printf("4. Persistent memory and its impact on allocation strategies\n\n");

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
    printf("Q: What's the difference between malloc() and calloc()?\n");
    printf("A: malloc() allocates uninitialized memory, while calloc() initializes memory to zero.\n\n");

    printf("Q: When should I use realloc()?\n");
    printf("A: Use realloc() to resize previously allocated memory, typically for growing arrays.\n\n");

    printf("Q: Is it necessary to cast the result of malloc()?\n");
    printf("A: In C, it's not necessary and can hide errors. In C++, it is required.\n\n");

    printf("Troubleshooting:\n");
    printf("1. Use debugging tools like Valgrind or AddressSanitizer to detect memory issues.\n");
    printf("2. Implement logging for all allocations and deallocations in critical sections.\n");
    printf("3. Use assert() to check invariants and preconditions in debug builds.\n");
    printf("4. Develop and use wrapper functions for memory allocation with built-in error checking.\n\n");

    // Example: Debugging wrapper for malloc
    void* debug_malloc(size_t size, const char* file, int line) {
        void* ptr = malloc(size);
        printf("Allocating %zu bytes at %p (%s:%d)\n", size, ptr, file, line);
        return ptr;
    }

    #define DEBUG_MALLOC(size) debug_malloc(size, __FILE__, __LINE__)

    printf("Debugging malloc wrapper example:\n");
    int* debug_ptr = (int*)DEBUG_MALLOC(sizeof(int));
    if (debug_ptr) {
        *debug_ptr = 42;
        printf("Value: %d\n", *debug_ptr);
        free(debug_ptr);
    }
    printf("\n");
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
    printf("4. Online course: 'Pointers and Memory Management in C' on Coursera\n\n");
}

void section8_performance_analysis() {
    printf("8. Performance Analysis and Optimization\n");
    printf("----------------------------------------\n");
    
    printf("Performance considerations:\n");
    printf("1. Allocation and deallocation can be expensive operations\n");
    printf("2. Fragmentation can occur with frequent allocations and deallocations\n");
    printf("3. Cache performance is affected by memory allocation patterns\n");
    printf("4. Large allocations may trigger system calls, impacting performance\n\n");

    printf("Optimization strategies:\n");
    printf("1. Use memory pools for frequent small allocations\n");
    printf("2. Align allocations to cache line boundaries for better performance\n");
    printf("3. Batch allocations and deallocations to reduce overhead\n");
    printf("4. Consider custom allocators for specific allocation patterns\n\n");

    // Performance comparison example
    #define TEST_SIZE 1000000
    #define POOL_BLOCK_SIZE 1024

    clock_t start, end;
    double cpu_time_used;

    // Standard malloc/free
    start = clock();
    for (int i = 0; i < TEST_SIZE; i++) {
        int* p = (int*)malloc(sizeof(int));
        if (p) {
            *p = i;
            free(p);
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Standard malloc/free time: %f seconds\n", cpu_time_used);

    // Simple memory pool
    typedef struct MemoryPool {
        char* memory;
        size_t used;
        struct MemoryPool* next;
    } MemoryPool;

    MemoryPool* create_pool() {
        MemoryPool* pool = (MemoryPool*)malloc(sizeof(MemoryPool));
        if (pool) {
            pool->memory = (char*)malloc(POOL_BLOCK_SIZE);
            pool->used = 0;
            pool->next = NULL;
        }
        return pool;
    }

    void* pool_alloc(MemoryPool** pool, size_t size) {
        if (!*pool || (*pool)->used + size > POOL_BLOCK_SIZE) {
            MemoryPool* new_pool = create_pool();
            if (!new_pool) return NULL;
            new_pool->next = *pool;
            *pool = new_pool;
        }
        void* ptr = &((*pool)->memory[(*pool)->used]);
        (*pool)->used += size;
        return ptr;
    }

    void destroy_pool(MemoryPool* pool) {
        while (pool) {
            MemoryPool* next = pool->next;
            free(pool->memory);
            free(pool);
            pool = next;
        }
    }

    MemoryPool* pool = create_pool();
    start = clock();
    for (int i = 0; i < TEST_SIZE; i++) {
        int* p = (int*)pool_alloc(&pool, sizeof(int));
        if (p) *p = i;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Memory pool allocation time: %f seconds\n", cpu_time_used);
    destroy_pool(pool);

    printf("\nNote: The memory pool is faster for allocations but doesn't include deallocation time.\n");
    printf("In practice, the pool would be reused, amortizing the creation and destruction costs.\n");

    printf("\nOptimization tips based on performance analysis:\n");
    printf("1. Use memory pools for frequent small allocations of fixed size.\n");
    printf("2. Align allocations to cache lines (typically 64 bytes) for better cache performance.\n");
    printf("3. Prefer stack allocation for small, short-lived objects when possible.\n");
    printf("4. Use profiling tools to identify memory-intensive parts of your code.\n");
    printf("5. Consider thread-local allocators for multi-threaded applications.\n");
}

void section9_how_to_contribute() {
    printf("9. How to Contribute\n");
    printf("--------------------\n");
    
    printf("We welcome contributions to improve and extend this cheat sheet. Here's how you can contribute:\n\n");
    
    printf("1. Fork the repository on GitHub.\n");
    printf("2. Create a new branch for your feature or bug fix.\n");
    printf("3. Make your changes, ensuring they follow the existing style and format.\n");
    printf("4. Add new examples or improve existing ones, focusing on dynamic memory allocation.\n");
    printf("5. Update the table of contents if you add new sections.\n");
    printf("6. Write clear commit messages describing your changes.\n");
    printf("7. Create a pull request with a description of your changes.\n");
    printf("8. Respond to any feedback or questions during the review process.\n\n");
    
    printf("Guidelines for contributions:\n");
    printf("- Ensure all code examples are correct, follow best practices, and compile without warnings.\n");
    printf("- Provide clear explanations for complex concepts related to dynamic memory allocation.\n");
    printf("- Include practical, real-world examples that demonstrate effective use of malloc, calloc, realloc, and free.\n");
    printf("- Maintain a balance between beginner-friendly content and advanced topics.\n");
    printf("- Consider adding or updating performance benchmarks for memory allocation techniques.\n");
    printf("- Keep the content up-to-date with the latest C standards and best practices.\n");
    printf("- If adding new sections, ensure they fit logically within the existing structure.\n\n");
    
    printf("Thank you for helping to improve this resource for the C programming community!\n");
}

// Helper functions used in the examples

void* safe_malloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void* safe_calloc(size_t nmemb, size_t size) {
    void* ptr = calloc(nmemb, size);
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void* safe_realloc(void* ptr, size_t size) {
    void* new_ptr = realloc(ptr, size);
    if (new_ptr == NULL && size != 0) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
    return new_ptr;
}

void demonstrate_malloc() {
    int* numbers = (int*)safe_malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        numbers[i] = i * 10;
    }
    printf("Malloc example: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    free(numbers);
}

void demonstrate_calloc() {
    int* numbers = (int*)safe_calloc(5, sizeof(int));
    printf("Calloc example: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);  // Will print all zeros
    }
    printf("\n");
    free(numbers);
}

void demonstrate_realloc() {
    int* numbers = (int*)safe_malloc(3 * sizeof(int));
    for (int i = 0; i < 3; i++) {
        numbers[i] = i * 10;
    }
    numbers = (int*)safe_realloc(numbers, 5 * sizeof(int));
    numbers[3] = 30;
    numbers[4] = 40;
    printf("Realloc example: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    free(numbers);
}

void demonstrate_free() {
    int* number = (int*)safe_malloc(sizeof(int));
    *number = 42;
    printf("Free example: %d\n", *number);
    free(number);
    // number = NULL;  // Good practice to prevent use after free
}
