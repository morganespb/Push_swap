/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morganesimonprovo <morganesimonprovo@stud  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:24:36 by morganesimonp     #+#    #+#             */
/*   Updated: 2026/04/29 21:17:19 by morganesimonp    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swapv2.h"

void	pa(t_node **a, t_node **b)
{
	t_node *node;

	if (!b || !*b)
		return ;
	node = pop_front(b);
	add_front(a, node);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	t_node *node;
	
	if (!b || !*b)
		return ;
	node = pop_front(a);
	add_front(b, node);
	write(1, "pb\n", 3);
}
