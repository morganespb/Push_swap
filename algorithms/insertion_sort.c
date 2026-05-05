/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 02:20:53 by lcoant--          #+#    #+#             */
/*   Updated: 2026/05/05 02:21:28 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"
#include <stdio.h>

static int	reindex(t_node *a)
{
	int		index;
	int		base_index;
	int		value;
	t_node	*tmp;

	index = 0;
	base_index = 0;
	value = a->value;
	tmp = a;
	while (tmp)
	{
		if (tmp->value < value)
		{
			value = tmp->value;
			base_index = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (base_index);
}

static int	index_pos(t_node *a, int value)
{
	int		index;
	t_node	*element;

	index = 0;
	element = a;
	if (value < min_val(a))
		return (where_min(a));
	if (value > max_val(a))
		return (where_max(a) + 1);
	while (element->next)
	{
		if (element->value < value && element->next->value > value)
			return (index + 1);
		element = element->next;
		index++;
	}
	return (0);
}

static void	to_position(t_node **a, int index, int write_on)
{
	int	size;

	size = stack_size(*a);
	if (index <= size / 2)
	{
		while (index--)
			ra(a, write_on);
	}
	else
	{
		while (index++ < size)
			rra(a, write_on);
	}
}

void	ft_insertion_sort(t_node **a, t_node **b, int write_on)
{
	int	i;
	int	size;
	int	value;
	int	index;

	g_stats.strategy = "Simple / O(n^2)";
	i = 0;
	size = stack_size(*a);
	while (i++ < size - 1)
		pb(a, b, write_on);
	while (*b)
	{
		value = (*b)->value;
		index = index_pos(*a, value);
		to_position(a, index, write_on);
		pa(a, b, write_on);
	}
	index = reindex(*a);
	to_position(a, index, write_on);
}
