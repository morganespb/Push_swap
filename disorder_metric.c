/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder_metric.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/30 12:07:44 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/05 00:54:59 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

float	compute_disorder(t_node *a)
{
	float	mistakes;
	float	total_pairs;
	t_node	*v1;
	t_node	*v2;

	mistakes = 0;
	total_pairs = 0;
	v1 = a;
	while (v1)
	{
		v2 = v1->next;
		while (v2)
		{
			if (v1->value > v2->value)
				mistakes++;
			total_pairs++;
			v2 = v2->next;
		}
		v1 = v1->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}
