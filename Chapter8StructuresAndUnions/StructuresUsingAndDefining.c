/*
Cheat Sheet: Structures in C
=========================================

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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <time.h>

// Function prototypes
void section1_overview();
void section2_syntax_and_examples();
void section3_best_practices();
void section4_real_world_applications();
void section5_advanced_concepts();
void section6_faqs_and_troubleshooting();
void section7_tools_and_resources();
void section8_performance_analysis();
void section9_how_to_contribute();

// Example functions for demonstration
void basic_structure_example();
void nested_structure_example();
void structure_alignment_example();
void flexible_array_member_example();
void structure_as_function_parameter();
void structure_with_pointers();

int main() {
    printf("Cheat Sheet: Structures in C\n");
    printf("=========================================\n\n");

    section1_overview();
    section2_syntax_and_examples();
    section3_best_practices();
    section4_real_world_applications();
    section5_advanced_concepts();
    section6_faqs_and_troubleshooting();
    section7_tools_and_resources();
    section8_performance_analysis();
    section9_how_to_contribute();

    return 0;
}

void section1_overview() {
    printf("1. Overview and Historical Context\n");
    printf("----------------------------------\n");
    printf("Structures in C are composite data types that group related data elements of different types.\n");
    printf("They allow programmers to create custom data types, organizing data in a meaningful way.\n\n");
    
    printf("Historical Context:\n");
    printf("- Introduced in early versions of C (early 1970s) to support complex data organization\n");
    printf("- Evolved from simpler array and record concepts in earlier languages\n");
    printf("- Fundamental to C's philosophy of providing low-level control with high-level abstractions\n\n");
    
    printf("Significance in Modern Development:\n");
    printf("- Essential for creating abstract data types and implementing object-oriented designs in C\n");
    printf("- Crucial for interfacing with hardware and system calls in systems programming\n");
    printf("- Basis for more complex data structures and algorithms\n");
    printf("- Foundational concept for understanding classes in object-oriented languages\n\n");
}

void section2_syntax_and_examples() {
    printf("2. Syntax, Key Concepts, and Code Examples\n");
    printf("------------------------------------------\n");

    printf("Basic structure definition and usage:\n");
    basic_structure_example();

    printf("\nNested structures:\n");
    nested_structure_example();

    printf("\nStructure alignment and padding:\n");
    structure_alignment_example();

    printf("\nFlexible array members (C99 feature):\n");
    flexible_array_member_example();

    printf("\nStructures as function parameters:\n");
    structure_as_function_parameter();

    printf("\nStructures with pointers:\n");
    structure_with_pointers();
}

void section3_best_practices() {
    printf("3. Best Practices, Common Pitfalls, and Advanced Tips\n");
    printf("----------------------------------------------------\n");
    
    printf("Best Practices:\n");
    printf("1. Use meaningful names for structures and their members.\n");
    printf("2. Initialize structures completely to avoid undefined behavior.\n");
    printf("3. Use const for structure parameters that shouldn't be modified.\n");
    printf("4. Consider using typedef for cleaner syntax.\n");
    printf("5. Be aware of structure padding and alignment for performance and compatibility.\n\n");

    printf("Common Pitfalls:\n");
    printf("1. Forgetting to allocate memory for pointer members.\n");
    printf("2. Incorrect use of flexible array members.\n");
    printf("3. Misalignment of structures in memory-mapped I/O.\n");
    printf("4. Assuming structures are packed by default.\n");
    printf("5. Incorrect copying of structures with pointer members.\n\n");

    printf("Advanced Tips:\n");
    printf("1. Use designated initializers for clarity and maintainability.\n");
    printf("2. Leverage bit-fields for compact representation of flags or small integers.\n");
    printf("3. Understand and use structure packing pragmas when necessary.\n");
    printf("4. Implement opaque structures for data hiding and encapsulation.\n");
    printf("5. Use compound literals for temporary structure creation.\n\n");

    // Example: Designated initializers and bit-fields
    typedef struct {
        unsigned int is_visible : 1;
        unsigned int color : 3;
        unsigned int size : 4;
    } Flags;

    Flags f = {
        .is_visible = 1,
        .color = 5,
        .size = 10
    };

    printf("Flags example:\n");
    printf("is_visible: %d, color: %d, size: %d\n", f.is_visible, f.color, f.size);
    printf("Size of Flags: %zu bytes\n\n", sizeof(Flags));
}

void section4_real_world_applications() {
    printf("4. Integration and Real-World Applications\n");
    printf("------------------------------------------\n");
    
    printf("Real-world applications of structures:\n");
    printf("1. Implementing complex data structures (e.g., linked lists, trees)\n");
    printf("2. Representing records in database systems\n");
    printf("3. Defining packet formats in network programming\n");
    printf("4. Organizing game entity data in game development\n");
    printf("5. Interfacing with hardware registers in embedded systems\n\n");

    // Example: Simple linked list implementation
    typedef struct Node {
        int data;
        struct Node* next;
    } Node;

    Node* create_node(int data) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        if (new_node) {
            new_node->data = data;
            new_node->next = NULL;
        }
        return new_node;
    }

    void print_list(Node* head) {
        while (head) {
            printf("%d -> ", head->data);
            head = head->next;
        }
        printf("NULL\n");
    }

    printf("Linked list example:\n");
    Node* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    print_list(head);

    // Clean up
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    printf("\n");
}

void section5_advanced_concepts() {
    printf("5. Advanced Concepts and Emerging Trends\n");
    printf("----------------------------------------\n");
    
    printf("Advanced concepts:\n");
    printf("1. Anonymous structures and unions (C11 feature)\n");
    printf("2. Structure packing and alignment optimization\n");
    printf("3. Using structures with variadic functions\n");
    printf("4. Self-referential structures\n\n");

    printf("Emerging trends:\n");
    printf("1. Generic programming techniques with _Generic keyword (C11)\n");
    printf("2. Tagged unions for type-safe polymorphism\n");
    printf("3. Introspection and reflection-like capabilities\n");
    printf("4. Integration with modern memory models and concurrency\n\n");

    // Example: Anonymous structure (C11)
    struct {
        int x;
        struct {
            int y;
            int z;
        };
    } point = {1, {2, 3}};

    printf("Anonymous structure example:\n");
    printf("point: x=%d, y=%d, z=%d\n\n", point.x, point.y, point.z);

    // Example: Tagged union
    typedef enum { INT, FLOAT } Type;
    typedef struct {
        Type type;
        union {
            int i;
            float f;
        } value;
    } Number;

    Number num = {INT, {.i = 42}};
    printf("Tagged union example:\n");
    printf("Number: type=%d, value=%d\n\n", num.type, num.value.i);
}

void section6_faqs_and_troubleshooting() {
    printf("6. FAQs and Troubleshooting\n");
    printf("---------------------------\n");
    
    printf("FAQs:\n");
    printf("Q: What's the difference between struct and typedef struct?\n");
    printf("A: typedef struct creates an alias, allowing you to omit the struct keyword when declaring.\n\n");

    printf("Q: How do I properly copy a structure with pointer members?\n");
    printf("A: Use deep copying, allocating new memory for pointer members and copying their contents.\n\n");

    printf("Q: Can I compare two structures using == operator?\n");
    printf("A: No, you need to compare member by member or use memcmp() if the structures are tightly packed.\n\n");

    printf("Troubleshooting:\n");
    printf("1. Unexpected structure sizes: Check for padding and alignment issues.\n");
    printf("2. Segmentation faults: Ensure proper initialization and memory allocation for pointer members.\n");
    printf("3. Data corruption: Be cautious of shallow copying structures with pointers.\n");
    printf("4. Compiler warnings about incompatible pointer types: Ensure correct structure definitions.\n\n");

    // Example: Debugging structure layout
    struct DebugStruct {
        char a;
        int b;
        char c;
    };

    printf("Debugging structure layout:\n");
    printf("Size of DebugStruct: %zu bytes\n", sizeof(struct DebugStruct));
    printf("Offset of a: %zu\n", offsetof(struct DebugStruct, a));
    printf("Offset of b: %zu\n", offsetof(struct DebugStruct, b));
    printf("Offset of c: %zu\n\n", offsetof(struct DebugStruct, c));
}

void section7_tools_and_resources() {
    printf("7. Recommended Tools, Libraries, and Resources\n");
    printf("----------------------------------------------\n");
    
    printf("Tools:\n");
    printf("1. pahole: Analyze struct layout and padding\n");
    printf("2. gcc -Wpadded: Warn about suboptimal structure padding\n");
    printf("3. Valgrind: Detect memory errors related to structure usage\n");
    printf("4. gdb: Debug issues with structure manipulation\n\n");

    printf("Libraries:\n");
    printf("1. libffi: Foreign Function Interface library for working with structures across language boundaries\n");
    printf("2. protobuf-c: Protocol Buffers implementation for C, useful for serializing structures\n");
    printf("3. json-c: JSON manipulation library, helpful for converting structures to/from JSON\n\n");

    printf("Resources:\n");
    printf("1. 'The C Programming Language' by Kernighan and Ritchie\n");
    printf("2. 'Expert C Programming' by Peter van der Linden\n");
    printf("3. 'C Interfaces and Implementations' by David R. Hanson\n");
    printf("4. Online course: 'Advanced C Programming' on platforms like Coursera or edX\n\n");
}

void section8_performance_analysis() {
    printf("8. Performance Analysis and Optimization\n");
    printf("----------------------------------------\n");
    
    printf("Performance considerations:\n");
    printf("1. Structure padding can affect memory usage and access speed\n");
    printf("2. Cache line alignment of structures impacts performance in tight loops\n");
    printf("3. Structure copying can be expensive for large structures\n");
    printf("4. Indirect access through pointers may cause cache misses\n\n");

    printf("Optimization strategies:\n");
    printf("1. Order structure members to minimize padding\n");
    printf("2. Use packed structures cautiously for memory-constrained systems\n");
    printf("3. Consider using structure of arrays (SoA) instead of array of structures (AoS) for better cache utilization\n");
    printf("4. Leverage restrict keyword for pointer members to aid compiler optimizations\n\n");

    // Performance comparison example
    #define ARRAY_SIZE 10000000
    #define NUM_ITERATIONS 100

    typedef struct {
        int x;
        int y;
    } Point;

    typedef struct {
        int* x;
        int* y;
    } PointSoA;

    clock_t start, end;
    double cpu_time_used;

    // AoS (Array of Structures)
    Point* points = (Point*)malloc(ARRAY_SIZE * sizeof(Point));
    start = clock();
    for (int iter = 0; iter < NUM_ITERATIONS; iter++) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            points[i].x += 1;
            points[i].y += 2;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("AoS time: %f seconds\n", cpu_time_used);
    free(points);

    // SoA (Structure of Arrays)
    PointSoA pointsSoA;
    pointsSoA.x = (int*)malloc(ARRAY_SIZE * sizeof(int));
    pointsSoA.y = (int*)malloc(ARRAY_SIZE * sizeof(int));
    start = clock();
    for (int iter = 0; iter < NUM_ITERATIONS; iter++) {
        for (int i = 0; i < ARRAY_SIZE; i++) {
            pointsSoA.x[i] += 1;
            pointsSoA.y[i] += 2;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("SoA time: %f seconds\n", cpu_time_used);
    free(pointsSoA.x);
    free(pointsSoA.y);

    printf("\nNote: SoA often performs better due to better cache utilization,\n");
    printf("especially when operating on a single member across many structures.\n");
}

void section9_how_to_contribute() {
    printf("9. How to Contribute\n");
    printf("--------------------\n");
    
    printf("We welcome contributions to improve and extend this cheat sheet. Here's how you can contribute:\n\n");
    
    printf("1. Fork the repository on GitHub.\n");
    printf("2. Create a new branch for your feature or bug fix.\n");
    printf("3. Make your changes, ensuring they follow the existing style and format.\n");
    printf("4. Add new examples or improve existing ones, focusing on structures in C.\n");
    printf("5. Update the table of contents if you add new sections.\n");
    printf("6. Write clear commit messages describing your changes.\n");
    printf("7. Create a pull request with a description of your changes.\n");
    printf("8. Respond to any feedback or questions during the review process.\n\n");
    
    printf("Guidelines for contributions:\n");
    printf("- Ensure all code examples are correct, follow best practices, and compile without warnings.\n");
    printf("- Provide clear explanations for complex concepts related to structures in C.\n");
    printf("- Include practical, real-world examples that demonstrate effective use of structures.\n");
    printf("- Maintain a balance between beginner-friendly content and advanced topics.\n");
    printf("- Consider adding or updating performance benchmarks for structure-related operations.\n");
    printf("- Keep the content up-to-date with the latest C standards and best practices.\n");
    printf("- If adding new sections, ensure they fit logically within the existing structure.\n\n");
    
    printf("Specific areas for improvement:\n");
    printf("1. More examples of structure usage in systems programming.\n");
    printf("2. Advanced techniques for structure serialization and deserialization.\n");
    printf("3. Detailed explanations of structure memory layout and alignment.\n");
    printf("4. Comparisons of structure usage across different C standards (C89, C99, C11, C17).\n");
    printf("5. Examples of using structures with modern C features like _Generic and _Atomic.\n\n");
    
    printf("Thank you for helping to improve this resource for the C programming community!\n");
}

// Helper functions used in the examples

void basic_structure_example() {
    struct Person {
        char name[50];
        int age;
        float height;
    };

    struct Person john = {"John Doe", 30, 1.75f};
    printf("Name: %s, Age: %d, Height: %.2f\n", john.name, john.age, john.height);
}

void nested_structure_example() {
    struct Address {
        char street[100];
        char city[50];
        char country[50];
    };

    struct Employee {
        char name[50];
        int id;
        struct Address addr;
    };

    struct Employee emp = {
        "Jane Smith",
        1001,
        {"123 Main St", "Anytown", "USA"}
    };

    printf("Employee: %s, ID: %d\n", emp.name, emp.id);
    printf("Address: %s, %s, %s\n", emp.addr.street, emp.addr.city, emp.addr.country);
}

void structure_alignment_example() {
    struct Aligned {
        char a;
        int b;
        char c;
    };

    struct Packed {
        char a;
        int b;
        char c;
    } __attribute__((packed));

    printf("Size of Aligned: %zu\n", sizeof(struct Aligned));
    printf("Size of Packed: %zu\n", sizeof(struct Packed));
}

void flexible_array_member_example() {
    struct FlexArray {
        int size;
        float data[];
    };

    int n = 5;
    struct FlexArray* fa = (struct FlexArray*)malloc(sizeof(struct FlexArray) + n * sizeof(float));
    fa->size = n;
    for (int i = 0; i < n; i++) {
        fa->data[i] = i * 1.1f;
    }

    printf("Flexible array member example:\n");
    for (int i = 0; i < fa->size; i++) {
        printf("%.2f ", fa->data[i]);
    }
    printf("\n");

    free(fa);
}

void print_person(const struct Person* p) {
    printf("Name: %s, Age: %d\n", p->name, p->age);
}

void structure_as_function_parameter() {
    struct Person {
        char name[50];
        int age;
    };

    struct Person alice = {"Alice", 25};
    print_person(&alice);
}

void structure_with_pointers() {
    struct Node {
        int data;
        struct Node* next;
    };

    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = (struct Node*)malloc(sizeof(struct Node));
    head->next->data = 2;
    head->next->next = NULL;

    printf("Linked list: %d -> %d -> NULL\n", head->data, head->next->data);

    // Clean up
    free(head->next);
    free(head);
}