/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:03:51 by jthomas           #+#    #+#             */
/*   Updated: 2022/12/08 01:43:20 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printnbr(unsigned long long n)
{
	char	*str;
	int		res;

	str = ft_itoa(n);
	res = ft_printstr(str);
	free(str);
	return (res);
}
