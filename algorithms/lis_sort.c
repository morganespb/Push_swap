/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/02 15:29:48 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/04 14:07:29 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//1.assign indexes
//2.find lis
//3.keep lis in A,push non lis to B
//4.for each b node, find target in A (=next bigger number in A)
//5.calculate cost
//6.pa into a
//7.repeat until b is empty
//8.rotate A until smallest on top

void	reset(t_node *a)//reset before computing
{
	while (a)
	{
		a->keep = 0;//not marked as LIS
		a->lis = 1;//every node is LIS of len 1
		a->prev_lis = NULL;//no previous LIS
		a = a->next;
	}
}

void	find_lis(t_node *a)
{
	t_node *i;
	t_node *j;
	t_node *best;

	i = a;
	best = a;

	while (a)
	{
		j = a;
		while (j != i)
		{
			if (j->index < i->index && j->lis + 1 > i->lis)
			{
				i->lis = j->lis + 1;//increase lis len
				i->prev_lis = j;//remember where lis starts
			}
			j = j->next;
		}
		if (i->lis > best->lis)
			best = i;
		i = i->next;
	}

	while (best)
	{
		best->keep = 1;
		best = best->prev_lis;
	}
}

void	push_non_lis(t_node **a, t_node **b)
{
	int size;
	int i;

	size = stack_size(*a);
	i = 0;

	while (i < size)
	{
		if ((*a)->keep)
			ra(a);
		else
			pb(a, b);
		i++;
	}
}

void	lis_dumb_sort(t_node **a, t_node **b)
{
	find_lis(*a);
	push_non_lis(a, b);

	while (*b)
		pa(a, b);

	//rotate smaller values
}




