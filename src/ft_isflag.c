// ft_isflag created by CleSucre on 16/11/2022 04:15

#include "../includes/libftprintf.h"

int	ft_isflag(char c)
{
    return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}