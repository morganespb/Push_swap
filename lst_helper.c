/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:48:32 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/05 14:21:03 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

t_node	*previous(t_node *stack)
{
	if (!stack || !stack->next)
		return (NULL);
	while (stack->next->next)
		stack = stack->next;
	return (stack);
}

int	stack_size(t_node *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	while (stack)
	{
		tmp = stack->next;
		stack->index = 0;
		stack->value = 0;
		free(stack);
		stack = tmp;
	}
}

int	add_value(t_node **a, char *str)
{
	t_node	*new;
	int		v;

	if (!safe_atoi(str, &v) || duplicates(*a, v))
		return (0);
	new = new_node(v);
	if (!new)
		return (0);
	add_back(a, new);
	return (1);
}
