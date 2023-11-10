/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:34:18 by julthoma          #+#    #+#             */
/*   Updated: 2023/11/10 18:42:42 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_fd(unsigned long long nb, char *base, int fd)
{
	int	res;
	int	len;

	res = 0;
	len = ft_strlen(base);
	if (nb >= (unsigned long long)len)
		res += ft_putnbr_base_fd(nb / len, base, fd);
	res += ft_putchar_fd(base[nb % len], fd);
	return (res);
}
