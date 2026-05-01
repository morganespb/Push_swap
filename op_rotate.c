/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morganesimonprovo <morganesimonprovo@stud  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:38:43 by morganesimonp     #+#    #+#             */
/*   Updated: 2026/05/01 14:18:53 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

static void		rotate(t_node **stack)
{
	t_node *first;
	t_node *last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = pop_front(stack);
	last = last_node(*stack);
	last->next = first;
	first->next = NULL;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
	op_count++;
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 1);
	op_count++;
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	op_count++;
}
