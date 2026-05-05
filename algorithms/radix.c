/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 11:43:29 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/05 02:24:25 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

void	assign_indexes(t_node *stack)
{
	t_node	*current;
	t_node	*compare;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		compare = stack;
		while (compare)
		{
			if (compare->value < current->value)
				index++;
			compare = compare->next;
		}
		current->index = index;
		current = current->next;
	}
}

void	radix_sort(t_node **a, t_node **b, int write_on)
{
	int (size) = stack_size(*a);
	int (max_index) = size - 1;
	int (max_bits) = 0;
	int (i) = 0;
	int (j) = 0;
	g_stats.strategy = "Complex / O(n log n)";
	while ((max_index >> max_bits) != 0)
		max_bits++;
	while (i++ < max_bits)
	{
		if (is_sorted(*a))
			break ;
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				pb(a, b, write_on);
			else
				ra(a, write_on);
			j++;
		}
		while (*b)
			pa(a, b, write_on);
	}
}
