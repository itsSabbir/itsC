/*
Cheat Sheet: Relational and Logical Operators in C
===============================================================

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

1. Overview and Historical Context
==================================
Relational and logical operators in C are fundamental constructs used for comparing
values and combining logical expressions. They are essential for controlling program
flow and making decisions based on conditions.

Key points:
- Relational operators compare two values and return a boolean result.
- Logical operators combine boolean expressions.
- These operators have been part of C since its inception in the early 1970s.
- They provide a direct mapping to CPU instructions, allowing for efficient branching.

Relational Operators:
==  : Equal to
!=  : Not equal to
<   : Less than
>   : Greater than
<=  : Less than or equal to
>=  : Greater than or equal to

Logical Operators:
&&  : Logical AND
||  : Logical OR
!   : Logical NOT

Historical context:
- Inherited from B, C's predecessor language.
- Standardized in K&R C and later in ANSI C (C89/C90).
- Behavior further clarified in subsequent C standards (C99, C11, C17).

Relevance in modern software development:
- Crucial for implementing control structures (if, while, for loops).
- Essential for boolean algebra and complex decision-making in algorithms.
- Fundamental to all aspects of programming, from basic conditionals to complex logic.

Comparison to other languages:
- Similar syntax in C-derived languages (C++, Java, JavaScript).
- Some languages (e.g., Python) use words instead of symbols for some operators.
- C's operators are more low-level, directly reflecting hardware operations.

2. Syntax, Key Concepts, and Code Examples
==========================================
*/

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include <float.h>
#include <time.h>

// Function prototypes
void basic_relational_operators();
void basic_logical_operators();
void short_circuit_evaluation();
void operator_precedence();
void floating_point_comparisons();
void bitwise_logical_operations();
void complex_logical_expressions();
void performance_comparison();

int main() {
    printf("C Relational and Logical Operators Cheat Sheet\n");
    printf("==============================================\n\n");

    basic_relational_operators();
    basic_logical_operators();
    short_circuit_evaluation();
    operator_precedence();
    floating_point_comparisons();
    bitwise_logical_operations();
    complex_logical_expressions();
    performance_comparison();

    return 0;
}

void basic_relational_operators() {
    printf("2.1 Basic Relational Operators\n");
    printf("-------------------------------\n");

    int a = 5, b = 10;
    printf("Given a = %d and b = %d:\n", a, b);
    printf("a == b is %s\n", (a == b) ? "true" : "false");
    printf("a != b is %s\n", (a != b) ? "true" : "false");
    printf("a < b is %s\n", (a < b) ? "true" : "false");
    printf("a > b is %s\n", (a > b) ? "true" : "false");
    printf("a <= b is %s\n", (a <= b) ? "true" : "false");
    printf("a >= b is %s\n\n", (a >= b) ? "true" : "false");
}

void basic_logical_operators() {
    printf("2.2 Basic Logical Operators\n");
    printf("----------------------------\n");

    bool p = true, q = false;
    printf("Given p = true and q = false:\n");
    printf("p && q is %s\n", (p && q) ? "true" : "false");
    printf("p || q is %s\n", (p || q) ? "true" : "false");
    printf("!p is %s\n", (!p) ? "true" : "false");
    printf("!q is %s\n\n", (!q) ? "true" : "false");
}

void short_circuit_evaluation() {
    printf("2.3 Short-Circuit Evaluation\n");
    printf("-----------------------------\n");

    int x = 5, y = 0;

    // Demonstrating short-circuit AND
    if (y != 0 && x / y > 2) {
        printf("This won't be printed due to short-circuit evaluation.\n");
    } else {
        printf("Short-circuit AND avoided division by zero.\n");
    }

    // Demonstrating short-circuit OR
    if (x > 0 || x / y > 2) {
        printf("Short-circuit OR avoided division by zero.\n");
    }

    printf("\n");
}

void operator_precedence() {
    printf("2.4 Operator Precedence\n");
    printf("------------------------\n");

    int a = 5, b = 10, c = 15;
    bool result;

    result = a < b && b < c;
    printf("a < b && b < c is %s\n", result ? "true" : "false");

    result = a > b || b < c && a < c;
    printf("a > b || b < c && a < c is %s\n", result ? "true" : "false");

    result = (a > b || b < c) && a < c;
    printf("(a > b || b < c) && a < c is %s\n\n", result ? "true" : "false");
}

void floating_point_comparisons() {
    printf("2.5 Floating-Point Comparisons\n");
    printf("-------------------------------\n");

    float f1 = 0.1f;
    float f2 = 0.1f + 0.1f + 0.1f;
    float f3 = 0.3f;

    printf("f1 = %.20f\n", f1);
    printf("f2 = %.20f\n", f2);
    printf("f3 = %.20f\n", f3);

    printf("f2 == f3 is %s\n", (f2 == f3) ? "true" : "false");

    // Using an epsilon for float comparison
    const float EPSILON = 1e-6f;
    printf("fabs(f2 - f3) < EPSILON is %s\n\n", (fabs(f2 - f3) < EPSILON) ? "true" : "false");
}

void bitwise_logical_operations() {
    printf("2.6 Bitwise Logical Operations\n");
    printf("-------------------------------\n");

    unsigned int a = 0xF0, b = 0x0F;
    printf("a = 0x%X, b = 0x%X\n", a, b);
    printf("a & b = 0x%X\n", a & b);  // Bitwise AND
    printf("a | b = 0x%X\n", a | b);  // Bitwise OR
    printf("a ^ b = 0x%X\n", a ^ b);  // Bitwise XOR
    printf("~a = 0x%X\n\n", ~a);      // Bitwise NOT
}

bool is_power_of_two(unsigned int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

void complex_logical_expressions() {
    printf("2.7 Complex Logical Expressions\n");
    printf("--------------------------------\n");

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;

    // Linear search using logical operators
    bool found = false;
    for (int i = 0; i < size && !found; i++) {
        if (arr[i] == target) {
            found = true;
        }
    }
    printf("Target %d was %sfound in the array.\n", target, found ? "" : "not ");

    // Checking if a number is a power of two
    unsigned int num = 16;
    printf("%u is %sa power of two.\n", num, is_power_of_two(num) ? "" : "not ");

    // Complex condition for validating input
    int age = 25;
    bool has_id = true;
    bool is_valid_customer = (age >= 18 && age <= 65) && has_id;
    printf("Customer is %svalid.\n\n", is_valid_customer ? "" : "not ");
}

// Helper function for performance comparison
bool complex_condition(int x, int y, int z) {
    return (x > y && y > z) || (x < y && y < z) || (x == y && y != z);
}

void performance_comparison() {
    printf("2.8 Performance Comparison\n");
    printf("---------------------------\n");

    clock_t start, end;
    double cpu_time_used;
    int iterations = 100000000;
    int true_count = 0;

    start = clock();
    for (int i = 0; i < iterations; i++) {
        if (complex_condition(i % 100, (i + 1) % 100, (i + 2) % 100)) {
            true_count++;
        }
    }
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for %d iterations: %f seconds\n", iterations, cpu_time_used);
    printf("Number of true conditions: %d\n\n", true_count);
}

/*
3. Best Practices, Common Pitfalls, and Advanced Tips
=====================================================
Best Practices:
1. Use parentheses to clarify complex logical expressions.
2. Leverage short-circuit evaluation for efficiency and to avoid potential errors.
3. Be cautious when comparing floating-point numbers for equality.
4. Use meaningful variable names to make boolean expressions more readable.
5. Prefer positive logic over negative logic for better readability.

Common Pitfalls:
1. Confusing '==' (comparison) with '=' (assignment) in conditions.
2. Ignoring operator precedence, leading to unexpected results.
3. Assuming that logical operators work on bit-level (use bitwise operators instead).
4. Not accounting for potential integer overflow in comparisons.
5. Misusing the comma operator in place of logical operators.

Advanced Tips:
1. Use De Morgan's laws to simplify complex boolean expressions.
2. Implement branchless programming techniques using bitwise operations.
3. Utilize the ternary operator for concise conditional assignments.
4. Understand and leverage compiler optimizations for logical expressions.
5. Implement custom comparison functions for complex data structures.

Performance Considerations:
- Be aware that short-circuit evaluation can significantly impact performance.
- Understand the cost of branch misprediction in modern CPUs.
- Consider using lookup tables for complex boolean functions in performance-critical code.

Scalability Strategies:
- Implement efficient bitset operations for large-scale boolean data.
- Use bloom filters for probabilistic set membership tests in large datasets.
- Consider parallel evaluation of independent logical expressions.

Edge Case Handling:
- Be cautious with comparisons involving INT_MIN and INT_MAX.
- Handle potential overflow when comparing unsigned integers.
- Implement robust error checking for input validation using logical operators.

Memory Management Tips:
- Use bitfields in structures to save memory for boolean flags.
- Be aware of potential cache effects when evaluating large boolean arrays.
- Utilize memory-mapped I/O efficiently with bitwise operations.

Testability:
- Write unit tests covering all branches of complex logical expressions.
- Use property-based testing to verify logical invariants.
- Implement fuzzing techniques to uncover edge cases in logical operations.

4. Integration and Real-World Applications
==========================================
Integration with Major Concepts:
- Control Structures: Fundamental to if statements, loops, and switch cases.
- Data Validation: Essential for input checking and error handling.
- State Machines: Used in implementing transitions and conditions.
- Query Systems: Core component of database query languages and filters.

Real-World Examples:
1. Network Protocols: Implementing packet validation and routing decisions.
2. Financial Systems: Evaluating complex conditions for trading algorithms.
3. Game Engines: Collision detection and AI decision making.
4. Operating Systems: Process scheduling and resource allocation.
5. Compilers: Implementing optimization passes and code analysis.

Use in Open-Source Projects:
- Linux Kernel: Extensive use in device drivers and system calls.
- SQLite: Core part of the query execution engine.
- Git: Used in diff algorithms and merge conflict resolution.

Language-Specific Idioms:
- Using bitwise operations for efficient flag handling.
- Implementing state machines with switch statements and logical operators.
- Leveraging the comma operator for complex initializations in for loops.

5. Advanced Concepts and Emerging Trends
========================================
- Quantum Computing: Exploring quantum logic gates and their classical simulations.
- Fuzzy Logic: Implementing multi-valued logic systems beyond binary.
- Machine Learning: Using logical operations in feature engineering and decision trees.
- Formal Verification: Applying logical proofs to software correctness.
- Probabilistic Programming: Integrating logical operations with probability theory.

6. FAQs and Troubleshooting
===========================
Q: How do I avoid division by zero when using logical operators?
A: Leverage short-circuit evaluation: (denominator != 0 && numerator / denominator > 0)

Q: What's the best way to compare floating-point numbers?
A: Use an epsilon-based comparison: fabs(a - b) < EPSILON

Q: How can I optimize a series of if-else statements?
A: Consider using switch statements, lookup tables, or bitwise operations depending on the scenario.

Troubleshooting Guide:
1. Unexpected Results: Check operator precedence and use parentheses to clarify.
2. Performance Issues: Profile code and consider reordering conditions for better short-circuiting.
3. Logical Errors: Use truth tables to verify complex boolean expressions.

Debugging Tips:
- Use assert() statements to check logical invariants during development.
- Leverage compiler warnings (-Wall -Wextra) to catch potential logical issues.
- Use debugger watchpoints to monitor changes in boolean variables.

7. Recommended Tools, Libraries, and Resources
==============================================
Tools:
- Clang Static Analyzer: Detects logical errors and unreachable code.
- Valgrind: Helps identify undefined behavior in logical operations.
- CppCheck: Static analysis tool that can find logical inconsistencies.

Libraries:
- Boost.Logic: Provides advanced logical operations and data structures.
- GNU MPFR: For precise floating-point comparisons in critical applications.

Resources:
- "Hacker's Delight" by Henry S. Warren, Jr. for bit-level logical operations.
- "The Art of Computer Programming, Vol. 4A" by Donald Knuth for boolean function theory.
- IEEE 754 standard for understanding floating-point comparisons.

8. Performance Analysis and Optimization
========================================
Profiling Techniques:
- Use performance counters to measure branch mispredictions.
- Implement A/B testing for different logical expression formulations.

Optimization Strategies:
- Reorder conditions to maximize short-circuit evaluation benefits.
- Use lookup tables for complex boolean functions.
- Leverage CPU branch prediction hints where available.

Performance Trade-offs:
- Balance between code readability and performance optimization.
- Consider the cost of branch misprediction vs. the complexity of branchless code.
- Evaluate the memory usage of lookup tables against their performance benefits.
- Weigh the benefits of short-circuit evaluation against consistent execution time requirements.

Example of optimizing a complex condition:
*/

// Original function
bool is_valid_input(int x, int y, int z) {
    return (x > 0 && y > 0 && z > 0) && (x + y > z) && (y + z > x) && (z + x > y);
}

// Optimized function
bool is_valid_input_optimized(int x, int y, int z) {
    if (x <= 0 || y <= 0 || z <= 0) return false;
    int sum = x + y + z;
    int max = (x > y) ? ((x > z) ? x : z) : ((y > z) ? y : z);
    return sum > 2 * max;
}

/*
The optimized version reduces the number of comparisons and leverages early returns
for invalid inputs, potentially improving performance, especially for invalid cases.

9. How to Contribute
====================
To contribute to this cheat sheet:
1. Fork the repository containing this file.
2. Make your changes or additions, ensuring they follow the established style and format.
3. Add your name to the contributors list below.
4. Submit a pull request with a clear description of your changes.

When contributing, consider the following:
- Ensure all code examples are correct and follow best practices.
- Provide clear explanations for complex concepts.
- Include practical, real-world examples where possible.
- Keep the content up-to-date with the latest C standards and best practices.
- Add relevant references or citations for advanced topics.

Contributors:
- [Your Name Here]

Remember to always test your code examples and verify the accuracy of any added information.

---

This cheat sheet serves as a comprehensive guide to relational and logical operators in C.
It covers fundamental concepts, advanced techniques, and practical applications, making it
a valuable resource for C programmers at all skill levels. As the language and its usage
evolve, contributions from the community will help keep this guide relevant and useful.

*/