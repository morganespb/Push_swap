/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morganesimonprovo <morganesimonprovo@stud  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:32:40 by morganesimonp     #+#    #+#             */
/*   Updated: 2026/04/29 21:17:53 by morganesimonp    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swapv2.h"

static void		swap_top(t_node **stack)
{
	int tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sa(t_node **a)
{
	swap_top(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap_top(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap_top(a);
	swap_top(b);
}




