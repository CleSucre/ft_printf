/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printunsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 02:09:50 by jthomas           #+#    #+#             */
/*   Updated: 2022/12/08 02:29:22 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*ft_uitoa(unsigned int n)
{
	char	*res;
	int		i;

	i = ft_nbrlen(n);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	res[i] = '\0';
	while (i)
	{
		res[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (res);
}

int	ft_putunsigned_fd(unsigned int n, int fd)
{
	int		res;
	char	*temp;

	res = 0;
	if (n == 0)
		res += write(fd, "0", 1);
	else
	{
		temp = ft_uitoa(n);
		res += ft_putstr_fd(temp, fd);
		free(temp);
	}
	return (res);
}
