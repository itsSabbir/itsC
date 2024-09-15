#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdbool.h>
#include <stdint.h>
#include <complex.h>

// Function prototypes
void overview_and_syntax(void);
void integer_types(void);
void floating_point_types(void);
void character_type(void);
void boolean_type(void);
void fixed_width_integer_types(void);
void complex_numbers(void);
void type_qualifiers(void);
void type_conversion(void);
void best_practices(void);
void common_pitfalls(void);
void advanced_tips(void);
void real_world_use_cases(void);
void integration_with_other_concepts(void);
void faqs_and_troubleshooting(void);
void recommended_tools_and_libraries(void);

int main() {
    printf("Basic Syntax and Data Types in C\n\n");

    overview_and_syntax();
    integer_types();
    floating_point_types();
    character_type();
    boolean_type();
    fixed_width_integer_types();
    complex_numbers();
    type_qualifiers();
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
    printf("1. Overview of Basic Syntax and Data Types in C\n");
    printf("-----------------------------------------------\n");
    printf("C is a statically-typed, compiled language known for its efficiency and low-level control.\n");
    printf("Basic data types in C include:\n");
    printf("- Integers (int, short, long, long long)\n");
    printf("- Floating-point numbers (float, double, long double)\n");
    printf("- Characters (char)\n");
    printf("- Boolean (introduced in C99 with <stdbool.h>)\n");
    printf("These types form the foundation for more complex data structures and algorithms.\n\n");

    printf("Basic syntax for declaring variables:\n");
    printf("type variable_name = initial_value;\n\n");

    printf("Example:\n");
    int x = 5;
    float y = 3.14f;
    char z = 'A';
    printf("int x = %d;\n", x);
    printf("float y = %f;\n", y);
    printf("char z = '%c';\n\n", z);
}

void integer_types() {
    printf("2. Integer Types\n");
    printf("----------------\n");
    printf("C provides several integer types with different sizes and ranges:\n\n");

    printf("- short int (typically 16 bits)\n");
    short s = 32767;
    printf("  short s = %d; // Range: %d to %d\n", s, SHRT_MIN, SHRT_MAX);

    printf("- int (typically 32 bits)\n");
    int i = 2147483647;
    printf("  int i = %d; // Range: %d to %d\n", i, INT_MIN, INT_MAX);

    printf("- long int (typically 32 or 64 bits)\n");
    long l = 9223372036854775807L;
    printf("  long l = %ld; // Range: %ld to %ld\n", l, LONG_MIN, LONG_MAX);

    printf("- long long int (at least 64 bits)\n");
    long long ll = 9223372036854775807LL;
    printf("  long long ll = %lld; // Range: %lld to %lld\n\n", ll, LLONG_MIN, LLONG_MAX);

    printf("Unsigned variants are also available (e.g., unsigned int).\n\n");
}

void floating_point_types() {
    printf("3. Floating-point Types\n");
    printf("------------------------\n");
    printf("C provides three floating-point types:\n\n");

    printf("- float (typically 32 bits)\n");
    float f = 3.14159265358979323846f;
    printf("  float f = %.7f; // Precision: %.7f\n", f, FLT_EPSILON);

    printf("- double (typically 64 bits)\n");
    double d = 3.14159265358979323846;
    printf("  double d = %.15f; // Precision: %.15f\n", d, DBL_EPSILON);

    printf("- long double (typically 80 bits or more)\n");
    long double ld = 3.14159265358979323846L;
    printf("  long double ld = %.18Lf; // Precision: %.18Lf\n\n", ld, LDBL_EPSILON);

    printf("Note: Actual precision may vary depending on the system and compiler.\n\n");
}

void character_type() {
    printf("4. Character Type\n");
    printf("------------------\n");
    printf("The char type is used to store single characters:\n\n");

    char c = 'A';
    printf("char c = '%c';\n", c);
    printf("ASCII value: %d\n\n", c);

    printf("Character literals are enclosed in single quotes.\n");
    printf("Multi-byte characters and strings use double quotes.\n\n");

    char str[] = "Hello";
    printf("char str[] = \"%s\";\n\n", str);
}

void boolean_type() {
    printf("5. Boolean Type\n");
    printf("---------------\n");
    printf("C99 introduced a Boolean type via <stdbool.h>:\n\n");

    bool flag = true;
    printf("bool flag = %s;\n\n", flag ? "true" : "false");

    printf("In older C versions, integers are used for boolean logic:\n");
    printf("0 is considered false, any non-zero value is true.\n\n");
}

void fixed_width_integer_types() {
    printf("6. Fixed-width Integer Types\n");
    printf("----------------------------\n");
    printf("C99 introduced fixed-width integer types in <stdint.h>:\n\n");

    int8_t i8 = 127;
    uint8_t ui8 = 255;
    int16_t i16 = 32767;
    uint16_t ui16 = 65535;
    int32_t i32 = 2147483647;
    uint32_t ui32 = 4294967295U;
    int64_t i64 = 9223372036854775807LL;
    uint64_t ui64 = 18446744073709551615ULL;

    printf("int8_t i8 = %d;\n", i8);
    printf("uint8_t ui8 = %u;\n", ui8);
    printf("int16_t i16 = %d;\n", i16);
    printf("uint16_t ui16 = %u;\n", ui16);
    printf("int32_t i32 = %d;\n", i32);
    printf("uint32_t ui32 = %u;\n", ui32);
    printf("int64_t i64 = %lld;\n", i64);
    printf("uint64_t ui64 = %llu;\n\n", ui64);

    printf("These types ensure consistent sizes across different platforms.\n\n");
}

void complex_numbers() {
    printf("7. Complex Numbers\n");
    printf("------------------\n");
    printf("C99 introduced support for complex numbers via <complex.h>:\n\n");

    double complex z1 = 1.0 + 2.0 * I;
    double complex z2 = 3.0 - 4.0 * I;
    double complex sum = z1 + z2;

    printf("z1 = %.2f + %.2fi\n", creal(z1), cimag(z1));
    printf("z2 = %.2f + %.2fi\n", creal(z2), cimag(z2));
    printf("sum = %.2f + %.2fi\n\n", creal(sum), cimag(sum));
}

void type_qualifiers() {
    printf("8. Type Qualifiers\n");
    printf("------------------\n");
    printf("C provides type qualifiers to modify variable behavior:\n\n");

    printf("- const: Value cannot be changed after initialization\n");
    const int DAYS_IN_WEEK = 7;
    printf("  const int DAYS_IN_WEEK = %d;\n", DAYS_IN_WEEK);

    printf("- volatile: Value may change unexpectedly\n");
    volatile int sensor_value = 0;
    printf("  volatile int sensor_value = %d;\n", sensor_value);

    printf("- restrict: Pointer is the only way to access the object it points to\n");
    int * restrict ptr = NULL;
    printf("  int * restrict ptr = NULL;\n\n");
}

void type_conversion() {
    printf("9. Type Conversion\n");
    printf("------------------\n");
    printf("C performs implicit type conversions, but explicit casting is often preferred:\n\n");

    int i = 5;
    float f = 2.5f;
    double d = (double)i / f;
    printf("int i = %d;\n", i);
    printf("float f = %.1f;\n", f);
    printf("double d = (double)i / f; // Result: %.2f\n\n", d);

    printf("Be cautious of potential data loss in conversions:\n");
    long long big = 1234567890123LL;
    int truncated = (int)big;
    printf("long long big = %lld;\n", big);
    printf("int truncated = (int)big; // Result: %d\n\n", truncated);
}

void best_practices() {
    printf("10. Best Practices\n");
    printf("------------------\n");
    printf("- Use appropriate types for your data to avoid overflow and precision issues\n");
    printf("- Initialize variables before use to prevent undefined behavior\n");
    printf("- Use const for values that should not change\n");
    printf("- Be explicit about integer signedness (signed vs unsigned)\n");
    printf("- Use fixed-width types when exact sizes are required\n");
    printf("- Be cautious with floating-point comparisons due to precision limitations\n");
    printf("- Use meaningful variable names that indicate the purpose or content\n");
    printf("- Declare variables in the smallest scope possible\n\n");
}

void common_pitfalls() {
    printf("11. Common Pitfalls\n");
    printf("-------------------\n");
    printf("- Integer overflow/underflow\n");
    printf("- Floating-point precision errors\n");
    printf("- Uninitialized variables leading to undefined behavior\n");
    printf("- Implicit type conversions causing unexpected results\n");
    printf("- Assuming specific sizes for basic types across different platforms\n");
    printf("- Misusing signed and unsigned integers in comparisons\n");
    printf("- Failing to account for null-terminator in strings\n\n");

    // Example of integer overflow
    int max_int = INT_MAX;
    printf("Integer overflow example:\n");
    printf("INT_MAX: %d\n", max_int);
    printf("INT_MAX + 1: %d\n\n", max_int + 1);
}

void advanced_tips() {
    printf("12. Advanced Tips and Optimizations\n");
    printf("-----------------------------------\n");
    printf("- Use bit fields for compact data structures\n");
    printf("- Leverage SIMD instructions for parallel data processing\n");
    printf("- Consider cache-friendly data layouts for performance\n");
    printf("- Use inline functions for small, frequently called functions\n");
    printf("- Understand and utilize type promotion rules\n");
    printf("- Use union for type-punning (with caution due to strict aliasing rules)\n");
    printf("- Utilize compiler-specific attributes for fine-grained control\n\n");

    // Example of a bit field
    struct Flags {
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
    } flags = {1, 0, 1};

    printf("Bit field example:\n");
    printf("sizeof(struct Flags): %zu bytes\n", sizeof(struct Flags));
    printf("flags: %d %d %d\n\n", flags.flag1, flags.flag2, flags.flag3);
}

void real_world_use_cases() {
    printf("13. Real-world Use Cases\n");
    printf("--------------------------\n");
    printf("- Embedded systems: Using fixed-width types for hardware registers\n");
    printf("- Financial software: Using decimal types for precise calculations\n");
    printf("- Scientific computing: Leveraging complex numbers and high-precision types\n");
    printf("- Game development: Optimizing data types for performance and memory usage\n");
    printf("- Network protocols: Defining packet structures with specific data types\n");
    printf("- Operating systems: Using volatile for memory-mapped I/O\n\n");

    // Example: Network packet header
    struct PacketHeader {
        uint16_t source_port;
        uint16_t dest_port;
        uint32_t sequence_number;
        uint32_t ack_number;
        uint16_t flags;
    };

    printf("Size of PacketHeader: %zu bytes\n\n", sizeof(struct PacketHeader));
}

void integration_with_other_concepts() {
    printf("14. Integration with Other Concepts\n");
    printf("-----------------------------------\n");
    printf("- Data structures: Building blocks for complex data types\n");
    printf("- Memory management: Understanding data sizes for proper allocation\n");
    printf("- Concurrency: Atomic types for thread-safe operations\n");
    printf("- I/O operations: Proper type usage for file and network I/O\n");
    printf("- API design: Choosing appropriate types for function parameters and return values\n");
    printf("- Serialization: Mapping data types to standardized formats\n\n");

    // Example: Atomic operation
    #include <stdatomic.h>
    atomic_int shared_counter = ATOMIC_VAR_INIT(0);
    atomic_fetch_add(&shared_counter, 1);
    printf("Atomic counter value: %d\n\n", atomic_load(&shared_counter));
}

void faqs_and_troubleshooting() {
    printf("15. FAQs and Troubleshooting\n");
    printf("----------------------------\n");
    printf("Q: Why does my floating-point comparison fail?\n");
    printf("A: Use an epsilon value for approximate equality: if (fabs(a - b) < EPSILON)\n\n");

    printf("Q: How can I determine the size of a type on my system?\n");
    printf("A: Use the sizeof operator: printf(\"Size of int: %%zu bytes\\n\", sizeof(int));\n\n");

    printf("Q: What's the difference between size_t and int?\n");
    printf("A: size_t is unsigned and guaranteed to hold the size of the largest object. Use it for sizes and indices.\n\n");

    printf("Q: What's the difference between size_t and int?\n");
    printf("A: size_t is unsigned and guaranteed to hold the size of the largest object. Use it for sizes and indices.\n\n");

    printf("Q: How do I handle platform-dependent integer sizes?\n");
    printf("A: Use fixed-width types from <stdint.h> or use the intmax_t and uintmax_t types for maximum portability.\n\n");

    printf("Q: Why am I getting unexpected results with char arithmetic?\n");
    printf("A: char can be signed or unsigned depending on the implementation. Use explicit signed char or unsigned char for consistency.\n\n");

    printf("Q: How can I represent boolean values in older C standards?\n");
    printf("A: Define macros or an enum: enum { FALSE = 0, TRUE = 1 };\n\n");

    printf("Q: What's the best way to initialize a large array?\n");
    printf("A: Use compound literals or designated initializers for partial initialization: int arr[1000] = {[0 ... 99] = 1};\n\n");
}

void recommended_tools_and_libraries() {
    printf("16. Recommended Tools and Libraries\n");
    printf("------------------------------------\n");
    printf("- Static Analysis Tools:\n");
    printf("  * Clang Static Analyzer: Detects bugs and quality issues in C code\n");
    printf("  * Cppcheck: Detects various types of bugs and suggests improvements\n\n");

    printf("- Debugging and Profiling Tools:\n");
    printf("  * Valgrind: Memory debugging, memory leak detection, and profiling\n");
    printf("  * GDB (GNU Debugger): Powerful debugger for inspecting program state\n\n");

    printf("- Libraries for Extended Functionality:\n");
    printf("  * GMP (GNU Multiple Precision Arithmetic Library): For arbitrary-precision arithmetic\n");
    printf("  * decimal.h (from IBM): For decimal floating-point arithmetic\n");
    printf("  * fenv.h: For controlling floating-point environment\n\n");

    printf("- Build Systems and Package Managers:\n");
    printf("  * CMake: Cross-platform build system\n");
    printf("  * Conan: C/C++ package manager\n\n");

    printf("- Code Formatting and Style Checking:\n");
    printf("  * clang-format: Code formatter for maintaining consistent style\n");
    printf("  * vera++: Static analysis tool for enforcing coding standards\n\n");

    printf("- Documentation Generation:\n");
    printf("  * Doxygen: Generate documentation from source code comments\n\n");

    printf("- Unit Testing Frameworks:\n");
    printf("  * Unity: Simple unit testing framework for C\n");
    printf("  * Check: Unit testing framework for C with support for fork-based tests\n\n");
}

// Add this to the main function
int main() {
    
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