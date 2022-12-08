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

//shoud alaways be called after ft_isflag
int	ft_printflag(char c, va_list args)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printptr(va_arg(args, unsigned long long)));
	else if (c == 'd' || c == 'i')
		return (ft_printnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_printunsigned(va_arg(args, int)));
	else if (c == 'x' || c == 'X')
		return (ft_printhex(va_arg(args, unsigned int), c));
	else if (c == '%')
		ft_putchar_fd(c, 1);
	return (1);
}
