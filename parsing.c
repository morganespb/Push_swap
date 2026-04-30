/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 16:39:20 by mosimon           #+#    #+#             */
/*   Updated: 2026/04/29 22:30:44 by morganesimonp    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

static void	print_error(void)
{
	write(2, "Error\n", 6);
}

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

t_node	*parsing(int ac, char **av)
{
	int		i;
	t_node	*a;
	int		v;

	i = 1;
	a = NULL;
	if (ac < 2)
		return (NULL);
	while (i < ac)
	{
		if (!safe_atoi(av[i], &v) || duplicates(a, v))
		{
			//print_error();
			free_stack(a);
			print_error();
			return (NULL);
		}
		add_back(&a, new_node(v));
		i++;
	}
	return (a);
}
