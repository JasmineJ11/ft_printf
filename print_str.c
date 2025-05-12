/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiawli <jiawli@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:24:07 by jiawli            #+#    #+#             */
/*   Updated: 2025/05/08 10:24:09 by jiawli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	print_str(char *str, int *count)
{
	int	res;

	if (*count < 0)
		return ;
	if (!str)
	{
		res = write(1, "(null)", 6);
		if (res == -1)
			*count = -1;
		else
			*count += res;
	}
	else
	{
		res = write(1, str, ft_strlen(str));
		if (res == -1)
			*count = -1;
		else
			*count += res;
	}
}

void	print_char(char c, int *count)
{
	int	res;

	if (*count < 0)
		return ;
	res = write(1, &c, 1);
	if (res < 1)
		*count = -1;
	else
		*count += res;
}
