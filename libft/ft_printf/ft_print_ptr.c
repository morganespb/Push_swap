/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-12 16:57:10 by marvin            #+#    #+#             */
/*   Updated: 2026/04/29 20:58:47 by morganesimonp    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int ft_print_ptr(void *ptr)
{
    unsigned long address;
    int len;

    address = (unsigned long)ptr;
    len = 0;
    len += write(1, "0x", 2);
    len += ft_print_hex(address, 0);
    return (len);
}
