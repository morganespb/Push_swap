/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:48:32 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/02 11:55:30 by lcoant--         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

int op_count = 0;

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int	mode;

	mode = 0;
	a = parsing(ac, av, &mode);
	if (!a && ac > 1)
		return (1);
	b = NULL;

	if (mode == 1)
		ft_insertion_sort(&a, &b);
	else if (mode == 2)
	{
		assign_indexes(a);
		bucket_sort(&a, &b);
		ft_insertion_sort(&a, &b);
	}
	else if (mode == 3)
	{
		assign_indexes(a);
		radix_sort(&a, &b);
	}
	/*print_stack("A", a);
	print_stack("B", b);
	printf("\n");
	printf("disorder: %.1f\n\n", compute_disorder(a));
	assign_indexes(a);
	//radix_sort(&a, &b);
	//ft_bubble_sort(&a);
	bucket_sort(&a, &b);
	ft_insertion_sort(&a, &b);
	print_stack("A", a);
	print_stack("B", b);
	printf("op counter: %d", op_count);

	pb(&b, &a);
	print_stack("A", a);
	print_stack("B", b);
	printf("\n");	
	ra(&a);
	print_stack("A", a);
	print_stack("B", b);
	printf("\n");
	pa(&a, &b);
	print_stack("A", a);
	print_stack("B", b);
	printf("\n");
	rra(&a);
	print_stack("A", a);*/

	free_stack(a);
	free_stack(b);
	return (0);
}
