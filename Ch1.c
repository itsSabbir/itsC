/**
 * Comprehensive Expert-level C Cheat Sheet: Basic Syntax and Data Types
 * 
 * This cheat sheet covers in-depth:
 * - Variables and constants
 * - Basic data types (int, float, double, char)
 * - Type modifiers (short, long, unsigned)
 * - Type casting
 * - Advanced type concepts and memory management
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <stdint.h>
#include <stdbool.h>
#include <complex.h>

// 1. Overview of the Topic
/**
 * Basic syntax and data types are fundamental to C programming, forming the building blocks
 * for all C programs. They define how data is represented, stored, and manipulated in memory.
 * 
 * Significance:
 * - Efficient memory usage: C's type system allows fine-grained control over memory allocation.
 * - Performance optimization: Choosing appropriate types can significantly impact program speed.
 * - Platform independence: Proper use of types ensures portability across different architectures.
 * - Type safety: C's type system helps catch certain errors at compile-time.
 * 
 * Common use cases:
 * - System programming: OS kernels, device drivers
 * - Embedded systems: IoT devices, microcontrollers
 * - High-performance computing: Scientific simulations, game engines
 * - Application development: Desktop and server applications
 */

// 2. Syntax and Key Concepts

int main() {
    // 2.1 Variables
    int a;           // Declaration
    int b = 5;       // Declaration with initialization
    a = 10;          // Assignment

    // 2.2 Constants
    const int MAX_VALUE = 100;  // Constant (cannot be modified)
    #define PI 3.14159          // Macro constant (preprocessor directive)

    // 2.3 Basic Data Types
    char c = 'A';               // Character (1 byte)
    int i = 42;                 // Integer (typically 4 bytes)
    float f = 3.14f;            // Single-precision floating-point (4 bytes)
    double d = 3.14159265359;   // Double-precision floating-point (8 bytes)
    _Bool bool_var = 1;         // Boolean (C99 standard)
    bool cpp_style_bool = true; // C++ style boolean (requires <stdbool.h>)

    // 2.4 Type Modifiers
    short int si = 32767;               // Short integer (typically 2 bytes)
    long int li = 2147483647L;          // Long integer (typically 4 or 8 bytes)
    long long int lli = 9223372036854775807LL;  // Long long integer (8 bytes)
    unsigned int ui = 4294967295U;      // Unsigned integer (4 bytes)
    long double ld = 3.14159265358979323846L;  // Extended precision floating-point

    // 2.5 Fixed-width Integer Types (C99)
    int8_t i8 = 127;                    // 8-bit signed integer
    uint16_t ui16 = 65535;              // 16-bit unsigned integer
    int32_t i32 = 2147483647;           // 32-bit signed integer
    uint64_t ui64 = 18446744073709551615ULL;  // 64-bit unsigned integer

    // 2.6 Complex Numbers (C99)
    complex float cf = 1.0f + 2.0f * I;      // Complex float
    complex double cd = 1.0 + 2.0 * I;       // Complex double

    // 2.7 Type Qualifiers
    const int READ_ONLY = 10;           // Value cannot be changed
    volatile int HARDWARE_FLAG;         // Value can change unexpectedly
    register int FAST_ACCESS = 100;     // Hint for compiler to use register (if possible)

    // 2.8 Type Casting
    int x = 10;
    float y = (float)x / 3;  // Explicit casting of x to float
    double z = 1.5;
    int truncated = (int)z;  // Truncates to 1

    // 3. Best Practices and Common Pitfalls

    // 3.1 Initialization
    int uninit_var;  // BAD: Uninitialized variable
    int init_var = 0;  // GOOD: Always initialize variables

    // 3.2 Integer Overflow
    int max_int = INT_MAX;
    int overflow = max_int + 1;  // DANGER: Integer overflow

    // 3.3 Floating-Point Comparison
    float fa = 0.1f;
    float fb = 0.2f;
    float fc = 0.3f;
    if (fa + fb == fc) {  // BAD: Direct comparison of floats
        printf("Equal (incorrect)\n");
    }
    const float EPSILON = 1e-6f;
    if (fabsf((fa + fb) - fc) < EPSILON) {  // GOOD: Compare with epsilon
        printf("Approximately equal\n");
    }

    // 3.4 Type Mismatch in Printf
    int value = 42;
    printf("%f\n", value);  // BAD: Type mismatch
    printf("%d\n", value);  // GOOD: Correct format specifier

    // 4. Advanced Tips and Optimizations

    // 4.1 Bit Fields
    struct {
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int data  : 6;
    } bit_field = {1, 0, 42};

    // 4.2 Unions for Memory Optimization
    union {
        int i;
        float f;
        char c[4];
    } memory_saver;

    // 4.3 Flexible Array Member (C99)
    struct flexible_array {
        int size;
        int data[];  // Flexible array member
    };
    struct flexible_array *fa_ptr = malloc(sizeof(struct flexible_array) + 5 * sizeof(int));
    fa_ptr->size = 5;
    for (int i = 0; i < 5; i++) {
        fa_ptr->data[i] = i;
    }

    // 4.4 Compound Literals (C99)
    int *p = (int[3]){1, 2, 3};  // Creates an unnamed array and returns a pointer

    // 4.5 Designated Initializers (C99)
    int days[12] = {[2] = 31, [4] = 31, [6] = 31, [9] = 31, [11] = 31};

    // 5. Real-world Use Cases

    // 5.1 Network Programming: IPv4 Address
    union ipv4_address {
        uint32_t full_address;
        struct {
            uint8_t a, b, c, d;
        } octets;
    } ip = {.octets = {192, 168, 0, 1}};

    // 5.2 Graphics Programming: RGB Color
    struct rgb_color {
        uint8_t r, g, b;
    } background_color = {255, 255, 255};  // White

    // 5.3 Embedded Systems: Register Manipulation
    #define PORTB *((volatile uint8_t*)0x25)
    PORTB |= (1 << 5);  // Set bit 5 of PORTB

    // 5.4 Scientific Computing: Complex Number Operations
    complex double z1 = 1.0 + 2.0 * I;
    complex double z2 = 3.0 + 4.0 * I;
    complex double sum = z1 + z2;
    printf("Sum: %.2f + %.2fi\n", creal(sum), cimag(sum));

    // 6. Code Examples

    // Beginner: Calculate average of an array
    int numbers[] = {10, 20, 30, 40, 50};
    int sum = 0;
    int count = sizeof(numbers) / sizeof(numbers[0]);
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    float average = (float)sum / count;
    printf("Average: %.2f\n", average);

    // Intermediate: Implement a simple stack using a struct and dynamic memory
    typedef struct {
        int *data;
        int top;
        int capacity;
    } Stack;

    Stack* createStack(int capacity) {
        Stack *s = (Stack*)malloc(sizeof(Stack));
        s->capacity = capacity;
        s->top = -1;
        s->data = (int*)malloc(capacity * sizeof(int));
        return s;
    }

    void push(Stack *s, int item) {
        if (s->top == s->capacity - 1) return;  // Stack overflow
        s->data[++s->top] = item;
    }

    int pop(Stack *s) {
        if (s->top == -1) return -1;  // Stack underflow
        return s->data[s->top--];
    }

    // Advanced: Implement a generic swap function using void pointers
    void swap(void *a, void *b, size_t size) {
        char *temp = (char*)malloc(size);
        memcpy(temp, a, size);
        memcpy(a, b, size);
        memcpy(b, temp, size);
        free(temp);
    }

    int x1 = 5, x2 = 10;
    swap(&x1, &x2, sizeof(int));
    printf("After swap: x1 = %d, x2 = %d\n", x1, x2);

    // 7. Integration with Other Concepts

    // 7.1 Data Structures: Binary Tree Node
    typedef struct Node {
        int data;
        struct Node *left;
        struct Node *right;
    } Node;

    // 7.2 Memory Management: Custom Allocator
    void* my_malloc(size_t size) {
        void *ptr = malloc(size);
        if (ptr == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
        return ptr;
    }

    // 7.3 Concurrency: Atomic Operations (C11)
    #include <stdatomic.h>
    atomic_int shared_counter = ATOMIC_VAR_INIT(0);
    atomic_fetch_add(&shared_counter, 1);

    // 7.4 Networking: Serialization
    uint32_t htonl(uint32_t hostlong);  // Host to network byte order (big endian)

    // 8. FAQs & Troubleshooting

    // Q: Why does my float comparison fail?
    // A: Use an epsilon value for approximate equality:
    float epsilon = 1e-6f;
    float a = 0.1f + 0.2f;
    float b = 0.3f;
    if (fabsf(a - b) < epsilon) {
        printf("Approximately equal\n");
    }

    // Q: How do I handle large numbers beyond long long int?
    // A: Use a library like GMP (GNU Multiple Precision Arithmetic Library)
    // #include <gmp.h>
    // mpz_t big_num;
    // mpz_init(big_num);
    // mpz_set_str(big_num, "123456789012345678901234567890", 10);

    // Q: How can I ensure my code is portable across different platforms?
    // A: Use fixed-width integer types and check for platform-specific macros:
    #ifdef _WIN32
        // Windows-specific code
    #elif defined(__linux__)
        // Linux-specific code
    #elif defined(__APPLE__)
        // macOS-specific code
    #endif

    // 9. Recommended Tools & Libraries

    // 9.1 Static Analysis Tools
    // - Clang Static Analyzer: clang --analyze
    // - Cppcheck: cppcheck --enable=all your_file.c

    // 9.2 Dynamic Analysis Tools
    // - Valgrind: valgrind --leak-check=full ./your_program

    // 9.3 Debugging
    // - GDB (GNU Debugger): gdb ./your_program

    // 9.4 Build Systems
    // - Make: write Makefiles for complex projects
    // - CMake: cross-platform build system generator

    // 9.5 Libraries
    // - GLib: general-purpose utility library
    // - libc: The C standard library (included by default)

    return 0;
}

// Additional advanced examples

// Example: Demonstrating undefined behavior with strict aliasing violation
void strict_aliasing_violation() {
    int i = 0x12345678;
    char *c = (char*)&i;
    
    // This violates strict aliasing rules and is undefined behavior
    printf("%02x %02x %02x %02x\n", c[0], c[1], c[2], c[3]);

    // Safe alternative using union (implementation-defined behavior)
    union {
        int i;
        char c[sizeof(int)];
    } u;
    u.i = 0x12345678;
    printf("%02x %02x %02x %02x\n", u.c[0], u.c[1], u.c[2], u.c[3]);
}

// Example: Demonstrating the limits of integer types
void show_integer_limits() {
    printf("Limits of integer types:\n");
    printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned int: 0 to %u\n", UINT_MAX);
    printf("size_t: 0 to %zu\n", SIZE_MAX);
}

// Example: Demonstrating floating-point precision issues
void floating_point_precision() {
    float f = 0.1f + 0.2f;
    double d = 0.1 + 0.2;
    
    printf("0.1 + 0.2 as float: %.20f\n", f);
    printf("0.1 + 0.2 as double: %.20lf\n", d);
    
    // Proper way to compare floating-point numbers
    const float EPSILON = 1e-6f;
    if (fabsf(f - 0.3f) < EPSILON) {
        printf("float comparison: close enough to 0.3\n");
    }
}

// Example: Using _Generic for type-generic programming (C11)
#define print_value(x) _Generic((x), \
    int: printf("Integer: %d\n", (x)), \
    float: printf("Float: %f\n", (x)), \
    double: printf("Double: %f\n", (x)), \
    char*: printf("String: %s\n", (x)), \
    default: printf("Unknown type\n") \
)

// Example