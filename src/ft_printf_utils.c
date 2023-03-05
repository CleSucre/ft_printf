/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:25:42 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/05 16:52:58 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putunsignedhex_fd(unsigned long n, int fd, int *error)
{
	int	res;

	if (!n)
		return (ft_putchar_fd('0', fd, error));
	res = 1;
	if (n >= 16)
	{
		res += ft_putunsignedhex_fd(n / 16, fd, error);
		res += ft_putunsignedhex_fd(n % 16, fd, error);
		res--;
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), fd, error);
		else
			ft_putchar_fd((n - 10 + 'a'), fd, error);
	}
	return (res);
}

int	ft_puthex_fd(unsigned int n, char format, int fd, int *error)
{
	int	res;

	if (!n)
		return (ft_putchar_fd('0', fd, error));
	res = 1;
	if (n >= 16)
	{
		res += ft_puthex_fd(n / 16, format, fd, error);
		res += ft_puthex_fd(n % 16, format, fd, error);
		res--;
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), fd, error);
		else
		{
			if (format == 'x')
				ft_putchar_fd((n - 10 + 'a'), fd, error);
			if (format == 'X')
				ft_putchar_fd((n - 10 + 'A'), fd, error);
		}
	}
	return (res);
}

char	*ft_uitoa(long long int n, int *error)
{
	char	*res;
	int		i;

	i = ft_nbrlen(n);
	res = (char *)malloc(sizeof(char) * (i + 1));
	if (!res)
	{
		*error = -1;
		return (0);
	}
	res[i] = '\0';
	while (i)
	{
		res[i - 1] = n % 10 + 48;
		n = n / 10;
		i--;
	}
	return (res);
}

int	ft_putunsigned_fd(long long int n, int fd, int *error)
{
	int				res;
	char			*temp;
	unsigned int	num;

	num = (unsigned int)n;
	res = 0;
	if (num == 0)
		res += ft_putchar_fd('0', fd, error);
	else
	{
		temp = ft_uitoa(num, error);
		res += ft_putstr_fd(temp, fd, error);
		free(temp);
	}
	return (res);
}
