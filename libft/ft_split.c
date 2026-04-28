/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: mosimon <morgane.simon@learner.42.tech>   #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/04/23 09:42:03 by mosimon          #+#    #+#              */
/*   Updated: 2026/04/24 10:23:36 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_sep(char i, char c)
{
	if (i == c)
		return (1);
	return (0);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!is_sep(s[i], c) && (i == 0 || is_sep(s[i - 1], c)))
			count++;
		i++;
	}
	return (count);
}

int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && !is_sep(s[len], c))
		len++;
	return (len);
}

char	*fill_words(char const *s, char c)
{
	char	*word;
	int		i;
	int		len;

	i = 0;
	len = word_len(s, c);
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	arr = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (s[i])
	{
		while (s[i] && is_sep(s[i], c))
			i++;
		if (s[i])
		{
			arr[j] = fill_words(&s[i], c);
			j++;
			while (s[i] && !is_sep(s[i], c))
				i++;
		}
	}
	arr[j] = NULL;
	return (arr);
}
