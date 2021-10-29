## ft_printf

### About

This project is all about recreating the standard printf() function.

External functions: malloc, free, write, va_start, va_arg, va_copy, va_end.

* The prototype of ft_printf:
  * `int ft_printf(const char *, ...)`
* It isn't do the buffer management like the real printf.
* It can manage the following conversions: cspdiuxX%
* It can manage any combination of the following flags: ’-0.*’ and minimum field
width with all conversions
* Makefile compiles object files and creates a static library for use

All functions are created in accordance with [Norm](https://github.com/42School/norminette) - the bunch of rules how code should be formatted.

### Requirements & usage
Project requires:
* C Lang compiler: **gcc** or **clang**
* Possibility to work with Makefile

Tested on:
* MacOS 10.15
* Linux Ubuntu 20.04

Compiling:
```
$> make all
```

### Makefile commands

* make / make all / make libftprintf.a - compile project
* make *.o - compile specific source file
* make clean - clean all object files
* make fclean - clean all object files & library
