/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/12 16:56:59 by marvin            #+#    #+#             */
/*   Updated: 2026/05/05 01:16:25 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_hex(unsigned long long n, int uppercase)
{
	char	*base;
	int		len;

	if (uppercase)
		base = "0123456789ABBCDEF";
	else
		base = "0123456789abcdef";
	len = 1;
	if (n >= 16)
		len += ft_print_hex(n / 16, uppercase);
	write(1, &base[n % 16], 1);
	return (len);
}
