/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:45:00 by jthomas           #+#    #+#             */
/*   Updated: 2022/12/08 02:46:39 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_isflag(char c);
int		ft_printflag(const char *format, va_list args);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_base_fd(int nbr, char *base, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_printchar(char c);
int		ft_printstr(char *s);
int		ft_printnbr(unsigned long long n);
int		ft_printhex(int n, char format);
int		ft_printunsigned(unsigned int n);
int		ft_printptr(unsigned long long n);
#endif //LIBFTPRINTF_H
