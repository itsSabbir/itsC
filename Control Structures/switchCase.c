#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Function prototypes
void overview_and_syntax(void);
void basic_switch_case(void);
void switch_with_fall_through(void);
void switch_with_ranges(void);
void nested_switch(void);
void switch_with_expressions(void);
void best_practices(void);
void common_pitfalls(void);
void advanced_tips(void);
void real_world_use_cases(void);
void integration_with_other_concepts(void);
void faqs_and_troubleshooting(void);
void recommended_tools_and_libraries(void);

int main() {
    printf("Expert-level Cheat Sheet: Control Structures (switch-case) in C\n\n");

    overview_and_syntax();
    basic_switch_case();
    switch_with_fall_through();
    switch_with_ranges();
    nested_switch();
    switch_with_expressions();
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
    printf("1. Overview and Syntax of switch-case in C\n");
    printf("------------------------------------------\n");
    printf("The switch-case statement in C is a control structure used for multi-way branching.\n");
    printf("It provides an efficient way to execute different code blocks based on the value of an expression.\n");
    printf("\nKey features:\n");
    printf("- Allows for multiple execution paths based on a single expression\n");
    printf("- More readable and often more efficient than long if-else chains\n");
    printf("- Works with integral types (int, char, enum) and some implementations support strings (GNU C)\n");
    printf("\nBasic syntax:\n");
    printf("switch (expression) {\n");
    printf("    case constant1:\n");
    printf("        // code block\n");
    printf("        break;\n");
    printf("    case constant2:\n");
    printf("        // code block\n");
    printf("        break;\n");
    printf("    default:\n");
    printf("        // code block\n");
    printf("}\n\n");
}

void basic_switch_case() {
    printf("2. Basic switch-case Example\n");
    printf("----------------------------\n");

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
            printf("Saturday\n");
            break;
        case 7:
            printf("Sunday\n");
            break;
        default:
            printf("Invalid day\n");
    }

    printf("\n");
}

void switch_with_fall_through() {
    printf("3. switch with Fall-through\n");
    printf("---------------------------\n");

    int grade = 2;

    switch (grade) {
        case 1:
            printf("Outstanding ");
            // Fall through
        case 2:
            printf("Excellent ");
            // Fall through
        case 3:
            printf("Good ");
            // Fall through
        case 4:
            printf("Fair\n");
            break;
        default:
            printf("Poor\n");
    }

    printf("\n");
}

void switch_with_ranges() {
    printf("4. switch with Ranges (using fall-through)\n");
    printf("------------------------------------------\n");

    int score = 85;

    switch (score / 10) {
        case 10:
        case 9:
            printf("Grade: A\n");
            break;
        case 8:
            printf("Grade: B\n");
            break;
        case 7:
            printf("Grade: C\n");
            break;
        case 6:
            printf("Grade: D\n");
            break;
        default:
            printf("Grade: F\n");
    }

    printf("\n");
}

void nested_switch() {
    printf("5. Nested switch Example\n");
    printf("------------------------\n");

    int department = 1;
    int year = 2;

    switch (department) {
        case 1: // Computer Science
            printf("Computer Science Department, ");
            switch (year) {
                case 1:
                    printf("First Year\n");
                    break;
                case 2:
                    printf("Second Year\n");
                    break;
                default:
                    printf("Advanced Year\n");
            }
            break;
        case 2: // Electrical Engineering
            printf("Electrical Engineering Department, ");
            switch (year) {
                case 1:
                    printf("First Year\n");
                    break;
                case 2:
                    printf("Second Year\n");
                    break;
                default:
                    printf("Advanced Year\n");
            }
            break;
        default:
            printf("Unknown Department\n");
    }

    printf("\n");
}

void switch_with_expressions() {
    printf("6. switch with Expressions (C23 feature)\n");
    printf("----------------------------------------\n");
    printf("Note: This feature requires C23 support. Example syntax:\n\n");
    printf("int result = switch (value) {\n");
    printf("    case 1: break 10;\n");
    printf("    case 2: break 20;\n");
    printf("    default: break 0;\n");
    printf("};\n\n");
    printf("As this feature is not widely supported yet, we'll simulate it with a function:\n\n");

    int value = 2;
    int result;

    switch (value) {
        case 1:
            result = 10;
            break;
        case 2:
            result = 20;
            break;
        default:
            result = 0;
    }

    printf("Result: %d\n\n", result);
}

void best_practices() {
    printf("7. Best Practices\n");
    printf("-----------------\n");
    printf("- Always include a default case to handle unexpected values\n");
    printf("- Use break statements consistently to prevent unintended fall-through\n");
    printf("- Comment intentional fall-through cases for clarity\n");
    printf("- Group related cases together for better readability\n");
    printf("- Use enums with switch statements for improved type safety\n");
    printf("- Keep case statements simple; move complex logic to separate functions\n");
    printf("- Use switch statements instead of long if-else chains when applicable\n");
    printf("- Consider using lookup tables for large sets of values\n\n");

    // Example of using enum with switch
    typedef enum {
        RED,
        GREEN,
        BLUE
    } Color;

    Color selected_color = GREEN;

    switch (selected_color) {
        case RED:
            printf("You selected red\n");
            break;
        case GREEN:
            printf("You selected green\n");
            break;
        case BLUE:
            printf("You selected blue\n");
            break;
        default:
            printf("Unknown color\n");
    }

    printf("\n");
}

void common_pitfalls() {
    printf("8. Common Pitfalls\n");
    printf("------------------\n");
    printf("- Forgetting break statements, causing unintended fall-through\n");
    printf("- Using non-constant expressions in case labels (not allowed in C)\n");
    printf("- Overlooking the default case, leading to unhandled scenarios\n");
    printf("- Duplicating code across multiple cases instead of using fall-through\n");
    printf("- Using switch statements with too many cases, reducing readability\n");
    printf("- Nesting switches too deeply, making code hard to understand\n");
    printf("- Forgetting that variables declared in one case are visible in subsequent cases\n\n");

    // Example of variable scope issue in switch
    int x = 5;
    switch (x) {
        case 5:
            {
                int y = 10; // y is visible in all subsequent cases
                printf("y is %d\n", y);
            }
            break;
        case 6:
            // Uncommenting the next line would cause a compilation error
            // printf("y is %d\n", y);
            break;
    }

    printf("\n");
}

void advanced_tips() {
    printf("9. Advanced Tips and Optimizations\n");
    printf("----------------------------------\n");
    printf("- Use jump tables for optimization (compiler usually does this automatically)\n");
    printf("- Consider using computed goto (GNU C extension) for performance-critical code\n");
    printf("- Use switch statements in expression context (C23 feature) for more concise code\n");
    printf("- Leverage fall-through behavior for implementing state machines\n");
    printf("- Use switch statements with bit flags for efficient multiple condition checking\n\n");

    // Example of using switch with bit flags
    typedef enum {
        FLAG_A = 1 << 0,
        FLAG_B = 1 << 1,
        FLAG_C = 1 << 2
    } Flags;

    Flags flags = FLAG_A | FLAG_C;

    switch (flags & (FLAG_A | FLAG_B)) {
        case FLAG_A:
            printf("Flag A is set\n");
            break;
        case FLAG_B:
            printf("Flag B is set\n");
            break;
        case FLAG_A | FLAG_B:
            printf("Both Flag A and B are set\n");
            break;
        default:
            printf("Neither Flag A nor B is set\n");
    }

    printf("\n");
}

void real_world_use_cases() {
    printf("10. Real-world Use Cases\n");
    printf("------------------------\n");
    printf("- Implementing command parsers in CLI applications\n");
    printf("- Handling different message types in network protocols\n");
    printf("- Implementing state machines in embedded systems\n");
    printf("- Menu-driven user interfaces in console applications\n");
    printf("- Dispatching events in event-driven architectures\n");
    printf("- Implementing simple calculators or interpreters\n\n");

    // Example: Simple calculator
    char operator = '+';
    int a = 10, b = 5, result;

    switch (operator) {
        case '+':
            result = a + b;
            break;
        case '-':
            result = a - b;
            break;
        case '*':
            result = a * b;
            break;
        case '/':
            result = (b != 0) ? (a / b) : 0;
            break;
        default:
            printf("Invalid operator\n");
            return;
    }

    printf("%d %c %d = %d\n", a, operator, b, result);
    printf("\n");
}

void integration_with_other_concepts() {
    printf("11. Integration with Other Concepts\n");
    printf("-----------------------------------\n");
    printf("- Combining with function pointers for dynamic dispatch\n");
    printf("- Using with enums for type-safe state machines\n");
    printf("- Integrating with error handling mechanisms\n");
    printf("- Applying in multi-threaded environments for task distribution\n");
    printf("- Utilizing in compiler design for lexical analysis\n\n");

    // Example: Function pointer dispatch
    typedef void (*operation)(int, int);

    void add(int a, int b) { printf("%d + %d = %d\n", a, b, a + b); }
    void subtract(int a, int b) { printf("%d - %d = %d\n", a, b, a - b); }
    void multiply(int a, int b) { printf("%d * %d = %d\n", a, b, a * b); }

    char op = '*';
    int x = 10, y = 5;
    operation func;

    switch (op) {
        case '+': func = add; break;
        case '-': func = subtract; break;
        case '*': func = multiply; break;
        default: func = NULL;
    }

    if (func) func(x, y);
    else printf("Invalid operation\n");

    printf("\n");
}

void faqs_and_troubleshooting() {
    printf("12. FAQs and Troubleshooting\n");
    printf("----------------------------\n");
    printf("Q: Can I use floating-point numbers in switch statements?\n");
    printf("A: No, switch statements in C only work with integral types (int, char, enum).\n\n");

    printf("Q: Why does my switch statement always execute all cases?\n");
    printf("A: You might be missing break statements at the end of each case.\n\n");

    printf("Q: Can I declare variables inside a case?\n");
    printf("A: Yes, but wrap the case in curly braces to create a new scope.\n\n");

    printf("Q: How can I handle multiple values in a single case?\n");
    printf("A: You can stack multiple case labels for the same code block.\n\n");

    printf("Q: Is switch faster than if-else?\n");
    printf("A: Often yes, especially for many cases, as compilers can optimize switches into jump tables.\n\n");

    printf("Q: Can I use strings in switch statements?\n");
    printf("A: Not in standard C, but some compilers (like GNU C) offer this as an extension.\n");

    printf("\n");
}

void recommended_tools_and_libraries() {
    printf("13. Recommended Tools and Libraries\n");
    printf("-----------------------------------\n");
    printf("- Static Analysis Tools:\n");
    printf("  * Cppcheck: Can detect issues like missing break statements\n");
    printf("  * Clang Static Analyzer: Part of the LLVM project, finds various C code issues\n\n");

    printf("- Debugging Tools:\n");
    printf("  * GDB (GNU Debugger): Useful for stepping through switch statements\n");
    printf("  * Valgrind: Can help detect memory issues that might occur in complex switch structures\n\n");

    printf("- Libraries for Advanced Control Flow:\n");
    printf("  * libcsm: A C library for implementing hierarchical state machines\n");
    printf("  * libfsm: A finite state machine library in C\n\n");

    printf("- Build Systems and Static Analysis Integration:\n");
    printf("  * CMake: Can integrate static analysis tools into the build process\n");
    printf("  * Make: Traditional build tool for C projects\n\n");

    printf("- IDEs with advanced C support:\n");
    printf("  * Visual Studio Code with C/C++ extension: Offers great debugging and IntelliSense\n");
    printf("  * CLion: JetBrains IDE with excellent C support and built-in static analysis\n");

    printf("\n");
}