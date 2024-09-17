#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

// Function prototypes
void overview(void);
void basic_function_example(void);
int add_numbers(int a, int b);
void pass_by_value_example(int x);
void pass_by_reference_example(int *x);
void array_as_parameter(int arr[], int size);
void multi_dimensional_array_parameter(int rows, int cols, int matrix[rows][cols]);
int *return_array(int size);
char *string_parameter_example(const char *str);
void function_pointer_example(void);
int higher_order_function(int (*func)(int), int value);
void variadic_function_example(const char *format, ...);
void static_and_inline_functions(void);
void recursion_example(void);
void best_practices(void);
void common_pitfalls(void);
void advanced_tips(void);
void real_world_applications(void);
void faqs_and_troubleshooting(void);
void recommended_tools_and_libraries(void);

int main() {
    printf("Expert-level Cheat Sheet: Functions in C\n\n");

    overview();
    basic_function_example();
    pass_by_value_example(5);
    
    int x = 10;
    pass_by_reference_example(&x);
    printf("After pass_by_reference_example, x = %d\n\n", x);

    int arr[] = {1, 2, 3, 4, 5};
    array_as_parameter(arr, 5);

    int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    multi_dimensional_array_parameter(3, 3, matrix);

    int *dynamic_array = return_array(5);
    printf("Dynamic array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dynamic_array[i]);
    }
    printf("\n\n");
    free(dynamic_array);

    char *modified_string = string_parameter_example("Hello, World!");
    printf("Modified string: %s\n\n", modified_string);
    free(modified_string);

    function_pointer_example();
    
    variadic_function_example("Int: %d, Float: %f, String: %s\n", 10, 3.14, "Hello");

    static_and_inline_functions();
    recursion_example();
    best_practices();
    common_pitfalls();
    advanced_tips();
    real_world_applications();
    faqs_and_troubleshooting();
    recommended_tools_and_libraries();

    return 0;
}

void overview(void) {
    printf("1. Overview of Functions in C\n");
    printf("-----------------------------\n");
    printf("Functions in C are blocks of code that perform specific tasks. They are fundamental\n");
    printf("to structured programming, allowing code reuse, modularity, and abstraction.\n");
    printf("Key aspects of C functions include:\n");
    printf("- Function declaration and definition\n");
    printf("- Parameters (arguments) for input\n");
    printf("- Return values for output\n");
    printf("- Scope and lifetime of variables\n");
    printf("Functions help in breaking down complex problems into smaller, manageable parts,\n");
    printf("improving code readability, maintainability, and debugging.\n\n");
}

void basic_function_example(void) {
    printf("2. Basic Function Example\n");
    printf("-------------------------\n");
    int result = add_numbers(5, 3);
    printf("Result of add_numbers(5, 3): %d\n\n", result);
}

int add_numbers(int a, int b) {
    return a + b;
}

void pass_by_value_example(int x) {
    printf("3. Pass by Value Example\n");
    printf("------------------------\n");
    printf("Original value of x: %d\n", x);
    x = x * 2;
    printf("Modified value of x inside function: %d\n", x);
    printf("Note: The original value outside the function remains unchanged.\n\n");
}

void pass_by_reference_example(int *x) {
    printf("4. Pass by Reference Example\n");
    printf("----------------------------\n");
    printf("Original value of x: %d\n", *x);
    *x = *x * 2;
    printf("Modified value of x inside function: %d\n", *x);
    printf("Note: The original value outside the function is changed.\n\n");
}

void array_as_parameter(int arr[], int size) {
    printf("5. Array as Parameter Example\n");
    printf("-----------------------------\n");
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Note: Arrays are always passed by reference in C.\n\n");
}

void multi_dimensional_array_parameter(int rows, int cols, int matrix[rows][cols]) {
    printf("6. Multi-dimensional Array Parameter Example\n");
    printf("--------------------------------------------\n");
    printf("Matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int *return_array(int size) {
    printf("7. Returning an Array Example\n");
    printf("------------------------------\n");
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    printf("Note: Returning a pointer to dynamically allocated memory.\n");
    printf("Remember to free this memory in the calling function.\n\n");
    return arr;
}

char *string_parameter_example(const char *str) {
    printf("8. String Parameter Example\n");
    printf("---------------------------\n");
    printf("Original string: %s\n", str);
    char *new_str = (char *)malloc(strlen(str) + 20);
    strcpy(new_str, "Modified: ");
    strcat(new_str, str);
    printf("Note: Returning a new string. Remember to free this memory.\n\n");
    return new_str;
}

int square(int x) { return x * x; }
int cube(int x) { return x * x * x; }

void function_pointer_example(void) {
    printf("9. Function Pointer Example\n");
    printf("---------------------------\n");
    int (*func_ptr)(int);
    func_ptr = square;
    printf("Square of 5: %d\n", func_ptr(5));
    func_ptr = cube;
    printf("Cube of 5: %d\n", func_ptr(5));

    printf("Higher-order function example:\n");
    printf("Square of 5 using higher-order function: %d\n", higher_order_function(square, 5));
    printf("Cube of 5 using higher-order function: %d\n\n", higher_order_function(cube, 5));
}

int higher_order_function(int (*func)(int), int value) {
    return func(value);
}

void variadic_function_example(const char *format, ...) {
    printf("10. Variadic Function Example\n");
    printf("-----------------------------\n");
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}

static int static_var = 0;

static void static_function(void) {
    static_var++;
    printf("Static variable value: %d\n", static_var);
}

inline int inline_function(int x) {
    return x * x;
}

void static_and_inline_functions(void) {
    printf("11. Static and Inline Functions\n");
    printf("-------------------------------\n");
    printf("Static function example:\n");
    static_function();
    static_function();
    printf("Inline function example:\n");
    printf("Square of 5 using inline function: %d\n\n", inline_function(5));
}

void recursion_example(void) {
    printf("12. Recursion Example\n");
    printf("---------------------\n");
    
    int factorial(int n) {
        if (n == 0 || n == 1) return 1;
        return n * factorial(n - 1);
    }

    printf("Factorial of 5: %d\n\n", factorial(5));
}

void best_practices(void) {
    printf("13. Best Practices\n");
    printf("------------------\n");
    printf("- Use meaningful function names that describe their purpose\n");
    printf("- Keep functions small and focused on a single task\n");
    printf("- Use const for parameters that shouldn't be modified\n");
    printf("- Always prototype functions before using them\n");
    printf("- Use static functions for internal linkage when appropriate\n");
    printf("- Return error codes or use errno for error handling\n");
    printf("- Validate function inputs to ensure robust code\n");
    printf("- Use inline functions judiciously for performance-critical code\n");
    printf("- Document functions with clear comments explaining purpose, parameters, and return values\n\n");
}

void common_pitfalls(void) {
    printf("14. Common Pitfalls\n");
    printf("-------------------\n");
    printf("- Forgetting to free dynamically allocated memory\n");
    printf("- Not checking return values of functions\n");
    printf("- Incorrect use of variadic functions\n");
    printf("- Buffer overflows in string manipulation\n");
    printf("- Returning pointers to local variables (stack memory)\n");
    printf("- Incorrect function prototypes leading to undefined behavior\n");
    printf("- Excessive use of global variables\n");
    printf("- Neglecting to handle all possible cases in a function\n\n");
}

void advanced_tips(void) {
    printf("15. Advanced Tips\n");
    printf("------------------\n");
    printf("- Use function pointers for callbacks and event-driven programming\n");
    printf("- Implement higher-order functions for more flexible and reusable code\n");
    printf("- Utilize inline assembly for performance-critical sections\n");
    printf("- Employ tail call optimization for recursive functions\n");
    printf("- Use __attribute__((constructor)) and __attribute__((destructor)) for setup/cleanup\n");
    printf("- Implement custom memory management for performance-critical applications\n");
    printf("- Use __builtin_expect() for branch prediction hints\n");
    printf("- Employ function-like macros for constant-folding optimizations\n\n");
}

void real_world_applications(void) {
    printf("16. Real-World Applications\n");
    printf("---------------------------\n");
    printf("- Device drivers: Low-level functions interacting with hardware\n");
    printf("- Embedded systems: Efficient, memory-constrained function implementations\n");
    printf("- Game development: High-performance rendering and physics functions\n");
    printf("- Financial systems: Precise calculation functions with error handling\n");
    printf("- Networking: Protocol implementation functions\n");
    printf("- Database systems: Query execution and optimization functions\n");
    printf("- Operating systems: Process scheduling and memory management functions\n");
    printf("- Cryptography: Secure hashing and encryption functions\n\n");
}

void faqs_and_troubleshooting(void) {
    printf("17. FAQs and Troubleshooting\n");
    printf("----------------------------\n");
    printf("Q: How do I return multiple values from a function?\n");
    printf("A: Use pointers as parameters, structs, or global variables (sparingly).\n\n");
    printf("Q: What's the difference between 'malloc' and 'calloc'?\n");
    printf("A: 'calloc' initializes memory to zero, 'malloc' doesn't.\n\n");
    printf("Q: How can I improve the performance of my functions?\n");
    printf("A: Use profiling tools, consider inline functions, and optimize algorithms.\n\n");
    printf("Q: How do I handle errors in functions?\n");
    printf("A: Return error codes, use errno, or implement a custom error handling system.\n\n");
    printf("Q: What's function overloading, and why doesn't C support it?\n");
    printf("A: Function overloading allows multiple functions with the same name but different parameters. C doesn't support it to maintain simplicity and backward compatibility.\n\n");
}

void recommended_tools_and_libraries(void) {
    printf("18. Recommended Tools and Libraries\n");
    printf("-----------------------------------\n");
    printf("- GCC and Clang: Popular C compilers with advanced optimization options\n");
    printf("- Valgrind: Memory debugging and profiling tool\n");
    printf("- GDB: GNU Debugger for debugging C programs\n");
    printf("- GNU Scientific Library (GSL): Collection of numerical computing functions\n");
    printf("- libc: Standard C library with essential functions\n");
    printf("- Doxygen: Documentation generator for C functions\n");
    printf("- CMake: Cross-platform build system\n");
    printf("- cppcheck: Static analysis tool for C code\n");
    printf("- Criterion: Unit testing framework for C\n");
    printf("- AddressSanitizer: Memory error detector for C programs\n\n");
}