/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 02:40:57 by jthomas           #+#    #+#             */
/*   Updated: 2022/12/08 02:51:53 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

void	ft_putptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_printptr(unsigned long long n)
{
	int	res;

	res = 0;
	res += write(1, "0x", 2);
	if (!n)
		res += write(1, "0", 1);
	else
	{
		ft_putptr(n);
		while (n /= 10)
			res++;
	}
	return (res);
}
