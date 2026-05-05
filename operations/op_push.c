/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:24:36 by morganesimo       #+#    #+#             */
/*   Updated: 2026/05/05 02:19:30 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

static void	push(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_node **a, t_node **b, int write_on)
{
	push(b, a);
	if (write_on)
		write(2, "pa\n", 3);
	g_stats.op_count += 1;
	g_stats.pa_count += 1;
}

void	pb(t_node **a, t_node **b, int write_on)
{
	push(a, b);
	if (write_on)
		write(2, "pb\n", 3);
	g_stats.op_count += 1;
	g_stats.pb_count += 1;
}
