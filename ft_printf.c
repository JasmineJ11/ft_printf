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

void	print_format(va_list args, char c, int *count)
{
	if (*count < 0)
		return ;
	if (c == 'c')
		print_char(va_arg(args, int), count);
	if (c == 's')
		print_str(va_arg(args, char *), count);
	if (c == 'u')
		print_uint(va_arg(args, unsigned int), "0123456789", 10, count);
	if (c == 'i' || c == 'd')
		print_int(va_arg(args, int), "0123456789", 10, count);
	if (c == 'p')
		print_pointer(va_arg(args, uintptr_t), "0123456789abcdef", 16, count);
	if (c == 'x')
		print_uint(va_arg(args, unsigned int), "0123456789abcdef", 16, count);
	if (c == 'X')
		print_uint(va_arg(args, unsigned int), "0123456789ABCDEF", 16, count);
	if (c == '%')
		print_char('%', count);
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
	while (str[i] != '\0' && count >= 0)
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '\0')
				break ;
			print_format(args, str[i + 1], &count);
			i += 2;
		}
		else
		{
			print_char(str[i], &count);
			i += 1;
		}
	}
	return (va_end(args), count);
}
