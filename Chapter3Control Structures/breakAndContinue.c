#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void overview_and_syntax(void);
void basic_break_example(void);
void basic_continue_example(void);
void nested_loop_break(void);
void nested_loop_continue(void);
void break_in_switch(void);
void break_vs_return(void);
void labeled_break_simulation(void);
void best_practices(void);
void common_pitfalls(void);
void advanced_tips(void);
void real_world_use_cases(void);
void integration_with_other_concepts(void);
void faqs_and_troubleshooting(void);
void recommended_tools_and_libraries(void);

int main() {
    printf("Cheat Sheet: break and continue Statements in C\n\n");

    overview_and_syntax();
    basic_break_example();
    basic_continue_example();
    nested_loop_break();
    nested_loop_continue();
    break_in_switch();
    break_vs_return();
    labeled_break_simulation();
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
    printf("1. Overview and Syntax of break and continue Statements in C\n");
    printf("----------------------------------------------------------\n");
    printf("break and continue are control flow statements in C that alter the normal execution of loops.\n\n");
    
    printf("break:\n");
    printf("- Terminates the innermost enclosing loop or switch statement immediately.\n");
    printf("- Transfers control to the statement following the terminated statement.\n");
    printf("- Syntax: break;\n\n");
    
    printf("continue:\n");
    printf("- Skips the rest of the current iteration of a loop.\n");
    printf("- Jumps to the next iteration of the enclosing loop.\n");
    printf("- Syntax: continue;\n\n");
    
    printf("These statements are powerful tools for controlling loop execution and improving code efficiency.\n");
    printf("They are commonly used in loops (for, while, do-while) and switch statements (break only).\n\n");
}

void basic_break_example() {
    printf("2. Basic break Example\n");
    printf("----------------------\n");
    
    printf("Finding the first occurrence of 5 in an array:\n");
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int i;
    
    for (i = 0; i < size; i++) {
        if (numbers[i] == 5) {
            printf("Found 5 at index %d\n", i);
            break;  // Exit the loop once 5 is found
        }
    }
    
    if (i == size) {
        printf("5 was not found in the array\n");
    }
    
    printf("\n");
}

void basic_continue_example() {
    printf("3. Basic continue Example\n");
    printf("--------------------------\n");
    
    printf("Printing odd numbers from 1 to 10:\n");
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {
            continue;  // Skip even numbers
        }
        printf("%d ", i);
    }
    printf("\n\n");
}

void nested_loop_break() {
    printf("4. Nested Loop break Example\n");
    printf("-----------------------------\n");
    
    printf("Finding the first pair of numbers that multiply to give 50:\n");
    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i * j == 50) {
                printf("Found pair: %d * %d = 50\n", i, j);
                break;  // This only breaks the inner loop
            }
        }
        if (i * 10 >= 50) break;  // This breaks the outer loop
    }
    printf("\n");
}

void nested_loop_continue() {
    printf("5. Nested Loop continue Example\n");
    printf("--------------------------------\n");
    
    printf("Printing a multiplication table, skipping multiples of 3:\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 5; j++) {
            if (i * j % 3 == 0) {
                continue;  // Skip multiples of 3
            }
            printf("%2d ", i * j);
        }
        printf("\n");
    }
    printf("\n");
}

void break_in_switch() {
    printf("6. break in switch Statement\n");
    printf("-----------------------------\n");
    
    int day = 3;
    switch (day) {
        case 1:
            printf("Monday\n");
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thursday\n");
            break;
        case 5:
            printf("Friday\n");
            break;
        default:
            printf("Weekend\n");
    }
    printf("\n");
}

void break_vs_return() {
    printf("7. break vs return\n");
    printf("-------------------\n");
    printf("break: Exits only the innermost loop or switch.\n");
    printf("return: Exits the entire function.\n\n");
    
    printf("Example using break:\n");
    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            printf("Breaking at i = %d\n", i);
            break;
        }
        printf("i = %d\n", i);
    }
    printf("Reached end of function\n\n");
    
    // Note: We can't demonstrate return here as it would exit the entire program
    printf("If we used 'return' instead of 'break', the function would exit immediately.\n\n");
}

void labeled_break_simulation() {
    printf("8. Simulating Labeled break (not natively supported in C)\n");
    printf("--------------------------------------------------------\n");
    
    printf("Simulating a labeled break using a flag:\n");
    bool outer_break = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                printf("Breaking both loops at i = %d, j = %d\n", i, j);
                outer_break = true;
                break;
            }
            printf("i = %d, j = %d\n", i, j);
        }
        if (outer_break) break;
    }
    printf("\n");
}

void best_practices() {
    printf("9. Best Practices\n");
    printf("------------------\n");
    printf("- Use break and continue judiciously to improve code readability and efficiency.\n");
    printf("- Avoid overuse, as it can make code flow harder to follow.\n");
    printf("- Consider using early returns or guard clauses instead of deeply nested conditions.\n");
    printf("- In switch statements, always include a break after each case (unless fall-through is intended).\n");
    printf("- Use comments to explain the purpose of break or continue in complex scenarios.\n");
    printf("- When using break in nested loops, consider refactoring into a separate function for clarity.\n");
    printf("\n");
}

void common_pitfalls() {
    printf("10. Common Pitfalls\n");
    printf("-------------------\n");
    printf("- Forgetting to include break in switch statements, causing unintended fall-through.\n");
    printf("- Using continue in a switch statement (it's not allowed and will cause a compilation error).\n");
    printf("- Overusing break and continue, leading to spaghetti code.\n");
    printf("- Assuming break will exit all nested loops (it only exits the innermost loop).\n");
    printf("- Using break or continue outside of a loop or switch, which will cause a compilation error.\n");
    printf("\n");
}

void advanced_tips() {
    printf("11. Advanced Tips and Optimizations\n");
    printf("-----------------------------------\n");
    printf("- Use break to exit loops early when a condition is met, potentially saving unnecessary iterations.\n");
    printf("- In performance-critical code, consider unrolling loops and using break for early termination.\n");
    printf("- Use continue to skip expensive computations when certain conditions are met.\n");
    printf("- In multi-threaded environments, be cautious with break in critical sections to avoid deadlocks.\n");
    printf("- When dealing with large datasets, consider using break to implement early stopping in algorithms.\n");
    printf("\n");
    
    printf("Example: Optimized search using break\n");
    int data[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int target = 11;
    int found_index = -1;
    
    for (int i = 0; i < 10; i++) {
        if (data[i] == target) {
            found_index = i;
            break;  // Exit loop as soon as target is found
        }
        if (data[i] > target) {
            break;  // Exit loop if we've passed where the target would be (assuming sorted data)
        }
    }
    
    if (found_index != -1) {
        printf("Target %d found at index %d\n", target, found_index);
    } else {
        printf("Target %d not found\n", target);
    }
    printf("\n");
}

void real_world_use_cases() {
    printf("12. Real-world Use Cases\n");
    printf("------------------------\n");
    printf("1. Error handling and graceful exit in complex algorithms.\n");
    printf("2. Implementing state machines in embedded systems.\n");
    printf("3. Optimization in game development for collision detection.\n");
    printf("4. Data processing: skipping invalid entries in large datasets.\n");
    printf("5. Implementing timeout mechanisms in network programming.\n\n");
    
    printf("Example: Simple timeout mechanism\n");
    time_t start_time = time(NULL);
    int timeout_seconds = 5;
    int iterations = 0;
    
    while (1) {
        // Simulating some work
        iterations++;
        
        // Check for timeout
        if (difftime(time(NULL), start_time) >= timeout_seconds) {
            printf("Operation timed out after %d iterations\n", iterations);
            break;
        }
        
        // In a real scenario, you might do some actual work here
        // For this example, we'll just sleep for a short time
        #ifdef _WIN32
            Sleep(100);  // Windows sleep function (milliseconds)
        #else
            usleep(100000);  // POSIX sleep function (microseconds)
        #endif
    }
    printf("\n");
}

void integration_with_other_concepts() {
    printf("13. Integration with Other Concepts\n");
    printf("-----------------------------------\n");
    printf("- Error Handling: Using break in try-catch-like constructs (setjmp/longjmp in C).\n");
    printf("- Memory Management: Using break to exit loops early to free resources promptly.\n");
    printf("- Concurrency: Careful use of break in critical sections and lock-free algorithms.\n");
    printf("- Design Patterns: Implementing state machines and observer patterns.\n");
    printf("- Algorithms: Optimizing search and sort algorithms with strategic use of break.\n\n");
    
    printf("Example: Simple state machine using switch and break\n");
    enum State { STATE_IDLE, STATE_RUNNING, STATE_PAUSED, STATE_STOPPED };
    enum State current_state = STATE_IDLE;
    bool is_active = true;
    
    while (is_active) {
        switch (current_state) {
            case STATE_IDLE:
                printf("State: IDLE\n");
                current_state = STATE_RUNNING;
                break;
            case STATE_RUNNING:
                printf("State: RUNNING\n");
                current_state = STATE_PAUSED;
                break;
            case STATE_PAUSED:
                printf("State: PAUSED\n");
                current_state = STATE_STOPPED;
                break;
            case STATE_STOPPED:
                printf("State: STOPPED\n");
                is_active = false;
                break;
        }
    }
    printf("\n");
}

void faqs_and_troubleshooting() {
    printf("14. FAQs and Troubleshooting\n");
    printf("----------------------------\n");
    printf("Q: Can I use break to exit multiple nested loops at once?\n");
    printf("A: No, break only exits the innermost loop. Use a flag or goto for multi-level breaks.\n\n");
    
    printf("Q: Why doesn't continue work in a switch statement?\n");
    printf("A: continue is only for loops. In switch, use break to exit a case.\n\n");
    
    printf("Q: How can I simulate a 'break n' to break out of n levels of nested loops?\n");
    printf("A: Use a counter or multiple flags, or consider refactoring into a function.\n\n");
    
    printf("Q: Is it bad practice to use break in the middle of a loop?\n");
    printf("A: Not necessarily. It can improve readability and efficiency when used correctly.\n\n");
    
    printf("Q: How do break and continue affect loop counters?\n");
    printf("A: break exits the loop immediately. continue skips to the next iteration, updating the counter as normal.\n");
    printf("\n");
}

void recommended_tools_and_libraries() {
    printf("15. Recommended Tools and Libraries\n");
    printf("-----------------------------------\n");
    printf("1. Static Analysis Tools:\n");
    printf("   - Cppcheck: Can detect misuse of break and continue\n");
    printf("   - Clang Static Analyzer: Part of LLVM, helps identify control flow issues\n\n");
    
    printf("2. Dynamic Analysis Tools:\n");
    printf("   - Valgrind: Helps detect memory leaks that might occur due to improper loop exits\n");
    printf("   - GDB (GNU Debugger): Useful for stepping through code and examining loop behavior\n\n");
    
    printf("3. Code Formatting Tools:\n");
    printf("   - clang-format: Helps maintain consistent formatting around control structures\n");
    printf("   - Artistic Style (astyle): Another option for code formatting\n\n");
    
    printf("4. Code Complexity Analysis:\n");
    printf("   - lizard: Analyzes code complexity, including use of break and continue\n");
    printf("   - pmccabe: Calculates McCabe cyclomatic complexity\n\n");
    
    printf("5. IDEs with Advanced Code Analysis:\n");
    printf("   - Visual Studio Code with C/C++ extension\n");
    printf("   - CLion: Provides intelligent coding assistance and refactoring tools\n");
    printf("   - Eclipse CDT: Offers advanced C/C++ development features\n\n");
    
    printf("6. Version Control Integration:\n");
    printf("   - Git hooks: Can be used to run static analysis before commits\n");
    printf("   - Gerrit: Code review tool that can integrate with static analyzers\n\n");
    
    printf("7. Continuous Integration Tools:\n");
    printf("   - Jenkins: Can be configured to run static analysis and complexity metrics\n");
    printf("   - Travis CI or GitLab CI: Can automate testing and analysis in cloud environments\n\n");
    
    printf("8. Documentation Tools:\n");
    printf("   - Doxygen: Helps document complex control flows involving break and continue\n");
    printf("   - cflow: Generates C functions call graph, useful for understanding control flow\n\n");
    
    printf("9. Performance Profiling:\n");
    printf("   - gprof: Can help identify performance bottlenecks in loops\n");
    printf("   - Perf: Linux profiling tool for detailed performance analysis\n\n");
    
    printf("10. Code Coverage Tools:\n");
    printf("    - gcov: Helps ensure all code paths, including those with break and continue, are tested\n");
    printf("    - LCOV: Provides a graphical front-end for gcov\n\n");
    
    printf("Remember, while these tools can be helpful, they're no substitute for good coding practices and thorough code reviews.\n");
}