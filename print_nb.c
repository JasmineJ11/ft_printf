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

int	print_uint(uintptr_t nb, char *digits, uintptr_t base)
{
	int	count;

	count = 0;
	if (nb >= base)
	{
		count += print_uint(nb / base, digits, base);
	}
	count += print_char(digits[nb % base]);
	return (count);
}

int	print_int(intptr_t nb, char *digits, intptr_t base)
{
	int	count;

	count = 0;
	if (nb < 0)
	{
		print_char('-');
		nb = -nb;
		count++;
	}
	count += print_uint(nb, digits, base);
	return (count);
}

int	print_pointer(uintptr_t nb, char *digits, uintptr_t base)
{
	int count;
	count = 0;
	if (nb == 0)
	{
		count = print_str("(nil)");
		return count;
	}
	
	count += print_str("0x");
	count += print_uint(nb, digits, base);
	return (count);
}