/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                        :+:      :+:    :+: */
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
	if (c == '\0')
		return (0);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		i;

	if (!str)
		return (-1);
	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			count += print_format(args, str[i + 1]);
			i += 2;
			continue ;
		}
		if (print_char(str[i++]) == -1)
			return (va_end(args), -1);
		count++;
	}
	return (va_end(args), count);
}
