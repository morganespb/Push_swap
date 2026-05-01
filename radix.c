/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/01 11:43:29 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/01 17:07:12 by morganesimonp    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swapv2.h"

//first we'll index the values (sorted) so we can work with less bits to check.
//then the idea is to check bit by bit from the rightmost. i is my index to the
//bit we're checking. if its even (=0) we push it to b, if not we rotate in A to
//keep the right order and check the next one. then you basically have two
//stacks of bits 0 and 1. you push back to A, so you have stack A filled with
//0's and 1's sorted. then you check the next bit, you repeat the operation, and
//you finish with a sorted A. let me know if i make sense.
//so logically radix should have a fixed number of operations, i dont think we
//go much lower than 1084 for 100 numbers. but my ego wants to try, so lets see
//if i can make it any better
void	assign_indexes(t_node *stack)//function to give each nodes its sorted rank
{
	t_node *current;//node we're indexing
	t_node *compare;//used to scan the stack
	int index;//count how many values are smaller than current->value

	current = stack;//first node
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

void	radix_sort(t_node **a, t_node **b)
{
	int size;
	int max_index;
	int max_bits;
	int i;//bit position
	int j;//loop counter

	size = stack_size(*a);
	max_index = size - 1;
	max_bits = 0;
	i = 0;//checking bit 0
	j = 0;//processed 0 nodes so far

	while ((max_index >> max_bits) != 0)
		max_bits++;

	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
			{
				pb(b, a);
				//printf("index:%d\n", i);
				print_stack("A", *a);
				print_stack("B", *b);
				printf("\n");
			}
			else
				ra(a);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
