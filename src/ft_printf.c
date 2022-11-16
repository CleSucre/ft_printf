// ft_printf created by CleSucre on 16/11/2022 03:41

#include "../includes/libftprintf.h"

int	ft_printf(const char *format, ...)
{
    int     i;
    int     count;
    va_list args;

    i = 0;
    count = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] != '%')
            write(1, &format[i++], 1);
        else if (ft_isflag(format[++i]))
        {
            ft_printflag(format[i++], &args);
            count++;
        }
    }
    va_end(args);
    return (count);
}