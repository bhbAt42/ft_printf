/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhenriqu <bhenriqu@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:57:18 by bhenriqu          #+#    #+#             */
/*   Updated: 2024/10/25 21:18:56 by bhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

void	ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr_recursive(int n);
int		ft_putnbr(int n);
int		ft_putnbr_unsigned(unsigned int n);
int		fill_hex_buffer(char *hexa, uintptr_t decimal, int uppercase);
int		print_hex_buffer(char *hexa, int size);
int		deci_to_hexa(uintptr_t decimal, int uppercase);
int		ft_putptr(uintptr_t ptr);
int		handle_char_formats(char format, va_list args);
int		handle_num_formats(char format, va_list args);
int		handle_format(char format, va_list args);
int		ft_printf(const char *format, ...);

#endif