/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhenriqu <bhenriqu@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:07:42 by bhenriqu          #+#    #+#             */
/*   Updated: 2024/10/25 21:08:59 by bhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	fill_hex_buffer(char *hexa, uintptr_t decimal, int uppercase)
{
    int	i;
    int	temp;

    i = 0;
    while (decimal != 0)
    {
        temp = decimal % 16;
        if (temp < 10)
            hexa[i] = temp + '0';
        else if (uppercase)
            hexa[i] = temp - 10 + 'A';
        else
            hexa[i] = temp - 10 + 'a';
        decimal = decimal / 16;
        i++;
    }
    return (i);
}

int	print_hex_buffer(char *hexa, int size)
{
    int	count;

    count = 0;
    while (size > 0)
    {
        size--;
        ft_putchar(hexa[size]);
        count++;
    }
    return (count);
}

int	deci_to_hexa(uintptr_t decimal, int uppercase)
{
    char	hexa[16];
    int		size;

    if (decimal == 0)
    {
        ft_putchar('0');
        return (1);
    }
    size = fill_hex_buffer(hexa, decimal, uppercase);
    return (print_hex_buffer(hexa, size));
}

int	ft_putptr(uintptr_t ptr)
{
    int	count;

    count = ft_putstr("0x");
    if (ptr == 0)
    {
        ft_putchar('0');
        return (count + 1);
    }
    return (count + deci_to_hexa(ptr, 0));
}
