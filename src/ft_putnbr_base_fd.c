/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:54:58 by jthomas           #+#    #+#             */
/*   Updated: 2022/12/06 23:55:07 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

void	ft_putnbr_base_fd(int nbr, char *base, int fd)
{
	long	i;
	int		size;

	size = ft_strlen(base);
	i = nbr;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i *= -1;
	}
	if (i < size)
		ft_putchar_fd(base[i], fd);
	else
	{
		ft_putnbr_base_fd(i / size, base, fd);
		ft_putnbr_base_fd(i % size, base, fd);
	}
}
