/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:32:40 by morganesimo       #+#    #+#             */
/*   Updated: 2026/05/05 02:17:13 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

static void	swap_top(t_node **stack)
{
	int	tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sa(t_node **a, int write_on)
{
	swap_top(a);
	if (write_on)
		write(2, "sa\n", 3);
	g_stats.op_count++;
	g_stats.sa_count++;
}

void	sb(t_node **b, int write_on)
{
	swap_top(b);
	if (write_on)
		write(2, "sb\n", 3);
	g_stats.op_count++;
	g_stats.sb_count++;
}

void	ss(t_node **a, t_node **b, int write_on)
{
	swap_top(a);
	swap_top(b);
	if (write_on)
		write(2, "ss\n", 3);
	g_stats.op_count++;
	g_stats.ss_count++;
}
