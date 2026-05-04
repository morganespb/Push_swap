/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 02:20:53 by lcoant--          #+#    #+#             */
/*   Updated: 2026/05/04 12:50:16 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swapv2.h"

static int	reindex(t_node *a)
{
	int	index;
	int	base_index;
	int	value;
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
	int	index;
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

static void	to_position(t_node **a, int index)
{
	int	size;

	size = stack_size(*a);
	if (index <= size / 2)
	{
		while (index--)
			ra(a);
	}
	else
	{
		while (index++ < size)
			rra(a);
	}
}

void	ft_insertion_sort(t_node **a, t_node **b)
{
	int	i;
	int	size;
	int	value;
	int	index;

	strategy = "Simple / O(n^2)";
	i = 0;
	size = stack_size(*a);
	while (i++ < size - 1)
	{
		printf("index: %d\n", i);
		print_stack("A", *a);
		print_stack("B", *b);
		pb(a, b);
		print_stack("a", *a);
		print_stack("b", *b);
		printf("\n");
	}
	while (*b)
	{
		value = (*b)->value;
		index = index_pos(*a, value);
		to_position(a, index);
		pa(a, b);
	}
	index = reindex(*a);
	to_position(a, index);
}

/*void	ft_insertion_sort(int *tab, int n)
{
	int	i;
	int	j;
	int	key;
	

	i = 1;
	while (i < n)
	{
		key = tab[i];
		j = i;
		while (j > 0 && tab[j - 1] > key)
		{
			tab[j] = tab[j - 1];
			j--;
		}
		tab[j] = key;
		i++;
	}
}

int	main(void)
{
	int	i = 0;
	int	tab[] = {32, 54, 1, 98, 3};
	ft_insertion_sort(tab, 5);
	while (i < 5)
	{
		printf("%d ", tab[i]);
		i++;
	}
	printf("\n");
}*/
