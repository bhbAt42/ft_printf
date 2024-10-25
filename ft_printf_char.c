/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bhenriqu <bhenriqu@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 21:10:28 by bhenriqu          #+#    #+#             */
/*   Updated: 2024/10/25 21:10:46 by bhenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
    write(1, &c, 1);
}

int	ft_putstr(char *str)
{
    int	count;

    count = 0;
    if (!str)
    {
        ft_putstr("(null)");
        return (6);
    }
    while (*str)
    {
        ft_putchar(*str);
        str++;
        count++;
    }
    return (count);
}
