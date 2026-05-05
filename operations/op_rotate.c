/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:38:43 by morganesimo       #+#    #+#             */
/*   Updated: 2026/05/05 02:24:28 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *(stack);
	*stack = (*stack)->next;
	first->next = NULL;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
}

void	ra(t_node **a, int write_on)
{
	rotate(a);
	if (write_on)
		write(2, "ra\n", 3);
	g_stats.op_count++;
	g_stats.ra_count++;
}

void	rb(t_node **b, int write_on)
{
	rotate(b);
	if (write_on)
		write(2, "rb\n", 3);
	g_stats.op_count++;
	g_stats.rb_count++;
}

void	rr(t_node **a, t_node **b, int write_on)
{
	rotate(a);
	rotate(b);
	if (write_on)
		write(2, "rr\n", 3);
	g_stats.op_count++;
	g_stats.rr_count++;
}
