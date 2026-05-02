/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 08:47:24 by lcoant--          #+#    #+#             */
/*   Updated: 2026/05/02 10:58:50 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

static int	give_chunk_size(int size)
{
	if (size <= 100)
		return (20);
	return (45);
}

void	bucket_sort(t_node **a, t_node **b)
{
	int	chunk_size;
	int	size;
	int	limit;

	size = stack_size(*a);
	chunk_size = give_chunk_size(size);
	limit = chunk_size;
	while (*a)
	{
		if ((*a)->index <= limit)
		{
			pb(a, b);
			limit++;
			/*printf("index:%d\n", (*a)->index);
			print_stack("A", *a);
			print_stack("B", *b);
			printf("\n");*/
		}
		else
			ra(a);
	}
	pa(a, b);
}
