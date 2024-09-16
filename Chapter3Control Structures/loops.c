#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <limits.h>

// Function prototypes
void overview_and_syntax(void);
void for_loop_basics(void);
void while_loop_basics(void);
void do_while_loop_basics(void);
void nested_loops(void);
void infinite_loops(void);
void loop_control_statements(void);
void best_practices(void);
void common_pitfalls(void);
void advanced_tips(void);
void real_world_use_cases(void);
void integration_with_other_concepts(void);
void faqs_and_troubleshooting(void);
void recommended_tools_and_libraries(void);

int main() {
    printf(" Cheat Sheet: Control Structures (Loops) in C\n\n");

    overview_and_syntax();
    for_loop_basics();
    while_loop_basics();
    do_while_loop_basics();
    nested_loops();
    infinite_loops();
    loop_control_statements();
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
    printf("1. Overview and Syntax of Loops in C\n");
    printf("------------------------------------\n");
    printf("Loops in C are control structures used for repetitive execution of a block of code.\n");
    printf("They are essential for tasks involving iteration, such as processing arrays, implementing algorithms, and handling data streams.\n");
    printf("\nC provides three main types of loops:\n");
    printf("1. for loop: Used when the number of iterations is known beforehand.\n");
    printf("2. while loop: Used when the loop should continue as long as a condition is true.\n");
    printf("3. do-while loop: Similar to while, but ensures the loop body is executed at least once.\n");
    printf("\nBasic syntax:\n");
    printf("for (initialization; condition; update) {\n");
    printf("    // code block\n");
    printf("}\n\n");
    printf("while (condition) {\n");
    printf("    // code block\n");
    printf("}\n\n");
    printf("do {\n");
    printf("    // code block\n");
    printf("} while (condition);\n\n");
}

void for_loop_basics() {
    printf("2. for Loop Basics\n");
    printf("------------------\n");
    printf("The for loop is used when we know the number of iterations in advance.\n");

    // Basic for loop
    printf("Counting from 1 to 5:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    // for loop with multiple expressions
    printf("Counting down from 10 to 0 by 2s:\n");
    for (int i = 10; i >= 0; i -= 2) {
        printf("%d ", i);
    }
    printf("\n\n");

    // for loop with comma operator
    printf("Using comma operator in for loop:\n");
    for (int i = 0, j = 10; i < 5; i++, j--) {
        printf("i: %d, j: %d\n", i, j);
    }
    printf("\n");
}

void while_loop_basics() {
    printf("3. while Loop Basics\n");
    printf("--------------------\n");
    printf("The while loop is used when we want to repeat a block of code as long as a condition is true.\n");

    // Basic while loop
    printf("Printing even numbers up to 10:\n");
    int num = 0;
    while (num <= 10) {
        printf("%d ", num);
        num += 2;
    }
    printf("\n\n");

    // while loop with complex condition
    printf("Finding the first power of 2 greater than 1000:\n");
    int power = 1;
    while (power <= 1000) {
        power *= 2;
    }
    printf("The first power of 2 greater than 1000 is: %d\n", power);
    printf("\n");
}

void do_while_loop_basics() {
    printf("4. do-while Loop Basics\n");
    printf("------------------------\n");
    printf("The do-while loop is similar to while, but it guarantees that the loop body is executed at least once.\n");

    // Basic do-while loop
    printf("Rolling a die until we get a 6:\n");
    int roll;
    int attempts = 0;
    do {
        roll = rand() % 6 + 1;
        attempts++;
        printf("Rolled a %d\n", roll);
    } while (roll != 6);
    printf("It took %d attempts to roll a 6.\n\n");
}

void nested_loops() {
    printf("5. Nested Loops\n");
    printf("---------------\n");
    printf("Nested loops are loops within loops, useful for working with multi-dimensional data or complex iterations.\n");

    // Example of nested loops: Printing a multiplication table
    printf("Multiplication table (1-5):\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            printf("%3d ", i * j);
        }
        printf("\n");
    }
    printf("\n");
}

void infinite_loops() {
    printf("6. Infinite Loops\n");
    printf("------------------\n");
    printf("Infinite loops are loops that run indefinitely. They can be useful in certain scenarios but often indicate a logical error.\n");

    printf("Examples of infinite loops:\n");
    printf("for (;;) { /* code */ }\n");
    printf("while (1) { /* code */ }\n");
    printf("do { /* code */ } while (true);\n\n");

    printf("Controlled infinite loop with break:\n");
    int counter = 0;
    while (1) {
        printf("%d ", counter++);
        if (counter >= 5) break;
    }
    printf("\n\n");
}

void loop_control_statements() {
    printf("7. Loop Control Statements\n");
    printf("---------------------------\n");
    printf("C provides statements to control the flow of loops:\n");
    printf("- break: Exits the loop immediately\n");
    printf("- continue: Skips the rest of the current iteration and moves to the next\n");
    printf("- goto: Jumps to a labeled statement (use with caution)\n\n");

    // Example of break and continue
    printf("Printing odd numbers up to 10, stopping at 7:\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) continue;
        if (i > 7) break;
        printf("%d ", i);
    }
    printf("\n\n");
}

void best_practices() {
    printf("8. Best Practices\n");
    printf("------------------\n");
    printf("- Choose the appropriate loop type for your use case\n");
    printf("- Keep loops simple and focused on a single task\n");
    printf("- Avoid modifying loop variables within the loop body (except in simple increments)\n");
    printf("- Use meaningful variable names for loop counters\n");
    printf("- Be cautious with floating-point comparisons in loop conditions\n");
    printf("- Consider using 'size_t' for array indices and sizes\n");
    printf("- Prefer for loops when the number of iterations is known\n");
    printf("- Use while loops for conditional iteration\n");
    printf("- Employ do-while loops when the body must execute at least once\n\n");

    // Example of using size_t for array iteration
    printf("Using size_t for array iteration:\n");
    int arr[] = {1, 2, 3, 4, 5};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n");
}

void common_pitfalls() {
    printf("9. Common Pitfalls\n");
    printf("-------------------\n");
    printf("- Off-by-one errors (e.g., using <= instead of < in for loops)\n");
    printf("- Infinite loops due to incorrect termination conditions\n");
    printf("- Mistakenly using assignment (=) instead of comparison (==) in conditions\n");
    printf("- Forgetting to update the loop variable in while loops\n");
    printf("- Unintended floating-point precision issues in loop conditions\n");
    printf("- Modifying loop variables within the loop body, leading to unexpected behavior\n");
    printf("- Neglecting to consider edge cases or boundary conditions\n\n");

    // Example of a common pitfall: off-by-one error
    printf("Correct vs. Incorrect array iteration:\n");
    int numbers[] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Correct: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("Incorrect (off-by-one error): ");
    for (int i = 0; i <= size; i++) {  // Note: <= instead of <
        printf("%d ", numbers[i]);  // This will access out-of-bounds memory
    }
    printf("\n\n");
}

void advanced_tips() {
    printf("10. Advanced Tips and Optimizations\n");
    printf("------------------------------------\n");
    printf("- Use loop unrolling for performance-critical code\n");
    printf("- Consider using Duff's device for optimized loop unrolling\n");
    printf("- Employ loop fusion to combine multiple loops when possible\n");
    printf("- Utilize loop invariant code motion to optimize performance\n");
    printf("- Use compiler pragmas and intrinsics for loop optimizations\n");
    printf("- Consider parallelization for computationally intensive loops\n");
    printf("- Employ cache-friendly access patterns in nested loops\n\n");

    // Example of loop unrolling
    printf("Loop unrolling example:\n");
    int sum = 0;
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Unrolled loop (unroll factor of 4)
    for (int i = 0; i < n; i += 4) {
        sum += numbers[i];
        if (i + 1 < n) sum += numbers[i + 1];
        if (i + 2 < n) sum += numbers[i + 2];
        if (i + 3 < n) sum += numbers[i + 3];
    }

    printf("Sum: %d\n\n", sum);
}

void real_world_use_cases() {
    printf("11. Real-world Use Cases\n");
    printf("--------------------------\n");
    printf("- Data processing and analysis in scientific computing\n");
    printf("- Implementing algorithms in computer graphics and game development\n");
    printf("- File I/O operations and parsing in system programming\n");
    printf("- Network packet processing in telecommunications\n");
    printf("- Iterative numerical methods in engineering simulations\n");
    printf("- Database query execution and optimization\n");
    printf("- Audio and video processing in multimedia applications\n\n");

    // Example: Simple moving average calculation
    printf("Calculating moving average of stock prices:\n");
    double prices[] = {100.0, 102.5, 101.5, 103.0, 104.5, 103.5, 105.0, 106.0};
    int window_size = 3;
    int n = sizeof(prices) / sizeof(prices[0]);

    for (int i = 0; i <= n - window_size; i++) {
        double sum = 0;
        for (int j = 0; j < window_size; j++) {
            sum += prices[i + j];
        }
        double average = sum / window_size;
        printf("Day %d-%d average: %.2f\n", i + 1, i + window_size, average);
    }
    printf("\n");
}

void integration_with_other_concepts() {
    printf("12. Integration with Other Concepts\n");
    printf("------------------------------------\n");
    printf("- Combining loops with dynamic memory allocation for flexible data structures\n");
    printf("- Using loops in recursive algorithms for tree traversal and graph search\n");
    printf("- Implementing state machines with loops for event-driven systems\n");
    printf("- Applying loops in multi-threaded environments for parallel processing\n");
    printf("- Utilizing loops in network programming for handling multiple connections\n");
    printf("- Employing loops in embedded systems for continuous sensor reading and control\n\n");

    // Example: Dynamic memory allocation with loops
    printf("Dynamic array resizing example:\n");
    int* dynamic_array = NULL;
    int capacity = 1;
    int size = 0;

    for (int i = 0; i < 10; i++) {
        if (size == capacity) {
            capacity *= 2;
            int* temp = realloc(dynamic_array, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Memory allocation failed\n");
                free(dynamic_array);
                return;
            }
            dynamic_array = temp;
        }
        dynamic_array[size++] = i * 10;
    }

    printf("Final array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", dynamic_array[i]);
    }
    printf("\n");
    free(dynamic_array);
    printf("\n");
}

void faqs_and_troubleshooting() {
    printf("13. FAQs and Troubleshooting\n");
    printf("-----------------------------\n");
    printf("Q: What's the difference between ++i and i++ in a for loop?\n");
    printf("A: In most cases, they're equivalent in a for loop. ++i pre-increments, i++ post-increments.\n\n");

    printf("Q: How can I iterate over an array in reverse order?\n");
    printf("A: Use a for loop with a decreasing counter: for (int i = size - 1; i >= 0; i--)\n\n");

    printf("Q: Why does my while loop never terminate?\n");
    printf("A: Check if the loop condition is being updated correctly inside the loop body.\n\n");

    printf("Q: How can I exit nested loops efficiently?\n");
    printf("A: Use a flag variable or goto statement (sparingly) to break out of multiple levels.\n\n");

    printf("Q: Is it okay to use goto in loops?\n");
    printf("A: While goto is generally discouraged, it can be useful for breaking out of nested loops.\n\n");

    printf("Q: How can I optimize my loops for better performance?\n");
    printf("A: Consider loop unrolling, minimizing work inside loops, using appropriate data types,\n");
    printf("   and ensuring good cache locality. Profile your code to identify bottlenecks.\n\n");

    printf("Q: When should I use a do-while loop instead of a while loop?\n");
    printf("A: Use do-while when you want to ensure the loop body executes at least once before checking the condition.\n\n");

    printf("Q: How can I prevent off-by-one errors in my loops?\n");
    printf("A: Be consistent with your loop boundaries. For arrays, use < size instead of <= size-1.\n");
    printf("   Double-check your initialization and termination conditions.\n\n");

    printf("Q: Is it safe to modify the loop variable inside the loop body?\n");
    printf("A: It's generally not recommended as it can lead to unexpected behavior. If necessary, document it clearly.\n\n");

    printf("Q: How can I iterate over a multi-dimensional array efficiently?\n");
    printf("A: Use nested loops, and consider the memory layout to optimize cache usage. For example, iterate\n");
    printf("   over rows first, then columns for row-major order arrays.\n\n");
}

void recommended_tools_and_libraries() {
    printf("14. Recommended Tools and Libraries\n");
    printf("------------------------------------\n");
    printf("- Static Analysis Tools:\n");
    printf("  * Cppcheck: Can detect various loop-related issues\n");
    printf("  * Clang Static Analyzer: Part of the LLVM project, finds complex bugs\n");
    printf("  * Coverity Scan: Advanced static analysis tool for detecting subtle issues\n\n");

    printf("- Profiling Tools:\n");
    printf("  * gprof: GNU profiler for analyzing program performance\n");
    printf("  * Valgrind: Suite of tools for debugging and profiling\n");
    printf("  * Intel VTune Profiler: Advanced profiling tool for Intel processors\n\n");

    printf("- Libraries for Advanced Looping:\n");
    printf("  * OpenMP: API for parallel programming, including parallel loops\n");
    printf("  * Intel TBB (Threading Building Blocks): C++ library for parallel programming\n");
    printf("  * BLAS (Basic Linear Algebra Subprograms): Efficient routines for vector and matrix operations\n\n");

    printf("- Build Systems and Optimization:\n");
    printf("  * CMake: Cross-platform build system with optimization options\n");
    printf("  * Autotools: GNU build system for portable package configuration\n\n");

    printf("- IDEs with Loop Analysis Features:\n");
    printf("  * Visual Studio Code with C/C++ extension: Offers code analysis and refactoring\n");
    printf("  * CLion: JetBrains IDE with powerful code analysis and refactoring tools\n");
    printf("  * Eclipse CDT: Open-source IDE with advanced C/C++ development features\n\n");

    printf("- Compiler-specific Tools:\n");
    printf("  * GCC's -fopt-info: Provides optimization reports\n");
    printf("  * Clang's -Rpass family: Gives detailed optimization reports\n");
    printf("  * MSVC's /Qvec-report: Reports auto-vectorization information\n\n");
}