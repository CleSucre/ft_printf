/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 07:06:58 by julthoma          #+#    #+#             */
/*   Updated: 2023/11/08 07:06:58 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	res1;
	int	res2;
	int	n;

	n = -1536;
	res1 = ft_printf("integer: %u\n", n);
	res2 = printf("integer: %u\n", n);
	ft_printf("res1: %d\nres2: %d\n", res1, res2);
	return (0);
}
