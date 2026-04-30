/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swapv2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:14:00 by mosimon           #+#    #+#             */
/*   Updated: 2026/04/30 12:48:04 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAPV2_H
# define PUSH_SWAPV2_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_node
{
	int	value;
	struct s_node * next;
}	t_node;

t_node	*new_node(int value);
void	add_front(t_node **stack, t_node *new);
void	add_back(t_node **stack, t_node *new);
t_node	*pop_front(t_node **stack);
t_node	*last_node(t_node *stack);
t_node	*previous(t_node *stack);
int		stack_size(t_node *stack);
void	free_stack(t_node *stack);
void	sa(t_node **stack);
//ive added printing in the op_functions to test
//some stuff but we'll need to change that obvio
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	ra(t_node **a);
void	rb(t_node **a);
void	rr(t_node **a, t_node **b);
void	print_stack(char *name, t_node *s);
t_node	*parsing(int ac, char **av);
float		compute_disorder(t_node *a);

#endif
