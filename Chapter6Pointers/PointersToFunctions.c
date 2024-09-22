/*
Cheat Sheet: Pointers to Functions in C
====================================================

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
int add(int a, int b);
int subtract(int a, int b);
void greet(const char* name);
int compare_int(const void* a, const void* b);

int main() {
    printf("Cheat Sheet: Pointers to Functions in C\n");
    printf("===================================================\n\n");

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
    printf("Function pointers in C are variables that store the address of a function.\n");
    printf("They allow functions to be passed as arguments, returned from other functions,\n");
    printf("and stored in data structures, enabling powerful programming techniques.\n\n");
    
    printf("Historical Context:\n");
    printf("- Introduced with the C programming language in the early 1970s.\n");
    printf("- Evolved from assembly language techniques for dynamic dispatch.\n");
    printf("- Fundamental to the development of callback mechanisms and event-driven programming.\n\n");
    
    printf("Significance in Modern Development:\n");
    printf("- Enable implementation of polymorphism and callbacks in C.\n");
    printf("- Crucial for plugin architectures and dynamic loading of code.\n");
    printf("- Form the basis for object-oriented concepts in C++.\n");
    printf("- Widely used in system programming, GUI frameworks, and embedded systems.\n\n");
}

void section2_syntax_and_examples() {
    printf("2. Syntax, Key Concepts, and Code Examples\n");
    printf("------------------------------------------\n");

    // Basic function pointer declaration and usage
    int (*operation)(int, int);
    operation = add;
    
    printf("Basic function pointer usage:\n");
    printf("Result of add(5, 3) via function pointer: %d\n\n", operation(5, 3));

    // Array of function pointers
    int (*operations[2])(int, int) = {add, subtract};
    
    printf("Array of function pointers:\n");
    for (int i = 0; i < 2; i++) {
        printf("Result of operation[%d](10, 5): %d\n", i, operations[i](10, 5));
    }
    printf("\n");

    // Function pointer as argument
    void higher_order_function(void (*func)(const char*), const char* arg) {
        func(arg);
    }
    
    printf("Function pointer as argument:\n");
    higher_order_function(greet, "Alice");
    printf("\n");

    // Typedef for function pointers
    typedef int (*BinaryOperation)(int, int);
    BinaryOperation my_op = add;
    
    printf("Typedef for function pointers:\n");
    printf("Result of my_op(7, 3): %d\n\n", my_op(7, 3));

    // Function returning a function pointer
    BinaryOperation get_operation(char op) {
        switch (op) {
            case '+': return add;
            case '-': return subtract;
            default: return NULL;
        }
    }
    
    printf("Function returning a function pointer:\n");
    BinaryOperation dynamic_op = get_operation('+');
    if (dynamic_op) {
        printf("Result of dynamic_op(8, 2): %d\n", dynamic_op(8, 2));
    }
    printf("\n");
}

void section3_best_practices() {
    printf("3. Best Practices, Common Pitfalls, and Advanced Tips\n");
    printf("----------------------------------------------------\n");
    
    printf("Best Practices:\n");
    printf("1. Use typedef to improve readability of function pointer declarations.\n");
    printf("2. Always check function pointers for NULL before calling.\n");
    printf("3. Use const for function pointers that won't be reassigned.\n");
    printf("4. Prefer function pointers over switch statements for extensibility.\n\n");

    printf("Common Pitfalls:\n");
    printf("1. Incorrect function pointer syntax leading to compilation errors.\n");
    printf("2. Calling function pointers without checking for NULL.\n");
    printf("3. Mixing incompatible function signatures.\n");
    printf("4. Failing to cast void* to the correct function pointer type.\n\n");

    printf("Advanced Tips:\n");
    printf("1. Use function pointers for runtime polymorphism in C.\n");
    printf("2. Implement simple closures using function pointers and structs.\n");
    printf("3. Utilize function pointers for effective mocking in unit tests.\n");
    printf("4. Understand the performance implications of indirect function calls.\n\n");

    // Example: Simple closure using function pointer and struct
    typedef struct {
        int (*func)(int);
        int context;
    } Closure;

    int add_n(int x) {
        return x + ((Closure*)__builtin_return_address(0) - 1)->context;
    }

    Closure add_5 = {add_n, 5};
    
    printf("Closure example:\n");
    printf("add_5(10) = %d\n\n", add_5.func(10));
}

void section4_real_world_applications() {
    printf("4. Integration and Real-World Applications\n");
    printf("------------------------------------------\n");
    
    printf("Real-world applications of function pointers:\n");
    printf("1. Callback mechanisms in event-driven programming\n");
    printf("2. Plugin architectures for extensible software\n");
    printf("3. Implementing virtual function tables in object-oriented C\n");
    printf("4. Signal handling in Unix-like operating systems\n");
    printf("5. Sorting algorithms with custom comparators\n\n");

    // Example: Custom sorting with qsort
    int numbers[] = {42, 13, 7, 55, 29, 36};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Custom sorting example:\n");
    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    qsort(numbers, n, sizeof(int), compare_int);
    
    printf("After sorting:  ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");

    // Example: Simple plugin architecture
    typedef struct {
        const char* name;
        void (*initialize)();
        void (*cleanup)();
    } Plugin;

    void dummy_init() { printf("Dummy plugin initialized\n"); }
    void dummy_cleanup() { printf("Dummy plugin cleaned up\n"); }

    Plugin plugins[] = {
        {"Dummy", dummy_init, dummy_cleanup},
        // Add more plugins here
    };

    printf("Simple plugin architecture example:\n");
    for (int i = 0; i < sizeof(plugins) / sizeof(plugins[0]); i++) {
        printf("Initializing %s plugin\n", plugins[i].name);
        plugins[i].initialize();
    }

    for (int i = 0; i < sizeof(plugins) / sizeof(plugins[0]); i++) {
        printf("Cleaning up %s plugin\n", plugins[i].name);
        plugins[i].cleanup();
    }
    printf("\n");
}

void section5_advanced_concepts() {
    printf("5. Advanced Concepts and Emerging Trends\n");
    printf("----------------------------------------\n");
    
    printf("Advanced concepts:\n");
    printf("1. Function pointer casting and type-punning\n");
    printf("2. Variadic function pointers\n");
    printf("3. Function pointers with different calling conventions\n");
    printf("4. Using function pointers with inline assembly\n\n");

    printf("Emerging trends:\n");
    printf("1. Lambda expressions in C++ as an alternative to function pointers\n");
    printf("2. Closure objects in modern languages vs. function pointers\n");
    printf("3. Just-In-Time (JIT) compilation techniques using function pointers\n");
    printf("4. Security implications of function pointers in modern architectures\n\n");

    // Example: Variadic function pointer
    typedef void (*VariadicFunc)(const char* format, ...);
    VariadicFunc print_func = (VariadicFunc)printf;
    
    printf("Variadic function pointer example:\n");
    print_func("This is a %s with %d arguments\n", "test", 2);
    printf("\n");
}

void section6_faqs_and_troubleshooting() {
    printf("6. FAQs and Troubleshooting\n");
    printf("---------------------------\n");
    
    printf("FAQs:\n");
    printf("Q: How do I declare a pointer to a function that returns a pointer?\n");
    printf("A: Use parentheses: int *(*func_ptr)(int);\n\n");

    printf("Q: Can I use function pointers with inline functions?\n");
    printf("A: Inline is a suggestion to the compiler. It may not inline when used with pointers.\n\n");

    printf("Q: How do function pointers affect program security?\n");
    printf("A: They can be a vector for attacks if not properly validated, especially in C.\n\n");

    printf("Troubleshooting:\n");
    printf("1. Segmentation fault: Ensure function pointer is not NULL before calling.\n");
    printf("2. Type mismatch: Check function signature matches the pointer declaration.\n");
    printf("3. Linker errors: Verify that the pointed-to function is actually defined.\n");
    printf("4. Unexpected behavior: Debug by printing function addresses and validating calls.\n\n");

    // Example: Debugging function pointers
    void (*debug_func_ptr)(const char*) = &greet;
    printf("Debugging example:\n");
    printf("Address of greet function: %p\n", (void*)&greet);
    printf("Value of debug_func_ptr:   %p\n", (void*)debug_func_ptr);
    printf("Calling debug_func_ptr:\n");
    if (debug_func_ptr) {
        debug_func_ptr("Debugger");
    } else {
        printf("Error: debug_func_ptr is NULL\n");
    }
    printf("\n");
}

void section7_tools_and_resources() {
    printf("7. Recommended Tools, Libraries, and Resources\n");
    printf("----------------------------------------------\n");
    
    printf("Tools:\n");
    printf("1. GNU gdb: Powerful debugger for inspecting function pointer behavior\n");
    printf("2. Valgrind: Memory analysis tool, useful for detecting function pointer misuse\n");
    printf("3. Compiler warnings: Enable -Wall -Wextra for catching potential issues\n");
    printf("4. Static analyzers: Tools like Clang Static Analyzer or Coverity\n\n");

    printf("Libraries:\n");
    printf("1. libffi: Foreign Function Interface library for working with function pointers\n");
    printf("2. dlfcn.h: Dynamic loading library for working with shared objects\n");
    printf("3. signal.h: Standard library for signal handling using function pointers\n\n");

    printf("Resources:\n");
    printf("1. 'Expert C Programming' by Peter van der Linden\n");
    printf("2. 'Advanced Programming in the UNIX Environment' by W. Richard Stevens\n");
    printf("3. 'Function Pointers in C' tutorial on Cprogramming.com\n");
    printf("4. 'Understanding Function Pointers in C' series on YouTube\n\n");
}

void section8_performance_analysis() {
    printf("8. Performance Analysis and Optimization\n");
    printf("----------------------------------------\n");
    
    printf("Performance considerations:\n");
    printf("1. Indirect calls via function pointers can be slower than direct calls\n");
    printf("2. Function pointers may inhibit certain compiler optimizations\n");
    printf("3. Cache behavior can be affected due to unpredictable call targets\n");
    printf("4. Branch prediction may be less effective with function pointers\n\n");

    // Example: Performance comparison
    #define ITERATIONS 100000000

    clock_t start, end;
    double cpu_time_used;

    // Direct call
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        add(i, i);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for direct calls: %f seconds\n", cpu_time_used);

    // Indirect call via function pointer
    int (*func_ptr)(int, int) = add;
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        func_ptr(i, i);
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time for indirect calls: %f seconds\n\n", cpu_time_used);

    printf("Optimization strategies:\n");
    printf("1. Use inline functions for performance-critical small functions\n");
    printf("2. Consider function inlining when using function pointers in hot paths\n");
    printf("3. Group related function pointers to improve cache locality\n");
    printf("4. Use Profile-Guided Optimization (PGO) to optimize indirect calls\n\n");
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
    printf("- Provide clear explanations for complex concepts related to function pointers.\n");
    printf("- Include practical, real-world examples that demonstrate the use of function pointers.\n");
    printf("- Maintain a balance between beginner-friendly content and advanced topics.\n");
    printf("- Consider adding or updating performance benchmarks for function pointer usage.\n");
    printf("- Keep the content up-to-date with the latest C standards and best practices.\n");
    printf("- If adding new sections, ensure they fit logically within the existing structure.\n\n");
    
    printf("Code style guidelines:\n");
    printf("- Use consistent indentation (preferably 4 spaces).\n");
    printf("- Follow the existing naming conventions for variables and functions.\n");
    printf("- Add comments to explain complex logic or non-obvious function pointer usage.\n");
    printf("- Keep line length to a maximum of 80 characters for better readability.\n\n");
    
    printf("Testing guidelines:\n");
    printf("- Add appropriate assertions to verify the behavior of new code examples.\n");
    printf("- If adding significant new functionality, consider including unit tests.\n");
    printf("- Ensure all examples run without errors on major C compilers (GCC, Clang, MSVC).\n\n");
    
    printf("Thank you for helping to improve this resource for the C programming community!\n");
}

// Helper functions used in the examples

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

void greet(const char* name) {
    printf("Hello, %s!\n", name);
}

int compare_int(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
