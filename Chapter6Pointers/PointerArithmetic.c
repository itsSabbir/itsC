/*
 * Cheat Sheet: Pointer Arithmetic in C
 * 
 * Table of Contents:
 * 1. Overview and Historical Context
 * 2. Syntax and Key Concepts
 * 3. Basic Pointer Arithmetic
 * 4. Advanced Pointer Arithmetic
 * 5. Best Practices and Common Pitfalls
 * 6. Integration and Real-World Applications
 * 7. Advanced Concepts and Emerging Trends
 * 8. FAQs and Troubleshooting
 * 9. Performance Analysis and Optimization
 * 10. Contributing to this Cheat Sheet
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

/*
 * 1. Overview and Historical Context
 * 
 * Pointer arithmetic in C allows manipulation of memory addresses through arithmetic operations.
 * It's a powerful feature that enables efficient memory access and manipulation, particularly
 * useful in array operations, dynamic memory allocation, and low-level system programming.
 * 
 * History: Pointer arithmetic has been a core feature of C since its inception in the early 1970s.
 * It was designed to provide direct memory manipulation capabilities, reflecting C's philosophy
 * of giving programmers low-level control over computer hardware.
 * 
 * Significance: Pointer arithmetic is crucial for:
 * - Efficient array traversal
 * - Dynamic memory management
 * - Implementing data structures (e.g., linked lists, trees)
 * - System-level programming and hardware interaction
 * 
 * Modern relevance: While high-level languages often abstract away direct memory manipulation,
 * pointer arithmetic remains vital in C for performance-critical applications, embedded systems,
 * and when interfacing with hardware.
 */

/*
 * 2. Syntax and Key Concepts
 * 
 * Basic syntax: ptr + n, ptr - n, ptr++, ptr--, etc.
 * where 'ptr' is a pointer and 'n' is an integer.
 * 
 * Key concepts:
 * - Pointer arithmetic is based on the size of the pointed-to type
 * - Adding 1 to a pointer moves it to the next element of its type
 * - Subtracting pointers of the same type yields the number of elements between them
 */

// Function prototypes
void basic_pointer_arithmetic();
void advanced_pointer_arithmetic();
void pointer_arithmetic_best_practices();
void real_world_applications();
void advanced_concepts();
void performance_analysis();

int main() {
    printf("Cheat Sheet: Pointer Arithmetic in C\n\n");

    basic_pointer_arithmetic();
    advanced_pointer_arithmetic();
    pointer_arithmetic_best_practices();
    real_world_applications();
    advanced_concepts();
    performance_analysis();

    return 0;
}

void basic_pointer_arithmetic() {
    printf("3. Basic Pointer Arithmetic\n");

    int arr[] = {10, 20, 30, 40, 50};
    int *ptr = arr;

    printf("Array contents: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));  // Accessing array elements using pointer arithmetic
    }
    printf("\n");

    // Incrementing a pointer
    ptr++;
    printf("After ptr++: %d\n", *ptr);  // Output: 20

    // Decrementing a pointer
    ptr--;
    printf("After ptr--: %d\n", *ptr);  // Output: 10

    // Adding an integer to a pointer
    ptr = ptr + 2;
    printf("After ptr + 2: %d\n", *ptr);  // Output: 30

    // Subtracting an integer from a pointer
    ptr = ptr - 1;
    printf("After ptr - 1: %d\n", *ptr);  // Output: 20

    // Subtracting two pointers
    int *end_ptr = &arr[4];
    ptrdiff_t elements_between = end_ptr - ptr;
    printf("Elements between ptr and end_ptr: %td\n", elements_between);

    printf("\n");
}

void advanced_pointer_arithmetic() {
    printf("4. Advanced Pointer Arithmetic\n");

    // Using pointer arithmetic with structures
    struct Point {
        int x;
        int y;
    };

    struct Point points[] = {{1, 2}, {3, 4}, {5, 6}};
    struct Point *p_ptr = points;

    printf("Points: ");
    for (int i = 0; i < 3; i++) {
        printf("(%d, %d) ", (p_ptr + i)->x, (p_ptr + i)->y);
    }
    printf("\n");

    // Pointer arithmetic with void pointers
    void *void_ptr = points;
    struct Point *cast_ptr = (struct Point *)void_ptr + 1;
    printf("Second point using void pointer: (%d, %d)\n", cast_ptr->x, cast_ptr->y);

    // Pointer arithmetic in multi-dimensional arrays
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int *mat_ptr = &matrix[0][0];

    printf("Matrix using pointer arithmetic: \n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(mat_ptr + i*3 + j));
        }
        printf("\n");
    }

    printf("\n");
}

void pointer_arithmetic_best_practices() {
    printf("5. Best Practices and Common Pitfalls\n");

    // Best Practice 1: Always initialize pointers
    int *good_ptr = NULL;
    // int *bad_ptr;  // Uninitialized pointer - avoid this

    // Best Practice 2: Check for NULL before dereferencing
    if (good_ptr != NULL) {
        // Safe to dereference
    }

    // Best Practice 3: Use size_t for pointer arithmetic in loops
    int arr[] = {1, 2, 3, 4, 5};
    size_t arr_size = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Common Pitfall 1: Off-by-one errors
    // Correct way to iterate through an array
    for (int *p = arr; p < arr + arr_size; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    // Common Pitfall 2: Dereferencing a pointer to unallocated memory
    int *dynamic_arr = (int *)malloc(5 * sizeof(int));
    if (dynamic_arr != NULL) {
        for (int i = 0; i < 5; i++) {
            *(dynamic_arr + i) = i + 1;
        }
        // Remember to free allocated memory
        free(dynamic_arr);
    }

    // Common Pitfall 3: Incrementing a pointer past the end of an array
    int *end_ptr = arr + arr_size;
    for (int *p = arr; p != end_ptr; p++) {
        printf("%d ", *p);
    }
    printf("\n");

    printf("\n");
}

void real_world_applications() {
    printf("6. Integration and Real-World Applications\n");

    // Example: Custom memory allocator
    void *memory_pool = malloc(1000);
    void *allocated_memory[10];
    size_t allocated_size[10];
    int allocation_count = 0;

    // Simple allocation function
    void *custom_alloc(size_t size) {
        if (allocation_count >= 10) return NULL;
        void *ptr = (char *)memory_pool + (allocation_count * 100);
        allocated_memory[allocation_count] = ptr;
        allocated_size[allocation_count] = size;
        allocation_count++;
        return ptr;
    }

    // Allocate some memory
    int *int_ptr = (int *)custom_alloc(sizeof(int));
    *int_ptr = 42;
    char *str_ptr = (char *)custom_alloc(20 * sizeof(char));
    strcpy(str_ptr, "Hello, World!");

    printf("Integer value: %d\n", *int_ptr);
    printf("String value: %s\n", str_ptr);

    // Clean up
    free(memory_pool);

    printf("\n");
}

void advanced_concepts() {
    printf("7. Advanced Concepts and Emerging Trends\n");

    // Function pointers and pointer arithmetic
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
    int multiply(int a, int b) { return a * b; }

    int (*operations[])(int, int) = {add, subtract, multiply};
    int a = 10, b = 5;

    for (int i = 0; i < 3; i++) {
        printf("Operation %d result: %d\n", i, operations[i](a, b));
    }

    // Pointer arithmetic in embedded systems (simulated)
    unsigned char *memory_mapped_io = (unsigned char *)malloc(256);
    *(memory_mapped_io + 0x10) = 0xFF;  // Set a value at memory address 0x10
    printf("Value at memory address 0x10: 0x%02X\n", *(memory_mapped_io + 0x10));

    free(memory_mapped_io);

    printf("\n");
}

void performance_analysis() {
    printf("9. Performance Analysis and Optimization\n");

    #define ARRAY_SIZE 1000000
    #define ITERATIONS 100

    int *large_array = (int *)malloc(ARRAY_SIZE * sizeof(int));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        large_array[i] = i;
    }

    clock_t start, end;
    double cpu_time_used;

    // Measure performance of array indexing
    start = clock();
    for (int iter = 0; iter < ITERATIONS; iter++) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            int value = large_array[i];
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken with array indexing: %f seconds\n", cpu_time_used);

    // Measure performance of pointer arithmetic
    start = clock();
    for (int iter = 0; iter < ITERATIONS; iter++) {
        for (int *p = large_array; p < large_array + ARRAY_SIZE; p++) {
            int value = *p;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken with pointer arithmetic: %f seconds\n", cpu_time_used);

    free(large_array);

    printf("\n");
}

/*
 * 8. FAQs and Troubleshooting
 * 
 * Q: Why does adding 1 to a pointer move it by the size of the data type?
 * A: Pointer arithmetic is scaled by the size of the pointed-to type to ensure
 *    that incrementing a pointer moves it to the next element of that type.
 * 
 * Q: How can I debug issues related to pointer arithmetic?
 * A: Use debugging tools like GDB, add assert statements, and use memory analysis
 *    tools like Valgrind to detect memory errors and leaks.
 * 
 * Q: Is pointer arithmetic always safe?
 * A: No, it can lead to undefined behavior if used incorrectly. Always ensure
 *    you're operating within allocated memory bounds.
 * 
 * Troubleshooting tips:
 * 1. Use address sanitizers in your compiler (e.g., -fsanitize=address in GCC)
 * 2. Implement bounds checking in debug builds
 * 3. Use static analysis tools to catch potential pointer arithmetic errors
 */

/*
 * 10. Contributing to this Cheat Sheet
 * 
 * This cheat sheet is open for community contributions. To contribute:
 * 1. Fork the repository containing this cheat sheet
 * 2. Make your changes, adding new examples or improving existing ones
 * 3. Ensure all code compiles and runs without errors
 * 4. Add comments explaining your changes
 * 5. Submit a pull request with a clear description of your contribution
 * 
 * Please adhere to the existing style and structure of the cheat sheet.
 * All contributions will be reviewed for accuracy and clarity before merging.
 */

/*
 * Recommended Tools and Resources:
 * 
 * 1. Static Analysis Tools:
 *    - Clang Static Analyzer
 *    - Cppcheck
 * 
 * 2. Debugging Tools:
 *    - GDB (GNU Debugger)
 *    - Valgrind for memory analysis
 * 
 * 3. Books:
 *    - "Expert C Programming: Deep C Secrets" by Peter van der Linden
 *    - "Pointers in C" by Yashavant Kanetkar
 * 
 * 4. Online Resources:
 *    - cppreference.com for C language reference
 *    - "Pointers and Memory" by Nick Parlante (Stanford CS Education Library)
 * 
 * 5. Compiler Explorer (godbolt.org) for exploring generated assembly code
 */