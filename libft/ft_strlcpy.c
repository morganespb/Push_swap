/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 14:18:58 by mosimon           #+#    #+#             */
/*   Updated: 2026/04/21 14:19:22 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	while (src[j] && j < size - 1)
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
