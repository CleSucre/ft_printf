/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:46:52 by jthomas           #+#    #+#             */
/*   Updated: 2023/01/28 15:18:55 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_isflag(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

int	ft_printflag(int fd, const char *format, va_list args)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
				ret += ft_putchar_fd(va_arg(args, int), fd);
			else if (format[i] == 's')
				ret += ft_putstr_fd(va_arg(args, char *), fd);
			else if (format[i] == 'p' || format[i] == 'd' || format[i] == 'i' || format[i] == 'u' || format[i] == 'x' || format[i] == 'X')
				ret += ft_putnbr_fd(va_arg(args, int), fd);
			else if (format[i] == '%' || format[i] == '#')
				ret += ft_putchar_fd(format[i], fd);
		}
		else
			ret += ft_putchar_fd(format[i], fd);
		i++;
	}
	return (ret);
}
