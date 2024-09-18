#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void overview();
void syntax_and_concepts();
void best_practices();
void integration_and_applications();
void faqs_and_troubleshooting();
void recommended_tools();

// 1. Overview
void overview() {
    printf("1. Overview of Multi-dimensional Arrays in C\n");
    printf("--------------------------------------------\n");
    printf("Multi-dimensional arrays in C are arrays of arrays, allowing you to create\n");
    printf("complex data structures to represent tables, matrices, and higher-dimensional data.\n");
    printf("They are crucial for various applications, including:\n");
    printf("- Image processing (2D arrays for pixel manipulation)\n");
    printf("- Scientific computing (matrices and tensors)\n");
    printf("- Game development (2D/3D world representation)\n");
    printf("- Database management (tables as 2D arrays)\n\n");
}

// 2. Syntax, Key Concepts, and Code Examples
void syntax_and_concepts() {
    printf("2. Syntax, Key Concepts, and Code Examples\n");
    printf("------------------------------------------\n");

    // 2D Array Declaration and Initialization
    printf("2.1 2D Array Declaration and Initialization\n\n");
    
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("int matrix[3][3] = {\n");
    printf("    {1, 2, 3},\n");
    printf("    {4, 5, 6},\n");
    printf("    {7, 8, 9}\n");
    printf("};\n\n");

    // Accessing and Modifying Elements
    printf("2.2 Accessing and Modifying Elements\n\n");
    
    printf("Accessing element: matrix[1][2] = %d\n", matrix[1][2]);
    matrix[1][2] = 10;
    printf("After modification: matrix[1][2] = %d\n\n", matrix[1][2]);

    // 3D Array Example
    printf("2.3 3D Array Example\n\n");
    
    int cube[2][2][2] = {
        {{1, 2}, {3, 4}},
        {{5, 6}, {7, 8}}
    };

    printf("int cube[2][2][2] = {\n");
    printf("    {{1, 2}, {3, 4}},\n");
    printf("    {{5, 6}, {7, 8}}\n");
    printf("};\n\n");

    printf("Accessing 3D element: cube[1][0][1] = %d\n\n", cube[1][0][1]);

    // Dynamic Allocation of 2D Array
    printf("2.4 Dynamic Allocation of 2D Array\n\n");
    
    int rows = 3, cols = 4;
    int **dynamic_matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        dynamic_matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Initialize and print dynamic matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dynamic_matrix[i][j] = i * cols + j;
            printf("%2d ", dynamic_matrix[i][j]);
        }
        printf("\n");
    }

    // Free dynamically allocated memory
    for (int i = 0; i < rows; i++) {
        free(dynamic_matrix[i]);
    }
    free(dynamic_matrix);

    printf("\n");
}

// 3. Best Practices, Common Pitfalls, and Advanced Tips
void best_practices() {
    printf("3. Best Practices, Common Pitfalls, and Advanced Tips\n");
    printf("-----------------------------------------------------\n");

    printf("3.1 Best Practices:\n");
    printf("- Use const for read-only arrays\n");
    printf("- Pass multi-dimensional arrays to functions with explicit dimensions\n");
    printf("- Use dynamic allocation for large arrays to avoid stack overflow\n");
    printf("- Consider using 1D arrays to represent multi-dimensional data for better cache performance\n\n");

    printf("3.2 Common Pitfalls:\n");
    printf("- Array index out of bounds (buffer overflow)\n");
    printf("- Incorrect row-major vs column-major access patterns\n");
    printf("- Memory leaks in dynamically allocated multi-dimensional arrays\n");
    printf("- Incorrect pointer arithmetic when working with flattened arrays\n\n");

    printf("3.3 Advanced Tips:\n");
    printf("- Use VLAs (Variable Length Arrays) for small, temporary arrays (C99 and later)\n");
    printf("- Implement cache-friendly algorithms by optimizing data access patterns\n");
    printf("- Utilize SIMD instructions for parallel processing of array elements\n");
    printf("- Consider using libraries like BLAS or LAPACK for high-performance matrix operations\n\n");

    // Example: Cache-friendly matrix multiplication
    printf("Example: Cache-friendly matrix multiplication\n\n");
    
    #define N 1000
    static double A[N][N], B[N][N], C[N][N];

    // Initialize matrices A and B (omitted for brevity)

    clock_t start = clock();

    // Cache-friendly multiplication
    for (int i = 0; i < N; i += 16) {
        for (int j = 0; j < N; j += 16) {
            for (int k = 0; k < N; k += 16) {
                for (int ii = i; ii < i + 16 && ii < N; ++ii) {
                    for (int jj = j; jj < j + 16 && jj < N; ++jj) {
                        for (int kk = k; kk < k + 16 && kk < N; ++kk) {
                            C[ii][jj] += A[ii][kk] * B[kk][jj];
                        }
                    }
                }
            }
        }
    }

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time taken for cache-friendly matrix multiplication: %f seconds\n\n", cpu_time_used);
}

// 4. Integration and Real-World Applications
void integration_and_applications() {
    printf("4. Integration and Real-World Applications\n");
    printf("------------------------------------------\n");

    printf("4.1 Integration with Other Concepts:\n");
    printf("- Data Structures: Multi-dimensional arrays as the basis for more complex structures\n");
    printf("- Algorithms: Fundamental to many algorithms (e.g., dynamic programming, graph algorithms)\n");
    printf("- Memory Management: Understanding row-major order and memory layout\n");
    printf("- Parallel Computing: Data partitioning for multi-threaded or distributed processing\n\n");

    printf("4.2 Real-World Applications:\n");
    printf("- Image Processing: Representing images as 2D or 3D arrays\n");
    printf("- Scientific Computing: Simulations, numerical methods, and data analysis\n");
    printf("- Game Development: Terrain maps, collision detection grids\n");
    printf("- Machine Learning: Feature matrices, convolutional neural networks\n");
    printf("- Financial Modeling: Time series data, correlation matrices\n\n");

    // Example: Simple image processing (edge detection)
    printf("Example: Simple image processing (edge detection)\n\n");
    
    #define WIDTH 5
    #define HEIGHT 5

    int image[HEIGHT][WIDTH] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    int kernel[3][3] = {
        {-1, -1, -1},
        {-1,  8, -1},
        {-1, -1, -1}
    };

    printf("Original Image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", image[i][j]);
        }
        printf("\n");
    }

    int result[HEIGHT][WIDTH] = {0};

    for (int i = 1; i < HEIGHT - 1; i++) {
        for (int j = 1; j < WIDTH - 1; j++) {
            int sum = 0;
            for (int ki = -1; ki <= 1; ki++) {
                for (int kj = -1; kj <= 1; kj++) {
                    sum += image[i + ki][j + kj] * kernel[ki + 1][kj + 1];
                }
            }
            result[i][j] = (sum > 0) ? 1 : 0;
        }
    }

    printf("\nEdge Detected Image:\n");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// 5. FAQs and Troubleshooting
void faqs_and_troubleshooting() {
    printf("5. FAQs and Troubleshooting\n");
    printf("----------------------------\n");

    printf("Q1: How do I pass a multi-dimensional array to a function?\n");
    printf("A1: You can pass it as a pointer to a pointer or with explicit dimensions:\n");
    printf("    void func(int (*arr)[COLS], int rows) or void func(int arr[][COLS], int rows)\n\n");

    printf("Q2: Why am I getting a segmentation fault when accessing array elements?\n");
    printf("A2: You might be accessing elements out of bounds. Always check array indices.\n\n");

    printf("Q3: How can I efficiently iterate over a large multi-dimensional array?\n");
    printf("A3: Use row-major order for better cache performance in C:\n");
    printf("    for(int i = 0; i < rows; i++)\n");
    printf("        for(int j = 0; j < cols; j++)\n");
    printf("            // Access array[i][j]\n\n");

    printf("Q4: How do I deallocate a dynamically allocated multi-dimensional array?\n");
    printf("A4: Free each row first, then free the array of pointers:\n");
    printf("    for(int i = 0; i < rows; i++)\n");
    printf("        free(array[i]);\n");
    printf("    free(array);\n\n");

    printf("Q5: Can I change the size of a multi-dimensional array at runtime?\n");
    printf("A5: Not for statically allocated arrays. Use dynamic allocation (malloc/realloc) for resizable arrays.\n\n");
}

// 6. Recommended Tools and Libraries
void recommended_tools() {
    printf("6. Recommended Tools and Libraries\n");
    printf("-----------------------------------\n");

    printf("- Valgrind: Memory debugging and profiling\n");
    printf("- GDB: Debugging C programs, including array-related issues\n");
    printf("- BLAS (Basic Linear Algebra Subprograms): High-performance matrix operations\n");
    printf("- LAPACK: Linear algebra package for more complex matrix operations\n");
    printf("- OpenMP: For parallel processing of large multi-dimensional arrays\n");
    printf("- Intel MKL: Math Kernel Library for optimized array and matrix operations\n");
    printf("- GNU Scientific Library (GSL): Scientific computing library with array utilities\n");
    printf("- Boost.MultiArray: C++ library for multi-dimensional arrays (if using C++)\n");
}

int main() {
    overview();
    syntax_and_concepts();
    best_practices();
    integration_and_applications();
    faqs_and_troubleshooting();
    recommended_tools();

    return 0;
}