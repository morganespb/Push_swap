/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:16:27 by mosimon           #+#    #+#             */
/*   Updated: 2026/04/22 13:46:33 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i])
	{
		if (s[i] == (char) c)
			last = (char *) & s[i];
		i++;
	}
	if ((char) c == '\0')
		return ((char *) & s[i]);
	return (last);
}
