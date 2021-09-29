/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfchouch <lfchouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:32:48 by lfchouch          #+#    #+#             */
/*   Updated: 2021/09/29 06:22:17 by lfchouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

/*void	ft_putchar(unsigned char c)
{
	write(1, &c, 1);
}*/

/*int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}*/

/*int	ft_putchar(unsigned char c, int *count)
{
	//static int count;

	*count += 1;
	//count++;
	write(1, &c, 1);
	//return (count);
	return (*count);
}*/

int	ft_putchar(char c)
{
	static int count = 0;
	if (c == (char)NULL)
		return (count);
	count++;
	write(1, &c, 1);
	//printf("count vaut %d\n", count);
	return (count);
}

void	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr_hex_lower(int n)
{
	long	x;

	x = n;
	if (n < 0)
		x = (2 * 2147483648) + n;
	if (x >= 16)
	{
		ft_putnbr_hex_lower(x / 16);
		ft_putnbr_hex_lower(x % 16);
	}
	else
	{
		if (x <= 9)
			ft_putchar(x + '0');
			//ft_putchar(x + '0');
		if (x > 9 && x <= 15)
		{
			x = x - 10;
			ft_putchar(x + 'a');
			//ft_putchar(x + 'a');
		}
	}
}

void	ft_putnbr_hex_upper(int n)
{
	long	x;

	x = n;
	if (n < 0)
		x = (2 * 2147483648) + n;
	if (x >= 16)
	{
		ft_putnbr_hex_upper(x / 16);
		ft_putnbr_hex_upper(x % 16);
	}
	else
	{
		if (x <= 9)
			ft_putchar(x + '0');
		if (x > 9 && x <= 15)
		{
			x = x - 10;
			ft_putchar(x + 'A');
		}
	}
}

int	ft_putnbr_hex_lower_ll(long long n)
{
	long long	x;

	x = n;
	if (x >= 16)
	{
		ft_putnbr_hex_lower_ll(x / 16);
		ft_putnbr_hex_lower_ll(x % 16);
	}
	else
	{
		if (x <= 9)
			ft_putchar(x + '0');
			//ft_putchar(x + '0');
		if (x > 9 && x <= 15)
		{
			x = x - 10;
			ft_putchar(x + 'a');
			//ft_putchar(x + 'a');
		}
	}
	return(x);
}

void	ft_putnbr(int n)
{
	unsigned int	x;

	x = n;
	if (n < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x >= 10)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
		ft_putchar(x + '0');
}

void	ft_putnbr_unsigned_int(int n)
{
	long	x;

	x = n;
	if (n < 0)
		x = (2 * 2147483648) + n;
	if (x >= 10)
	{
		ft_putnbr_unsigned_int(x / 10);
		ft_putnbr_unsigned_int(x % 10);
	}
	else
		if (x <= 9)
			ft_putchar(x + '0');
}

/*void	ft_hex(unsigned long c, va_list ap)
{
	void	*address;
	char	*new;

	address = va_arg(ap, void *);
	new = (char *)address;
	ft_putnbr_hex_lower_ll((unsigned long)new);
}*/



int	ft_printf(const char *format, ...)
{
	va_list			ap;
	unsigned char	c;
	char			*s;
	unsigned long	addr;
	int				d;
	int				u;
	int				i;
	int				hex;
	int				HEX;

	i = -1;
	va_start(ap, format);
	if (!format || !*format)
		return (0);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			++i;
			if (format[i] == 'c')
			{
				c = (unsigned char)va_arg(ap, int);
				ft_putchar(c);
			}
			if (format[i] == 's')

			{
				s = (char *)va_arg(ap, char *);
				ft_putstr(s);
			}
			if (format[i] == 'p')
			{
				addr = (unsigned long)va_arg(ap, void *);
				ft_putchar('0');
				ft_putchar('x');
				ft_putnbr_hex_lower_ll(addr);
			}

			if (format[i] == 'd')
			{
				d = (unsigned int)va_arg(ap, int);
				ft_putnbr(d);
			}
			if (format[i] == 'i')
			{
				i = (unsigned int)va_arg(ap, int);
				ft_putnbr(i);
			}
			if (format[i] == 'u')
			{
				u = (unsigned int)va_arg(ap, int);
				ft_putnbr_unsigned_int(u);
			}
			if (format[i] == 'x')
			{
				hex = (unsigned int)va_arg(ap, int);
				ft_putnbr_hex_lower(hex);
			}
			if (format[i] == 'X')
			{
				HEX = (unsigned int)va_arg(ap, int);
				ft_putnbr_hex_upper(HEX);
			}
			if (format[i] == '%')
				ft_putchar('%');
		}
		else
			ft_putchar(format[i]);
	}
	va_end(ap);
	return(ft_putchar(0));
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	//char	a = 10;
	//char	b = 54;
	//int		i = 0;
	//char		*p;

	//ft_putnbr(-2147483648);
	//ft_putnbr_hex_lower(16);
	//printf("\n");
	//printf("%i\n", -2147483650);
	//ft_putnbr(-2147483649);
	//printf("\n");
	//printf("%x\n", 2147483647);
	/*p = &i;
	printf("%p\n",p);
	p = NULL;
	printf("%p\n",p);
	return (0);*/
	//char *str = "%s %s \n";
	//int moi = ft_printf(str, "", "Hello Wolrd");
	//printf("Result : %d\n\n", moi);
	//int vrai = printf("%s %s\n", "", "hello");
	//printf("Result : %d\n", vrai);
	/*char *str = "%s %s\n";
	int moi = ft_printf(str, "", "Hello W");
	printf("Result : %d\n\n", moi);

	int vrai = printf(str, "", "Hello W");
	printf("Result : %d\n", vrai);*/

	//printf("%p\n", &p);
	//ft_printf("%p\n", p);
	int a = 15;
	/*printf("a - declared\n");
	ft_printf("int a = [%d]\n", a);
	ft_printf("int a pointer = [%p]\n%%\n%d\n", &a, a);
	printf("%d\n", (ft_printf("int a pointer = [%p]\n", &a)));
	printf("\n");
	a = 20;
	printf("a - initialized to value of 20\n");
	printf("int a = [%d]\n", a);
	printf("int a pointer = [%p]\n%%\n", (void *) &a);
	printf("%d\n", (printf("int a pointer = [%p]\n", (void *) &a)));
	printf("%lx\n", 21474836499);
	ft_putnbr_hex_lower_ll(21474836499);
	printf("\n");*/
	//printf("%p\n%d\n%x\n%%\n%i\n", (void *) &a, 32, 33, 34);
	//ft_printf("%p\n%d\n%x\n%%\n%i\n", (void *) &a, 32, 33, 34);
	//printf("result %i\n", 34);
	//ft_printf("result %i\n", 34);
	//printf("\n");
	//printf("%d\n", printf("result %i\n", 34));
	//printf(" %d\n", printf("result"));
	//printf(" %d\n", ft_printf("result"));
	//ft_printf("kjbsdk\n");
	printf("result : %d\n", ft_printf("%p\n%d\n%x\n%%\n%d\n", (void *) &a, 32, 33, 34));
	printf("result : %d\n", printf("%p\n%d\n%x\n%%\n%d\n", (void *) &a, 32, 33, 34));

	//printf("result : %d\n", printf("%s\n", "hello\n"));
	//ft_printf("result : %d\n", ft_printf("%s\n", "hello\n"));

	//printf("result %d\n et %d\n", ft_printf("%d\n%d\n", 123456, a), a);
	//printf("result %d\n et %d\n", printf("%d\n%d\n", 123456, a), a);
}
