/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 18:02:19 by julthoma          #+#    #+#             */
/*   Updated: 2023/11/10 18:42:45 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int nb, int fd)
{
	int		res;
	long	n;

	res = 0;
	n = nb;
	if (n < 0)
	{
		res++;
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		res += ft_putnbr_fd(n / 10, fd);
	res += ft_putchar_fd(n % 10 + '0', fd);
	return (res);
}
