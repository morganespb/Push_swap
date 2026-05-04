/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoant-- <lcoant--@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 13:17:17 by lcoant--          #+#    #+#             */
/*   Updated: 2026/05/04 13:59:45 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

/*void	ft_bench(void)
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
}*/
void	print_disorder(float disorder)
{
	int value;

	value = (int)(disorder * 10000);
	ft_putnbr_fd(value / 100, 2);
	ft_putstr_fd(".", 2);
	if ((value % 100) < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(value % 100, 2);
	ft_putstr_fd("%\n", 2);
}

void	print_bench(float disorder, char *strategy, int op_count)//create new struct to count op?
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_disorder(disorder);

	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd("\n", 2);

	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(op_count, 2);
	ft_putstr_fd("\n", 2);
}
