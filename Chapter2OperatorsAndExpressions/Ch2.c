/**
 * Expert-level C Cheat Sheet: Operators and Expressions
 *
 * This cheat sheet covers:
 * - Arithmetic operators
 * - Relational and logical operators
 * - Bitwise operators
 * - Assignment operators
 * - Operator precedence
 * - Advanced expression techniques
 */

#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Global definitions and structures
#define BUFFER_SIZE 8
#define BUFFER_MASK (BUFFER_SIZE - 1)
#define FIXED_POINT_FRACTIONAL_BITS 16
#define FLAG_A (1 << 0)
#define FLAG_B (1 << 1)
#define FLAG_C (1 << 2)
#define FLAG_D (1 << 3)
#define ARRAY_SIZE 1000
#define BITS_PER_ELEMENT (sizeof(unsigned int) * 8)
#define ARRAY_BITS (ARRAY_SIZE / BITS_PER_ELEMENT)

typedef int32_t fixed_point_t;
typedef struct { int x, y; } Point;
typedef struct { unsigned int a : 5; unsigned int b : 3; unsigned int c : 1; } PackedData;
typedef struct { uint32_t state; } LCG;

int main() {
    // 1. Overview of the Topic
    /**
     * Operators and expressions are fundamental building blocks in C programming.
     * They allow manipulation of data, perform calculations, make decisions, and control program flow.
     *
     * Purpose:
     * - Perform mathematical and logical operations
     * - Manipulate data at bit level
     * - Assign values to variables
     * - Compare values and make decisions
     *
     * Significance:
     * - Essential for implementing algorithms and logic
     * - Critical for performance optimization
     * - Fundamental to all aspects of C programming
     *
     * Common use cases:
     * - Arithmetic calculations in scientific computing
     * - Boolean logic in decision-making structures
     * - Bitwise operations in low-level system programming
     * - Complex expressions in game development and graphics programming
     */

    // 2. Syntax and Key Concepts

    // 2.1 Arithmetic Operators
    int a = 10, b = 3;
    int sum = a + b;        // Addition
    int difference = a - b; // Subtraction
    int product = a * b;    // Multiplication
    int quotient = a / b;   // Division (integer division)
    int remainder = a % b;  // Modulus (remainder)
    int negation = -a;      // Unary minus
    int increment = ++a;    // Pre-increment
    int decrement = --b;    // Pre-decrement
    
    // 2.2 Relational and Logical Operators
    bool equal = (a == b);          // Equal to
    bool not_equal = (a != b);      // Not equal to
    bool greater = (a > b);         // Greater than
    bool less = (a < b);            // Less than
    bool greater_equal = (a >= b);  // Greater than or equal to
    bool less_equal = (a <= b);     // Less than or equal to
    
    bool logical_and = (a > 0 && b > 0);  // Logical AND
    bool logical_or = (a > 0 || b > 0);   // Logical OR
    bool logical_not = !(a > b);          // Logical NOT
    
    // 2.3 Bitwise Operators
    int bitwise_and = a & b;   // Bitwise AND
    int bitwise_or = a | b;    // Bitwise OR
    int bitwise_xor = a ^ b;   // Bitwise XOR
    int bitwise_not = ~a;      // Bitwise NOT (complement)
    int left_shift = a << 2;   // Left shift
    int right_shift = a >> 1;  // Right shift
    
    // 2.4 Assignment Operators
    int c = 5;
    c += 2;  // Equivalent to: c = c + 2
    c -= 2;  // Equivalent to: c = c - 2
    c *= 2;  // Equivalent to: c = c * 2
    c /= 2;  // Equivalent to: c = c / 2
    c %= 2;  // Equivalent to: c = c % 2
    c &= 2;  // Equivalent to: c = c & 2
    c |= 2;  // Equivalent to: c = c | 2
    c ^= 2;  // Equivalent to: c = c ^ 2
    c <<= 2; // Equivalent to: c = c << 2
    c >>= 2; // Equivalent to: c = c >> 2
    
    // 2.5 Operator Precedence (from highest to lowest)
    int d = 5, e = 2, f = 3;
    int result = (a + b) * c - (d / e) % f;
    // Parentheses () have the highest precedence
    // Then *, /, %
    // Then +, -
    // Full precedence chart in comments below
    
    // 3. Best Practices and Common Pitfalls
    
    // BEST PRACTICE: Use parentheses for clarity
    int clear_precedence = ((a + b) * c) - ((d / e) % f);
    
    // PITFALL: Integer division truncation
    float incorrect_division = 5 / 2;    // Result: 2.0
    float correct_division = 5.0f / 2.0f;  // Result: 2.5
    
    // PITFALL: Unintended assignment in conditions
    if (a = b) { /* This assigns b to a and always evaluates to true if b is non-zero */ }
    if (a == b) { /* This compares a and b */ }
    
    // BEST PRACTICE: Use compound assignment operators for readability and potential optimization
    a += 5;  // Instead of a = a + 5;
    
    // PITFALL: Undefined behavior with signed integer overflow
    int max_int = INT_MAX;
    int overflow = max_int + 1;  // Undefined behavior
    
    // 4. Advanced Tips and Optimizations
    
    // 4.1 Bitwise tricks for performance
    int is_even = !(a & 1);  // Check if a number is even
    int is_power_of_two = (a & (a - 1)) == 0;  // Check if a number is a power of 2
    
    // 4.2 Fast multiplication/division by powers of 2
    int fast_multiply = a << 3;  // Equivalent to a * 8
    int fast_divide = a >> 2;    // Equivalent to a / 4
    
    // 4.3 Avoid branching with bitwise operations
    int max = a ^ ((a ^ b) & -(a < b));  // Maximum of a and b without branching
    
    // 4.4 Swap two integers without a temporary variable
    a ^= b;
    b ^= a;
    a ^= b;
    
    // 4.5 Compute absolute value without branching (for 2's complement systems)
    int abs_value = (a + (a >> 31)) ^ (a >> 31);
    
    // 5. Real-world Use Cases
    
    // 5.1 Graphics Programming: Color manipulation
    unsigned int color = 0xFF5733;
    unsigned int red = (color >> 16) & 0xFF;
    unsigned int green = (color >> 8) & 0xFF;
    unsigned int blue = color & 0xFF;
    
    // 5.2 Network Programming: IP address manipulation
    unsigned int ip = 0xC0A80001;  // 192.168.0.1
    unsigned char octet1 = (ip >> 24) & 0xFF;
    unsigned char octet2 = (ip >> 16) & 0xFF;
    unsigned char octet3 = (ip >> 8) & 0xFF;
    unsigned char octet4 = ip & 0xFF;
    
    // 5.3 Embedded Systems: Register manipulation
    unsigned char PORTA = 0b10101010;
    PORTA |= (1 << 2);  // Set bit 2
    PORTA &= ~(1 << 3); // Clear bit 3
    PORTA ^= (1 << 4);  // Toggle bit 4
    
    // 5.4 Cryptography: Simple XOR encryption
    char plaintext[] = "Hello";
    char key = 0x42;
    for (int i = 0; plaintext[i] != '\0'; i++) {
        plaintext[i] ^= key;  // Encrypt
        plaintext[i] ^= key;  // Decrypt
    }
    
    // 6. Code Examples
    
    // Beginner: Calculate the area of a rectangle
    int length = 5, width = 3;
    int area = length * width;
    printf("Area of rectangle: %d\n", area);
    
    // Intermediate: Implement a simple state machine
    typedef enum { STATE_IDLE, STATE_RUNNING, STATE_PAUSED, STATE_STOPPED } State;
    State current_state = STATE_IDLE;
    int event = 1;  // Assume 1 is START event
    
    switch (current_state) {
        case STATE_IDLE:
            if (event == 1) current_state = STATE_RUNNING;
            break;
        case STATE_RUNNING:
            if (event == 2) current_state = STATE_PAUSED;  // Assume 2 is PAUSE event
            break;
        // ... other states
    }
    
    // Advanced: Implement a circular buffer using bitwise operations
    int buffer[BUFFER_SIZE];
    int write_index = 0;
    int read_index = 0;
    
    void write(int value) {
        buffer[write_index & BUFFER_MASK] = value;
        write_index++;
    }
    
    int read() {
        int value = buffer[read_index & BUFFER_MASK];
        read_index++;
        return value;
    }
    
    // 7. Integration with Other Concepts
    
    // 7.1 Function Pointers: Using operators with function pointers
    int add(int a, int b) { return a + b; }
    int subtract(int a, int b) { return a - b; }
    
    int (*operation)(int, int);
    operation = (a > b) ? add : subtract;
    int func_result = operation(a, b);
    
    // 7.2 Preprocessor: Macro operators
    #define MAX(a, b) ((a) > (b) ? (a) : (b))
    #define SQUARE(x) ((x) * (x))
    
    // 7.3 Type Casting: Operators in type casting
    float f = 3.14f;
    int i = (int)f;  // Explicit cast
    void* ptr = &i;
    int* int_ptr = (int*)ptr;  // Cast from void* to int*
    
    // 7.4 Memory Management: Operators in pointer arithmetic
    int arr[5] = {1, 2, 3, 4, 5};
    int* p = arr;
    int third_element = *(p + 2);  // Equivalent to arr[2]
    
    // Additional advanced examples and concepts

    // Example: Implementing a simple fixed-point arithmetic system
    fixed_point_t float_to_fixed(float f) {
        return (fixed_point_t)(f * (1 << FIXED_POINT_FRACTIONAL_BITS));
    }

    float fixed_to_float(fixed_point_t f) {
        return (float)f / (1 << FIXED_POINT_FRACTIONAL_BITS);
    }

    fixed_point_t fixed_multiply(fixed_point_t a, fixed_point_t b) {
        return (fixed_point_t)(((int64_t)a * b) >> FIXED_POINT_FRACTIONAL_BITS);
    }

    // Example: Using compound literals and designated initializers
    void print_point(Point p) {
        printf("(%d, %d)\n", p.x, p.y);
    }

    // Example: Bit manipulation for efficient data packing
    {
        PackedData data = {.a = 16, .b = 5, .c = 1};
        printf("Packed data: a = %u, b = %u, c = %u\n", data.a, data.b, data.c);
        
        // Manipulating bit fields
        data.a |= 1;  // Set the least significant bit of a
        data.b &= ~2; // Clear the second bit of b
        data.c ^= 1;  // Toggle c

        printf("Modified packed data: a = %u, b = %u, c = %u\n", data.a, data.b, data.c);

        // Accessing the entire packed structure as an integer
        unsigned int* raw_data = (unsigned int*)&data;
        printf("Raw data: 0x%08X\n", *raw_data);
    }

    // Example: Using bitwise operators for flag manipulation
    {
        unsigned int flags = 0;

        // Setting flags
        flags |= FLAG_A | FLAG_C;
        printf("Flags after setting A and C: 0x%X\n", flags);

        // Checking flags
        if (flags & FLAG_B) {
            printf("Flag B is set\n");
        } else {
            printf("Flag B is not set\n");
        }

        // Clearing a flag
        flags &= ~FLAG_C;
        printf("Flags after clearing C: 0x%X\n", flags);

        // Toggling a flag
        flags ^= FLAG_D;
        printf("Flags after toggling D: 0x%X\n", flags);
    }

    // Example: Implementing a circular shift operation
    unsigned int circular_left_shift(unsigned int value, int shift) {
        const int bits = sizeof(unsigned int) * 8;
        shift %= bits;
        return (value << shift) | (value >> (bits - shift));
    }

    unsigned int circular_right_shift(unsigned int value, int shift) {
        const int bits = sizeof(unsigned int) * 8;
        shift %= bits;
        return (value >> shift) | (value << (bits - shift));
    }

    // Example: Using bitwise operations for efficient modulo with powers of 2
    unsigned int fast_modulo_power_of_two(unsigned int value, unsigned int divisor) {
        // Note: divisor must be a power of 2
        return value & (divisor - 1);
    }

    // Example: Implementing a simple hash function using bitwise operations
    unsigned int simple_hash(const char* str) {
        unsigned int hash = 0;
        while (*str) {
            hash = (hash << 5) + hash + *str;
            str++;
        }
        return hash;
    }

    // Example: Using the comma operator for complex expressions
    {
        int a = 1, b = 2, c = 3;
        int result = (a++, b += 2, c *= 3);
        printf("a = %d, b = %d, c = %d, result = %d\n", a, b, c, result);
    }

    // Example: Implementing a simple linear congruential generator using bitwise operations
    uint32_t lcg_next(LCG* lcg) {
        lcg->state = (uint32_t)(((uint64_t)lcg->state * 1103515245 + 12345) & 0xFFFFFFFF);
        return lcg->state >> 16;
    }

    // Example: Using compound assignment operators with function calls
    int increment(int* value) {
        return ++(*value);
    }

    {
        int x = 5;
        x += increment(&x);
        printf("x after compound assignment: %d\n", x);
    }

    // Example: Demonstrating sequence points and undefined behavior
    {
        int i = 5;
        int j = i++ + i++;  // Undefined behavior

        int k = 5;
        int l = (k++) + (k++);  // Well-defined behavior due to sequence point

        printf("i = %d, j = %d\n", i, j);
        printf("k = %d, l = %d\n", k, l);
    }

    // Example: Using bitwise operations for efficient array operations
    unsigned int bit_array[ARRAY_BITS] = {0};

    void set_bit(int index) {
        bit_array[index / BITS_PER_ELEMENT] |= (1U << (index % BITS_PER_ELEMENT));
    }

    void clear_bit(int index) {
        bit_array[index / BITS_PER_ELEMENT] &= ~(1U << (index % BITS_PER_ELEMENT));
    }

    int test_bit(int index) {
        return (bit_array[index / BITS_PER_ELEMENT] & (1U << (index % BITS_PER_ELEMENT))) != 0;
    }

    // Example: Using the ternary operator for conditional initialization
    void ternary_operator_example(int condition) {
        int result = condition ? (condition > 0 ? 1 : -1) : 0;
        printf("Ternary operator result: %d\n", result);
    }

    // Demonstrating the use of all examples
    printf("\n--- Demonstrating all examples ---\n");

    // Fixed-point arithmetic
    fixed_point_t fixed_val = float_to_fixed(3.14f);
    printf("Fixed-point value: %d\n", fixed_val);
    printf("Converted back to float: %f\n", fixed_to_float(fixed_val));

    // Compound literals and designated initializers
    print_point((Point){.x = 5, .y = 10});

    // Circular shift operations
    unsigned int value = 0xABCD1234;
    printf("Original value: 0x%08X\n", value);
    printf("Circular left shift by 8: 0x%08X\n", circular_left_shift(value, 8));
    printf("Circular right shift by 8: 0x%08X\n", circular_right_shift(value, 8));

    // Fast modulo with power of 2
    printf("Fast modulo 16 of 100: %u\n", fast_modulo_power_of_two(100, 16));

    // Simple hash function
    printf("Hash of 'Hello': %u\n", simple_hash("Hello"));

    // Linear Congruential Generator
    LCG lcg = {.state = 12345};
    printf("Random number from LCG: %u\n", lcg_next(&lcg));

    // Bit array operations
    set_bit(42);
    printf("Bit 42 is set: %s\n", test_bit(42) ? "true" : "false");
    clear_bit(42);
    printf("Bit 42 after clearing: %s\n", test_bit(42) ? "true" : "false");

    // Ternary operator example
    ternary_operator_example(10);
    ternary_operator_example(-5);
    ternary_operator_example(0);

    // 8. FAQs & Troubleshooting
    printf("\n--- FAQs & Troubleshooting ---\n");
    
    // Q: Why does (1/2) * 5 give 0 instead of 2.5?
    printf("(1/2) * 5 = %d\n", (1/2) * 5);
    printf("(1.0/2) * 5 = %f\n", (1.0/2) * 5);
    // A: Integer division truncates. Use (1.0/2) * 5 for floating-point division.
    
    // Q: How can I check if a number is odd or even without using the modulus operator?
    int number_to_check = 42;
    printf("%d is %s\n", number_to_check, (number_to_check & 1) ? "odd" : "even");
    // A: Use bitwise AND: if (number & 1) { /* odd */ } else { /* even */ }
    
    // Q: How do I set, clear, or toggle a specific bit in an integer?
    unsigned int num = 0;
    printf("Initial num: 0x%08X\n", num);
    num |= (1 << 3);  // Set bit 3
    printf("After setting bit 3: 0x%08X\n", num);
    num &= ~(1 << 3);  // Clear bit 3
    printf("After clearing bit 3: 0x%08X\n", num);
    num ^= (1 << 3);  // Toggle bit 3
    printf("After toggling bit 3: 0x%08X\n", num);
    
    // Q: Why does my bitwise operation on a signed integer produce unexpected results?
    int signed_num = -1;
    unsigned int unsigned_num = (unsigned int)signed_num;
    printf("Signed -1 right shift by 1: %d\n", signed_num >> 1);
    printf("Unsigned -1 right shift by 1: %u\n", unsigned_num >> 1);
    // A: Signed integers use two's complement representation. For portable code,
    //    use unsigned integers for bitwise operations.

    // 9. Recommended Tools & Libraries
    printf("\n--- Recommended Tools & Libraries ---\n");
    printf("Static Analysis Tools:\n");
    printf("- Clang Static Analyzer: Detects bugs in expressions\n");
    printf("- Cppcheck: Checks for undefined behavior in expressions\n");
    
    printf("\nDebugging Tools:\n");
    printf("- GDB (GNU Debugger): Evaluate expressions during runtime\n");
    printf("- Valgrind: Detect memory errors in expressions\n");
    
    printf("\nLibraries:\n");
    printf("- GMP (GNU Multiple Precision Arithmetic Library): For arbitrary-precision arithmetic\n");
    printf("- Boost.Operators: Simplifies operator overloading in C++\n");
    
    printf("\nCompiler Flags:\n");
    printf("-Wall -Wextra: Enable additional warnings for potentially problematic expressions\n");
    printf("-fwrapv: Define signed integer overflow to wrap (GCC)\n");

    return 0;
}

// Operator Precedence Chart (from highest to lowest)
/**
 * 1. () [] -> .            Left-to-right
 * 2. ! ~ ++ -- + - * & (type) sizeof  Right-to-left
 * 3. * / %                 Left-to-right
 * 4. + -                   Left-to-right
 * 5. << >>                 Left-to-right
 * 6. < <= > >=             Left-to-right
 * 7. == !=                 Left-to-right
 * 8. &                     Left-to-right
 * 9. ^                     Left-to-right
 * 10. |                    Left-to-right
 * 11. &&                   Left-to-right
 * 12. ||                   Left-to-right
 * 13. ?:                   Right-to-left
 * 14. = += -= *= /= %= &= ^= |= <<= >>= Right-to-left
 * 15. ,                    Left-to-right
 */

/**
 * Additional notes on operator precedence and associativity:
 *
 * Precedence rules can be overridden using parentheses. It's often a good
 * practice to use parentheses to make the intended order of operations clear,
 * even when not strictly necessary.
 *
 * Examples:
 * 1. a + b * c         is equivalent to   a + (b * c)
 * 2. (a + b) * c       parentheses change the order of operations
 * 3. a || b && c       is equivalent to   a || (b && c)   due to && having higher precedence
 * 4. (a || b) && c     parentheses change the order of operations
 *
 * Associativity becomes important when operators of the same precedence appear in an expression:
 * 1. Left-to-right: a - b + c  is evaluated as  (a - b) + c
 * 2. Right-to-left: a = b = c  is evaluated as  a = (b = c)
 *
 * Be cautious with expressions that rely on side effects and sequencing:
 * 1. i = i++ + ++i;  // Undefined behavior
 * 2. f(i++, i);      // Unspecified order of evaluation of function arguments
 *
 * When in doubt, break complex expressions into simpler statements to ensure
 * well-defined behavior and improve code readability.
 */