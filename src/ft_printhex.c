/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:18:15 by jthomas           #+#    #+#             */
/*   Updated: 2022/12/08 02:39:51 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printhex(int n, char format)
{
	int	res;

	if (!n)
		return (write(1, "0", 1));
	res = 1;
	if (n >= 16)
	{
		res += ft_printhex(n / 16, format);
		res += ft_printhex(n % 16, format);
		res--;
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
	return (res);
}
