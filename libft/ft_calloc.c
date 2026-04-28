/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mosimon <morgane.simon@learner.42.tech>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/22 09:32:53 by mosimon          #+#    #+#              */
/*   Updated: 2026/04/24 10:09:11 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*tmp;
	size_t			i;

	if (size == 0 || count == 0)
		return (malloc(1));
	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	i = 0;
	tmp = (unsigned char *) ptr;
	while (i < size * count)
	{
		tmp[i] = 0;
		i++;
	}
	return (ptr);
}
