/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:40:32 by mosimon           #+#    #+#             */
/*   Updated: 2026/04/29 21:15:51 by morganesimonp    ###   ########.fr       */
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
