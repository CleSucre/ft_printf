/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:46:52 by jthomas           #+#    #+#             */
/*   Updated: 2022/12/08 02:43:19 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int ft_printflag(int fd, const char *format, va_list args)
{
	int		ret = 0;
	char	*temp;

	for (int i = 0; format[i]; i++)
	{
		if (format[i] == '%') {
			i++;
			if (format[i] == 'c') {
				ret++;
				ft_putchar_fd(va_arg(args, int), fd);
			} else if (format[i] == 's') {
				temp = va_arg(args, char *);
				ret += ft_strlen(temp);
				ft_putstr_fd(temp, fd);
			} else if (format[i] == 'p') {
				ret += ft_putnbr_base_fd(va_arg(args, unsigned long), "0123456789ABCDEF", fd);
			} else if (format[i] == 'd' || format[i] == 'i') {
				ret += ft_putnbr_fd(va_arg(args, int), fd);
			} else if (format[i] == 'u') {
				ret += ft_printunsigned(va_arg(args, unsigned int));
			} else if (format[i] == 'x') {
				ret += ft_printhex(va_arg(args, unsigned int), format[i]);
			} else if (format[i] == 'X') {
				ret += ft_printhex(va_arg(args, unsigned int), format[i]);
			} else if (format[i] == '%') {
				ret++;
				ft_putchar_fd(format[i], fd);
			} else if (format[i] == '#') {
				ret += 2;
				ft_putstr_fd("0x", fd);
			} else if (format[i] == '+') {
				ret += ft_printnbr(va_arg(args, int));
			}
		}
		else {
			ret++;
			ft_putchar_fd(format[i], fd);
		}
	}

	return ret;
}