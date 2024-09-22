/*
Cheat Sheet: Memory Leaks and How to Avoid Them in C
=================================================================

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
void demonstrate_memory_leak();
void demonstrate_leak_fix();
void* create_int_array(size_t size);
void free_int_array(void* ptr);

int main() {
    printf("Cheat Sheet: Memory Leaks and How to Avoid Them in C\n");
    printf("================================================================\n\n");

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
    printf("A memory leak occurs when a program fails to release memory that is no longer needed,\n");
    printf("causing the program to consume increasing amounts of memory over time.\n\n");
    
    printf("Historical Context:\n");
    printf("- Memory leaks became a significant issue with the advent of long-running programs and systems.\n");
    printf("- Early detection methods relied on manual code review and primitive debugging techniques.\n");
    printf("- The development of dynamic memory allocation in C (introduced in the 1970s) made memory leaks more common.\n\n");
    
    printf("Significance in Modern Development:\n");
    printf("- Critical for maintaining system stability and performance, especially in long-running applications.\n");
    printf("- Essential for resource-constrained environments like embedded systems and mobile devices.\n");
    printf("- A common source of security vulnerabilities (e.g., denial of service attacks).\n");
    printf("- Addressing memory leaks is crucial for scalable and reliable software systems.\n\n");
}

void section2_syntax_and_examples() {
    printf("2. Syntax, Key Concepts, and Code Examples\n");
    printf("------------------------------------------\n");

    printf("Basic memory allocation and deallocation:\n");
    int* ptr = (int*)malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 42;
        printf("Allocated value: %d\n", *ptr);
        free(ptr);  // Proper deallocation
        ptr = NULL; // Good practice to avoid dangling pointers
    }

    printf("\nDemonstrating a memory leak:\n");
    demonstrate_memory_leak();

    printf("\nFixed version without memory leak:\n");
    demonstrate_leak_fix();

    printf("\nUsing custom allocation wrapper:\n");
    int* safe_ptr = (int*)safe_malloc(sizeof(int));
    if (safe_ptr != NULL) {
        *safe_ptr = 100;
        printf("Safely allocated value: %d\n", *safe_ptr);
        free(safe_ptr);
        safe_ptr = NULL;
    }
}

void section3_best_practices() {
    printf("3. Best Practices, Common Pitfalls, and Advanced Tips\n");
    printf("----------------------------------------------------\n");
    
    printf("Best Practices:\n");
    printf("1. Always free dynamically allocated memory when it's no longer needed.\n");
    printf("2. Use tools like Valgrind or Address Sanitizer to detect memory leaks.\n");
    printf("3. Implement and use safe memory allocation wrappers.\n");
    printf("4. Follow the RAII principle (Resource Acquisition Is Initialization) where possible.\n");
    printf("5. Use smart pointers or reference counting in C++ projects.\n\n");

    printf("Common Pitfalls:\n");
    printf("1. Forgetting to free memory in error handling code paths.\n");
    printf("2. Losing the last reference to allocated memory.\n");
    printf("3. Incorrect use of realloc() leading to memory leaks.\n");
    printf("4. Memory leaks in recursive functions.\n");
    printf("5. Leaks in long-running loops or event handlers.\n\n");

    printf("Advanced Tips:\n");
    printf("1. Implement custom memory allocators for specific use cases.\n");
    printf("2. Use static analysis tools to catch potential leaks at compile-time.\n");
    printf("3. Implement leak detection in production code using canary values.\n");
    printf("4. Use memory pools for frequent allocations of fixed-size objects.\n");
    printf("5. Employ garbage collection techniques for complex data structures.\n\n");

    // Example: Simple memory pool
    #define POOL_SIZE 1024
    static char memory_pool[POOL_SIZE];
    static size_t pool_index = 0;

    void* pool_alloc(size_t size) {
        if (pool_index + size > POOL_SIZE) return NULL;
        void* ptr = &memory_pool[pool_index];
        pool_index += size;
        return ptr;
    }

    void pool_reset() {
        pool_index = 0;
    }

    int* pool_int = (int*)pool_alloc(sizeof(int));
    if (pool_int) {
        *pool_int = 42;
        printf("Value from memory pool: %d\n", *pool_int);
    }
    pool_reset();  // Reset the pool instead of individual frees
}

void section4_real_world_applications() {
    printf("4. Integration and Real-World Applications\n");
    printf("------------------------------------------\n");
    
    printf("Real-world applications of memory leak prevention:\n");
    printf("1. Operating Systems: Kernel memory management\n");
    printf("2. Web Servers: Handling multiple client connections\n");
    printf("3. Database Systems: Managing large data caches\n");
    printf("4. Game Engines: Resource management for long-running games\n");
    printf("5. Embedded Systems: Efficient use of limited memory\n\n");

    // Example: Simple resource manager for a game engine
    typedef struct {
        void** resources;
        size_t count;
        size_t capacity;
    } ResourceManager;

    ResourceManager* create_resource_manager(size_t initial_capacity) {
        ResourceManager* rm = (ResourceManager*)malloc(sizeof(ResourceManager));
        if (rm == NULL) return NULL;
        rm->resources = (void**)malloc(initial_capacity * sizeof(void*));
        if (rm->resources == NULL) {
            free(rm);
            return NULL;
        }
        rm->count = 0;
        rm->capacity = initial_capacity;
        return rm;
    }

    void add_resource(ResourceManager* rm, void* resource) {
        if (rm->count == rm->capacity) {
            size_t new_capacity = rm->capacity * 2;
            void** new_resources = (void**)realloc(rm->resources, new_capacity * sizeof(void*));
            if (new_resources == NULL) return;
            rm->resources = new_resources;
            rm->capacity = new_capacity;
        }
        rm->resources[rm->count++] = resource;
    }

    void destroy_resource_manager(ResourceManager* rm) {
        for (size_t i = 0; i < rm->count; i++) {
            free(rm->resources[i]);
        }
        free(rm->resources);
        free(rm);
    }

    printf("Game engine resource manager example:\n");
    ResourceManager* rm = create_resource_manager(10);
    if (rm) {
        for (int i = 0; i < 5; i++) {
            int* resource = (int*)malloc(sizeof(int));
            if (resource) {
                *resource = i * 10;
                add_resource(rm, resource);
            }
        }
        printf("Resources managed: %zu\n", rm->count);
        destroy_resource_manager(rm);
    }
    printf("\n");
}

void section5_advanced_concepts() {
    printf("5. Advanced Concepts and Emerging Trends\n");
    printf("----------------------------------------\n");
    
    printf("Advanced concepts:\n");
    printf("1. Automated memory management techniques in C\n");
    printf("2. Custom allocators for specific memory patterns\n");
    printf("3. Memory tagging and canary values for leak detection\n");
    printf("4. Thread-safe memory management in concurrent programs\n\n");

    printf("Emerging trends:\n");
    printf("1. Rust's ownership model as an alternative to manual memory management\n");
    printf("2. Static analysis tools with machine learning for leak detection\n");
    printf("3. Hardware-assisted memory protection and leak detection\n");
    printf("4. Memory-safe subsets of C for critical systems\n\n");

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
    printf("Q: How can I detect memory leaks in my C program?\n");
    printf("A: Use tools like Valgrind, AddressSanitizer, or implement custom leak detection.\n\n");

    printf("Q: Are small memory leaks a problem?\n");
    printf("A: Even small leaks can become significant in long-running programs or systems with limited resources.\n\n");

    printf("Q: How do I handle memory leaks in third-party libraries?\n");
    printf("A: Wrap library calls, use memory pools, or consider alternative libraries if leaks persist.\n\n");

    printf("Troubleshooting:\n");
    printf("1. Use memory profiling tools to identify leaking allocations.\n");
    printf("2. Implement logging for all allocations and deallocations in critical sections.\n");
    printf("3. Use debugger watchpoints to track specific memory addresses.\n");
    printf("4. Simplify code to isolate leaks, then gradually reintroduce complexity.\n\n");

    // Example: Simple allocation tracker
    #define MAX_ALLOCS 1000
    static void* alloc_tracker[MAX_ALLOCS];
    static size_t alloc_count = 0;

    void* tracked_malloc(size_t size) {
        void* ptr = malloc(size);
        if (ptr && alloc_count < MAX_ALLOCS) {
            alloc_tracker[alloc_count++] = ptr;
        }
        return ptr;
    }

    void tracked_free(void* ptr) {
        for (size_t i = 0; i < alloc_count; i++) {
            if (alloc_tracker[i] == ptr) {
                alloc_tracker[i] = alloc_tracker[--alloc_count];
                free(ptr);
                return;
            }
        }
    }

    void print_leak_report() {
        printf("Leak report: %zu unfreed allocations\n", alloc_count);
    }

    printf("Allocation tracking example:\n");
    int* tracked_ptr = (int*)tracked_malloc(sizeof(int));
    if (tracked_ptr) *tracked_ptr = 42;
    print_leak_report();
    tracked_free(tracked_ptr);
    print_leak_report();
    printf("\n");
}

void section7_tools_and_resources() {
    printf("7. Recommended Tools, Libraries, and Resources\n");
    printf("----------------------------------------------\n");
    
    printf("Tools:\n");
    printf("1. Valgrind: Comprehensive memory debugging and profiling\n");
    printf("2. AddressSanitizer: Fast memory error detector\n");
    printf("3. Dr. Memory: Memory debugging tool for Windows and Linux\n");
    printf("4. Memcheck: Part of Valgrind, specifically for memory-related errors\n\n");

    printf("Libraries:\n");
    printf("1. Boehm GC: Conservative garbage collector for C\n");
    printf("2. jemalloc: General-purpose malloc implementation with leak checking\n");
    printf("3. tcmalloc: Google's fast, multi-threaded malloc implementation\n\n");

    printf("Resources:\n");
    printf("1. 'Expert C Programming' by Peter van der Linden\n");
    printf("2. 'Advanced C Programming' by Richard M. Reese\n");
    printf("3. 'Effective C' by Robert C. Seacord\n");
    printf("4. Online course: 'C Dynamic Memory' on platforms like Coursera or edX\n\n");
}

void section8_performance_analysis() {
    printf("8. Performance Analysis and Optimization\n");
    printf("----------------------------------------\n");
    
    printf("Performance considerations:\n");
    printf("1. Memory leaks can lead to increased memory usage and slower performance over time\n");
    printf("2. Frequent allocation and deallocation can cause fragmentation\n");
    printf("3. Overuse of garbage collection can impact real-time performance\n");
    printf("4. Improper use of memory pools can lead to inefficient memory usage\n\n");

    printf("Optimization strategies:\n");
    printf("1. Use memory pools for frequent allocations of similar-sized objects\n");
    printf("2. Implement custom allocators for specific use cases\n");
    printf("3. Use stack allocation for small, short-lived objects\n");
    printf("4. Batch allocations and deallocations to reduce overhead\n");
    printf("5. Profile your code to identify memory-intensive areas\n\n");

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

    // Custom memory pool
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
}

void section9_how_to_contribute() {
    printf("9. How to Contribute\n");
    printf("--------------------\n");
    
    printf("We welcome contributions to improve and extend this cheat sheet. Here's how you can contribute:\n\n");
    
    printf("1. Fork the repository on GitHub.\n");
    printf("2. Create a new branch for your feature or bug fix.\n");
    printf("3. Make your changes, ensuring they follow the existing style and format.\n");
    printf("4. Add new examples or improve existing ones, focusing on memory leak prevention.\n");
    printf("5. Update the table of contents if you add new sections.\n");
    printf("6. Write clear commit messages describing your changes.\n");
    printf("7. Create a pull request with a description of your changes.\n");
    printf("8. Respond to any feedback or questions during the review process.\n\n");
    
    printf("Guidelines for contributions:\n");
    printf("- Ensure all code examples are correct, follow best practices, and compile without warnings.\n");
    printf("- Provide clear explanations for complex concepts related to memory management and leak prevention.\n");
    printf("- Include practical, real-world examples that demonstrate effective memory leak prevention techniques.\n");
    printf("- Maintain a balance between beginner-friendly content and advanced topics.\n");
    printf("- Consider adding or updating performance benchmarks for memory management techniques.\n");
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

void demonstrate_memory_leak() {
    int* leak = (int*)malloc(sizeof(int));
    if (leak != NULL) {
        *leak = 42;
        printf("Leaked value: %d\n", *leak);
        // Intentionally not freeing 'leak' to demonstrate a memory leak
    }
}

void demonstrate_leak_fix() {
    int* no_leak = (int*)malloc(sizeof(int));
    if (no_leak != NULL) {
        *no_leak = 42;
        printf("Non-leaked value: %d\n", *no_leak);
        free(no_leak);
        no_leak = NULL;  // Good practice to avoid dangling pointers
    }
}

void* create_int_array(size_t size) {
    return calloc(size, sizeof(int));
}

void free_int_array(void* ptr) {
    free(ptr);
}
