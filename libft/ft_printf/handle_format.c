/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <student.42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026-04-12 17:11:35 by marvin            #+#    #+#             */
/*   Updated: 2026/04/29 21:00:33 by morganesimonp    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int handle_format(char c, va_list args)
{
    if (c == 'c')
        return (ft_print_char((char)va_arg(args, int)));
    else if (c == 's')
        return (ft_print_str(va_arg(args, char *)));
    else if (c == 'd' || c == 'i')
        return (ft_print_nbr(va_arg(args, int)));
    else if (c == 'u')
        return (ft_print_unsigned(va_arg(args, unsigned int)));
    else if (c == 'x')
        return (ft_print_hex(va_arg(args, unsigned int), 0));
    else if (c == 'X')
        return (ft_print_hex(va_arg(args, unsigned int), 1));
    else if (c == '%')
        return (ft_print_char('%'));
    return (0);
}

