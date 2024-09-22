/*
Cheat Sheet: Pointers and Arrays in C
==================================================

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

int main() {
    printf("Cheat Sheet: Pointers and Arrays in C\n");
    printf("=================================================\n\n");

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
    printf("Pointers and arrays are fundamental concepts in C, providing powerful mechanisms for\n");
    printf("memory manipulation and efficient data structure implementation.\n\n");
    
    printf("Pointers: Variables that store memory addresses, allowing direct memory access.\n");
    printf("Arrays: Contiguous memory blocks storing elements of the same data type.\n\n");
    
    printf("Historical Context:\n");
    printf("- Introduced with C in the early 1970s by Dennis Ritchie at Bell Labs.\n");
    printf("- Designed for low-level memory access while maintaining high-level language structure.\n");
    printf("- Fundamental to C's philosophy of providing mechanisms, not policies.\n\n");
    
    printf("Modern Relevance:\n");
    printf("- Essential in systems programming, embedded systems, and performance-critical applications.\n");
    printf("- Basis for dynamic memory allocation and complex data structures.\n");
    printf("- Provides fine-grained control over memory, crucial for resource-constrained environments.\n\n");
}

void section2_syntax_and_examples() {
    printf("2. Syntax, Key Concepts, and Code Examples\n");
    printf("------------------------------------------\n");

    // Basic pointer and array declaration
    int number = 42;
    int *ptr = &number;
    int arr[5] = {1, 2, 3, 4, 5};
    
    printf("Basic pointer and array example:\n");
    printf("number = %d, *ptr = %d, arr[0] = %d\n\n", number, *ptr, arr[0]);

    // Pointer arithmetic
    printf("Pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d, *(arr + %d) = %d\n", i, arr[i], i, *(arr + i));
    }
    printf("\n");

    // Dynamic memory allocation
    int *dynamic_arr = (int*)malloc(5 * sizeof(int));
    if (dynamic_arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    
    for (int i = 0; i < 5; i++) {
        dynamic_arr[i] = i * 10;
    }
    
    printf("Dynamic array:\n");
    for (int i = 0; i < 5; i++) {
        printf("dynamic_arr[%d] = %d\n", i, dynamic_arr[i]);
    }
    printf("\n");
    
    free(dynamic_arr);

    // Multidimensional arrays and pointers
    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int (*matrix_ptr)[3] = matrix;
    
    printf("Multidimensional array:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix_ptr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Array of pointers
    const char *words[] = {"Hello", "World", "Pointers", "Arrays"};
    printf("Array of pointers:\n");
    for (int i = 0; i < 4; i++) {
        printf("%s ", words[i]);
    }
    printf("\n\n");
}

void section3_best_practices() {
    printf("3. Best Practices, Common Pitfalls, and Advanced Tips\n");
    printf("----------------------------------------------------\n");
    
    printf("Best Practices:\n");
    printf("1. Always initialize pointers and check for NULL after allocation.\n");
    printf("2. Use const for pointers to read-only data.\n");
    printf("3. Prefer array notation when working with arrays for clarity.\n");
    printf("4. Use size_t for array indices and pointer arithmetic.\n");
    printf("5. Free dynamically allocated memory to prevent leaks.\n\n");

    printf("Common Pitfalls:\n");
    printf("1. Buffer overflows: Accessing array elements out of bounds.\n");
    printf("2. Dangling pointers: Using pointers to freed memory.\n");
    printf("3. Memory leaks: Failing to free dynamically allocated memory.\n");
    printf("4. Incorrect pointer arithmetic: Miscalculating offsets.\n\n");

    printf("Advanced Tips:\n");
    printf("1. Use flexible array members for variable-length structures.\n");
    printf("2. Leverage restrict keyword for optimization in function parameters.\n");
    printf("3. Understand alignment requirements for different data types.\n");
    printf("4. Use tools like Valgrind for memory error detection.\n\n");

    // Example: Flexible array member
    typedef struct {
        int size;
        double data[];
    } FlexibleArray;

    size_t total_size = sizeof(FlexibleArray) + 5 * sizeof(double);
    FlexibleArray *flex_arr = (FlexibleArray*)malloc(total_size);
    if (flex_arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    flex_arr->size = 5;
    for (int i = 0; i < flex_arr->size; i++) {
        flex_arr->data[i] = i * 1.1;
    }

    printf("Flexible array member example:\n");
    for (int i = 0; i < flex_arr->size; i++) {
        printf("%.2f ", flex_arr->data[i]);
    }
    printf("\n\n");

    free(flex_arr);
}

void section4_real_world_applications() {
    printf("4. Integration and Real-World Applications\n");
    printf("------------------------------------------\n");
    
    printf("Real-world applications of pointers and arrays:\n");
    printf("1. Data structures: Linked lists, trees, graphs\n");
    printf("2. Memory management in operating systems\n");
    printf("3. Image processing and computer vision\n");
    printf("4. Network packet handling and parsing\n");
    printf("5. Compiler design and implementation\n\n");

    // Example: Simple image convolution (edge detection)
    int image[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int kernel[3][3] = {
        {-1, -1, -1},
        {-1,  8, -1},
        {-1, -1, -1}
    };

    int result[3][3] = {0};

    printf("Image convolution example (edge detection):\n");
    printf("Original image:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int ki = 0; ki < 3; ki++) {
                for (int kj = 0; kj < 3; kj++) {
                    result[i][j] += image[i+ki][j+kj] * kernel[ki][kj];
                }
            }
        }
    }

    printf("\nConvolved image (edges):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%2d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void section5_advanced_concepts() {
    printf("5. Advanced Concepts and Emerging Trends\n");
    printf("----------------------------------------\n");
    
    printf("Advanced concepts:\n");
    printf("1. Pointer-to-functions for callback mechanisms\n");
    printf("2. Variable-length arrays (VLAs) in C99\n");
    printf("3. Compound literals for temporary array creation\n");
    printf("4. Type-generic macros for pointer manipulation\n\n");

    printf("Emerging trends:\n");
    printf("1. Smart pointers in C++ as safer alternatives\n");
    printf("2. Bounds-checking interfaces in C11 (Annex K)\n");
    printf("3. Pointer authentication in modern architectures\n");
    printf("4. Static analysis tools for pointer and array safety\n\n");

    // Example: Pointer-to-function
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }

    int operate(int (*operation)(int, int), int x, int y) {
        return operation(x, y);
    }

    printf("Pointer-to-function example:\n");
    printf("operate(add, 5, 3) = %d\n", operate(add, 5, 3));
    printf("operate(subtract, 5, 3) = %d\n\n", operate(subtract, 5, 3));

    // Example: Compound literal
    int *temp_array = (int[]){1, 2, 3, 4, 5};
    printf("Compound literal example:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", temp_array[i]);
    }
    printf("\n\n");
}

void section6_faqs_and_troubleshooting() {
    printf("6. FAQs and Troubleshooting\n");
    printf("---------------------------\n");
    
    printf("FAQs:\n");
    printf("Q: What's the difference between arr and &arr?\n");
    printf("A: arr is a pointer to the first element, &arr is a pointer to the whole array.\n\n");

    printf("Q: How do I pass a 2D array to a function?\n");
    printf("A: Use a pointer to an array: void func(int (*arr)[COLS]);\n\n");

    printf("Q: How can I check for array bounds in C?\n");
    printf("A: C doesn't have built-in bounds checking. Use assertions or manual checks.\n\n");

    printf("Troubleshooting:\n");
    printf("1. Segmentation fault: Check for NULL pointers and array bounds.\n");
    printf("2. Memory leaks: Use Valgrind or similar tools to detect and fix leaks.\n");
    printf("3. Unexpected behavior: Watch for off-by-one errors in array indexing.\n");
    printf("4. Performance issues: Profile your code and optimize memory access patterns.\n\n");

    // Example: Using assert for bounds checking
    int test_array[5] = {1, 2, 3, 4, 5};
    int index = 3;

    printf("Using assert for bounds checking:\n");
    assert(index >= 0 && index < 5 && "Array index out of bounds");
    printf("test_array[%d] = %d\n\n", index, test_array[index]);

    // Uncommenting the next line would trigger an assertion failure
    // index = 10;
    // assert(index >= 0 && index < 5 && "Array index out of bounds");
    // printf("test_array[%d] = %d\n", index, test_array[index]);
}

void section7_tools_and_resources() {
    printf("7. Recommended Tools, Libraries, and Resources\n");
    printf("----------------------------------------------\n");
    
    printf("Tools:\n");
    printf("1. Valgrind: Memory debugging and leak detection\n");
    printf("2. AddressSanitizer: Fast memory error detector\n");
    printf("3. Clang Static Analyzer: Static analysis tool\n");
    printf("4. GDB: GNU Debugger for runtime analysis\n\n");

    printf("Libraries:\n");
    printf("1. Boehm GC: Conservative garbage collector for C\n");
    printf("2. jemalloc: General-purpose malloc implementation\n");
    printf("3. Judy Arrays: High-performance array implementations\n\n");

    printf("Resources:\n");
    printf("1. 'Expert C Programming' by Peter van der Linden\n");
    printf("2. 'Understanding and Using C Pointers' by Richard Reese\n");
    printf("3. 'C Programming: A Modern Approach' by K. N. King\n");
    printf("4. Online course: 'Pointers in C' on platforms like Coursera or edX\n\n");
}

void section8_performance_analysis() {
    printf("8. Performance Analysis and Optimization\n");
    printf("----------------------------------------\n");
    
    printf("Performance considerations:\n");
    printf("1. Cache-friendly access patterns for arrays\n");
    printf("2. Pointer aliasing and its impact on optimization\n");
    printf("3. Memory alignment for efficient access\n");
    printf("4. Trade-offs between arrays and linked data structures\n\n");

    // Example: Comparing row-major vs column-major access
    #define ROWS 1000
    #define COLS 1000

    int matrix[ROWS][COLS];
    clock_t start, end;
    double cpu_time_used;

    // Initialize matrix
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = i * COLS + j;
        }
    }

    // Row-major access
    start = clock();
    long long sum = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            sum += matrix[i][j];
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Row-major access time: %f seconds\n", cpu_time_used);

    // Column-major access
    start = clock();
    sum = 0;
    for (int j = 0; j < COLS; j++) {
        for (int i = 0; i < ROWS; i++) {
            sum += matrix[i][j];
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Column-major access time: %f seconds\n", cpu_time_used);

    printf("\nOptimization strategies:\n");
    printf("1. Use row-major access for C arrays (stored in row-major order).\n");
    printf("2. Optimize for cache line size (typically 64 bytes).\n");
    printf("3. Use pointer arithmetic instead of array indexing for slight performance gain.\n");
    printf("4. Consider using SIMD instructions for parallel processing of array elements.\n\n");

    // Example: Using pointer arithmetic for array traversal
    start = clock();
    sum = 0;
    int *p = &matrix[0][0];
    int *end = p + ROWS * COLS;
    while (p < end) {
        sum += *p++;
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Pointer arithmetic access time: %f seconds\n\n", cpu_time_used);
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
    printf("- Ensure all code examples are correct and follow best practices.\n");
    printf("- Provide clear explanations for complex concepts.\n");
    printf("- Include references to authoritative sources when introducing new information.\n");
    printf("- Maintain a balance between beginner-friendly and advanced content.\n");
    printf("- Consider adding performance benchmarks for new code examples.\n\n");
    
    printf("Thank you for helping to improve this resource for the C programming community!\n");
}
