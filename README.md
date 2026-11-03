*This project has been created as part of the 42 curriculum by alopez-t.*  
*(Este proyecto ha sido creado como parte del currículo de 42 por alopez-t.)*

# ft_printf

## Description
The **ft_printf** project consists of recoding the famous `printf()` function from the standard C library (`libc`). The primary objective is to learn how to handle variadic functions in C using `<stdarg.h>` (`va_start`, `va_arg`, `va_copy`, `va_end`), and to design a modular, scalable architecture for formatting and outputting different data types across various numeric bases.

### Supported Conversions (Mandatory Part)
| Specifier | Description |
| :---: | :--- |
| `%c` | Prints a single character. |
| `%s` | Prints a string of characters (`char *`). |
| `%p` | Prints a pointer address (`void *`) in hexadecimal format with a `0x` prefix. |
| `%d` | Prints a signed decimal integer (base 10). |
| `%i` | Prints a signed integer in base 10. |
| `%u` | Prints an unsigned decimal number (base 10). |
| `%x` | Prints an unsigned hexadecimal number in lowercase (`0-9`, `a-f`). |
| `%X` | Prints an unsigned hexadecimal number in uppercase (`0-9`, `A-F`). |
| `%%` | Prints a literal percent sign. |

### Flags and Modifiers (Bonus Part)
| Flag / Modifier | Description |
| :---: | :--- |
| `-` | Left-justify output within the minimum field width. |
| `0` | Zero-pad numbers to the left instead of using spaces. |
| `.` | Precision: minimum number of digits to print for numbers, or maximum string length. |
| `#` | Alternate form: prepends `0x` or `0X` to non-zero hexadecimal values. |
| `+` | Forces a sign (`+` or `-`) to be output for signed numeric conversions. |
| `' '` *(space)* | Inserts a blank space before positive numbers if no sign is printed. |
| *field width* | Minimum number of characters to write to the output. |

---

## Instructions

### Compilation
The project includes a Makefile adhering to 42 Norminette standards with `-Wall -Wextra -Werror` flags and strictly preventing relinking:

- **Compile mandatory library:**
  ```bash
  make
  ```
  Generates `libftprintf.a`.

- **Compile with bonus features:**
  ```bash
  make bonus
  ```
  Generates `libftprintf.a` including full flag and width/precision parsing.

- **Clean object files:**
  ```bash
  make clean
  ```

- **Full clean (objects and library):**
  ```bash
  make fclean
  ```

- **Rebuild everything:**
  ```bash
  make re
  ```

### Usage
Include the header in your C source file:
```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s, number: %d, hex: %#X\n", "42", 42, 42);
	return (0);
}
```
Compile linking `libftprintf.a`:
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o my_program
```

---

## Technical Decisions & How It Works

### 1. Sequential Traversal & Flag Parser
- `ft_printf` iterates sequentially character by character through the format string.
- Ordinary characters are directly printed to standard output (`write(1, &str[i], 1)`), incrementing the total length counter.
- Whenever a `%` character is encountered, the conversion process begins:
  1. The `t_flags` state structure is reset to zero (`ft_bzero`).
  2. The parser `get_flags` scans forward to identify any combination of flags (`-`, `0`, `#`, ` `, `+`), the minimum field width, and optional precision (`.`).
  3. The conversion specifier character is saved into `flags->specifier`.

### 2. Function Pointer Dispatch Table (LUT)
Instead of chaining long `if / else if` conditionals, `ft_printf` uses a **Function Pointer Dispatch Table (Look-Up Table / Jump Table)** indexed directly by the ASCII character value of the specifier:
```c
static const t_print_func	g_dispatch[127] = {
	['c'] = print_char,
	['s'] = print_string,
	['%'] = print_percent,
	['p'] = print_pointer,
	['d'] = print_int,
	['i'] = print_int,
	['u'] = print_unsigned,
	['x'] = print_hex,
	['X'] = print_hex
};
```
Because all specifier handler functions share the exact same prototype:
```c
typedef int (*t_print_func)(va_list, t_flags *);
```
Passing the variadic arguments and the parsed flags structure is unified, concise, and allows instant $O(1)$ dispatching.

### 3. Centralized Formatting Engine (`print_universal`)
All numeric conversions (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) feed into a shared rendering engine (`print_universal`). This function abstracts:
- Prefix output (`-`, `+`, ` `, `0x`, `0X`).
- Precision zero padding (`flags->zeros`).
- Recursive base output (`h_putnbr_base`) using call-stack recursion without unnecessary heap allocations.
- Field width space/zero padding (`flags->pad`) aligned according to left/right justification flags.

---

## Resources & References

### Literature & Tutorials
- [Function Pointers | C Programming Tutorial (YouTube)](https://youtu.be/f_uWOWViYc0?si=elAwfmUpGRQcsXeX)
- [Function Dispatch Tables in C (Alice Goldfuss)](https://blog.alicegoldfuss.com/function-dispatch-tables/)
- [How arguments are passed to functions in C (YouTube)](https://youtu.be/MCVa1ZhQaqI?si=40p1joCZ-KgSjuvM)
- [How to create functions with a variable number of arguments using stdarg.h (YouTube)](https://youtu.be/3iX9a_l9W9Y?si=EEFtLdPtGTLfqCYl)
- [C Tutorial – 45. Variadic Functions (YouTube)](https://youtu.be/yPrOq2Io4D8?si=cdAgFj5nLJUr5MhH)
- [How Look Up Tables (LUTs) make your code Smaller, Faster, and Better (YouTube)](https://youtu.be/JPPxV3Hdz_A?si=Vmz6zkBcwhn8etnj)
- [Variable Functions (DigiPen CS120)](https://azrael.digipen.edu/~mmead/www/Courses/CS120/VariadicFunctions.html)
- [Coddy Tech - printf in C Documentation](https://coddy.tech/docs/es/c/printf)
- Linux Manual Pages: `man 3 printf`, `man 3 stdarg`.

### Testing Tools
- [Francinette ("paco") Framework by fsoares](https://github.com/xicodomingues/francinette)
- [Tripouille printfTester](https://github.com/Tripouille/printfTester)
- [Cacharle ft_printf_test](https://github.com/cacharle/ft_printf_test)

### Use of Artificial Intelligence
AI was used in an educational and advisory capacity as a **reviewer and tutor**:
- Providing conceptual explanations of C standard rules and POSIX formatting specifications to stimulate critical thinking and architectural reasoning.
- Assisting in debugging subtle edge cases in automated tester frameworks (such as diagnosing Makefile relink behavior under Francinette / paco and identifying tester compiler warnings).
