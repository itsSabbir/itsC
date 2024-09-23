/*
Expert-Level Cheat Sheet: File Handling - Error Handling in File Operations - in the C Programming Language
===========================================================================================================

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

1. Overview and Historical Context
==================================
Error handling in file operations is a critical aspect of C programming that ensures
robustness and reliability when working with external files. It involves detecting,
reporting, and gracefully handling errors that may occur during file I/O operations.

Key points:
- Essential for maintaining data integrity and program stability.
- Evolved alongside C's file I/O functions and error reporting mechanisms.
- Crucial for developing reliable and fault-tolerant software systems.

Historical context:
- Error handling in C dates back to its creation in the early 1970s.
- The errno mechanism was introduced to provide detailed error information.
- POSIX standards further refined error handling practices for file operations.

Relevance in modern software development:
- Critical for developing robust applications that interact with file systems.
- Essential in systems programming, data processing, and I/O-intensive applications.
- Important for maintaining security and preventing data corruption.

Comparison to other languages:
- C's approach is low-level compared to exception handling in languages like C++ or Java.
- Requires more explicit error checking than higher-level languages.
- Provides fine-grained control over error handling, suitable for system-level programming.

2. Syntax, Key Concepts, and Code Examples
==========================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

// Function prototypes
void basic_file_error_handling();
void advanced_file_error_handling();
void custom_error_handling();
void error_logging_example();
void file_locking_error_handling();
void asynchronous_io_error_handling();
void error_recovery_strategies();
void performance_comparison();

int main() {
    printf("C File Error Handling Cheat Sheet\n");
    printf("==================================\n\n");

    basic_file_error_handling();
    advanced_file_error_handling();
    custom_error_handling();
    error_logging_example();
    file_locking_error_handling();
    asynchronous_io_error_handling();
    error_recovery_strategies();
    performance_comparison();

    return 0;
}

void basic_file_error_handling() {
    printf("2.1 Basic File Error Handling\n");
    printf("------------------------------\n");

    FILE *file = fopen("nonexistent.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        printf("Error number: %d\n", errno);
        printf("Error message: %s\n", strerror(errno));
    } else {
        fclose(file);
    }
    printf("\n");
}

void advanced_file_error_handling() {
    printf("2.2 Advanced File Error Handling\n");
    printf("--------------------------------\n");

    FILE *file = fopen("test.txt", "w");
    if (file == NULL) {
        fprintf(stderr, "Failed to open file: %s\n", strerror(errno));
        return;
    }

    const char *data = "Hello, World!";
    size_t len = strlen(data);
    size_t written = fwrite(data, 1, len, file);
    
    if (written != len) {
        if (ferror(file)) {
            fprintf(stderr, "Error writing to file: %s\n", strerror(errno));
        } else {
            fprintf(stderr, "Partial write occurred\n");
        }
    }

    if (fclose(file) != 0) {
        fprintf(stderr, "Error closing file: %s\n", strerror(errno));
    }

    printf("Advanced error handling demonstrated\n\n");
}

// Custom error enum
typedef enum {
    NO_ERROR,
    FILE_OPEN_ERROR,
    FILE_READ_ERROR,
    FILE_WRITE_ERROR,
    FILE_CLOSE_ERROR
} FileError;

// Custom error handling function
void handle_file_error(FileError error) {
    switch (error) {
        case FILE_OPEN_ERROR:
            fprintf(stderr, "Failed to open file\n");
            break;
        case FILE_READ_ERROR:
            fprintf(stderr, "Error reading from file\n");
            break;
        case FILE_WRITE_ERROR:
            fprintf(stderr, "Error writing to file\n");
            break;
        case FILE_CLOSE_ERROR:
            fprintf(stderr, "Error closing file\n");
            break;
        default:
            fprintf(stderr, "Unknown error occurred\n");
    }
}

void custom_error_handling() {
    printf("2.3 Custom Error Handling\n");
    printf("-------------------------\n");

    FILE *file = fopen("test.txt", "r");
    if (file == NULL) {
        handle_file_error(FILE_OPEN_ERROR);
    } else {
        // Simulating a read error
        if (fgetc(file) == EOF && ferror(file)) {
            handle_file_error(FILE_READ_ERROR);
        }
        if (fclose(file) != 0) {
            handle_file_error(FILE_CLOSE_ERROR);
        }
    }
    printf("Custom error handling demonstrated\n\n");
}

void error_logging_example() {
    printf("2.4 Error Logging Example\n");
    printf("--------------------------\n");

    FILE *log_file = fopen("error.log", "a");
    if (log_file == NULL) {
        fprintf(stderr, "Failed to open log file: %s\n", strerror(errno));
        return;
    }

    // Simulating an error condition
    FILE *data_file = fopen("nonexistent.txt", "r");
    if (data_file == NULL) {
        time_t now = time(NULL);
        fprintf(log_file, "[%s] File open error: %s\n", ctime(&now), strerror(errno));
    } else {
        fclose(data_file);
    }

    fclose(log_file);
    printf("Error logging demonstrated\n\n");
}

#include <fcntl.h>
#include <unistd.h>

void file_locking_error_handling() {
    printf("2.5 File Locking Error Handling\n");
    printf("--------------------------------\n");

    int fd = open("locked_file.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    struct flock fl = {
        .l_type = F_WRLCK,
        .l_whence = SEEK_SET,
        .l_start = 0,
        .l_len = 0,
    };

    if (fcntl(fd, F_SETLK, &fl) == -1) {
        if (errno == EACCES || errno == EAGAIN) {
            printf("File is locked by another process\n");
        } else {
            perror("Error locking file");
        }
    } else {
        printf("File locked successfully\n");
        // Unlock the file
        fl.l_type = F_UNLCK;
        if (fcntl(fd, F_SETLK, &fl) == -1) {
            perror("Error unlocking file");
        }
    }

    close(fd);
    printf("\n");
}

#include <aio.h>

void asynchronous_io_error_handling() {
    printf("2.6 Asynchronous I/O Error Handling\n");
    printf("------------------------------------\n");

    int fd = open("async_test.txt", O_RDWR | O_CREAT, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return;
    }

    char buffer[128] = "Asynchronous I/O test data";
    struct aiocb cb = {
        .aio_fildes = fd,
        .aio_buf = buffer,
        .aio_nbytes = strlen(buffer),
        .aio_offset = 0,
    };

    if (aio_write(&cb) == -1) {
        perror("Error queuing async write");
    } else {
        while (aio_error(&cb) == EINPROGRESS) {
            // Wait for I/O to complete
        }

        int ret = aio_return(&cb);
        if (ret == -1) {
            perror("Async write failed");
        } else {
            printf("Async write succeeded, %d bytes written\n", ret);
        }
    }

    close(fd);
    printf("\n");
}

void error_recovery_strategies() {
    printf("2.7 Error Recovery Strategies\n");
    printf("------------------------------\n");

    FILE *file = fopen("important_data.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        // Attempt to create the directory and retry
        system("mkdir -p ./data");
        file = fopen("./data/important_data.txt", "w");
        if (file == NULL) {
            fprintf(stderr, "Recovery attempt failed\n");
            return;
        }
        printf("Recovery successful: file created in ./data directory\n");
    }

    // Simulating a write error
    if (fprintf(file, "Important data") < 0) {
        fprintf(stderr, "Write error occurred\n");
        // Attempt to flush the stream and retry
        fflush(file);
        if (fprintf(file, "Important data") < 0) {
            fprintf(stderr, "Recovery attempt failed\n");
        } else {
            printf("Recovery successful: data written after flush\n");
        }
    }

    fclose(file);
    printf("\n");
}

#define ITERATIONS 1000000

void performance_comparison() {
    printf("2.8 Performance Comparison\n");
    printf("---------------------------\n");

    clock_t start, end;
    double cpu_time_used;

    // Approach 1: Checking errno after each operation
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        FILE *file = fopen("perf_test.txt", "w");
        if (file == NULL) {
            continue;
        }
        fprintf(file, "Test");
        if (errno != 0) {
            // Handle error
        }
        fclose(file);
        if (errno != 0) {
            // Handle error
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time with frequent errno checks: %f seconds\n", cpu_time_used);

    // Approach 2: Minimal error checking
    start = clock();
    for (int i = 0; i < ITERATIONS; i++) {
        FILE *file = fopen("perf_test.txt", "w");
        if (file != NULL) {
            fprintf(file, "Test");
            fclose(file);
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Time with minimal error checking: %f seconds\n", cpu_time_used);

    printf("\n");
}

/*
3. Best Practices, Common Pitfalls, and Advanced Tips
=====================================================
Best Practices:
1. Always check return values of file operations.
2. Use appropriate error handling mechanisms (errno, perror, strerror).
3. Close files properly, even when errors occur.
4. Use fflush() to ensure data is written to disk.
5. Implement proper logging for file operation errors.

Common Pitfalls:
1. Ignoring return values of file operations.
2. Forgetting to close files, leading to resource leaks.
3. Not handling all possible error conditions.
4. Misinterpreting errno values.
5. Assuming file operations are always successful.

Advanced Tips:
1. Implement custom error handling and recovery mechanisms.
2. Use memory-mapped files for improved performance in certain scenarios.
3. Implement file locking for concurrent access scenarios.
4. Utilize asynchronous I/O for improved performance in I/O-bound applications.
5. Implement proper error propagation in complex systems.

Performance Considerations:
- Balance between thorough error checking and performance impact.
- Use buffered I/O (fread, fwrite) for better performance with small, frequent operations.
- Consider using mmap for large files that require frequent random access.

Scalability Strategies:
- Implement efficient error logging and monitoring for large-scale systems.
- Use connection pooling for database file operations in high-concurrency scenarios.
- Implement proper file locking strategies for multi-process/multi-threaded applications.

Edge Case Handling:
- Handle disk full scenarios gracefully.
- Implement timeout mechanisms for operations on network file systems.
- Handle unexpected file format changes or corruptions.

Memory Management Tips:
- Always free resources (close files, free memory) in error handling code paths.
- Use static analysis tools to detect resource leaks in error handling code.
- Implement proper cleanup in signal handlers that may interrupt file operations.

Testability:
- Implement mock file systems for unit testing file error handling code.
- Use fault injection techniques to simulate various file operation errors.
- Write comprehensive test cases covering various error scenarios.

4. Integration and Real-World Applications
==========================================
Integration with Major Concepts:
- Error handling in file operations is crucial in:
  * Database Management Systems: Ensuring data integrity and crash recovery.
  * Web Servers: Handling concurrent file access and logging.
  * Operating Systems: Managing file systems and device drivers.
  * Version Control Systems: Ensuring data consistency during commits and merges.

Real-World Examples:
1. Log Management Systems: Robust error handling for continuous log file writing.
2. Financial Systems: Ensuring transaction integrity in file-based operations.
3. Content Management Systems: Handling upload errors and file corruption scenarios.
4. Scientific Computing: Managing large datasets and handling I/O errors in simulations.
5. IoT Systems: Handling file operations on embedded devices with limited resources.

Use in Open-Source Projects:
- SQLite: Comprehensive error handling in its file-based database operations.
- Git: Robust file handling for version control operations.
- Apache Web Server: Advanced error handling in log file management.

Language-Specific Idioms:
- Using goto for centralized error handling and cleanup in C.
- Implementing RAII-like patterns using macros for resource management.
- Creating wrapper functions for common file operations with integrated error handling.

5. Advanced Concepts and Emerging Trends
========================================
- Exploring lock-free algorithms for file operations in multi-threaded environments.
- Implementing machine learning techniques for predictive error handling in file systems.
- Developing advanced error correction techniques for file systems in unreliable storage media.
- Investigating the use of formal verification methods for file I/O error handling code.
- Exploring new file system designs that inherently reduce the likelihood of certain types of errors.

6. FAQs and Troubleshooting
===========================
Q: How do I handle "Too many open files" errors?
A: Implement proper file descriptor management, use select() or poll() for multiple I/O streams, and consider increasing the system's file descriptor limit.

Q: What's the best way to handle disk full errors?
A: Check the return value of write operations, use ftruncate() to reduce file size if possible, implement a cleanup routine to free space, or provide user feedback to free up disk space.

Q: How can I recover from corrupted file errors?
A: Implement checksums or error-correcting codes, maintain backup copies, use journaling techniques, or implement a file recovery algorithm based on file format specifics.

Q: What's the proper way to handle network file system errors?
A: Implement timeouts, retry mechanisms with exponential backoff, handle network-specific errors (e.g., connection lost), and consider caching strategies to reduce network dependency.

Q: How do I ensure atomic file writes?
A: Use file locking mechanisms, implement a two-phase commit protocol, or use specialized system calls like rename() for atomic file replacement.

Troubleshooting Guide:
1. Unexpected EOF: Check if all data was read, verify file size, and ensure proper file closing.
2. Permission Denied: Verify file permissions, check process privileges, and ensure proper file ownership.
3. File Descriptor Leaks: Use tools like lsof to track open file descriptors, implement proper error handling to ensure file closure in all code paths.

Debugging Tips:
- Use strace or ltrace to trace system calls and library calls related to file operations.
- Implement verbose logging for all file operations in debug builds.
- Use memory debugging tools like Valgrind to detect file descriptor leaks.
- Implement assertions to check invariants in file handling code.

7. Recommended Tools, Libraries, and Resources
==============================================
Tools:
- Valgrind: For detecting memory leaks and file descriptor leaks.
- strace/ltrace: For tracing system calls and library calls related to file operations.
- fsck (File System Consistency Check): For detecting and repairing file system errors.
- inotify tools: For monitoring file system events and debugging file access issues.

Libraries:
- libev: Event-driven programming library useful for handling multiple file descriptors.
- libaio: Asynchronous I/O library for Linux, useful for high-performance file operations.
- libmagic: File type detection library, useful for validating file types before operations.

Resources:
- "Advanced Programming in the UNIX Environment" by W. Richard Stevens and Stephen A. Rago
- "The Linux Programming Interface" by Michael Kerrisk
- POSIX specifications for file operations and error handling
- Linux man pages, especially sections 2 (System calls) and 3 (Library functions)

8. Performance Analysis and Optimization
========================================
Profiling Techniques:
- Use tools like gprof or Valgrind's callgrind to profile file operation performance.
- Implement custom timing mechanisms for critical file operations.
- Use strace with timing information to analyze system call overhead.

Optimization Strategies:
- Use appropriate buffer sizes for file I/O operations.
- Implement read-ahead and write-behind techniques for sequential access patterns.
- Consider memory-mapped files for large, randomly accessed files.
- Use vectored I/O (readv/writev) for operations involving multiple buffers.

Example: Optimized buffered read
*/

#define BUFFER_SIZE 4096

ssize_t optimized_read(int fd, void *buf, size_t count) {
    static char buffer[BUFFER_SIZE];
    static size_t buffer_pos = 0;
    static ssize_t buffer_size = 0;

    size_t total_read = 0;
    while (total_read < count) {
        if (buffer_pos >= buffer_size) {
            buffer_size = read(fd, buffer, BUFFER_SIZE);
            if (buffer_size <= 0) {
                return (total_read > 0) ? total_read : buffer_size;
            }
            buffer_pos = 0;
        }

        size_t to_copy = (count - total_read < buffer_size - buffer_pos) ?
                         count - total_read : buffer_size - buffer_pos;
        memcpy(buf + total_read, buffer + buffer_pos, to_copy);
        total_read += to_copy;
        buffer_pos += to_copy;
    }

    return total_read;
}

/*
Performance Trade-offs:
- Balance between error checking frequency and performance impact.
- Consider the trade-off between data safety (e.g., frequent flushing) and performance.
- Evaluate the cost of file locking in multi-threaded scenarios vs. potential race conditions.

9. How to Contribute
====================
To contribute to this cheat sheet:
1. Fork the repository containing this file.
2. Make your changes or additions, ensuring they follow the established style and format.
3. Add your name to the contributors list below.
4. Submit a pull request with a clear description of your changes.

When contributing, consider the following:
- Ensure all code examples are correct and follow best practices.
- Provide clear explanations for complex error handling scenarios.
- Include practical, real-world examples where possible.
- Keep the content up-to-date with the latest C standards and best practices.
- Add relevant references or citations for advanced topics.

Contributors:
- [Your Name Here]

Remember to always test your code examples and verify the accuracy of any added information.

---

Final Note:
===========
Error handling in file operations is a critical aspect of robust C programming. It requires
a deep understanding of both the C language and the underlying operating system. As you
develop your skills, always prioritize data integrity and system stability when working
with files.

Remember that effective error handling is not just about catching errors, but also about
gracefully recovering from them when possible. Strive to write code that is not only
functionally correct but also resilient in the face of unexpected conditions.

Keep exploring, experimenting, and learning. The depth of knowledge you can gain about
file handling and error management is what sets apart truly skilled C programmers.

Happy coding!

*/