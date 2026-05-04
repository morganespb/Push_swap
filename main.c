/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:48:32 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/04 15:36:10 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

int op_count = 0;
char *strategy = NULL;

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int	mode;
	int bench;
	float disorder;

	mode = 4;
	a = parsing(ac, av, &mode);
	if (!a && ac > 1)
		return (1);

	bench = is_bench(mode);
	mode = which_strategy(mode);
	disorder = compute_disorder(a);
	b = NULL;

	printf("disorder: %.1f\n\n", compute_disorder(a));
	ft_ftoa(compute_disorder(a));
	printf("disorder: %.1f\n\n", compute_disorder(a));
	if (mode == 1)
		//ft_bubble_sort(&a);
		ft_insertion_sort(&a, &b);
	else if (mode == 2)
	{
		assign_indexes(a);
		//bucket_sort(&a, &b);
		//ft_insertion_sort(&a, &b);
		chunk_sort(&a, &b);
	}
	else if (mode == 3)
	{
		assign_indexes(a);
		radix_sort(&a, &b);
	}
	else if (mode == 4 || mode == 11)
	{
		//adaptativ();
	}
	else if (mode == 6)
	{
		ft_insertion_sort(&a, &b);
		ft_bench();
	}
	else if (mode == 7)
	{
		assign_indexes(a);
		bucket_sort(&a, &b);
		ft_insertion_sort(&a, &b);
		ft_bench();
	}
	else if (mode == 8)
	{
		assign_indexes(a);
		radix_sort(&a, &b);
		ft_bench();
	}
	else if (mode == 10 || mode == 9)
	{
		//adaptativ();
		ft_bench();
	}
	printf("op counter: %d", op_count);
	/*print_stack("A", a);
	if (bench)
		print_bench(disorder, strategy, op_count);
	printf("op counter: %d\n", op_count);
	print_stack("A", a);
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
