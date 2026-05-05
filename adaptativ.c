/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptativ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/04 23:33:31 by lcoant--          #+#    #+#             */
/*   Updated: 2026/05/05 13:40:13 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

void	ft_adaptativ(t_node **a, t_node **b, float disorder, int write_on)
{
	if (disorder < 0.2)
		ft_insertion_sort(a, b, write_on);
	else if (disorder >= 0.2 && disorder < 0.5)
	{
		assign_indexes(*a);
		chunk_sort(a, b, write_on);
	}
	else if (disorder >= 0.5)
	{
		assign_indexes(*a);
		radix_sort(a, b, write_on);
	}
}
