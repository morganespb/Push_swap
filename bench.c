/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:17:17 by lcoant--          #+#    #+#             */
/*   Updated: 2026/05/05 01:27:01 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

void	ft_bench(float disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(disorder);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(g_stats.strategy, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.op_count), 2);
	ft_putstr_fd("\n", 2);
	ft_display_stats();
}

void	ft_display_stats(void)
{
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.sa_count), 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.sb_count), 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.ss_count), 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.pa_count), 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.pb_count), 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.ra_count), 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.rb_count), 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.rr_count), 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.rra_count), 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.rrb_count), 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putstr_fd_free(ft_itoa(g_stats.rrr_count), 2);
	ft_putstr_fd("\n", 2);
}

void	print_disorder(float disorder)
{
	int	value;

	value = (int)(disorder * 10000);
	ft_putnbr_fd(value / 100, 2);
	ft_putstr_fd(".", 2);
	if ((value % 100) < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(value % 100, 2);
	ft_putstr_fd("%\n", 2);
}
