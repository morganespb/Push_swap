/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:28:40 by morganesimo       #+#    #+#             */
/*   Updated: 2026/05/05 02:18:58 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = previous(*stack);
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **a, int write_on)
{
	reverse_rotate(a);
	if (write_on)
		write(2, "rra\n", 4);
	g_stats.op_count++;
	g_stats.rra_count++;
}

void	rrb(t_node **b, int write_on)
{
	reverse_rotate(b);
	if (write_on)
		write(2, "rrb\n", 4);
	g_stats.op_count++;
	g_stats.rrb_count++;
}

void	rrr(t_node **a, t_node **b, int write_on)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (write_on)
		write(2, "rrr\n", 4);
	g_stats.op_count++;
	g_stats.rrr_count++;
}
