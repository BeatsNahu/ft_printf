*This project was created as part of the 42 curriculum by alopez-t.*

# Libft - Your first library

## Description
Libft is a custom C library containing a collection of general-purpose functions. The objective of this project is to understand how standard C library (libc) functions work under the hood by rewriting them from scratch. This library will serve as a foundational toolset for future C projects in the 42 curriculum.

## Library Contents

### Part 1: Libc Functions
Re-implementations of standard C library functions.
* **Character checks & manipulation:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`, `ft_toupper`, `ft_tolower`.
* **String manipulation:** `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`, `ft_strdup`.
* **Memory manipulation:** `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`.
* **Conversion:** `ft_atoi`.

### Part 2: Additional Functions
Utility functions not strictly present in the standard libc.
* **String operations:** `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`.
* **Conversion:** `ft_itoa`.
* **File descriptor output:** `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`.

### Part 3: Linked Lists (Bonus)
Functions to create and manipulate a custom `t_list` structure.
* **List operations:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

## Instructions

### Compilation
The library is compiled using the provided `Makefile`. It adheres to the strict standard of using `cc` with `-Wall -Werror -Wextra` flags.

Run the following commands in the root directory:
* `make`: Compiles the mandatory functions into `libft.a`.
* `make clean`: Removes all compiled `.o` object files.
* `make fclean`: Removes the object files and the `libft.a` binary.
* `make re`: Fully recompiles the library.

### Usage
To use this library in your projects:
1. Include the header in your C source files: `#include "libft.h"`
2. Compile your program linking the library: `cc your_program.c -L. -libft`

## Resources
* **AI Usage:** AI was used as a conceptual learning tool to understand pointer arithmetic and memory allocation nuances (e.g., the difference between `memcpy` and `memmove`). No code was directly generated or copied from AI, ensuring strict adherence to the pedagogical goals of building foundational skills manually.
* **References:** GNU C Library Manual, Linux man pages, Geekforgeeks.org, libftTester repository
