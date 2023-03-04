#include "../includes/libftprintf.h"

int	ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return (-1);
	i = 0;
	while (*s)
		i += write(fd, &*s++, 1);
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	long	i;
	int		temp;

	i = n;
	temp = 0;
	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i *= -1;
		temp++;
	}
	if (i < 10)
	{
		ft_putchar_fd(i + '0', fd);
		temp++;
	}
	else
	{
		temp += ft_putnbr_fd(i / 10, fd);
		temp += ft_putnbr_fd(i % 10, fd);
	}
	return (temp);
}

size_t	ft_nbrlen(long n)
{
	size_t	i;

	i = 1;
	if (0 > n)
	{
		n *= -1;
		i++;
	}
	while (9 < n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
