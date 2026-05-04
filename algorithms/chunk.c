/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morganesimonprovo <morganesimonprovo@stud  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 18:23:53 by morganesimonp     #+#    #+#             */
/*   Updated: 2026/05/04 12:50:11 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

int	index_max(t_node *s)
{
	int max;

	max = s->index;
	while (s)
	{
		if (s->index > max)
			max = s->index;
		s = s->next;
	}
	return max;
}

int pos_max(t_node *s)
{
	int max = s->index;
	int i = 0;
	int max_pos = 0;

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
	return max_pos;
}

void	push_back_max(t_node **a, t_node **b)
{
	int pos;
	int size_b;

	while (*b)
	{
		pos = pos_max(*b);
		size_b = stack_size(*b);

		if (pos <= size_b / 2)
			while (pos-- > 0)
				rb(b);
		else
			while (pos++ < size_b)
				rrb(b);

		pa(a, b);
	}
}

void	chunk_sort(t_node **a, t_node **b)
{
	int size;
	int chunk_size;
	int pushed;

	pushed = 0;
	strategy = "Medium / O(nn)";
	size = stack_size(*a);
	if (size <= 100)
		chunk_size = 15;
	else
		chunk_size = 40;

	while (*a)
	{
		if ((*a)->index <= pushed)
		{
			pb(a, b);
			rb(b);
			pushed++;
		}

		else if ((*a)->index <= pushed + chunk_size)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
	}
	push_back_max(a, b);

}
