/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swapv2.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:14:00 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/05 14:21:54 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAPV2_H
# define PUSH_SWAPV2_H

# include "libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;

	struct s_node	*next;
}					t_node;

typedef struct s_count
{
	int				op_count;
	char			*strategy;
	int				sa_count;
	int				sb_count;
	int				ss_count;
	int				ra_count;
	int				rb_count;
	int				rr_count;
	int				rra_count;
	int				rrb_count;
	int				rrr_count;
	int				pa_count;
	int				pb_count;
}					t_count;

extern t_count		g_stats;

t_node				*new_node(int value);
void				add_front(t_node **stack, t_node *new);
void				add_back(t_node **stack, t_node *new);
t_node				*pop_front(t_node **stack);
t_node				*last_node(t_node *stack);
t_node				*previous(t_node *stack);
int					stack_size(t_node *stack);
void				free_stack(t_node *stack);
void				sa(t_node **stack, int write_on);
void				sb(t_node **b, int write_on);
void				ss(t_node **a, t_node **b, int write_on);
void				pa(t_node **a, t_node **b, int write_on);
void				pb(t_node **a, t_node **b, int write_on);
void				rra(t_node **a, int write_on);
void				rrb(t_node **b, int write_on);
void				rrr(t_node **a, t_node **b, int write_on);
void				ra(t_node **a, int write_on);
void				rb(t_node **a, int write_on);
void				rr(t_node **a, t_node **b, int write_on);
t_node				*parsing(int ac, char **av, int *mode);
float				compute_disorder(t_node *a);
void				assign_indexes(t_node *stack);
void				radix_sort(t_node **a, t_node **b, int write_on);
int					is_sorted(t_node *a);
int					index_max(t_node *s);
int					pos_max(t_node *s);
void				chunk_sort(t_node **a, t_node **b, int write_on);
void				ft_insertion_sort(t_node **a, t_node **b, int write_on);
int					where_min(t_node *a);
int					where_max(t_node *a);
int					min_val(t_node *a);
int					max_val(t_node *a);
void				ft_bench(float disorder);
void				print_disorder(float disorder);
void				ft_bench_mode(int mode, t_node **a, t_node **b,
						float disorder);
void				ft_normal_mode(int mode, t_node **a, t_node **b,
						float disorder);
void				ft_chose_mode(int mode, t_node **a, t_node **b,
						float disorder);
void				ft_set_stats(void);
void				ft_display_stats(void);
void				ft_adaptativ(t_node **a, t_node **b, float disorder,
						int write_on);
int					add_value(t_node **a, char *str);
int					safe_atoi(const char *str, int *out);
int					duplicates(t_node *a, int v);

#endif
