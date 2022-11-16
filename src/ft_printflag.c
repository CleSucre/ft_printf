// ft_printflag created by CleSucre on 16/11/2022 04:17

#include "../includes/libftprintf.h"

//shoud alaways be called after ft_isflag
void	ft_printflag(char c, va_list *args)
{
    if (c == 'c')
        ft_putchar_fd(va_arg(*args, int), 1);
    else if (c == 's')
        ft_putstr_fd(va_arg(*args, char *), 1);
    else if (c == 'p')
        ft_putnbr_base_fd(va_arg(*args, unsigned long), "0123456789abcdef", 1);
    else if (c == 'd')
        ft_putnbr_fd(va_arg(*args, int), 1);
    else if (c == 'i')
        ft_putnbr_fd(va_arg(*args, int), 1);
    else if (c == 'u')
        ft_putnbr_fd(va_arg(*args, int), 1);
    else if (c == 'x')
        ft_putnbr_fd(va_arg(*args, int), 1);
    else if (c == 'X')
        ft_putnbr_fd(va_arg(*args, int), 1);
    else if (c == '%')
        ft_putnbr_fd(va_arg(*args, int), 1);
}