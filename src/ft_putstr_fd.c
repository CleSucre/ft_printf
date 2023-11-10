/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:59:22 by julthoma          #+#    #+#             */
/*   Updated: 2023/11/10 18:42:52 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(const char *str, int fd)
{
	int	res;

	if (str == NULL)
		str = "(null)";
	res = 0;
	while (*str)
		res += ft_putchar_fd(*str++, fd);
	return (res);
}
