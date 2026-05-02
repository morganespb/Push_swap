/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:17:17 by lcoant--          #+#    #+#             */
/*   Updated: 2026/05/02 13:33:07 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

void	ft_bench(void)
{
	int	fd = open("bench.txt", O_WRONLY);
	ft_putstr_fd("[bench] disorder: ",fd);
	ft_putstr_fd("40.00%\n",fd); //place holder
	ft_putstr_fd("[bench] strategy: ",fd);
	ft_putstr_fd("Simple / O(n^2)\n",fd);
	ft_putstr_fd("[bench] total_ops: ",fd);
	ft_putstr_fd("231\n",fd);
	ft_putstr_fd("[bench] sa: ",fd);
	ft_putstr_fd("0 ",fd);
	ft_putstr_fd("ss:  ",fd);
	ft_putstr_fd("0 ",fd);
	ft_putstr_fd("pa: ",fd);
	ft_putstr_fd("0 ",fd);
	ft_putstr_fd("pb: ",fd);
	ft_putstr_fd("0 \n",fd);
	ft_putstr_fd("[bench] ra: ",fd);
	ft_putstr_fd("0 ",fd);
	ft_putstr_fd("rb: ",fd);
	ft_putstr_fd("0 ",fd);
	ft_putstr_fd("rr: ",fd);
	ft_putstr_fd("0 ",fd);
	ft_putstr_fd("rra: ",fd);
	ft_putstr_fd("0 ",fd);
	ft_putstr_fd("rrb: ",fd);
	ft_putstr_fd("0 ",fd);
	ft_putstr_fd("rrr: ",fd);
	ft_putstr_fd("0 \n",fd);
	close(fd);
}
