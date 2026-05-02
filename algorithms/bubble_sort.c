#include "push_swapv2.h"

void	ft_bubble_sort(t_node **a)
{
	int	is_sorted;
	int	i;
	int	size;
	int	n;

	is_sorted = 0;
	size = stack_size(*a);
	printf("SIZE : %d\n", size);
	n = size - 1;
	while(n > 0)
	{
		i = 0;
		is_sorted = 1;
		while (i < n)
		{
			if ((*a)->value > (*a)->next->value)
			{
				sa(a);
				printf("index: %d\n", i);
				print_stack("A", *a);
				printf("\n");
				is_sorted = 0;
			}
			ra(a);
			printf("index: %d\n", i);
			print_stack("A", *a);
			printf("\n");
			i++;
		}
		while (i--)
			rra(a);
		if (is_sorted)
			break;
		n--;
	}
	return ;
}
