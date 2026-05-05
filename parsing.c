/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:39:20 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/05 14:16:18 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

int	safe_atoi(const char *str, int *out)
{
	long (res) = 0;
	int (sign) = 1;
	int (i) = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	if (!str[i])
		return (0);
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

int	duplicates(t_node *a, int v)
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
}

static void	ft_parse_flag(int *mode, int *i)
{
	if ((*mode >= 1 && *mode <= 4) || *mode == 10)
		(*i)++;
	else if (*mode >= 6 && *mode <= 9)
		*i = *i + 2;
}

t_node	*parsing(int ac, char **av, int *mode)
{
	int (i) = 0;
	t_node (*a) = NULL;
	if (ac < 2)
		return (NULL);
	while (i++ < ac - 1)
	{
		if (i == 1)
		{
			ft_is_flag(av, mode);
			ft_parse_flag(mode, &i);
		}
		if (!add_value(&a, av[i]))
		{
			free_stack(a);
			write(2, "Error\n", 6);
			return (NULL);
		}
	}
	return (a);
}
