#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void overview_of_recursion(void);
int factorial(int n);
int fibonacci(int n);
void print_binary(unsigned int n);
int sum_of_digits(int n);
int ackermann(int m, int n);
char* reverse_string(char* str);
int binary_search(int arr[], int left, int right, int x);
void quicksort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod);
void flood_fill(int screen[][5], int m, int n, int x, int y, int prevColor, int newColor);
void print_screen(int screen[][5], int m, int n);
void tail_recursion_example(int n);
void best_practices_and_pitfalls(void);
void advanced_tips_and_optimizations(void);
void integration_and_real_world_applications(void);
void faqs_and_troubleshooting(void);
void recommended_tools_and_libraries(void);

int main() {
    printf("Expert-level Cheat Sheet: Functions - Recursion in C\n\n");

    overview_of_recursion();

    // Basic recursion examples
    printf("Factorial of 5: %d\n", factorial(5));
    printf("6th Fibonacci number: %d\n", fibonacci(6));
    
    printf("Binary representation of 13: ");
    print_binary(13);
    printf("\n");

    printf("Sum of digits of 12345: %d\n", sum_of_digits(12345));

    // More advanced recursion examples
    printf("Ackermann(3, 2): %d\n", ackermann(3, 2));

    char str[] = "Hello, World!";
    printf("Reversed string: %s\n", reverse_string(str));

    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    int result = binary_search(arr, 0, n - 1, x);
    printf("Element %d is %s in the array\n", x, (result == -1) ? "not present" : "present at index " + result);

    int arr2[] = {10, 7, 8, 9, 1, 5};
    n = sizeof(arr2) / sizeof(arr2[0]);
    quicksort(arr2, 0, n - 1);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    printf("Tower of Hanoi with 3 disks:\n");
    tower_of_hanoi(3, 'A', 'C', 'B');

    int screen[5][5] = {
        {1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1}
    };
    printf("Original screen:\n");
    print_screen(screen, 5, 5);
    flood_fill(screen, 5, 5, 2, 2, 1, 2);
    printf("Screen after flood fill:\n");
    print_screen(screen, 5, 5);

    printf("Tail recursion example:\n");
    tail_recursion_example(5);

    best_practices_and_pitfalls();
    advanced_tips_and_optimizations();
    integration_and_real_world_applications();
    faqs_and_troubleshooting();
    recommended_tools_and_libraries();

    return 0;
}

void overview_of_recursion() {
    printf("1. Overview of Recursion\n");
    printf("------------------------\n");
    printf("Recursion is a programming technique where a function calls itself to solve a problem.\n");
    printf("It's based on the principle of solving a complex problem by breaking it down into simpler subproblems.\n");
    printf("Key characteristics of recursion:\n");
    printf("- Base case: The condition that stops the recursion\n");
    printf("- Recursive case: The part where the function calls itself\n");
    printf("- Progress towards the base case: Each recursive call should move closer to the base case\n");
    printf("\nCommon use cases:\n");
    printf("- Tree and graph traversal\n");
    printf("- Divide and conquer algorithms (e.g., quicksort, merge sort)\n");
    printf("- Backtracking problems\n");
    printf("- Mathematical computations (e.g., factorial, Fibonacci)\n");
    printf("- String manipulation\n\n");
}

int factorial(int n) {
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

int fibonacci(int n) {
    // Base cases
    if (n <= 1) {
        return n;
    }
    // Recursive case
    return fibonacci(n - 1) + fibonacci(n - 2);
}

void print_binary(unsigned int n) {
    // Base case
    if (n > 1) {
        // Recursive case
        print_binary(n / 2);
    }
    printf("%d", n % 2);
}

int sum_of_digits(int n) {
    // Base case
    if (n == 0) {
        return 0;
    }
    // Recursive case
    return (n % 10) + sum_of_digits(n / 10);
}

int ackermann(int m, int n) {
    // Base case
    if (m == 0) {
        return n + 1;
    }
    // Recursive cases
    if (n == 0) {
        return ackermann(m - 1, 1);
    }
    return ackermann(m - 1, ackermann(m, n - 1));
}

char* reverse_string(char* str) {
    static int i = 0;
    static char rev[100];
    if (*str) {
        reverse_string(str + 1);
        rev[i++] = *str;
    }
    return rev;
}

int binary_search(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return binary_search(arr, left, mid - 1, x);

        // Else the element can only be present in right subarray
        return binary_search(arr, mid + 1, right, x);
    }

    // Element is not present in array
    return -1;
}

void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

void flood_fill(int screen[][5], int m, int n, int x, int y, int prevColor, int newColor) {
    // Base cases
    if (x < 0 || x >= m || y < 0 || y >= n)
        return;
    if (screen[x][y] != prevColor)
        return;

    // Replace the color at (x, y)
    screen[x][y] = newColor;

    // Recur for north, east, south and west
    flood_fill(screen, m, n, x+1, y, prevColor, newColor);
    flood_fill(screen, m, n, x-1, y, prevColor, newColor);
    flood_fill(screen, m, n, x, y+1, prevColor, newColor);
    flood_fill(screen, m, n, x, y-1, prevColor, newColor);
}

void print_screen(int screen[][5], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", screen[i][j]);
        printf("\n");
    }
}

void tail_recursion_example(int n) {
    if (n == 0) {
        return;
    }
    printf("%d ", n);
    tail_recursion_example(n - 1);
}

void best_practices_and_pitfalls() {
    printf("\n2. Best Practices and Common Pitfalls\n");
    printf("-------------------------------------\n");
    printf("Best Practices:\n");
    printf("- Always define a base case to prevent infinite recursion\n");
    printf("- Ensure progress towards the base case in each recursive call\n");
    printf("- Use tail recursion when possible for better performance\n");
    printf("- Consider iterative solutions for simple problems to avoid stack overflow\n");
    printf("- Use static variables or helper functions to avoid redundant computations\n");
    
    printf("\nCommon Pitfalls:\n");
    printf("- Forgetting the base case, leading to infinite recursion\n");
    printf("- Not making progress towards the base case\n");
    printf("- Excessive recursion depth causing stack overflow\n");
    printf("- Redundant recursive calls (e.g., in naive Fibonacci implementation)\n");
    printf("- Incorrect assumption about the problem's recursive nature\n");
    
    printf("\nDebugging Tips:\n");
    printf("- Use print statements to track the recursion depth and function arguments\n");
    printf("- Implement a maximum recursion depth as a safeguard during development\n");
    printf("- Use debugger to step through recursive calls and examine the call stack\n");
    printf("- Start with small inputs and gradually increase complexity\n\n");
}

void advanced_tips_and_optimizations() {
    printf("3. Advanced Tips and Optimizations\n");
    printf("----------------------------------\n");
    printf("- Tail Call Optimization: Rewrite recursive functions to use tail recursion\n");
    printf("- Memoization: Cache results of expensive function calls to avoid redundant computations\n");
    printf("- Trampolining: Use a loop to handle recursive calls, avoiding stack overflow\n");
    printf("- Hybrid Approaches: Combine recursion with iteration for optimal performance\n");
    printf("- Parallel Recursion: Utilize multi-threading for independent recursive calls\n");
    printf("- Stack Allocation: Be mindful of stack usage in deeply recursive algorithms\n");
    printf("- Compiler Optimizations: Use appropriate compiler flags to enable recursion-specific optimizations\n\n");
}

void integration_and_real_world_applications() {
    printf("4. Integration and Real-World Applications\n");
    printf("------------------------------------------\n");
    printf("Integration with other concepts:\n");
    printf("- Dynamic Programming: Combine recursion with memoization for optimal substructure problems\n");
    printf("- Functional Programming: Utilize recursion as a core concept in functional paradigms\n");
    printf("- Divide and Conquer: Apply recursion in algorithms like Merge Sort and Quick Sort\n");
    printf("- Tree and Graph Algorithms: Use recursion for traversal, searching, and manipulation\n");
    
    printf("\nReal-world applications:\n");
    printf("- Compiler Design: Recursive descent parsing in language processing\n");
    printf("- Computer Graphics: Fractal generation and ray tracing algorithms\n");
    printf("- AI and Machine Learning: Decision tree traversal and backtracking in game AI\n");
    printf("- File System Operations: Recursive directory traversal and file searches\n");
    printf("- Mathematical Software: Implementations of complex mathematical functions\n");
    printf("- Web Crawlers: Depth-first traversal of web pages\n");
    printf("- Database Systems: Hierarchical data processing in SQL recursive queries\n\n");
}

void faqs_and_troubleshooting() {
    printf("5. FAQs and Troubleshooting\n");
    printf("---------------------------\n");
    printf("Q: How do I avoid stack overflow in deeply recursive algorithms?\n");
    printf("A: Use tail recursion, increase stack size, or consider iterative solutions.\n\n");
    
    printf("Q: When should I use recursion vs. iteration?\n");
    printf("A: Use recursion for problems with a natural recursive structure (e.g., tree traversal) and iteration for simpler, linear problems.\n\n");
    
    printf("Q: How can I optimize recursive Fibonacci implementation?\n");
    printf("A: Use memoization or dynamic programming to avoid redundant calculations.\n\n");
    
    printf("Q: Is recursion always slower than iteration?\n");
    printf("A: Not necessarily. With proper optimization, recursive solutions can be as efficient as iterative ones.\n\n");
    
    printf("Q: How do I debug complex recursive functions?\n");
    printf("A: Use print statements, a debugger to step through calls, and start with small inputs.\n\n");
}

void recommended_tools_and_libraries() {
    printf("6. Recommended Tools and Libraries\n");
    printf("----------------------------------\n");
    printf("- GDB (GNU Debugger): For stepping through recursive calls and examining the call stack\n");
    printf("- Valgrind: Memory profiling tool to detect stack overflow and memory leaks\n");
    printf("- GNU MPFR: For arbitrary-precision arithmetic in deeply recursive mathematical computations\n");
    printf("- Boost C++ Libraries: Provides utilities for recursive algorithms and data structures\n");
    printf("- GraphViz: Visualization tool for recursive data structures like trees and graphs\n");
    printf("- Compiler-specific tools: e.g., Visual Studio's 'Call Stack' and 'Autos' windows\n");
    printf("- Performance profiling tools:\n");
    printf("  * gprof: GNU profiler for analyzing program performance\n");
    printf("  * Instruments (for macOS): Time Profiler and Allocations instruments for recursive function analysis\n");
    printf("  * Intel VTune Profiler: Advanced performance analysis for recursive algorithms\n");
    printf("- Static analysis tools:\n");
    printf("  * Clang Static Analyzer: Detects bugs in recursive functions\n");
    printf("  * Cppcheck: Identifies potential issues in recursive code\n");
    printf("- Recursion visualization tools:\n");
    printf("  * Python Tutor (with C support): Visualizes recursive function calls step-by-step\n");
    printf("  * Recursion Tree Visualizer: Online tool for creating recursion trees\n");
    printf("- Libraries for memoization and dynamic programming:\n");
    printf("  * libdynam: C library for dynamic programming\n");
    printf("  * Memo-C: Simple memoization library for C\n");
    printf("- Tail call optimization support:\n");
    printf("  * Check compiler documentation (e.g., GCC's -foptimize-sibling-calls option)\n");
    printf("- Parallelization libraries for recursive algorithms:\n");
    printf("  * OpenMP: For parallelizing recursive functions on multi-core systems\n");
    printf("  * Intel Threading Building Blocks (TBB): Includes parallel_for and parallel_reduce for recursive algorithms\n");
    printf("- Functional programming libraries that support recursive patterns:\n");
    printf("  * Klib: Lightweight C library with functional programming utilities\n");
    printf("- Memory management libraries for custom stack implementations:\n");
    printf("  * jemalloc: Memory allocator that can help with recursive memory usage patterns\n");
    printf("- Benchmarking tools:\n");
    printf("  * Google Benchmark: For measuring performance of recursive vs. iterative implementations\n");
    printf("\nRemember to choose tools and libraries based on your specific needs, project constraints, and performance requirements. Always benchmark and profile your recursive implementations to ensure they meet your performance criteria.\n");
}