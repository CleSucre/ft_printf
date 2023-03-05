/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 23:46:38 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/05 15:51:19 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;
	int		error;

	error = 0;
	va_start(args, format);
	ret = ft_printflag(1, format, args, &error);
	va_end(args);
	if (error == -1)
		return (-1);
	return (ret);
}
