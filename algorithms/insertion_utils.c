/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 05:05:16 by lcoant--          #+#    #+#             */
/*   Updated: 2026/05/05 02:21:27 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

int	max_val(t_node *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

int	min_val(t_node *a)
{
	int	min;

	min = a->value;
	while (a)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

int	where_min(t_node *a)
{
	int		index;
	int		min_index;
	int		min;
	t_node	*element;

	index = 0;
	min_index = 0;
	min = a->value;
	element = a;
	while (element)
	{
		if (element->value < min)
		{
			min = element->value;
			min_index = index;
		}
		element = element->next;
		index++;
	}
	return (min_index);
}

int	where_max(t_node *a)
{
	int		index;
	int		max_index;
	int		max;
	t_node	*element;

	index = 0;
	max_index = 0;
	max = a->value;
	element = a;
	while (element)
	{
		if (element->value > max)
		{
			max = element->value;
			max_index = index;
		}
		element = element->next;
		index++;
	}
	return (max_index);
}
