#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <float.h>
#include <complex.h>

// Macro constants
#define PI 3.14159265358979323846
#define MAX_BUFFER_SIZE 1024

// Global variables (use sparingly)
int global_variable = 10;

// Function prototypes
void overview_and_syntax(void);
void basic_data_types(void);
void variables_and_constants(void);
void type_qualifiers(void);
void operators_and_expressions(void);
void type_conversion(void);
void best_practices(void);
void common_pitfalls(void);
void advanced_tips(void);
void real_world_use_cases(void);
void integration_with_other_concepts(void);
void faqs_and_troubleshooting(void);
void recommended_tools_and_libraries(void);

int main() {
    printf("Expert-level Cheat Sheet: Basic Syntax, Data Types, Variables, and Constants in C\n\n");

    overview_and_syntax();
    basic_data_types();
    variables_and_constants();
    type_qualifiers();
    operators_and_expressions();
    type_conversion();
    best_practices();
    common_pitfalls();
    advanced_tips();
    real_world_use_cases();
    integration_with_other_concepts();
    faqs_and_troubleshooting();
    recommended_tools_and_libraries();

    return 0;
}

void overview_and_syntax() {
    printf("1. Overview and Basic Syntax\n");
    printf("----------------------------\n");
    printf("C is a general-purpose, procedural programming language known for its efficiency and low-level control.\n");
    printf("Key features of C syntax:\n");
    printf("- Case-sensitive\n");
    printf("- Statements end with semicolons ';'\n");
    printf("- Blocks of code are enclosed in curly braces '{}'\n");
    printf("- Comments: // for single-line, /* */ for multi-line\n");
    printf("- Functions are the basic building blocks of C programs\n\n");

    // Basic syntax example
    int x = 5;
    if (x > 0) {
        printf("This is a basic syntax example.\n");
        /* This is a multi-line comment
           demonstrating block structure */
    }
    printf("\n");
}

void basic_data_types() {
    printf("2. Basic Data Types\n");
    printf("-------------------\n");

    // Integer types
    printf("Integer types:\n");
    printf("char: %zu bytes, range: %d to %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("short: %zu bytes, range: %d to %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("int: %zu bytes, range: %d to %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("long: %zu bytes, range: %ld to %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("long long: %zu bytes, range: %lld to %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);

    // Floating-point types
    printf("\nFloating-point types:\n");
    printf("float: %zu bytes, range: %e to %e\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("double: %zu bytes, range: %e to %e\n", sizeof(double), DBL_MIN, DBL_MAX);
    printf("long double: %zu bytes, range: %Le to %Le\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

    // Other types
    printf("\nOther types:\n");
    printf("_Bool: %zu byte(s)\n", sizeof(_Bool));
    printf("size_t: %zu bytes (unsigned integer type)\n", sizeof(size_t));
    printf("void: incomplete type, used in function returns and generic pointers\n");

    // Complex types (C99 and later)
    printf("\nComplex types (C99+):\n");
    printf("float _Complex: %zu bytes\n", sizeof(float _Complex));
    printf("double _Complex: %zu bytes\n", sizeof(double _Complex));
    printf("long double _Complex: %zu bytes\n", sizeof(long double _Complex));

    printf("\n");
}

void variables_and_constants() {
    printf("3. Variables and Constants\n");
    printf("---------------------------\n");

    // Variable declaration and initialization
    int a;          // Declaration
    int b = 5;      // Declaration with initialization
    a = 10;         // Assignment

    // Constants
    const int MAX_VALUE = 100;  // Compile-time constant
    enum Days {MON, TUE, WED, THU, FRI, SAT, SUN};  // Enumeration constant

    // Storage classes
    auto int x = 10;        // Default for local variables (keyword often omitted)
    register int y = 20;    // Hint for compiler to use CPU register (may be ignored)
    static int count = 0;   // Retains value between function calls

    // Demonstrate variable scope
    {
        int local_var = 30;  // Block-scoped variable
        printf("local_var: %d\n", local_var);
    }
    // printf("local_var: %d\n", local_var);  // This would cause a compilation error

    printf("Global variable: %d\n", global_variable);
    printf("Constant: %d\n", MAX_VALUE);
    printf("Enumeration constant: %d\n", WED);

    printf("\n");
}

void type_qualifiers() {
    printf("4. Type Qualifiers\n");
    printf("------------------\n");

    // const: value cannot be changed after initialization
    const int FIXED_VALUE = 100;
    // FIXED_VALUE = 200;  // This would cause a compilation error

    // volatile: value can change unexpectedly (e.g., hardware registers)
    volatile int sensor_value;

    // restrict: pointer is the only way to access the object it points to (C99+)
    int * restrict ptr = (int *)malloc(sizeof(int));
    *ptr = 10;
    printf("Value pointed to by restrict pointer: %d\n", *ptr);
    free(ptr);

    // _Atomic: ensures atomic access in concurrent programming (C11+)
    _Atomic int atomic_counter = 0;

    printf("\n");
}

void operators_and_expressions() {
    printf("5. Operators and Expressions\n");
    printf("----------------------------\n");

    int a = 10, b = 3;

    // Arithmetic operators
    printf("Arithmetic: %d + %d = %d, %d - %d = %d, %d * %d = %d, %d / %d = %d, %d %% %d = %d\n",
           a, b, a + b, a, b, a - b, a, b, a * b, a, b, a / b, a, b, a % b);

    // Relational operators
    printf("Relational: %d > %d is %d, %d <= %d is %d\n",
           a, b, a > b, a, b, a <= b);

    // Logical operators
    printf("Logical: (%d > 0) && (%d < 0) is %d\n", a, b, (a > 0) && (b < 0));

    // Bitwise operators
    printf("Bitwise: %d & %d = %d, %d | %d = %d, %d ^ %d = %d, ~%d = %d\n",
           a, b, a & b, a, b, a | b, a, b, a ^ b, a, ~a);

    // Shift operators
    printf("Shift: %d << 1 = %d, %d >> 1 = %d\n", a, a << 1, a, a >> 1);

    // Increment/Decrement
    int c = a++;
    int d = --b;
    printf("Increment/Decrement: a++ results in c = %d, --b results in d = %d\n", c, d);

    // Conditional operator
    int max = (a > b) ? a : b;
    printf("Conditional: max of %d and %d is %d\n", a, b, max);

    printf("\n");
}

void type_conversion() {
    printf("6. Type Conversion\n");
    printf("------------------\n");

    // Implicit conversion
    int i = 10;
    double d = i;  // int to double
    printf("Implicit int to double: %d to %f\n", i, d);

    // Explicit conversion (casting)
    double pi = 3.14159;
    int rounded = (int)pi;  // double to int
    printf("Explicit double to int: %f to %d\n", pi, rounded);

    // Potential loss of data
    long long big_num = 1234567890123LL;
    int truncated = (int)big_num;
    printf("Potential data loss: %lld to %d\n", big_num, truncated);

    // Unsigned to signed conversion
    unsigned int u = 4294967295U;  // Maximum value for 32-bit unsigned int
    int s = u;
    printf("Unsigned to signed: %u to %d\n", u, s);

    printf("\n");
}

void best_practices() {
    printf("7. Best Practices\n");
    printf("------------------\n");
    printf("- Use meaningful variable names\n");
    printf("- Initialize variables before use\n");
    printf("- Use const for values that shouldn't change\n");
    printf("- Be cautious with implicit type conversions\n");
    printf("- Use appropriate data types for the task\n");
    printf("- Avoid global variables when possible\n");
    printf("- Use enums for related constants\n");
    printf("- Be consistent with naming conventions\n");
    printf("- Comment your code, especially for complex logic\n");
    printf("- Use parentheses to clarify operator precedence\n");
    printf("\n");
}

void common_pitfalls() {
    printf("8. Common Pitfalls\n");
    printf("------------------\n");
    printf("- Integer division truncation\n");
    printf("- Uninitialized variables\n");
    printf("- Off-by-one errors in loops and arrays\n");
    printf("- Confusing assignment (=) with equality comparison (==)\n");
    printf("- Ignoring compiler warnings\n");
    printf("- Buffer overflows\n");
    printf("- Memory leaks\n");
    printf("- Undefined behavior due to sequence points\n");
    printf("- Assuming specific sizes for data types\n");
    printf("- Failing to check for integer overflow\n");
    printf("\n");
}

void advanced_tips() {
    printf("9. Advanced Tips and Optimizations\n");
    printf("----------------------------------\n");
    printf("- Use bitfields for space-efficient structs\n");
    printf("- Leverage compiler-specific attributes for optimization\n");
    printf("- Use inline functions for performance-critical code\n");
    printf("- Understand and utilize cache-friendly data structures\n");
    printf("- Use function pointers for flexible designs\n");
    printf("- Implement custom memory management for performance\n");
    printf("- Utilize SIMD instructions for parallel data processing\n");
    printf("- Use volatile for memory-mapped I/O\n");
    printf("- Understand and leverage undefined behavior for optimization\n");
    printf("- Use flexible array members for variable-length structures\n");
    printf("\n");

    // Example of bitfields
    struct Flags {
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
    } flags = {1, 0, 1};

    printf("Bitfields example: %zu bytes\n", sizeof(flags));

    // Example of inline function
    inline int max(int a, int b) {
        return (a > b) ? a : b;
    }
    printf("Inline function result: %d\n", max(10, 20));

    printf("\n");
}

void real_world_use_cases() {
    printf("10. Real-world Use Cases\n");
    printf("------------------------\n");
    printf("- Embedded systems programming\n");
    printf("- Operating system kernels\n");
    printf("- Device drivers\n");
    printf("- Game development (especially game engines)\n");
    printf("- High-performance computing and scientific simulations\n");
    printf("- Database management systems\n");
    printf("- Compiler design\n");
    printf("- Network protocol implementations\n");
    printf("- Signal processing and real-time systems\n");
    printf("- Cryptography and security software\n");
    printf("\n");

    // Example: Simple data structure for a linked list node
    struct Node {
        int data;
        struct Node* next;
    };

    // Create a simple linked list
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 1;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = NULL;

    printf("Linked list example: %d -> %d -> NULL\n", head->data, head->next->data);

    // Clean up
    free(head->next);
    free(head);

    printf("\n");
}

void integration_with_other_concepts() {
    printf("11. Integration with Other Concepts\n");
    printf("-----------------------------------\n");
    printf("- Memory management and dynamic allocation\n");
    printf("- Pointers and data structures\n");
    printf("- File I/O and system calls\n");
    printf("- Multithreading and concurrency\n");
    printf("- Networking and socket programming\n");
    printf("- Interfacing with assembly language\n");
    printf("- Integration with other languages (e.g., C++, Python via extensions)\n");
    printf("- Low-level hardware manipulation\n");
    printf("- Signal handling and process control\n");
    printf("- Cross-platform development considerations\n");
    printf("\n");
}

void faqs_and_troubleshooting() {
    printf("12. FAQs and Troubleshooting\n");
    printf("----------------------------\n");
    printf("Q: What's the difference between 'int' and 'long'?\n");
    printf("A: The size of 'int' and 'long' can vary by platform. Use <stdint.h> for fixed-size integers.\n\n");

    printf("Q: How do I properly use 'const' with pointers?\n");
    printf("A: 'const int *p' means the int is const, 'int * const p' means the pointer is const.\n\n");

    printf("Q: Why am I getting 'segmentation fault'?\n");
    printf("A: Common causes include dereferencing NULL pointers, buffer overflows, or stack overflow.\n\n");

    printf("Q: How can I check for integer overflow?\n");
    printf("A: Use library functions like 'sadd_overflow' from <stdckdint.h> (C23) or implement custom checks.\n\n");

    printf("Q: What's the difference between 'malloc' and 'calloc'?\n");
    printf("A: 'malloc' allocates uninitialized memory, while 'calloc' initializes the allocated memory to zero.\n\n");

    printf("Q: How do I properly free memory in C?\n");
    printf("A: Use 'free()' for each successful 'malloc()', 'calloc()', or 'realloc()' call. Set the pointer to NULL after freeing.\n\n");

    printf("Q: What does 'static' mean in C?\n");
    printf("A: 'static' has different meanings: for local variables, it retains value between calls; for global variables/functions, it limits scope to the file.\n\n");

    printf("Q: How can I handle platform-dependent code?\n");
    printf("A: Use preprocessor directives like #ifdef, #ifndef, #if defined(), etc., along with predefined macros.\n\n");

    printf("Q: Why is my floating-point comparison not working as expected?\n");
    printf("A: Due to precision issues, use an epsilon value for approximate equality: if (fabs(a - b) < EPSILON)\n");

    printf("\n");
}

void recommended_tools_and_libraries() {
    printf("13. Recommended Tools and Libraries\n");
    printf("------------------------------------\n");
    printf("Compilers:\n");
    printf("- GCC (GNU Compiler Collection): Widely used, supports many platforms\n");
    printf("- Clang: Part of the LLVM project, known for fast compilation and helpful error messages\n");
    printf("- MSVC (Microsoft Visual C++): Preferred for Windows development\n\n");

    printf("Build tools:\n");
    printf("- Make: Traditional build automation tool\n");
    printf("- CMake: Cross-platform build system generator\n");
    printf("- Ninja: Fast, small build system alternative to Make\n\n");

    printf("Debugging tools:\n");
    printf("- GDB (GNU Debugger): Powerful command-line debugger\n");
    printf("- LLDB: Part of the LLVM project, alternative to GDB\n");
    printf("- Valgrind: For memory debugging, memory leak detection, and profiling\n\n");

    printf("Static analysis tools:\n");
    printf("- Cppcheck: Detects bugs, unusual code, and unsafe constructs\n");
    printf("- Clang Static Analyzer: Deep analysis tool for finding bugs\n");
    printf("- SonarQube: Platform for continuous inspection of code quality\n\n");

    printf("Libraries:\n");
    printf("- Standard C library (libc): Essential C functions (stdio.h, stdlib.h, etc.)\n");
    printf("- GLib: General-purpose utility library\n");
    printf("- libuv: Multi-platform support library with focus on asynchronous I/O\n");
    printf("- OpenSSL: Toolkit for the Transport Layer Security (TLS) protocols\n");
    printf("- SQLite: Lightweight, file-based database engine\n\n");

    printf("Documentation tools:\n");
    printf("- Doxygen: Generate documentation from source code\n");
    printf("- Man pages: Traditional Unix documentation system\n\n");

    printf("Version control:\n");
    printf("- Git: Distributed version control system\n");
    printf("- SVN: Centralized version control system\n\n");

    printf("IDE and text editors:\n");
    printf("- Visual Studio Code: Lightweight, extensible editor with C/C++ support\n");
    printf("- CLion: Dedicated C/C++ IDE by JetBrains\n");
    printf("- Vim/Emacs: Powerful, customizable text editors popular among experienced developers\n");

    printf("\n");
}