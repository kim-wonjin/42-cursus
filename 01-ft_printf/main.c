#include "ft_printf.h"
#include <stdio.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define PRINT ft_printf

int	main(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	
	printf(" --- Return : %d\n", printf("%10s SEOUL %d, %i, %4c,1010%% %u,%4p, %p %u, %x, %X", n, d, -97, 97, -111, NULL, p, 0, 970, 1010));
	ft_printf(" --- Return : %d\n", ft_printf("%10s SEOUL %d, %i, %4c,1010%% %u,%4p, %p %u, %x, %X", n, d, -97, 97, -111, NULL, p, 0, 970, 1010));
	

	printf("printf: \n");
 	printf("res: %c\n", 'a');
 	printf("%5c\n", 'a');
 	printf("%%\n");
 	printf("\n");
	printf("ft_printf: \n");
 	ft_printf("res: %c", 'a');
 	printf("\n");
	ft_printf("%5c", 'a');
 	printf("\n");
 	ft_printf("%%");
	printf("\n\n\n");
	char *ptr;
 	printf("printf:\n");
 	printf("%p\n", ptr);
 	printf("%10p\n", ptr);
	printf("==========\n");
 	printf("ft_printf:\n");
 	ft_printf("%p", ptr);
 	printf("\n");
 	ft_printf("%10p", ptr);
 	printf("\n\n\n");

	printf("printf:\n");
 	printf("%u\n", 123);
 	printf("%u\n", -123);
 	printf("%d\n", INT_MAX);
 	printf("%d\n", INT_MIN);
 	printf("%u\n", INT_MAX);
 	printf("%u\n", INT_MIN);
 	printf("==========\n");

 	printf("ft_printf:\n");
 	ft_printf("%u", 123);
 	printf("\n");
 	ft_printf("%u", -123);
 	printf("\n");
 	ft_printf("%d", INT_MAX);
 	printf("\n");
 	ft_printf("%d", INT_MIN);
 	printf("\n");
 	ft_printf("%u", INT_MAX);
 	printf("\n");
 	ft_printf("%u", INT_MIN);
	printf("\n\n\n");

	printf("printf: \n");
 	printf("%s\n", "abc");
 	printf("%5s\n", "abc");
 	printf("%2s\n", "abc");	
	printf("ft_printf:\n");
 	ft_printf("%s", "abc");
 	printf("\n");
 	ft_printf("%5s", "abc");
 	printf("\n");
 	ft_printf("%2s", "abc");
 	printf("\n\n\n");

	printf("%x",1234);
	printf("\n");
	printf("%x",0x1234);
	printf("\n");
	printf("%10x", 0x12A4);
	printf("\n");
	printf("==========\n");
	printf("\n");
	ft_printf("%x",1234);
	printf("\n");
	ft_printf("%x", 0x1234);
	printf("\n");
	ft_printf("%10x", 0x12A4);
	printf("\n\n\n");

	printf("%X",1234);
	printf("\n");
	printf("%X  %d",0x1234, 2);
	printf("\n");
	printf("%10X%%", 0x12A4);
	printf("\n");
	printf("==========\n");
	printf("\n");
	ft_printf("%X",1234);
	printf("\n");
	ft_printf("%X  %d", 0x1234, 2);
	printf("\n");
	ft_printf("%10X%%", 0x12A4);
	
 }
