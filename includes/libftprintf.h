/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:45:00 by jthomas           #+#    #+#             */
/*   Updated: 2022/11/16 03:45:00 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdarg.h>

int ft_printf(const char *format, ...);
int	ft_isflag(char c);
void    ft_printflag(char c, va_list *args);

#endif //LIBFTPRINTF_H
