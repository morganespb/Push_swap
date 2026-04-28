/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/22 09:18:53 by username         #+#    #+#              */
/*   Updated: 2026/04/22 13:15:44 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) & s[i]);
		i++;
	}
	if ((char) c == '\0')
		return ((char *) & s[i]);
	return (NULL);
}
