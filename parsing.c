/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:39:20 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/04 15:58:48 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

/*static void	print_error(void)
{
	write(2, "Error\n", 6);
}*/

static int	safe_atoi(const char *str, int *out) //not sure of this, tried to make an atoi that check overlow and also returns value but testing needed
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;

	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}

	//if (!str[i])
	//return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		res = res * 10 + (str[i] - '0');
		if (res * sign > INT_MAX || res * sign < INT_MIN)
			return (0);
		i++;
	}
	*out = (int)(res * sign);
	return (1);
}

static int	duplicates(t_node *a, int v)
{
	while (a)
	{
		if (a->value == v)
			return (1);
		a = a->next;
	}
	return (0);
}

static void	ft_is_flag(char **av, int *mode)
{
	if (!ft_strncmp(av[1], "--simple", 50))
		*mode = 1;
	else if (!ft_strncmp(av[1], "--medium", 50))
		*mode = 2;
	else if (!ft_strncmp(av[1], "--complex", 50))
		*mode = 3;
	else if (!ft_strncmp(av[1], "--adaptive", 50))
		*mode = 4;
	else if (!ft_strncmp(av[1], "--bench", 50))
	{
		printf("AV : %s\n", av[2]);
		printf("CMP : %d\n", ft_strncmp(av[2], "--complex", 50));
		if (!ft_strncmp(av[2], "--simple", 50))
			*mode = 6;
		else if (!ft_strncmp(av[2], "--medium", 50))
			*mode = 7;
		else if (!ft_strncmp(av[2], "--complex", 50))
			*mode = 8;
		else if (!ft_strncmp(av[2], "--adaptive", 50))
			*mode = 9;
		else
			*mode = 10;
	}
	else
		*mode = 11;
	write(2, "ERROR\n", 6);
	printf("MODE VALUE : %d\n", (*mode));
}

/*int	is_bench(int mode)
{
	return (mode >= 6);
}

int	which_strategy(int mode)
{
	if (mode >= 6 &&mode <= 9)
		return (mode - 5);
	if (mode == 10)
		return (4);
	return (mode);
}*/

static void	ft_parse_flag(int *mode, int *i)
{
	if ((*mode >= 1 && *mode <= 4) || *mode == 10)
		(*i)++;
	else if (*mode >= 6 && *mode <= 9)
		*i = *i + 2;
}

t_node	*parsing(int ac, char **av, int *mode)
{
	int		i;
	t_node	*a;
	int		v;

	i = 0;
	a = NULL;
	if (ac < 2)
		return (NULL);
	printf("AV : %s\n", av[1]);
	printf("AV : %s\n", av[2]);
	while (i++ < ac - 1)
	{
		write(2, "ERROR\n", 6);
		printf("VALUE I : %d\n", i);
		printf("VALUE I : %d\n", i);
		if (i == 1)
		{
			write(2, "ERROR\n", 6);
			printf("MODE VALUE : %d\n", (*mode));
			ft_is_flag(av, mode);
			ft_parse_flag(mode, &i);
		}
		if (!safe_atoi(av[i], &v) || duplicates(a, v))
		{
			write(2, "ERROR\n", 6);
			//print_error();
			free_stack(a);
			//print_error();
			return (NULL);
		}
		add_back(&a, new_node(v));
	}
	return (a);
}
