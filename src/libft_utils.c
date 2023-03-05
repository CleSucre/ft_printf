/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:52:00 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/05 15:54:25 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_putchar_fd(char c, int fd, int *error)
{
	int	res;

	if (*error == -1)
		return (-1);
	res = write(fd, &c, 1);
	if (res < 0)
		*error = -1;
	return (res);
}

int	ft_putstr_fd(char *s, int fd, int *error)
{
	int	i;

	if (!s)
		return (ft_putstr_fd("(null)", fd, error));
	i = 0;
	while (*s)
		i += ft_putchar_fd(*s++, fd, error);
	return (i);
}

int	ft_putnbr_fd(int n, int fd, int *error)
{
	long	i;
	int		temp;

	i = n;
	temp = 0;
	if (i < 0)
	{
		ft_putchar_fd('-', fd, error);
		i *= -1;
		temp++;
	}
	if (i < 10)
	{
		ft_putchar_fd(i + '0', fd, error);
		temp++;
	}
	else
	{
		temp += ft_putnbr_fd(i / 10, fd, error);
		temp += ft_putnbr_fd(i % 10, fd, error);
	}
	return (temp);
}

size_t	ft_nbrlen(long n)
{
	size_t	i;

	i = 1;
	if (0 > n)
	{
		n *= -1;
		i++;
	}
	while (9 < n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
