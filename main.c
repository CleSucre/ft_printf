/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:12:16 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/01 18:14:58 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>

int	main(void)
{
	void	*p;
	int		ret1;
	int		ret2;

	p = (void *)0x7fff5fbffb90;
	ft_putstr_fd("===============TESTS START HERE===============\n", 1);
	ret1 = 0;
	ret1 = ft_printf("%p\n", p);
	ret2 = printf("%p\n", p);
	printf("ft_printf: %d, printf: %d\n", ret1, ret2);
	return (0);
}
