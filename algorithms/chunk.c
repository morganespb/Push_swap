/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:23:53 by morganesimo       #+#    #+#             */
/*   Updated: 2026/05/05 02:21:29 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

int	index_max(t_node *s)
{
	int	max;

	max = s->index;
	while (s)
	{
		if (s->index > max)
			max = s->index;
		s = s->next;
	}
	return (max);
}

int	pos_max(t_node *s)
{
	int	max;
	int	i;
	int	max_pos;

	max = s->index;
	i = 0;
	max_pos = 0;
	while (s)
	{
		if (s->index > max)
		{
			max = s->index;
			max_pos = i;
		}
		s = s->next;
		i++;
	}
	return (max_pos);
}

void	push_back_max(t_node **a, t_node **b, int write_on)
{
	int	pos;
	int	size_b;

	while (*b)
	{
		pos = pos_max(*b);
		size_b = stack_size(*b);
		if (pos <= size_b / 2)
			while (pos-- > 0)
				rb(b, write_on);
		else
			while (pos++ < size_b)
				rrb(b, write_on);
		pa(a, b, write_on);
	}
}

static int	ft_get_chunk(int size)
{
	if (size <= 100)
		return (15);
	else
		return (40);
}

void	chunk_sort(t_node **a, t_node **b, int write_on)
{
	int (size) = stack_size(*a);
	int (chunk_size) = ft_get_chunk(size);
	int (pushed) = 0;
	g_stats.strategy = "Medium / O(n√n)";
	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b, write_on);
			rb(b, write_on);
			pushed++;
		}
		else if ((*a)->index <= pushed + chunk_size)
		{
			pb(a, b, write_on);
			pushed++;
		}
		else
			ra(a, write_on);
	}
	push_back_max(a, b, write_on);
}
