/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: morganesimonprovo <morganesimonprovo@stud  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 13:24:36 by morganesimonp     #+#    #+#             */
/*   Updated: 2026/04/30 12:00:39 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swapv2.h"

static void	push(t_node **src, t_node **dst)
{
	t_node *tmp;

	if (!src || !*src)
		return ;
	tmp = *src;//take first node from tmp
	*src = (*src)->next;//src head becomes second node
	tmp->next = *dst;//old src head points to dst head
	*dst = tmp;//dst head becomes old src head
}

void	pa(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
