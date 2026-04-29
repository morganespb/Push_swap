/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 12:00:32 by mosimon           #+#    #+#             */
/*   Updated: 2026/04/29 19:47:42 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//list manipulations helpers, def more than 5 functions, but we might be able to reduce that was just a
//first sketch. you're more comfortable in lists than me i think feel free to lmk if anything looks weird (:

t_node	*new_node(int value)
{
	t_node	*n;

	n = malloc(sizeof(t_node));
	if (!n)
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}

void	add_front(t_node **stack, t_node *new)
{
	if (!new)
		return ;
	new->next = *stack;
	*stack = new;
}

void	add_back(t_node **stack, t_node *new)
{
	t_node	*tmp;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

t_node	*pop_front(t_node **stack)
{
	t_node	*tmp;

	if (!*stack)
		return (NULL);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	return (tmp);
}

t_node	*last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

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
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
