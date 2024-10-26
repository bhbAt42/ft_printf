## 🖨️ ft_printf

### About
Recreation of the libc printf function. This project teaches about variable arguments and implementing complex formatting logic.

### Supported Features
- Conversions: `%c` `%s` `%p` `%d` `%i` `%u` `%x` `%X` `%%`
- Minimum field width management
- Precision handling
- `-` flag (left-align) handling
- `0` flag (zero-padding) handling
- `.` flag (precision) handling

### Prototype
```c
int ft_printf(const char *format, ...);
```

### Compilation
```bash
make        # compile the library
make clean  # remove object files
make fclean # remove object files and library
make re     # recompile the library
```

### Usage Examples
```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "42");
    ft_printf("Pointer: %p\n", (void *)0x42);
    ft_printf("Number: %d\n", 42);
    ft_printf("Hexadecimal: %x\n", 42);
    return (0);
}
```

### Notes
- Project follows 42's Norm
- All files are compiled with flags `-Wall -Wextra -Werror`
- Functions are written to never produce memory leaks

⭐ Don't forget to star this project if you found it useful!
