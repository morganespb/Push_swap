/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:40:32 by mosimon           #+#    #+#             */
/*   Updated: 2026/05/01 13:50:26 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swapv2.h"

void	print_stack(char *name, t_node *s)
{
	printf("%s: ", name);
	while (s)
	{
		printf("%d ", s->value);
		s = s->next;
	}
	printf("\n");
}

void	print_debug(t_node *s)
{
	int count = 0;
	while (s && count < 50)
	{
		printf("%d(index=%d) -> ", s->value, s->index);
		s = s->next;
		count++;
	}
	printf("NULL\n");
	if (count == 50)
		printf("STOPPED");
}
