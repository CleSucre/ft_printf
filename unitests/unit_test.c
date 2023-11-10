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

void	run_tests(void)
{
	printf("test 1: %d\n", ft_printf("Salut %s\n", "Julien"));
}

int	main(void)
{
	run_tests();
	return (0);
}
