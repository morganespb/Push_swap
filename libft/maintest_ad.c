/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest_ad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 13:54:55 by mosimon           #+#    #+#             */
/*   Updated: 2026/04/23 13:27:45 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	f(unsigned int i, char c)
{
	return (c = c + i);
}

void	g(unsigned int i, char *c)
{
	*c = *c + i;
}

int	main(void)
{
	char *s;
	char str[] = "abcd";
	char **tab;
	int i;

	//substr
	s = ft_substr("hello world", 6, 5);
	printf("substr : [%s]\n\n", s);
	free(s);

	//strjoin
	s = ft_strjoin("hello ", "world");
	printf("strjoin : [%s]\n\n", s);
	free(s);

	//strtrim
	s = ft_strtrim("   \t42Paris\n  ", "  \n\t");
	printf("strtrim : [%s]\n\n", s);
	free(s);

	//split
	tab = ft_split("aa bb  cc  ", ' ');
	printf("split: ");
	i = 0;
	while (tab[i])
	{
		printf("[%s] " , tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	printf("\n\n");

	//striteri
	ft_striteri(str, g);
	printf("striteri: [%s]\n\n", str);

	//strmapi
	s = ft_strmapi("abcd", f);
	printf("strmapi : [%s]\n\n", str);

	//fd functions
	printf("fd_functions:\n");
	ft_putchar_fd('A', 1);
	write(1, "\n", 1);
	ft_putstr_fd("hello", 1);
	write(1, "\n", 1);
	ft_putendl_fd("world", 1);
	ft_putnbr_fd(-12345, 1);
	write(1, "\n", 1);

	return 0;
}
