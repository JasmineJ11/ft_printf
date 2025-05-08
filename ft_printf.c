/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiawli <jiawli@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:02:44 by jiawli            #+#    #+#             */
/*   Updated: 2025/05/02 11:02:46 by jiawli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(va_list args, char c)
{
	if (c == 'c')
		return (print_char(va_arg(args, int)));
	if (c == 's')
		return (print_str(va_arg(args, char *)));
	if (c == 'u')
		return (print_uint(va_arg(args, unsigned int), "0123456789", 10));
	if (c == 'i' || c == 'd')
		return (print_int(va_arg(args, int), "0123456789", 10));
	if (c == 'p')
		return (print_pointer(va_arg(args, uintptr_t), "0123456789abcdef", 16));
	if (c == 'x')
		return (print_uint(va_arg(args, unsigned int), "0123456789abcdef", 16));
	if (c == 'X')
		return (print_uint(va_arg(args, unsigned int), "0123456789ABCDEF", 16));
	if (c == '%')
		return (print_char('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			count += print_format(args, str[i + 1]);
			i += 2;
		}
		else
		{
			count += print_char(str[i]);
			i++;
		}
	}
	va_end(args);
	return (count);
}

int	main(void)
{

	int i = 0;
	int	j = 0;
	char *c = "abc";
	int out1 = ft_printf("str:%s", c);
	printf("\n");
	printf("%d\n ", out1);
	printf("----------------\n");

	unsigned int nb1 = -99;
	char *str = "abcdefg";

	printf("c: printf: %c \n", *str);
	ft_printf("ft_printf: %c \n", *str);
	ft_printf("\n");

	printf("s: printf: %s \n", str);
	ft_printf("ft_printf: %s \n", str);
	ft_printf("\n");

	printf("u: printf: %u \n", nb1);
	ft_printf("ft_printf: %u \n", nb1);
	ft_printf("\n");

	printf("d: printf: %d \n", nb1);
	ft_printf("ft_printf: %d \n", nb1);
	ft_printf("\n");

	printf("i: printf: %i \n", nb1);
	ft_printf("ft_printf: %i \n", nb1);
	ft_printf("\n");

	printf("p: printf: %p \n", (void*)0);
	ft_printf("ft_printf: %p \n", (void*)0);
	ft_printf("\n");

	printf("X: printf: %X \n", nb1);
	ft_printf("ft_printf: %X \n", nb1);
	ft_printf("\n");

	i = printf("x: printf: %x \n", nb1);
	j = ft_printf("ft_printf: %x \n", nb1);
	ft_printf("printf: %d, ft_printf: %d\n", i, j);
	ft_printf("\n");

	printf(": printf: %%%%sssS \n");
	ft_printf("ft_printf: %%%%sssS \n");
	ft_printf("\n");

	printf("s: printf: %s \n", ((char*)0));
	ft_printf("ft_printf: %s \n", ((char*)0));
}