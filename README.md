# get_next_line

*This project has been created as part of the 42 curriculum by mmadouan.*

## Description

The `get_next_line` project is an exercise in reading a file descriptor line by line in C. The goal is to create a function `get_next_line(int fd)` that returns the next line from the file descriptor `fd` each time it is called. The implementation must handle multiple lines, large files, and memory efficiently, using linked lists to store the contents of each line instead of string manipulation functions.

The project challenges you to work with low-level memory management and dynamic memory allocation while learning how to manipulate buffers and file descriptors. It also provides an opportunity to become familiar with linked list structures in C.

## Instructions

### Compilation

To compile the project, you need to have the following files:

- `get_next_line.c`: The main function file containing the implementation of `get_next_line`.
- `get_next_line_utils.c`: A utility file with helper functions, such as linked list operations and buffer management.

You can compile the project with the following command:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c -o get_next_line
