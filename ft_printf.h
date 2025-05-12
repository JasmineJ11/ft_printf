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
# include <stdint.h>
# include <unistd.h>

int		ft_strlen(char *str);
void	print_str(char *str, int *count);
void	print_char(char c, int *count);
void	print_uint(uintptr_t nb, char *digits, uintptr_t base, int *count);
void	print_int(intptr_t nb, char *digits, intptr_t base, int *count);
void	print_pointer(uintptr_t nb, char *digits, uintptr_t base, int *count);
void	print_format(va_list args, char c, int *count);
int		ft_printf(const char *str, ...);
#endif
