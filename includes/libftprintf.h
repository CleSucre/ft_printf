/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jthomas <jthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 03:45:00 by jthomas           #+#    #+#             */
/*   Updated: 2023/03/05 16:36:56 by jthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_printf(const char *format, ...);
int		ft_printflag(int fd, const char *format, va_list args, int *error);
int		ft_puthex_fd(unsigned int n, char format, int fd, int *error);
int		ft_putunsigned_fd(long long int n, int fd, int *error);
int		ft_putunsignedhex_fd(unsigned long n, int fd, int *error);
int		ft_putchar_fd(char c, int fd, int *error);
int		ft_putstr_fd(char *s, int fd, int *error);
int		ft_putnbr_fd(int n, int fd, int *error);
size_t	ft_nbrlen(long n);
#endif
