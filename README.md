*Este proyecto ha sido creado como parte del currículo de 42 por alopez-t.*

# ft_printf

## Descripción
El proyecto **ft_printf** consiste en reimplementar la función `printf()` de la biblioteca estándar de C (`libc`). El objetivo primordial es aprender a manejar funciones variádicas en C haciendo uso de la cabecera `<stdarg.h>` (`va_start`, `va_arg`, `va_copy`, `va_end`), así como diseñar una arquitectura modular y extensible para el formateo de cadenas y conversiones numéricas en diferentes bases.

### Especificadores Soportados (Parte Obligatoria)
| Especificador | Conversión / Descripción |
| :---: | :--- |
| `%c` | Imprime un único carácter. |
| `%s` | Imprime una cadena de caracteres (`char *`). |
| `%p` | Imprime una dirección de puntero (`void *`) en formato hexadecimal con prefijo `0x`. |
| `%d` | Imprime un número entero con signo en base 10. |
| `%i` | Imprime un entero en base 10. |
| `%u` | Imprime un número decimal sin signo en base 10. |
| `%x` | Imprime un número hexadecimal sin signo en minúsculas (`0-9`, `a-f`). |
| `%X` | Imprime un número hexadecimal sin signo en mayúsculas (`0-9`, `A-F`). |
| `%%` | Imprime el carácter literal del porcentaje. |

### Modificadores y Flags (Parte Bonus)
| Flag / Modificador | Descripción |
| :---: | :--- |
| `-` | Justificación a la izquierda dentro del ancho mínimo de campo. |
| `0` | Relleno con ceros a la izquierda en lugar de espacios. |
| `.` | Precisión: número mínimo de dígitos en conversiones numéricas o longitud máxima en strings. |
| `#` | Formato alternativo: añade prefijo `0x` o `0X` a números hexadecimales no nulos. |
| `+` | Fuerza la impresión del signo (`+` o `-`) en conversiones numéricas con signo. |
| `' '` *(espacio)* | Inserta un espacio previo si el número positivo no lleva signo. |
| *ancho mínimo* | Ancho de campo mínimo a ocupar en la salida. |

---

## Instrucciones

### Compilación
El proyecto incluye un `Makefile` compatible con la Norma de 42, con banderas `-Wall -Wextra -Werror` y sin relink:

- **Compilar parte obligatoria:**
  ```bash
  make
  ```
  Genera la librería estática `libftprintf.a`.

- **Compilar con parte bonus:**
  ```bash
  make bonus
  ```
  Incorpora el manejo de flags y modificadores avanzados en `libftprintf.a`.

- **Limpiar objetos:**
  ```bash
  make clean
  ```

- **Limpiar objetos y librería:**
  ```bash
  make fclean
  ```

- **Recompilar todo:**
  ```bash
  make re
  ```

### Uso
Para utilizar la librería en tu propio programa C:
```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hola %s, el número es %d y en hex %#x\n", "42", 42, 42);
	return (0);
}
```
Compilación vinculando `libftprintf.a`:
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o mi_programa
```

---

## Algoritmo y Estructura de Datos

### 1. Tabla de Despacho (Jump Table / Dispatch Table)
En lugar de encadenar múltiples sentencias condicionales (`if / else if`) para identificar el especificador tras el `%`, se utiliza una **tabla de punteros a función indexada directamente por el código ASCII del especificador**:
```c
static const t_print_func g_dispatch[127] = {
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
Esto permite una resolución inmediata en tiempo constante $O(1)$, desacoplando completamente la lógica de parseo de la lógica de cada tipo de dato.

### 2. Estructura de Flags (`t_flags`)
La estructura `t_flags` almacena de forma ordenada el estado de la conversión actual (flags activos, ancho, precisión, base numérica y padding calculado), permitiendo transferir el contexto entre funciones de forma limpia y respetando las restricciones de parámetros de la Norminette.

### 3. Motor Centralizado (`print_universal`)
Todas las conversiones numéricas (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) convergen en un único motor de renderizado (`print_universal`). Este se encarga de:
- Imprimir prefijos calculados (`-`, `+`, ` `, `0x`, `0X`).
- Generar ceros de precisión (`flags->zeros`).
- Volcar recursivamente los dígitos del número en su base correspondiente sin requerir memoria dinámica adicional en el heap.
- Rellenar con espacios o ceros de ancho (`flags->pad`) según la justificación derecha o izquierda.

---

## Recursos

### Referencias
- Manual de Linux: `man 3 printf`, `man 3 stdarg`.
- Especificación POSIX / IEEE Std 1003.1 sobre conversiones de formato en `printf`.
- Documentación de GNU C Library (glibc) sobre format flags y compatibilidad.

### Uso de Inteligencia Artificial
Se ha utilizado asistencia de IA para:
- Análisis y depuración de edge cases en suites de tests automatizadas (como Francinette y Tripouille printfTester).
- Corrección de dependencias y reglas en el `Makefile` para garantizar la compatibilidad entre pruebas obligatorias y bonus sin provocar relinks.
- Consulta de precedencia de flags conflictivas según el estándar POSIX (ej. precedencia de `-` sobre `0`, o desactivación de `0` en presencia de precisión numérica).
