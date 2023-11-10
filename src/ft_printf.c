/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:54:17 by julthoma          #+#    #+#             */
/*   Updated: 2023/11/08 06:54:17 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_param(va_list ap, const char param, int fd)
{
	int	res;

	res = 0;
	if (param == 'c')
		res += ft_putchar_fd(va_arg(ap, int), fd);
	else if (param == 's')
		res += ft_putstr_fd(va_arg(ap, char *), fd);
	else if (param == 'p')
		res += ft_putpointer_fd(va_arg(ap, char *), fd);
	else if (param == 'd' || param == 'i')
		res += ft_putnbr_fd(va_arg(ap, int), fd);
	else if (param == 'u')
		res += ft_putnbr_unsigned_fd(va_arg(ap, unsigned int), fd);
	else if (param == 'x')
		res += ft_putnbr_base_fd(
				va_arg(ap, unsigned int), "0123456789abcdef", fd);
	else if (param == 'X')
		res += ft_putnbr_base_fd(
				va_arg(ap, unsigned int), "0123456789ABCDEF", fd);
	else if (param == '%')
		res += ft_putchar_fd('%', fd);
	else
		res += ft_putchar_fd(param, fd);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	param;
	int		res;
	int		fd;

	res = 0;
	fd = 1;
	va_start(param, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			res += ft_print_param(param, *format, fd);
		}
		else
			res += ft_putchar_fd(*format, fd);
		format++;
	}
	va_end(param);
	return (res);
}
