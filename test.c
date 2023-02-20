#include "includes/libftprintf.h"

#include <stdio.h>

int main(void)
{
	char c = 'A';
	char *s = "Hello, world!";
	void *p = (void *)0x7fff5fbffb90;
	int d = 42;
	int i = -42;
	unsigned int u = 42;
	int x = 42;
	int X = 42;
	int pound = 42;
	int plus = 42;

	int ret1, ret2;

	ft_putstr_fd("=========================TESTS START HERE=========================\n", 1);

	ret1 = 0;
	//ret1 = ft_printf("%c\n", c);
	ret2 = printf("%c\n", c);
	printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	//ret1 = ft_printf("%s\n", s);
	ret2 = printf("%s\n", s);
	//printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	//ret1 = ft_printf("%p\n", p);
	ret2 = printf("%p\n", p);
	printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	//ret1 = ft_printf("%d\n", d);
	ret2 = printf("%d\n", d);
	printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	//ret1 = ft_printf("%i\n", i);
	ret2 = printf("%i\n", i);
	printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	//ret1 = ft_printf("%u\n", u);
	ret2 = printf("%u\n", u);
	printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	//ret1 = ft_printf("%x\n", x);
	ret2 = printf("%x\n", x);
	printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	//ret1 = ft_printf("%X\n", X);
	ret2 = printf("%X\n", X);
	printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	//ret1 = ft_printf("%%\n");
	ret2 = printf("%%\n");
	printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	//ret1 = ft_printf("%p", "");
	ret2 = printf("%p", "");
	printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	//BONUS PART

	//ret1 = ft_printf("%#x\n", pound);
	//ret2 = printf("%#x\n", pound);
	//printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	//ret1 = ft_printf("%+d\n", plus);
	//ret2 = printf("%+d\n", plus);
	//printf("ft_printf: %d, printf: %d\n", ret1, ret2);

	return 0;
}