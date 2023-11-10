/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julthoma <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 06:56:08 by julthoma          #+#    #+#             */
/*   Updated: 2023/11/08 06:56:08 by julthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

// Print functions
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(const char *str, int fd);
int		ft_putpointer_fd(void *ptr, int fd);
int		ft_putnbr_fd(int nb, int fd);
int		ft_putnbr_unsigned_fd(unsigned int nb, int fd);
int		ft_putnbr_base_fd(unsigned long long nb, char *base, int fd);

// Utils functions
size_t	ft_strlen(const char *str);

#endif
