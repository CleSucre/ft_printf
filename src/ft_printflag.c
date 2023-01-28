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
	char	*temp;

	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				ret++;
				ft_putchar_fd(va_arg(args, int), fd);
			}
			else if (format[i] == 's')
			{
				temp = va_arg(args, char *);
				ret += ft_strlen(temp);
				ft_putstr_fd(temp, fd);
			}
			else if (format[i] == 'p')
				ret += ft_putnbr_base_fd(
						va_arg(args, unsigned long), "0123456789ABCDEF", fd);
			else if (format[i] == 'd' || format[i] == 'i')
				ret += ft_putnbr_fd(va_arg(args, int), fd);
			else if (format[i] == 'u')
				ret += ft_putunsigned_fd(va_arg(args, unsigned int), fd);
			else if (format[i] == 'x')
				ret += ft_puthex_fd(va_arg(args, unsigned int), format[i], fd);
			else if (format[i] == 'X')
				ret += ft_puthex_fd(va_arg(args, unsigned int), format[i], fd);
			else if (format[i] == '%')
			{
				ret++;
				ft_putchar_fd(format[i], fd);
			}
			else if (format[i] == '#')
			{
				ret += 2;
				ft_putstr_fd("0x", fd);
			}
			else if (format[i] == '+')
				ret += ft_putnbr_fd(va_arg(args, int), fd);
		}
		else
		{
			ret++;
			ft_putchar_fd(format[i], fd);
		}
		i++;
	}
	return (ret);
}
