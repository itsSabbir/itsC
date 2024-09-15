#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

// Function prototypes
void overview_and_syntax(void);
void basic_if_else(void);
void else_if_example(void);
void nested_if_else(void);
void switch_case_example(void);
void ternary_operator(void);
void short_circuit_evaluation(void);
void goto_example(void);
void best_practices(void);
void common_pitfalls(void);
void advanced_tips(void);
void real_world_use_cases(void);
void integration_with_other_concepts(void);
void faqs_and_troubleshooting(void);
void recommended_tools_and_libraries(void);

int main() {
    printf("Expert-level Cheat Sheet: Control Structures (if-else) in C\n\n");

    overview_and_syntax();
    basic_if_else();
    else_if_example();
    nested_if_else();
    switch_case_example();
    ternary_operator();
    short_circuit_evaluation();
    goto_example();
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
    printf("1. Overview and Syntax of Control Structures in C\n");
    printf("------------------------------------------------\n");
    printf("Control structures in C are programming constructs that allow you to control the flow of execution in your program.\n");
    printf("They are essential for decision-making and creating complex logic in your applications.\n");
    printf("The primary control structures in C are:\n");
    printf("- if-else statements\n");
    printf("- switch-case statements\n");
    printf("- loops (while, do-while, for)\n");
    printf("- goto statements (used sparingly)\n\n");

    printf("Basic syntax of an if-else statement:\n");
    printf("if (condition) {\n");
    printf("    // code to execute if condition is true\n");
    printf("} else {\n");
    printf("    // code to execute if condition is false\n");
    printf("}\n\n");
}

void basic_if_else() {
    printf("2. Basic if-else Example\n");
    printf("------------------------\n");

    int x = 10;

    if (x > 5) {
        printf("x is greater than 5\n");
    } else {
        printf("x is not greater than 5\n");
    }

    printf("\n");
}

void else_if_example() {
    printf("3. else-if Example\n");
    printf("------------------\n");

    int score = 75;

    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else if (score >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }

    printf("\n");
}

void nested_if_else() {
    printf("4. Nested if-else Example\n");
    printf("--------------------------\n");

    int age = 25;
    bool has_license = true;

    if (age >= 18) {
        if (has_license) {
            printf("You can drive a car\n");
        } else {
            printf("You're old enough, but you need a license to drive\n");
        }
    } else {
        printf("You're too young to drive\n");
    }

    printf("\n");
}

void switch_case_example() {
    printf("5. switch-case Example\n");
    printf("-----------------------\n");

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
        case 6:
        case 7:
            printf("Weekend\n");
            break;
        default:
            printf("Invalid day\n");
    }

    printf("\n");
}

void ternary_operator() {
    printf("6. Ternary Operator Example\n");
    printf("----------------------------\n");

    int x = 10;
    int y = 20;

    int max = (x > y) ? x : y;
    printf("The maximum of %d and %d is %d\n", x, y, max);

    printf("\n");
}

void short_circuit_evaluation() {
    printf("7. Short-circuit Evaluation\n");
    printf("---------------------------\n");

    int a = 5;
    int b = 0;

    // This will not cause a division by zero error due to short-circuit evaluation
    if (b != 0 && a / b > 2) {
        printf("This won't be printed\n");
    } else {
        printf("Short-circuit evaluation prevented a division by zero\n");
    }

    printf("\n");
}

void goto_example() {
    printf("8. goto Example (Use Sparingly)\n");
    printf("--------------------------------\n");

    int i = 0;

start:
    if (i < 5) {
        printf("%d ", i);
        i++;
        goto start;
    }

    printf("\nLoop using goto completed\n");
    printf("\n");
}

void best_practices() {
    printf("9. Best Practices\n");
    printf("-----------------\n");
    printf("- Keep conditions simple and readable\n");
    printf("- Use braces {} even for single-line blocks to improve readability and prevent errors\n");
    printf("- Avoid deep nesting of if-else statements (consider refactoring or using switch-case)\n");
    printf("- Use switch-case for multiple conditions on a single variable\n");
    printf("- Prefer positive conditions (if (is_valid) instead of if (!is_invalid))\n");
    printf("- Be cautious with short-circuit evaluation and ensure it doesn't hide bugs\n");
    printf("- Avoid using goto except in very specific scenarios (e.g., error handling in systems programming)\n");
    printf("\n");
}

void common_pitfalls() {
    printf("10. Common Pitfalls\n");
    printf("-------------------\n");
    printf("- Using = instead of == in conditions (assignment vs. comparison)\n");
    printf("- Forgetting break statements in switch-case (causing fall-through)\n");
    printf("- Overcomplicating conditions (consider breaking them down or using temporary variables)\n");
    printf("- Inconsistent formatting leading to misinterpretation of code structure\n");
    printf("- Redundant else statements when if block always returns or exits\n");
    printf("\n");
}

void advanced_tips() {
    printf("11. Advanced Tips and Optimizations\n");
    printf("-----------------------------------\n");
    printf("- Use lookup tables or switch statements instead of long if-else chains for better performance\n");
    printf("- Consider using bitwise operations for flag-based conditions\n");
    printf("- Use De Morgan's laws to simplify complex boolean expressions\n");
    printf("- Leverage compiler optimizations (e.g., -O2 or -O3 flags in GCC)\n");
    printf("- Use __builtin_expect() for branch prediction hints in performance-critical code\n");
    printf("\n");

    // Example of using __builtin_expect()
    int x = 10;
    if (__builtin_expect(x > 5, 1)) {
        printf("This branch is more likely to be taken\n");
    } else {
        printf("This branch is less likely to be taken\n");
    }

    printf("\n");
}

void real_world_use_cases() {
    printf("12. Real-world Use Cases\n");
    printf("------------------------\n");
    printf("- Input validation and error handling in user interfaces\n");
    printf("- State machines in embedded systems and game development\n");
    printf("- Access control and permission checking in security systems\n");
    printf("- Routing and request handling in web servers\n");
    printf("- Data processing and filtering in analytics applications\n");
    printf("\n");

    // Example: Simple state machine for a traffic light
    enum TrafficLightState { RED, YELLOW, GREEN };
    enum TrafficLightState current_state = RED;

    for (int i = 0; i < 6; i++) {
        switch (current_state) {
            case RED:
                printf("Traffic Light: Red - Stop\n");
                current_state = GREEN;
                break;
            case YELLOW:
                printf("Traffic Light: Yellow - Prepare to stop\n");
                current_state = RED;
                break;
            case GREEN:
                printf("Traffic Light: Green - Go\n");
                current_state = YELLOW;
                break;
        }
    }

    printf("\n");
}

void integration_with_other_concepts() {
    printf("13. Integration with Other Concepts\n");
    printf("-----------------------------------\n");
    printf("- Combining with loops for complex iterations and data processing\n");
    printf("- Using with function pointers for callback-based architectures\n");
    printf("- Integrating with error handling mechanisms (e.g., setjmp/longjmp for exception-like behavior)\n");
    printf("- Applying in multi-threaded environments for synchronization and atomic operations\n");
    printf("- Utilizing in preprocessor macros for conditional compilation\n");
    printf("\n");

    // Example: Function pointer based on condition
    typedef void (*operation)(int, int);

    void add(int a, int b) { printf("%d + %d = %d\n", a, b, a + b); }
    void subtract(int a, int b) { printf("%d - %d = %d\n", a, b, a - b); }

    bool should_add = true;
    operation op = should_add ? add : subtract;
    op(10, 5);

    printf("\n");
}

void faqs_and_troubleshooting() {
    printf("14. FAQs and Troubleshooting\n");
    printf("----------------------------\n");
    printf("Q: Why is my if statement always executing regardless of the condition?\n");
    printf("A: Check if you're using = (assignment) instead of == (comparison) in your condition.\n\n");

    printf("Q: How can I compare floating-point numbers in an if statement?\n");
    printf("A: Use an epsilon value for approximate equality: if (fabs(a - b) < EPSILON)\n\n");

    printf("Q: My switch statement is behaving unexpectedly. What could be wrong?\n");
    printf("A: Ensure you have break statements after each case, or you'll get fall-through behavior.\n\n");

    printf("Q: How can I make my if-else chains more efficient?\n");
    printf("A: Consider using switch statements or lookup tables for better performance with multiple conditions.\n\n");

    printf("Q: Is it okay to use goto in C?\n");
    printf("A: While goto is available, it's generally discouraged except for specific use cases like error handling in systems programming.\n");
    printf("\n");
}

void recommended_tools_and_libraries() {
    printf("15. Recommended Tools and Libraries\n");
    printf("-----------------------------------\n");
    printf("- Static Analysis Tools:\n");
    printf("  * Cppcheck: Detects various types of bugs and suggests improvements\n");
    printf("  * Clang Static Analyzer: Part of the LLVM project, finds bugs in C code\n\n");

    printf("- Debugging Tools:\n");
    printf("  * GDB (GNU Debugger): Powerful debugger for inspecting program state\n");
    printf("  * Valgrind: Memory debugging, memory leak detection, and profiling\n\n");

    printf("- Libraries for Advanced Control Flow:\n");
    printf("  * setjmp.h: Provides setjmp() and longjmp() for non-local jumps\n");
    printf("  * pthread.h: For multi-threaded applications with complex control flow\n\n");

    printf("- Build Systems and Static Analysis Integration:\n");
    printf("  * CMake: Cross-platform build system that can integrate static analysis\n");
    printf("  * Make: Traditional build tool for C projects\n");
    printf("\n");
}