#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

// Function prototypes
void overview(void);
void basic_function_example(void);
void function_with_parameters(int a, int b);
int function_with_return(int a, int b);
void function_declaration_vs_definition(void);
void function_parameters(void);
void return_values(void);
void static_functions(void);
void inline_functions(void);
void recursive_functions(int n);
void function_pointers(void);
void variadic_functions(const char* format, ...);
void best_practices(void);
void common_pitfalls(void);
void advanced_tips(void);
void real_world_applications(void);
void integration_with_other_concepts(void);
void faqs_and_troubleshooting(void);
void recommended_tools_and_libraries(void);

// Main function
int main() {
    printf("Expert-level Cheat Sheet: Functions in C\n\n");

    overview();
    basic_function_example();
    function_with_parameters(5, 3);
    printf("Sum: %d\n", function_with_return(5, 3));
    function_declaration_vs_definition();
    function_parameters();
    return_values();
    static_functions();
    inline_functions();
    recursive_functions(5);
    function_pointers();
    variadic_functions("Int: %d, Float: %.2f, String: %s", 10, 3.14, "Hello");
    best_practices();
    common_pitfalls();
    advanced_tips();
    real_world_applications();
    integration_with_other_concepts();
    faqs_and_troubleshooting();
    recommended_tools_and_libraries();

    return 0;
}

void overview(void) {
    printf("1. Overview of Functions in C\n");
    printf("-----------------------------\n");
    printf("Functions in C are self-contained blocks of code that perform a specific task.\n");
    printf("They are fundamental to structured programming and offer several benefits:\n");
    printf("- Code reusability\n");
    printf("- Modularity\n");
    printf("- Abstraction\n");
    printf("- Easier maintenance and debugging\n");
    printf("Functions in C consist of two main parts:\n");
    printf("1. Function Declaration (Prototype): Tells the compiler about the function's name, return type, and parameters.\n");
    printf("2. Function Definition: Contains the actual code that defines what the function does.\n\n");
}

void basic_function_example(void) {
    printf("2. Basic Function Example\n");
    printf("-------------------------\n");
    printf("void greet(void) {\n");
    printf("    printf(\"Hello, World!\\n\");\n");
    printf("}\n\n");
    printf("Calling the function:\n");
    printf("greet();\n\n");
    
    // Actual function call
    void greet(void) {
        printf("Hello, World!\n");
    }
    greet();
    printf("\n");
}

void function_with_parameters(int a, int b) {
    printf("3. Function with Parameters\n");
    printf("---------------------------\n");
    printf("void function_with_parameters(int a, int b) {\n");
    printf("    printf(\"Sum: %%d\\n\", a + b);\n");
    printf("}\n\n");
    printf("Calling the function:\n");
    printf("function_with_parameters(5, 3);\n\n");
    printf("Result: Sum: %d\n\n", a + b);
}

int function_with_return(int a, int b) {
    printf("4. Function with Return Value\n");
    printf("-----------------------------\n");
    printf("int function_with_return(int a, int b) {\n");
    printf("    return a + b;\n");
    printf("}\n\n");
    printf("Calling the function:\n");
    printf("int result = function_with_return(5, 3);\n");
    printf("printf(\"Sum: %%d\\n\", result);\n\n");
    return a + b;
}

void function_declaration_vs_definition(void) {
    printf("5. Function Declaration vs Definition\n");
    printf("-------------------------------------\n");
    printf("// Function declaration (prototype)\n");
    printf("int add(int a, int b);\n\n");
    printf("// Function definition\n");
    printf("int add(int a, int b) {\n");
    printf("    return a + b;\n");
    printf("}\n\n");
    printf("Function declarations are typically placed in header files (.h),\n");
    printf("while definitions are in source files (.c).\n\n");
}

void function_parameters(void) {
    printf("6. Function Parameters\n");
    printf("----------------------\n");
    printf("- Pass by Value: Default in C, a copy of the argument is passed.\n");
    printf("- Pass by Reference: Achieved using pointers.\n");
    printf("- Const Parameters: Prevent modification of the parameter.\n");
    printf("- Default Parameters: Not supported in C (unlike C++).\n\n");
    printf("Example of pass by reference:\n");
    printf("void swap(int *a, int *b) {\n");
    printf("    int temp = *a;\n");
    printf("    *a = *b;\n");
    printf("    *b = temp;\n");
    printf("}\n\n");
}

void return_values(void) {
    printf("7. Return Values\n");
    printf("-----------------\n");
    printf("- Functions can return a single value of any data type.\n");
    printf("- To return multiple values, use pointers or structures.\n");
    printf("- void functions don't return a value.\n\n");
    printf("Example of returning multiple values:\n");
    printf("void min_max(int arr[], int size, int *min, int *max) {\n");
    printf("    *min = *max = arr[0];\n");
    printf("    for (int i = 1; i < size; i++) {\n");
    printf("        if (arr[i] < *min) *min = arr[i];\n");
    printf("        if (arr[i] > *max) *max = arr[i];\n");
    printf("    }\n");
    printf("}\n\n");
}

void static_functions(void) {
    printf("8. Static Functions\n");
    printf("-------------------\n");
    printf("Static functions have internal linkage and are only visible within their source file.\n\n");
    printf("static int private_function(int x) {\n");
    printf("    return x * 2;\n");
    printf("}\n\n");
    printf("Benefits:\n");
    printf("- Encapsulation: Hide implementation details\n");
    printf("- Avoid name conflicts in large projects\n\n");
}

void inline_functions(void) {
    printf("9. Inline Functions\n");
    printf("-------------------\n");
    printf("Inline functions suggest the compiler to insert the function's code directly at the call site.\n\n");
    printf("inline int max(int a, int b) {\n");
    printf("    return (a > b) ? a : b;\n");
    printf("}\n\n");
    printf("Benefits:\n");
    printf("- Can reduce function call overhead\n");
    printf("- Useful for small, frequently called functions\n");
    printf("Note: 'inline' is a suggestion to the compiler, not a command.\n\n");
}

void recursive_functions(int n) {
    printf("10. Recursive Functions\n");
    printf("----------------------\n");
    printf("Recursive functions call themselves to solve a problem.\n\n");
    printf("int factorial(int n) {\n");
    printf("    if (n <= 1) return 1;\n");
    printf("    return n * factorial(n - 1);\n");
    printf("}\n\n");
    printf("Example: factorial(%d) = ", n);
    
    int factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }
    printf("%d\n\n", factorial(n));
}

void function_pointers(void) {
    printf("11. Function Pointers\n");
    printf("---------------------\n");
    printf("Function pointers allow functions to be passed as arguments or stored in data structures.\n\n");
    printf("int (*operation)(int, int);\n");
    printf("int add(int a, int b) { return a + b; }\n");
    printf("int subtract(int a, int b) { return a - b; }\n\n");
    printf("operation = add;\n");
    printf("int result = operation(5, 3);  // result = 8\n\n");
    printf("operation = subtract;\n");
    printf("result = operation(5, 3);  // result = 2\n\n");
}

void variadic_functions(const char* format, ...) {
    printf("12. Variadic Functions\n");
    printf("-----------------------\n");
    printf("Variadic functions accept a variable number of arguments.\n\n");
    printf("void print_values(const char* format, ...) {\n");
    printf("    va_list args;\n");
    printf("    va_start(args, format);\n");
    printf("    vprintf(format, args);\n");
    printf("    va_end(args);\n");
    printf("}\n\n");
    printf("Example usage:\n");
    printf("print_values(\"%%d %%f %%s\\n\", 10, 3.14, \"Hello\");\n\n");
    
    // Actual variadic function implementation
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n\n");
}

void best_practices(void) {
    printf("13. Best Practices\n");
    printf("------------------\n");
    printf("- Use meaningful function names that describe their purpose\n");
    printf("- Keep functions small and focused on a single task\n");
    printf("- Use function prototypes to catch errors early\n");
    printf("- Document functions with comments explaining purpose, parameters, and return values\n");
    printf("- Use const for parameters that shouldn't be modified\n");
    printf("- Prefer returning error codes or using errno.h for error handling\n");
    printf("- Use static functions for internal helper functions\n");
    printf("- Avoid global variables; pass necessary data as parameters\n\n");
}

void common_pitfalls(void) {
    printf("14. Common Pitfalls\n");
    printf("-------------------\n");
    printf("- Forgetting to declare functions before use\n");
    printf("- Mismatching function signatures between declaration and definition\n");
    printf("- Incorrect use of return values (e.g., not checking return values)\n");
    printf("- Stack overflow due to excessive recursion\n");
    printf("- Memory leaks in functions that allocate memory\n");
    printf("- Accessing out-of-bounds array elements in functions\n");
    printf("- Using uninitialized variables in functions\n\n");
}

void advanced_tips(void) {
    printf("15. Advanced Tips and Optimizations\n");
    printf("-----------------------------------\n");
    printf("- Use tail recursion optimization for recursive functions\n");
    printf("- Consider inline functions for performance-critical code\n");
    printf("- Use restrict keyword for pointer parameters to aid compiler optimizations\n");
    printf("- Utilize function attributes like __attribute__((pure)) or __attribute__((const))\n");
    printf("- Implement function overloading using macro techniques (e.g., _Generic in C11)\n");
    printf("- Use function-like macros cautiously for very small, performance-critical operations\n");
    printf("- Employ link-time optimization (LTO) for cross-module optimizations\n\n");
}

void real_world_applications(void) {
    printf("16. Real-World Applications\n");
    printf("---------------------------\n");
    printf("- Callback functions in event-driven programming (e.g., GUI applications)\n");
    printf("- Signal handlers in system programming\n");
    printf("- Sorting and searching algorithms with custom comparator functions\n");
    printf("- Plugin architectures using function pointers\n");
    printf("- State machines in embedded systems\n");
    printf("- Mathematical modeling and simulations\n");
    printf("- Custom memory management with allocation and deallocation functions\n\n");
}

void integration_with_other_concepts(void) {
    printf("17. Integration with Other Concepts\n");
    printf("-----------------------------------\n");
    printf("- Object-Oriented Programming: Functions as methods in structs\n");
    printf("- Functional Programming: Higher-order functions and function composition\n");
    printf("- Concurrent Programming: Thread-safe function design\n");
    printf("- Module Systems: Organizing related functions into modules\n");
    printf("- Error Handling: Using functions for consistent error reporting\n");
    printf("- Memory Management: Custom allocator functions\n");
    printf("- Compiler Design: Abstract Syntax Tree (AST) traversal functions\n\n");
}

void faqs_and_troubleshooting(void) {
    printf("18. FAQs and Troubleshooting\n");
    printf("----------------------------\n");
    printf("Q: How do I return multiple values from a function?\n");
    printf("A: Use pointers as out parameters or return a struct.\n\n");
    printf("Q: Why am I getting a 'conflicting types' error?\n");
    printf("A: Ensure function declarations match definitions and are included before use.\n\n");
    printf("Q: How can I pass an array to a function?\n");
    printf("A: Pass a pointer to the array's first element and its size as separate parameters.\n\n");
    printf("Q: What's the difference between 'static' and 'extern' functions?\n");
    printf("A: 'static' limits the function's visibility to its file, while 'extern' makes it globally visible.\n\n");
    printf("Q: How do I debug a function that's crashing?\n");
    printf("A: Use a debugger to set breakpoints, step through the code, and inspect variables.\n\n");
}

void recommended_tools_and_libraries(void) {
    printf("19. Recommended Tools and Libraries\n");
    printf("-----------------------------------\n");
    printf("- GCC and Clang: Compilers with advanced optimization capabilities\n");
    printf("- GDB and LLDB: Powerful debuggers for inspecting function behavior\n");
    printf("- Valgrind: Memory debugging and profiling tool\n");
    printf("- AddressSanitizer: Runtime error detector for C/C++\n");
    printf("- Doxygen: Documentation generator for C functions\n");
    printf("- Unity: Unit testing framework for C\n");
    printf("- libffi: Foreign Function Interface library for working with functions at runtime\n");
    printf("- GNU Scientific Library (GSL): Collection of numerical computing functions\n");
    printf("- APR (Apache Portable Runtime): Cross-platform utility functions\n\n");
}