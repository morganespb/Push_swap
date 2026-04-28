/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mosimon <morgane.simon@learner.42.tech>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/23 09:44:05 by mosimon          #+#    #+#              */
/*   Updated: 2026/04/23 09:57:39 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 1;
	if (n <= 0)
		len++;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*res;

	long (nb) = n;
	int (len) = ft_len(n);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (nb < 0)
	{
		res[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		res[0] = '0';
	while (nb > 0)
	{
		res[len - 1] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
	return (res);
}
