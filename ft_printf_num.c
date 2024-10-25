/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhenriqu <bhenriqu@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:09:35 by bhenriqu          #+#    #+#             */
/*   Updated: 2024/10/25 21:10:00 by bhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_recursive(int n)
{
    int	count;

    count = 0;
    if (n >= 10)
        count += ft_putnbr_recursive(n / 10);
    ft_putchar((n % 10) + '0');
    return (count + 1);
}

int	ft_putnbr(int n)
{
    int	count;

    count = 0;
    if (n == -2147483648)
        return (ft_putstr("-2147483648"));
    if (n < 0)
    {
        ft_putchar('-');
        n = -n;
        count++;
    }
    count += ft_putnbr_recursive(n);
    return (count);
}

int	ft_putnbr_unsigned(unsigned int n)
{
    int	count;

    count = 0;
    if (n >= 10)
        count += ft_putnbr_unsigned(n / 10);
    ft_putchar((n % 10) + '0');
    return (count + 1);
}
