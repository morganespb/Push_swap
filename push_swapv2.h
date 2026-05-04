/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swapv2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:14:00 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/04 15:37:34 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAPV2_H
# define PUSH_SWAPV2_H

# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_node
{
	int	value;
	int	index;

	struct s_node * next;
}	t_node;

extern int	op_count;
extern char *strategy;

t_node	*new_node(int value);
void	add_front(t_node **stack, t_node *new);
void	add_back(t_node **stack, t_node *new);
t_node	*pop_front(t_node **stack);
t_node	*last_node(t_node *stack);
t_node	*previous(t_node *stack);
int		stack_size(t_node *stack);
void	free_stack(t_node *stack);
void	sa(t_node **stack);
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
t_node	*parsing(int ac, char **av, int *mode);
float		compute_disorder(t_node *a);
void	assign_indexes(t_node *stack);
void	radix_sort(t_node **a, t_node **b);
void	print_debug(t_node *s);
int		is_sorted(t_node *a);
int		index_max(t_node *s);
int		pos_max(t_node *s);
void	chunk_sort(t_node **a, t_node **b);
void	ft_bubble_sort(t_node **a);
void	ft_insertion_sort(t_node **a, t_node **b);
int	where_min(t_node *a);
int	where_max(t_node *a);
int	min_val(t_node *a);
int	max_val(t_node *a);
void	bucket_sort(t_node **a, t_node **b);
void	ft_bench(void);
char	*ft_ftoa(float nb);
void	print_bench(float disorder,char *strategy,int op_count);
int		is_bench(int mode);
int		which_strategy(int mode);

#endif
