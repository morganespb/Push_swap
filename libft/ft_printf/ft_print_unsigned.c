/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-12 16:56:48 by marvin            #+#    #+#             */
/*   Updated: 2026/04/29 20:59:07 by morganesimonp    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_print_unsigned(unsigned int n)
{
    char c;
    int len;

    len = 1;
    if (n >= 10)
        len += ft_print_unsigned(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
    return (len);
}

