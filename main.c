/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:48:32 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/05 13:37:01 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

t_count	g_stats;

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		mode;
	float	disorder;

	ft_set_stats();
	a = parsing(ac, av, &mode);
	if (!a && ac > 1)
		return (1);
	disorder = compute_disorder(a);
	b = NULL;
	ft_chose_mode(mode, &a, &b, disorder);
	free_stack(a);
	free_stack(b);
	return (0);
}

void	ft_chose_mode(int mode, t_node **a, t_node **b, float disorder)
{
	if ((mode >= 1 && mode <= 4) || mode == 11)
		ft_normal_mode(mode, a, b, disorder);
	else
		ft_bench_mode(mode, a, b, disorder);
}

void	ft_normal_mode(int mode, t_node **a, t_node **b, float disorder)
{
	if (mode == 1)
		ft_insertion_sort(a, b, 1);
	else if (mode == 2)
	{
		assign_indexes(*a);
		chunk_sort(a, b, 1);
	}
	else if (mode == 3)
	{
		assign_indexes(*a);
		radix_sort(a, b, 1);
	}
	else if (mode == 4 || mode == 11)
		ft_adaptativ(a, b, disorder, 1);
}

void	ft_bench_mode(int mode, t_node **a, t_node **b, float disorder)
{
	if (mode == 6)
	{
		ft_insertion_sort(a, b, 0);
		ft_bench(disorder);
	}
	else if (mode == 7)
	{
		assign_indexes(*a);
		chunk_sort(a, b, 0);
		ft_bench(disorder);
	}
	else if (mode == 8)
	{
		assign_indexes(*a);
		radix_sort(a, b, 0);
		ft_bench(disorder);
	}
	else if (mode == 10 || mode == 9)
	{
		ft_adaptativ(a, b, disorder, 0);
		ft_bench(disorder);
	}
}

void	ft_set_stats(void)
{
	g_stats.op_count = 0;
	g_stats.sa_count = 0;
	g_stats.sb_count = 0;
	g_stats.ss_count = 0;
	g_stats.ra_count = 0;
	g_stats.rb_count = 0;
	g_stats.rr_count = 0;
	g_stats.rra_count = 0;
	g_stats.rrb_count = 0;
	g_stats.rrr_count = 0;
	g_stats.pa_count = 0;
	g_stats.pb_count = 0;
}
