#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
 * Arrays and Strings - Character arrays and strings in C Programming Language
 * ==========================================================================
 *
 * 1. Overview:
 * ------------
 * In C, strings are represented as arrays of characters (char arrays) terminated by a null character '\0'.
 * They are fundamental for text processing, input/output operations, and data manipulation.
 * Common use cases include user input handling, file I/O, and text-based data structures.
 *
 * 2. Syntax, Key Concepts, and Code Examples:
 * -------------------------------------------
 */

// Basic string declaration and initialization
void basic_string_operations() {
    char str1[] = "Hello"; // Compiler automatically adds '\0'
    char str2[6] = {'W', 'o', 'r', 'l', 'd', '\0'}; // Explicit null termination
    char str3[20]; // Uninitialized string

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    // String input
    printf("Enter a string: ");
    fgets(str3, sizeof(str3), stdin);
    str3[strcspn(str3, "\n")] = '\0'; // Remove newline character
    printf("You entered: %s\n", str3);

    // String length
    printf("Length of str1: %zu\n", strlen(str1));

    // String copy
    char str4[20];
    strcpy(str4, str1);
    printf("Copied string: %s\n", str4);

    // String concatenation
    strcat(str4, str2);
    printf("Concatenated string: %s\n", str4);

    // String comparison
    if (strcmp(str1, str2) == 0) {
        printf("str1 and str2 are equal\n");
    } else {
        printf("str1 and str2 are not equal\n");
    }
}

// Advanced string manipulation
void advanced_string_operations() {
    char str[] = "Hello, World!";
    char *token;

    // String tokenization
    token = strtok(str, " ,!");
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = strtok(NULL, " ,!");
    }

    // String searching
    char haystack[] = "needle in a haystack";
    char needle[] = "needle";
    char *result = strstr(haystack, needle);
    if (result) {
        printf("'%s' found at position: %ld\n", needle, result - haystack);
    } else {
        printf("'%s' not found\n", needle);
    }

    // Case conversion
    char mixed_case[] = "MiXeD cAsE";
    for (int i = 0; mixed_case[i]; i++) {
        mixed_case[i] = tolower(mixed_case[i]);
    }
    printf("Lowercase: %s\n", mixed_case);

    for (int i = 0; mixed_case[i]; i++) {
        mixed_case[i] = toupper(mixed_case[i]);
    }
    printf("Uppercase: %s\n", mixed_case);
}

/*
 * 3. Best Practices, Common Pitfalls, and Advanced Tips:
 * ------------------------------------------------------
 * Best Practices:
 * - Always null-terminate strings manually when not using string literals.
 * - Use strncpy() instead of strcpy() to prevent buffer overflows.
 * - Check return values of string functions for error handling.
 * - Use const for string parameters that shouldn't be modified.
 *
 * Common Pitfalls:
 * - Buffer overflows due to insufficient array size.
 * - Forgetting to null-terminate strings.
 * - Using strcmp() incorrectly (remember it returns 0 for equal strings).
 *
 * Advanced Tips:
 * - Use SSE (Streaming SIMD Extensions) for faster string operations in performance-critical code.
 * - Implement custom string functions for specific use cases to optimize performance.
 * - Use static analysis tools to detect potential string-related vulnerabilities.
 */

// Example of a memory-safe string copy function
char* safe_strcpy(char* dest, size_t dest_size, const char* src) {
    if (dest == NULL || src == NULL || dest_size == 0) {
        return NULL;
    }
    
    size_t src_len = strlen(src);
    if (src_len >= dest_size) {
        src_len = dest_size - 1;
    }
    
    memcpy(dest, src, src_len);
    dest[src_len] = '\0';
    
    return dest;
}

// Demonstrating the safe string copy function
void demonstrate_safe_strcpy() {
    char dest[10];
    const char* src = "This is a very long string that would cause buffer overflow";
    
    safe_strcpy(dest, sizeof(dest), src);
    printf("Safely copied string: %s\n", dest);
}

/*
 * 4. Integration and Real-World Applications:
 * -------------------------------------------
 * - Parsing configuration files: Using string operations to read and interpret config files.
 * - Network protocols: Handling text-based protocols like HTTP or SMTP.
 * - Database queries: Constructing and parsing SQL queries.
 * - Command-line interfaces: Parsing user input and formatting output.
 */

// Simple key-value parser (simulating a basic config file reader)
typedef struct {
    char key[50];
    char value[100];
} ConfigItem;

#define MAX_CONFIG_ITEMS 10

void parse_config_line(const char* line, ConfigItem* item) {
    char* equals_pos = strchr(line, '=');
    if (equals_pos) {
        size_t key_length = equals_pos - line;
        strncpy(item->key, line, key_length);
        item->key[key_length] = '\0';
        
        strcpy(item->value, equals_pos + 1);
        
        // Trim whitespace
        char* end = item->key + strlen(item->key) - 1;
        while (end > item->key && isspace(*end)) *end-- = '\0';
        
        char* start = item->value;
        while (*start && isspace(*start)) start++;
        memmove(item->value, start, strlen(start) + 1);
    }
}

void simulate_config_parser() {
    const char* config_lines[] = {
        "database_host = localhost",
        "database_port = 5432",
        "max_connections = 100"
    };
    ConfigItem config_items[MAX_CONFIG_ITEMS];
    int item_count = 0;

    for (int i = 0; i < 3 && item_count < MAX_CONFIG_ITEMS; i++) {
        parse_config_line(config_lines[i], &config_items[item_count++]);
    }

    printf("Parsed configuration:\n");
    for (int i = 0; i < item_count; i++) {
        printf("%s: %s\n", config_items[i].key, config_items[i].value);
    }
}

/*
 * 5. FAQs and Troubleshooting:
 * ----------------------------
 * Q: Why does my string comparison always return false?
 * A: Make sure you're using strcmp() and not comparing the string pointers directly.
 *
 * Q: How do I remove the newline character from fgets() input?
 * A: Use str[strcspn(str, "\n")] = '\0'; after fgets().
 *
 * Q: How can I convert a string to an integer?
 * A: Use the atoi() function from <stdlib.h> or strtol() for more control.
 *
 * Q: How do I handle Unicode strings in C?
 * A: Use wide character strings (wchar_t) and the corresponding wide string functions.
 *
 * 6. Recommended Tools and Libraries:
 * -----------------------------------
 * - GLib: Provides advanced string manipulation functions.
 * - ICU (International Components for Unicode): For robust Unicode support.
 * - PCRE (Perl Compatible Regular Expressions): For complex string pattern matching.
 * - Valgrind: For detecting memory leaks and buffer overflows in string operations.
 */

// Main function to demonstrate all concepts
int main() {
    printf("Basic String Operations:\n");
    printf("------------------------\n");
    basic_string_operations();

    printf("\nAdvanced String Operations:\n");
    printf("---------------------------\n");
    advanced_string_operations();

    printf("\nSafe String Copy Demonstration:\n");
    printf("-------------------------------\n");
    demonstrate_safe_strcpy();

    printf("\nConfig Parser Simulation:\n");
    printf("-------------------------\n");
    simulate_config_parser();

    return 0;
}