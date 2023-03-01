/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:45:00 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/01 18:33:35 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_printflag(int fd, const char *format, va_list args);
int	ft_puthex_fd(unsigned int n, char format, int fd);
int	ft_putunsigned_fd(unsigned int n, int fd);
int	ft_printptr_fd(unsigned long long s, int fd);
int	ft_putunsignedhex_fd(unsigned long n, int fd);
#endif
