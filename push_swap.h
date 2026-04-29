/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 09:54:04 by mosimon           #+#    #+#             */
/*   Updated: 2026/04/28 09:59:15 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*To morgane, the comments that i've put in this files
 * are indications that I found usefull to explain 
 * the functions and/or struct that i've implented
 * feel free to delet them once you don't need them 
 * anymore*/

/*_____Our includes_____*/
//#include "libft/libft.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/*_____Our struct_____*/
typedef struct s_node
{
	int				value;
	struct s_node	*next;
} t_node;

/*The collection is the string of integer where the first element is the top of the stack
 * the capacity is the maximum space of our stack which is ecual to our malloc
 * the size is the acutal number of element in the stack*/
typedef struct s_stack
{
	int	*collection;
	int	capacity;
	int	size;
}		t_stack;

/*_____Our functions_____*/
/*---The stacks functions---*/
/*The basic function for stack operation*/
/*Creation and destruction of the stack*/
t_stack	*creat_stack(int capacity);
void	destroy_stack(t_stack *stack);
/*Information of our stack*/
bool	is_ful(t_stack *stack);
bool	is_empty(t_stack *stack);
/*Direct operation on our stack*/
bool	pop(t_stack *stack, int *item);
bool	push(t_stack *stack, int item);
bool	peek(t_stack *stack, int *item);

#endif
