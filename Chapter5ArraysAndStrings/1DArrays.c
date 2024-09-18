#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * ARRAYS AND STRINGS CHEAT SHEET (One-dimensional arrays in C)
 * =============================================================
 *
 * 1. OVERVIEW
 * -----------
 * Arrays in C are contiguous memory locations that store multiple items of the same type.
 * Strings in C are essentially arrays of characters, terminated by a null character '\0'.
 * 
 * Purpose: Efficient storage and manipulation of collections of data.
 * Significance: Fundamental to many algorithms and data structures.
 * Common use cases: Storing lists of numbers, characters, or complex data types.
 *
 * 2. SYNTAX, KEY CONCEPTS, AND CODE EXAMPLES
 * ------------------------------------------
 */

// Basic array declaration and initialization
void basic_array_operations() {
    int numbers[5] = {1, 2, 3, 4, 5};  // Declare and initialize
    int partial[5] = {1, 2};  // Partially initialize, rest are 0
    int auto_size[] = {1, 2, 3};  // Size determined by initializer

    printf("Third element: %d\n", numbers[2]);  // Accessing elements (0-indexed)
    numbers[1] = 10;  // Modifying elements

    // Iterating through an array
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}

// String operations
void string_operations() {
    char str1[] = "Hello";  // String initialization
    char str2[20];  // Declare empty string
    
    strcpy(str2, "World");  // String copy
    printf("Length of str1: %lu\n", strlen(str1));  // String length
    
    strcat(str1, " ");  // String concatenation
    strcat(str1, str2);
    printf("Concatenated string: %s\n", str1);
    
    if (strcmp(str1, "Hello World") == 0) {  // String comparison
        printf("Strings are equal\n");
    }
}

// Dynamic memory allocation for arrays
void dynamic_arrays() {
    int *dynamic_array;
    int size = 5;
    
    dynamic_array = (int*)malloc(size * sizeof(int));  // Allocate memory
    
    if (dynamic_array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        dynamic_array[i] = i * 2;
    }
    
    // Resize array
    int new_size = 10;
    int *temp = (int*)realloc(dynamic_array, new_size * sizeof(int));
    
    if (temp == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        free(dynamic_array);
        return;
    }
    
    dynamic_array = temp;
    
    for (int i = size; i < new_size; i++) {
        dynamic_array[i] = i * 2;
    }
    
    for (int i = 0; i < new_size; i++) {
        printf("%d ", dynamic_array[i]);
    }
    printf("\n");
    
    free(dynamic_array);  // Don't forget to free allocated memory
}

/*
 * 3. BEST PRACTICES, COMMON PITFALLS, AND ADVANCED TIPS
 * -----------------------------------------------------
 * 
 * Best Practices:
 * - Always initialize arrays to avoid undefined behavior.
 * - Use const for arrays that shouldn't be modified.
 * - Prefer stack allocation for small, fixed-size arrays.
 * - Use dynamic allocation for large or variable-sized arrays.
 * - Always check the return value of malloc/realloc.
 * 
 * Common Pitfalls:
 * - Array index out of bounds (buffer overflow)
 * - Forgetting to null-terminate strings
 * - Using sizeof on array parameters (it returns pointer size)
 * - Memory leaks with dynamically allocated arrays
 * 
 * Advanced Tips:
 * - Use flexible array members for structs with variable-length arrays
 * - Implement custom allocators for better performance in specific scenarios
 * - Use restrict keyword for pointer parameters to enable compiler optimizations
 */

// Demonstrating buffer overflow prevention
void safe_string_input(char *buffer, size_t buffer_size) {
    printf("Enter a string: ");
    if (fgets(buffer, buffer_size, stdin) != NULL) {
        // Remove trailing newline if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len-1] == '\n') {
            buffer[len-1] = '\0';
        }
    }
}

// Advanced: Flexible array member
struct flexible_array_struct {
    int size;
    int data[];  // Flexible array member
};

void flexible_array_demo() {
    int size = 5;
    struct flexible_array_struct *fas = malloc(sizeof(struct flexible_array_struct) + size * sizeof(int));
    
    if (fas == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    
    fas->size = size;
    for (int i = 0; i < size; i++) {
        fas->data[i] = i * i;
    }
    
    for (int i = 0; i < fas->size; i++) {
        printf("%d ", fas->data[i]);
    }
    printf("\n");
    
    free(fas);
}

/*
 * 4. INTEGRATION AND REAL-WORLD APPLICATIONS
 * ------------------------------------------
 * 
 * Integration:
 * - Arrays are fundamental to many data structures (e.g., hash tables, graphs)
 * - Strings are crucial in parsing, text processing, and network communications
 * - In microservices: Used for buffering data, managing request/response payloads
 * - In distributed systems: Serialization of data for network transfer
 * 
 * Real-world applications:
 * - Image processing: Representing pixel data
 * - Audio processing: Storing audio samples
 * - Financial systems: Managing lists of transactions
 * - Bioinformatics: Storing and processing genetic sequences
 */

// Simple image processing example (grayscale conversion)
void image_processing_demo() {
    // Simulating an RGB image (3 bytes per pixel)
    unsigned char image[3][3][3] = {
        {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}},
        {{255, 255, 0}, {255, 0, 255}, {0, 255, 255}},
        {{128, 128, 128}, {0, 0, 0}, {255, 255, 255}}
    };
    unsigned char grayscale[3][3];
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Convert to grayscale using luminosity method
            grayscale[i][j] = (unsigned char)(0.21 * image[i][j][0] + 0.72 * image[i][j][1] + 0.07 * image[i][j][2]);
            printf("%3d ", grayscale[i][j]);
        }
        printf("\n");
    }
}

/*
 * 5. FAQs AND TROUBLESHOOTING
 * ---------------------------
 * 
 * Q: How do I pass an array to a function?
 * A: You can pass it as a pointer: void func(int *arr) or void func(int arr[])
 * 
 * Q: Why does sizeof(arr) not give the correct size when arr is a function parameter?
 * A: Arrays decay to pointers when passed to functions. Use a separate size parameter.
 * 
 * Q: How can I return an array from a function?
 * A: Return a pointer to dynamically allocated memory or use a struct wrapper.
 * 
 * Q: How do I handle string input safely?
 * A: Use fgets() with a specified buffer size, or use scanf() with a field width limit.
 * 
 * Troubleshooting:
 * - Segmentation fault: Check for array bounds violations
 * - Unexpected output: Ensure proper null-termination of strings
 * - Memory leaks: Use tools like Valgrind to detect and fix leaks
 */

// Demonstration of safe array passing and returning
int* create_and_fill_array(int size, int value) {
    int *arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        arr[i] = value;
    }
    return arr;
}

void use_dynamic_array() {
    int size = 5;
    int *my_array = create_and_fill_array(size, 42);
    if (my_array == NULL) {
        fprintf(stderr, "Failed to create array\n");
        return;
    }
    
    for (int i = 0; i < size; i++) {
        printf("%d ", my_array[i]);
    }
    printf("\n");
    
    free(my_array);
}

/*
 * 6. RECOMMENDED TOOLS AND LIBRARIES
 * ----------------------------------
 * 
 * - Valgrind: Memory debugging and leak detection
 * - GDB (GNU Debugger): Debugging C programs
 * - AddressSanitizer: Fast memory error detector
 * - C string handling libraries: string.h (built-in), stringview (third-party)
 * - Array manipulation libraries: C++ STL (if using C++), GLib (for C)
 * - Static analysis tools: Clang Static Analyzer, Cppcheck
 */

// Main function to demonstrate various concepts
int main() {
    printf("=== Arrays and Strings Cheat Sheet ===\n\n");

    printf("Basic Array Operations:\n");
    basic_array_operations();
    printf("\n");

    printf("String Operations:\n");
    string_operations();
    printf("\n");

    printf("Dynamic Arrays:\n");
    dynamic_arrays();
    printf("\n");

    printf("Safe String Input:\n");
    char input_buffer[50];
    safe_string_input(input_buffer, sizeof(input_buffer));
    printf("You entered: %s\n\n", input_buffer);

    printf("Flexible Array Demo:\n");
    flexible_array_demo();
    printf("\n");

    printf("Image Processing Demo:\n");
    image_processing_demo();
    printf("\n");

    printf("Dynamic Array Creation and Usage:\n");
    use_dynamic_array();

    return 0;
}