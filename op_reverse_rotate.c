/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morganesimonprovo <morganesimonprovo@stud  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:28:40 by morganesimonp     #+#    #+#             */
/*   Updated: 2026/04/29 15:56:50 by morganesimonp    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node *prev;
	t_node *last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	prev = previous(*stack);
	last = prev->next;
	prev->next = NULL;
	add_front(last, stack);

}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}
