/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhenriqu <bhenriqu@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:04:53 by bhenriqu          #+#    #+#             */
/*   Updated: 2024/10/25 21:06:28 by bhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_char_formats(char format, va_list args)
{
    if (format == 's')
        return (ft_putstr(va_arg(args, char *)));
    if (format == 'c')
    {
        ft_putchar((char)va_arg(args, int));
        return (1);
    }
    if (format == '%')
    {
        ft_putchar('%');
        return (1);
    }
    return (0);
}

int	handle_num_formats(char format, va_list args)
{
    if (format == 'd' || format == 'i')
        return (ft_putnbr(va_arg(args, int)));
    if (format == 'u')
        return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
    if (format == 'x')
        return (deci_to_hexa(va_arg(args, unsigned int), 0));
    if (format == 'X')
        return (deci_to_hexa(va_arg(args, unsigned int), 1));
    if (format == 'p')
        return (ft_putptr((uintptr_t)va_arg(args, void *)));
    return (0);
}

int	handle_format(char format, va_list args)
{
    int	result;

    result = handle_char_formats(format, args);
    if (result)
        return (result);
    return (handle_num_formats(format, args));
}

int	ft_printf(const char *format, ...)
{
    va_list	args;
    int		total_count;

    if (!format)
        return (-1);
    total_count = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%' && *(format + 1))
        {
            format++;
            total_count += handle_format(*format, args);
        }
        else
        {
            ft_putchar(*format);
            total_count++;
        }
        format++;
    }
    va_end(args);
    return (total_count);
}
