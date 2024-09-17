#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// Forward declarations for functions used in examples
void overview_and_syntax(void);
int add(int a, int b);
void swap(int *a, int *b);
int factorial(int n);
double average(int count, ...);
int (*higher_order_function(int x))(int, int);
void real_world_examples(void);
void best_practices(void);
void common_pitfalls(void);
void advanced_tips(void);
void integration_with_other_concepts(void);
void faqs_and_troubleshooting(void);
void recommended_tools_and_libraries(void);

// Main function
int main() {
    printf("Expert-level Cheat Sheet: Functions and Function Prototypes in C\n\n");

    overview_and_syntax();

    // Basic function call
    int result = add(5, 3);
    printf("5 + 3 = %d\n\n", result);

    // Function with pointers
    int x = 10, y = 20;
    printf("Before swap: x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("After swap: x = %d, y = %d\n\n", x, y);

    // Recursive function
    printf("Factorial of 5 = %d\n\n", factorial(5));

    // Variadic function
    printf("Average of 2, 4, 6, 8 = %.2f\n\n", average(4, 2, 4, 6, 8));

    // Higher-order function
    int (*operation)(int, int) = higher_order_function(1);
    printf("Result of higher-order function: %d\n\n", operation(5, 3));

    real_world_examples();
    best_practices();
    common_pitfalls();
    advanced_tips();
    integration_with_other_concepts();
    faqs_and_troubleshooting();
    recommended_tools_and_libraries();

    return 0;
}

void overview_and_syntax(void) {
    printf("1. Overview and Syntax of Functions and Function Prototypes in C\n");
    printf("--------------------------------------------------------------\n");
    printf("Functions in C are reusable blocks of code that perform specific tasks.\n");
    printf("Function prototypes declare a function's interface before its actual definition.\n\n");

    printf("Basic syntax of a function prototype:\n");
    printf("return_type function_name(parameter_type1 parameter1, parameter_type2 parameter2, ...);\n\n");

    printf("Basic syntax of a function definition:\n");
    printf("return_type function_name(parameter_type1 parameter1, parameter_type2 parameter2, ...) {\n");
    printf("    // Function body\n");
    printf("    return value; // if return_type is not void\n");
    printf("}\n\n");

    printf("Key concepts:\n");
    printf("- Functions promote code reusability and modularity\n");
    printf("- Function prototypes allow forward declaration, enabling flexible code organization\n");
    printf("- Functions can have parameters (inputs) and return values (outputs)\n");
    printf("- The 'void' keyword is used for functions with no parameters or no return value\n\n");
}

int add(int a, int b) {
    return a + b;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

double average(int count, ...) {
    va_list args;
    va_start(args, count);

    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += va_arg(args, int);
    }

    va_end(args);
    return sum / count;
}

int add_wrapper(int a, int b) { return a + b; }
int subtract_wrapper(int a, int b) { return a - b; }

int (*higher_order_function(int x))(int, int) {
    if (x > 0) {
        return add_wrapper;
    } else {
        return subtract_wrapper;
    }
}

void real_world_examples(void) {
    printf("2. Real-World Examples\n");
    printf("----------------------\n");
    
    printf("Example 1: Custom string manipulation function\n");
    char str[] = "Hello, World!";
    printf("Original string: %s\n", str);
    
    // Custom function to reverse a string
    void reverse_string(char* s) {
        int length = strlen(s);
        for (int i = 0; i < length / 2; i++) {
            char temp = s[i];
            s[i] = s[length - 1 - i];
            s[length - 1 - i] = temp;
        }
    }
    
    reverse_string(str);
    printf("Reversed string: %s\n\n", str);

    printf("Example 2: Callback function for custom sorting\n");
    int numbers[] = {42, 13, 7, 30, 5};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    
    // Comparison function for descending order
    int compare_desc(const void* a, const void* b) {
        return (*(int*)b - *(int*)a);
    }
    
    qsort(numbers, n, sizeof(int), compare_desc);
    
    printf("Sorted numbers in descending order: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");
}

void best_practices(void) {
    printf("3. Best Practices\n");
    printf("------------------\n");
    printf("- Use meaningful function names that describe their purpose\n");
    printf("- Keep functions short and focused on a single task\n");
    printf("- Use function prototypes to declare functions before they are used\n");
    printf("- Group related functions together in source files\n");
    printf("- Use const for parameters that should not be modified\n");
    printf("- Return error codes or use errno for error handling\n");
    printf("- Validate input parameters at the beginning of the function\n");
    printf("- Use static functions for internal linkage when appropriate\n");
    printf("- Consider using inline functions for small, frequently used functions\n");
    printf("- Document functions with clear comments explaining purpose, parameters, and return values\n\n");
}

void common_pitfalls(void) {
    printf("4. Common Pitfalls\n");
    printf("-------------------\n");
    printf("- Forgetting to include function prototypes, leading to implicit declarations\n");
    printf("- Mismatching function prototypes and definitions\n");
    printf("- Incorrect use of return values (e.g., not checking return values for errors)\n");
    printf("- Stack overflow due to excessive recursion\n");
    printf("- Memory leaks in functions that allocate memory\n");
    printf("- Accessing out-of-bounds array elements in function parameters\n");
    printf("- Using uninitialized variables within functions\n");
    printf("- Failing to handle all possible cases in a function\n");
    printf("- Inconsistent parameter ordering across similar functions\n");
    printf("- Side effects in functions that are not clearly documented\n\n");
}

void advanced_tips(void) {
    printf("5. Advanced Tips and Optimizations\n");
    printf("----------------------------------\n");
    printf("- Use function pointers for implementing callbacks and creating flexible APIs\n");
    printf("- Leverage inline functions for performance-critical code\n");
    printf("- Utilize tail call optimization for recursive functions\n");
    printf("- Use restrict keyword for pointer parameters to enable compiler optimizations\n");
    printf("- Implement variadic functions for flexible argument handling\n");
    printf("- Use attribute((nonnull)) for functions that expect non-null pointer arguments\n");
    printf("- Employ function-like macros for compile-time optimizations (use with caution)\n");
    printf("- Utilize __builtin_expect() for branch prediction hints in GCC\n");
    printf("- Consider using computed goto for optimizing certain types of switch statements\n");
    printf("- Use __attribute__((constructor)) and __attribute__((destructor)) for automatic function execution\n\n");
}

void integration_with_other_concepts(void) {
    printf("6. Integration with Other Concepts\n");
    printf("----------------------------------\n");
    printf("- Modularity: Functions are the building blocks of modular programming\n");
    printf("- Object-Oriented Programming: Functions can be used to implement methods in structs\n");
    printf("- Error Handling: Functions often return error codes or set errno for error reporting\n");
    printf("- Memory Management: Functions can encapsulate memory allocation and deallocation\n");
    printf("- Concurrency: Functions can be used as entry points for threads\n");
    printf("- Event-Driven Programming: Functions serve as event handlers or callbacks\n");
    printf("- Generic Programming: Function-like macros or void pointers enable generic functions\n");
    printf("- Functional Programming: Higher-order functions and function pointers enable functional paradigms\n");
    printf("- Interoperability: Functions define the interface for interacting with libraries or other languages\n");
    printf("- Design Patterns: Many design patterns in C rely heavily on function pointers and callbacks\n\n");
}

void faqs_and_troubleshooting(void) {
    printf("7. FAQs and Troubleshooting\n");
    printf("---------------------------\n");
    printf("Q: Why am I getting 'implicit declaration of function' warnings?\n");
    printf("A: Ensure you have function prototypes or include the appropriate header files.\n\n");

    printf("Q: How can I return multiple values from a function?\n");
    printf("A: Use pointers as parameters, return a struct, or use global variables (cautiously).\n\n");

    printf("Q: What's the difference between 'void func()' and 'void func(void)' in C?\n");
    printf("A: 'void func()' allows any number of arguments, while 'void func(void)' explicitly takes no arguments.\n\n");

    printf("Q: How do I handle variable numbers of arguments in a function?\n");
    printf("A: Use variadic functions with <stdarg.h> or use an array/struct to pass multiple arguments.\n\n");

    printf("Q: Can I have a function return another function?\n");
    printf("A: Yes, you can return a function pointer. Example: int (*func(void))(int, int);\n\n");

    printf("Q: How do I debug a function that's crashing my program?\n");
    printf("A: Use a debugger like GDB, add logging/print statements, or use assert() for invariant checking.\n");
}

void recommended_tools_and_libraries(void) {
    printf("8. Recommended Tools and Libraries\n");
    printf("----------------------------------\n");
    printf("- Static Analysis Tools:\n");
    printf("  * Cppcheck: Detects various types of bugs and suggests improvements\n");
    printf("  * Clang Static Analyzer: Part of the LLVM project, finds bugs in C code\n");
    printf("  * Coverity: Commercial static analysis tool for detecting defects\n\n");

    printf("- Debugging and Profiling Tools:\n");
    printf("  * GDB (GNU Debugger): Powerful debugger for inspecting program state\n");
    printf("  * Valgrind: Memory debugging, memory leak detection, and profiling\n");
    printf("  * perf: Linux profiling tool for performance analysis\n\n");

    printf("- Documentation Tools:\n");
    printf("  * Doxygen: Generates documentation from annotated source code\n");
    printf("  * Natural Docs: Documentation generator that uses natural language\n\n");

    printf("- Build Systems:\n");
    printf("  * CMake: Cross-platform build system\n");
    printf("  * Make: Traditional build tool for C projects\n\n");

    printf("- Testing Frameworks:\n");
    printf("  * Unity: Simple unit testing framework for C\n");
    printf("  * Check: Unit testing framework for C\n");
    printf("  * Google Test: C++ testing framework that can be used with C\n\n");

    printf("- Libraries for Extended Functionality:\n");
    printf("  * GLib: General-purpose utility library\n");
    printf("  * libuv: Multi-platform support library with a focus on asynchronous I/O\n");
    printf("  * libcurl: Client-side URL transfer library\n");
}