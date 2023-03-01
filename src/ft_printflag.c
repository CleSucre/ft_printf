/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:46:52 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/01 18:56:51 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_print(int fd, const char format, va_list args)
{
	int	res;

	res = 0;
	if (format == 'c')
		return (ft_putchar_fd(va_arg(args, int), fd));
	if (format == 's')
		return (ft_putstr_fd(va_arg(args, char *), fd));
	if (format == 'd' || format == 'i')
		return (ft_putnbr_fd(va_arg(args, int), fd));
	if (format == 'u')
		return (ft_putunsigned_fd(va_arg(args, int), fd));
	if (format == 'x' || format == 'X')
		return (ft_puthex_fd(va_arg(args, int), format, fd));
	if (format == '%' || format == '#')
		return (ft_putchar_fd(format, fd));
	if (format == 'p')
	{
		res += ft_putstr_fd("0x", fd);
		res += ft_putunsignedhex_fd(va_arg(args, unsigned long long), fd);
	}
	return (res);
}

int	ft_printflag(int fd, const char *format, va_list args)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (format[i])
	{
		if (format[i++] == '%')
			ret += ft_print(fd, format[i++], args);
		else
			ret += ft_putchar_fd(format[i - 1], fd);
	}
	return (ret);
}
