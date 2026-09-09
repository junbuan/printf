# printf

*This project has been created as part of the 42 curriculum by juho.*


## Description

`ft_printf` is a custom re-implementation of the C standard library function `printf`, built from scratch without using any existing formatting functions (`printf`, `sprintf`, etc.) from the standard library.

The goal of the project is to understand — at a low level — how a variadic function like `printf` actually works: how it reads a format string character by character, how it pulls an unknown number of extra arguments off the stack using `va_list`/`va_arg`, and how it converts those arguments into their printed representation one byte at a time using only `write()`.

The library currently supports the following conversions:

| Specifier | Meaning                          |
|-----------|-----------------------------------|
| `%c`      | Character                         |
| `%s`      | String                             |
| `%d`, `%i`| Signed decimal integer            |
| `%u`      | Unsigned decimal integer          |
| `%p`      | Pointer address (hexadecimal)     |
| `%x`      | Unsigned hex (lowercase)          |
| `%X`      | Unsigned hex (uppercase)          |
| `%%`      | A literal `%` character            |

`ft_printf` returns the total number of characters printed, exactly like the real `printf`.

## Instructions

### Compilation

The project builds as a static library, following the standard 42 Makefile rules:

```bash
make        # compiles ft_printf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # fclean + make
```

### Usage

Include the header and link against the compiled library:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s, you are %d years old (in hex: %x)\n", "Jun", 21, 21);
    return (0);
}
```

Compile your program with the library:

```bash
gcc your_file.c -L. -lftprintf -o your_program
```

## Resources

- `man 3 printf` — the reference behavior `ft_printf` aims to reproduce
- `man 3 stdarg` — documentation for `va_start`, `va_arg`, `va_end`
- *The C Programming Language* (K&R) — background on variadic functions and pointer arithmetic
- 42 Norminette documentation — coding style constraints followed throughout the project

**AI usage:** Claude (Anthropic) was used as a learning aid during development — specifically to get plain-language explanations of how `va_list`/`va_arg` work internally (including the x86-64 ABI detail that lets a `va_list` passed to a helper function still advance the caller's argument pointer), to clarify the difference between a stack-allocated array and an uninitialized pointer, and to talk through the design of the digit-extraction algorithm described below. All code was written, tested, and debugged independently; AI was not used to generate any of the submitted source files.

<!-- Be specific and honest here about what you actually used it for — staff will ask. -->

## Algorithm & Data Structure Justification

The trickiest part of the project is converting a number into its printed digits (used by `%d`, `%u`, `%x`, `%X`, and pointer printing for `%p`).

**The problem:** repeatedly dividing a number by its base (10 for decimal, 16 for hex) naturally produces its digits in **reverse order** — least significant digit first. For example, extracting the hex digits of `250` via `n % 16` then `n /= 16` yields `'a'`, then `'f'` — but `250` in hex is `fa`, so printing digits the moment they're found would print them backwards.

**The solution:** a small fixed-size local buffer (`char buffer[32]`) is used to temporarily hold each digit character as it's produced, before anything is printed. Digits are written into the buffer from index `0` upward while they're extracted (least-significant first), and a counter tracks how many digits were collected. Once extraction is complete, the buffer is printed by walking it **backwards** (from the last filled index down to `0`), which restores the correct human-reading order.

This fill-forward, read-backward access pattern is functionally a **LIFO (last-in, first-out) stack**, even though it's implemented with a plain array rather than a dedicated stack structure — the last digit pushed in (the most significant digit) is the first one read back out.

A fixed-size stack array (rather than a dynamically-sized `malloc`'d buffer) was chosen deliberately:
- The maximum possible size is known in advance and small — a 64-bit number needs at most 16 hexadecimal digits (or 20 decimal digits), so 32 bytes comfortably covers every case with room to spare.
- It avoids heap allocation overhead for what is a short-lived, tiny piece of scratch memory.
- It's automatically cleaned up when the function returns, removing any risk of a memory leak — an important constraint given 42's strict no-leak grading policy.

A dynamic (`malloc`/`realloc`) approach was considered but rejected, since the upper bound is fixed and known, making a stack-allocated array strictly simpler and safer with no practical downside.