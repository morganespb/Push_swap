/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:48:32 by mosimon           #+#    #+#             */
/*   Updated: 2026/04/29 19:54:51 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = parsing(ac, av);
	if (!a && ac > 1)
		return (1);
	b = NULL;
	print_stack("A", a);
	print_stack("B", b);
	pb(&a, &b);
	print_stack("A", a);
	print_stack("B", b);
}
