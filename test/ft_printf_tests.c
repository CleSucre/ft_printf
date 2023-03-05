/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:52:39 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/05 15:53:30 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"
#include <stdio.h>
#include <assert.h>

int	main(void)
{
	assert(printf("%c\n", 'A') == ft_printf("%c\n", 'A'));
	assert(printf("%s\n", "Hello, world!") == ft_printf("%s\n", "Hello, world!"));
	assert(printf("%p\n", (void *)0x7fff5fbffb90) == ft_printf("%p\n", (void *)0x7fff5fbffb90));
	assert(printf("%d\n", 42) == ft_printf("%d\n", 42));
	assert(printf("%i\n", -42) == ft_printf("%i\n", -42));
	assert(printf("%u\n", 42) == ft_printf("%u\n", 42));
	assert(printf("%x\n", 42) == ft_printf("%x\n", 42));
	assert(printf("%X\n", 42) == ft_printf("%X\n", 42));
	assert(printf("%%\n") == ft_printf("%%\n"));
	assert(printf("%p", "") == ft_printf("%p", ""));
	return (0);
}
