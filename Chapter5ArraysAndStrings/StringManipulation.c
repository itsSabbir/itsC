#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

/*
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
*/

// 1. Overview and Historical Context
/*
String manipulation in C involves working with arrays of characters.
C doesn't have a built-in string type, so strings are represented as
arrays of chars terminated by a null character '\0'.

History:
- Introduced with the C language in the early 1970s by Dennis Ritchie
- Initially, string handling was done manually
- Standard string functions were later added to the C standard library

Relevance in modern software:
- Foundation for many higher-level languages (e.g., C++, Objective-C)
- Essential in systems programming, embedded systems, and performance-critical applications
- Provides low-level control over memory and performance

Comparison to other languages:
- More manual memory management compared to languages like Java or Python
- Offers direct memory access, allowing for highly optimized code
- Lacks built-in bounds checking, requiring more careful programming
*/

// 2. Syntax, Key Concepts, and Code Examples

// Basic string declaration and initialization
void basic_string_ops() {
    char str1[] = "Hello";  // Array size is automatically set to 6 (5 chars + '\0')
    char str2[20] = "World";  // Array size is explicitly set, remaining space is filled with '\0'
    char str3[6];  // Uninitialized array

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    // Copying strings
    strcpy(str3, str1);  // Copy str1 to str3
    printf("str3 after strcpy: %s\n", str3);

    // String length
    printf("Length of str1: %zu\n", strlen(str1));

    // String concatenation
    strcat(str2, "!");
    printf("str2 after strcat: %s\n", str2);
}

// String comparison
void string_comparison() {
    char str1[] = "apple";
    char str2[] = "banana";

    int result = strcmp(str1, str2);
    if (result < 0) {
        printf("%s comes before %s\n", str1, str2);
    } else if (result > 0) {
        printf("%s comes after %s\n", str1, str2);
    } else {
        printf("%s is equal to %s\n", str1, str2);
    }

    // Case-insensitive comparison
    if (strcasecmp(str1, "APPLE") == 0) {
        printf("strcasecmp: strings are equal ignoring case\n");
    }
}

// Searching within strings
void string_searching() {
    char haystack[] = "needle in a haystack";
    char needle[] = "needle";

    // Find first occurrence of a substring
    char *result = strstr(haystack, needle);
    if (result) {
        printf("'%s' found at position: %ld\n", needle, result - haystack);
    }

    // Find first occurrence of a character
    char ch = 'a';
    result = strchr(haystack, ch);
    if (result) {
        printf("'%c' first found at position: %ld\n", ch, result - haystack);
    }

    // Find last occurrence of a character
    result = strrchr(haystack, ch);
    if (result) {
        printf("'%c' last found at position: %ld\n", ch, result - haystack);
    }
}

// String tokenization
void string_tokenization() {
    char str[] = "This,is,a,comma-separated,string";
    const char delim[] = ",";
    char *token;

    // First call to strtok
    token = strtok(str, delim);

    // Subsequent calls
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, delim);
    }
}

// Advanced string manipulation
void advanced_string_ops() {
    // Using sprintf for string formatting
    char buffer[50];
    int day = 15, month = 9, year = 2024;
    sprintf(buffer, "Date: %02d/%02d/%04d", day, month, year);
    printf("Formatted date: %s\n", buffer);

    // Using sscanf for string parsing
    char input[] = "John Doe 30";
    char name[20];
    int age;
    sscanf(input, "%s %*s %d", name, &age);  // %*s skips the middle name
    printf("Name: %s, Age: %d\n", name, age);

    // String to number conversion
    char num_str[] = "12345";
    int num = atoi(num_str);
    printf("Converted number: %d\n", num);

    // Number to string conversion
    char str[20];
    snprintf(str, sizeof(str), "%d", num);
    printf("Number converted back to string: %s\n", str);
}

// Custom string manipulation functions
size_t custom_strlen(const char *str) {
    const char *s;
    for (s = str; *s; ++s);
    return (s - str);
}

char *custom_strcpy(char *dest, const char *src) {
    char *d = dest;
    while ((*d++ = *src++));
    return dest;
}

// 3. Best Practices, Common Pitfalls, and Advanced Tips

/*
Best Practices:
1. Always null-terminate strings.
2. Use strncpy instead of strcpy to prevent buffer overflows.
3. Check return values of string functions for error handling.
4. Use const for string parameters that shouldn't be modified.
5. Prefer standard library functions over custom implementations for better performance and reliability.

Common Pitfalls:
1. Buffer overflow: Writing beyond array bounds.
2. Off-by-one errors: Forgetting to account for the null terminator.
3. Using strcpy without checking destination buffer size.
4. Modifying string literals (undefined behavior).
5. Failing to null-terminate strings after manipulation.

Advanced Tips:
1. Use memcpy for performance when copying fixed-size data.
2. Consider using strnlen for safer string length calculation.
3. Use strdup for dynamic string duplication (remember to free).
4. Implement your own string class for more complex projects.
5. Use static analysis tools to catch potential string-related bugs.
*/

// Demonstrating best practices and avoiding pitfalls
void string_best_practices() {
    char src[] = "This is a long string";
    char dest[10];  // Intentionally small to demonstrate safe practices

    // Using strncpy safely
    strncpy(dest, src, sizeof(dest) - 1);
    dest[sizeof(dest) - 1] = '\0';  // Ensure null-termination
    printf("Safely copied string: %s\n", dest);

    // Checking return value
    if (strlen(dest) == sizeof(dest) - 1) {
        printf("Warning: String may have been truncated\n");
    }

    // Using const for string parameters
    const char *read_only = "Read-only string";
    // read_only[0] = 'r';  // This would cause undefined behavior

    // Demonstrating strnlen for safer length calculation
    size_t len = strnlen(src, sizeof(src));
    printf("Length of src (max %zu): %zu\n", sizeof(src), len);
}

// 4. Integration and Real-World Applications

/*
String manipulation is crucial in various real-world applications:

1. Web Development:
   - Parsing URL parameters
   - Handling form inputs
   - Generating dynamic HTML content

2. Data Processing:
   - Parsing CSV or JSON data
   - Cleaning and normalizing text data
   - Implementing search functionality

3. System Programming:
   - Parsing command-line arguments
   - Processing configuration files
   - Handling file paths and names

4. Network Programming:
   - Parsing network protocols
   - Handling IP addresses and hostnames
   - Processing email headers and content

5. Cryptography:
   - Encoding and decoding base64
   - Generating and verifying hashes
   - Implementing simple encryption schemes
*/

// Example: Simple URL parser
void parse_url(const char *url) {
    char schema[10], host[100], path[100];
    sscanf(url, "%9[^:]://%99[^/]/%99[^\n]", schema, host, path);
    printf("Schema: %s\nHost: %s\nPath: %s\n", schema, host, path);
}

// 5. Advanced Concepts and Emerging Trends

/*
Advanced Concepts:
1. Unicode and multibyte character support (e.g., using wchar_t)
2. String interning for performance optimization
3. Rope data structures for efficient string manipulation
4. Lock-free string algorithms for concurrent programming

Emerging Trends:
1. Integration with newer C standards (C11, C17, C2x)
2. Adoption of safer string handling functions (e.g., strncpy_s)
3. Increased focus on security in string manipulation (e.g., constant-time comparison)
4. Use of string views for non-owning string references
*/

// Example: Using wide characters for Unicode support
void unicode_example() {
    wchar_t wide_str[] = L"こんにちは";  // "Hello" in Japanese
    printf("Wide string length: %zu\n", wcslen(wide_str));
}

// 6. FAQs and Troubleshooting

/*
Q: Why does my string comparison always return false?
A: Make sure you're using strcmp() and not comparing the string pointers directly.

Q: How do I convert a string to uppercase?
A: Use a loop with toupper() from <ctype.h> for each character.

Q: Why am I getting segmentation fault when using strcpy?
A: Ensure the destination buffer is large enough. Use strncpy() for safer copying.

Q: How can I remove whitespace from the beginning and end of a string?
A: Implement a trim function using isspace() and memmove().

Q: Is it safe to use gets() for user input?
A: No, gets() is dangerous and removed from C11. Use fgets() instead.
*/

// Troubleshooting example: Trimming whitespace
char *trim(char *str) {
    char *end;
    // Trim leading space
    while(isspace((unsigned char)*str)) str++;
    if(*str == 0) return str;  // All spaces?
    // Trim trailing space
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
    // Write new null terminator
    *(end+1) = 0;
    return str;
}

// 7. Recommended Tools, Libraries, and Resources

/*
Tools and Libraries:
1. GLib: Provides advanced string manipulation functions.
2. ICU (International Components for Unicode): For Unicode and internationalization support.
3. PCRE (Perl Compatible Regular Expressions): For powerful regex capabilities.
4. Valgrind: For detecting memory leaks and other issues in string handling.
5. Splint: Static analysis tool to catch potential string-related bugs.

Resources:
1. "C Programming: A Modern Approach" by K. N. King
2. "Expert C Programming: Deep C Secrets" by Peter van der Linden
3. C99 and C11 standards documents
4. Online resources: cppreference.com, en.cppreference.com/w/c

Further Reading:
1. "Algorithms on Strings, Trees, and Sequences" by Dan Gusfield
2. "Beautiful Code: Leading Programmers Explain How They Think" (Chapter on string algorithms)
*/

// 8. Performance Analysis and Optimization

// Benchmarking function
double benchmark(void (*func)(void), int iterations) {
    clock_t start, end;
    start = clock();
    for (int i = 0; i < iterations; i++) {
        func();
    }
    end = clock();
    return ((double) (end - start)) / CLOCKS_PER_SEC;
}

// Example functions to benchmark
void str_copy_test() {
    char src[] = "This is a test string";
    char dest[100];
    strcpy(dest, src);
}

void str_cat_test() {
    char str[100] = "Hello";
    strcat(str, " World");
}

// Performance comparison
void performance_comparison() {
    printf("Benchmarking string operations:\n");
    printf("strcpy: %f seconds\n", benchmark(str_copy_test, 1000000));
    printf("strcat: %f seconds\n", benchmark(str_cat_test, 1000000));
}

// 9. How to Contribute

/*
To contribute to this cheat sheet:
1. Fork the repository containing this file.
2. Make your changes or additions.
3. Ensure all code examples are correct and follow the established style.
4. Add comments explaining new concepts or functions.
5. Update the Table of Contents if necessary.
6. Submit a pull request with a clear description of your changes.

Guidelines for contributions:
- Maintain the current format and style.
- Provide working code examples for new concepts.
- Include performance considerations for new functions.
- Add relevant references or citations for advanced topics.
*/

// Main function to demonstrate all concepts
int main() {
    printf("C String Manipulation Expert-Level Cheat Sheet\n\n");

    printf("Basic String Operations:\n");
    basic_string_ops();
    printf("\n");

    printf("String Comparison:\n");
    string_comparison();
    printf("\n");

    printf("String Searching:\n");
    string_searching();
    printf("\n");

    printf("String Tokenization:\n");
    string_tokenization();
    printf("\n");

    printf("Advanced String Operations:\n");
    advanced_string_ops();
    printf("\n");

    printf("Custom String Functions:\n");
    char test_str[] = "Test";
    printf("Custom strlen: %zu\n", custom_strlen(test_str));
    char test_copy[10];
    custom_strcpy(test_copy, test_str);
    printf("Custom strcpy result: %s\n", test_copy);
    printf("\n");

    printf("String Best Practices:\n");
    string_best_practices();
    printf("\n");

    printf("URL Parsing Example:\n");
    parse_url("https://www.example.com/path/to/resource");
    printf("\n");

    printf("Unicode Example:\n");
    unicode_example();
    printf("\n");

    printf("Trim Function Example:\n");
    char trim_test[] = "  Hello, World!  ";
    printf("Before trim: '%s'\n", trim_test);
    printf("After trim: '%s'\n", trim(trim_test));
    printf("\n");

    printf("Performance Analysis:\n");
    performance_comparison();

    return 0;
}