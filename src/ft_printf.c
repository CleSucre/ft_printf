/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:46:38 by jthomas           #+#    #+#             */
/*   Updated: 2022/12/08 01:31:13 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

#include <stdio.h>
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
	va_list args;
	int ret;

	va_start(args, format);
	ret = ft_printflag(format, args);
	va_end(args);

	return ret;
}
