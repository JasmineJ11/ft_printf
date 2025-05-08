/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiawli <jiawli@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 17:10:04 by jiawli            #+#    #+#             */
/*   Updated: 2025/05/02 17:10:09 by jiawli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int	ft_strlen(char *str);
int	print_str(char *str);
int	print_char(char c);
int	print_uint(uintptr_t nb, char *digits, uintptr_t base);
int	print_int(intptr_t nb, char *digits, intptr_t base);
int	print_pointer(uintptr_t nb, char *digits, uintptr_t base);
int	print_format(va_list args, char c);
int	ft_printf(const char *str, ...);
#endif