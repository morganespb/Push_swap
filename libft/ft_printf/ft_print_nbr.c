/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-12 16:56:25 by marvin            #+#    #+#             */
/*   Updated: 2026/04/29 21:00:15 by morganesimonp    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_print_nbr(int n)
{
    long nb;
    char c;
    int len;

    nb = n;
    len = 1;
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
        len++;
    }
    if (nb >= 10)
        len += ft_print_nbr(nb / 10);
    c = (nb % 10) + '0';
    write(1, &c, 1);
    return (len);
}
