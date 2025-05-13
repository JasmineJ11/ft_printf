/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiawli <jiawli@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:25:27 by jiawli            #+#    #+#             */
/*   Updated: 2025/05/08 10:25:29 by jiawli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_uint(uintptr_t nb, char *digits, uintptr_t base, int *count)
{
	if (nb >= base)
	{
		print_uint(nb / base, digits, base, count);
		if (*count < 0)
			return ;
	}
	print_char(digits[nb % base], count);
}

void	print_int(intptr_t nb, char *digits, intptr_t base, int *count)
{
	if (nb < 0)
	{
		print_char('-', count);
		if (*count < 0)
			return ;
		nb = -nb;
	}
	print_uint((uintptr_t)nb, digits, base, count);
}

void	print_pointer(uintptr_t nb, char *digits, uintptr_t base, int *count)
{
	int	res;

	if (nb == 0)
	{
		res = write(1, "(nil)", 5);
		if (res == -1)
			*count = -1;
		else
			(*count) += res;
		return ;
	}
	res = write(1, "0x", 2);
	if (res == -1)
	{
		*count = -1;
		return ;
	}
	(*count) += res;
	if (*count < 0)
		return ;
	print_uint(nb, digits, base, count);
}
