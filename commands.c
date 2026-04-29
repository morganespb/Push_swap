/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mosimon <mosimon@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 13:32:23 by mosimon           #+#    #+#             */
/*   Updated: 2026/04/28 13:33:22 by mosimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DO BE CAREFULL there is more than 5 functions in this file*/
/*_____All the operations_____*/
#include "push_swap.h"

bool	swap_a(t_stack *stack_a)
{
	int	first_item;
	int	second_item;

  if (stack_a->size < 2)
    return (false);
  pop(stack_a, &first_item);
  pop(stack_a, &second_item);
  push(stack_a, first_item);
  push(stack_a, second_item);
  return (true);
}

bool	swap_b(t_stack *stack_b)
{
	int	first_item;
	int	second_item;
  
  if (stack_b->size < 2)
    return (false);
  pop(stack_b, &first_item);
  pop(stack_b, &second_item);
  push(stack_b, first_item);
  push(stack_b, second_item);
  return (true);
}

bool  swap_ab(t_stack *stack_a, t_stack *stack_b)
{
  swap_a(stack_a);
  swap_b(stack_b);
  return (true);
}

bool  push_a(t_stack *stack_a, t_stack *stack_b)
{
  int b_element;

  if (is_empty(stack_b) == true)
    return (false);
  pop(stack_b, &b_element);
  push(stack_a, b_element);
  return (true);
}

bool  push_b(t_stack *stack_b, t_stack *stack_a)
{
  int a_element;

  if (is_empty(stack_a) == true)
    return (false);
  pop(stack_a, &a_element);
  push(stack_b, a_element);
  return (true);
}

/*It's probably not the best idea to use
* malloc here for optimisation
* maybe there is a lest complex way*/
bool rotate_a(t_stack *stack_a)
{
  int stack_len;
  int *tmp;
  int first_element;
  int i;

  i = 0;
  stack_len = stack_a->size;
  /*im handling the case where the stack is is is empty 
    * since we do not want to malloc(0)*/
  if (stack_len < 2)
    return (true);
  pop(stack_a, &first_element);
  tmp = malloc(sizeof(int) * (stack_len - 1));
  if (!tmp)
    return (false);
  while (i++ < (stack_len - 1))
    pop(stack_a, &tmp[i]);
  i = 0;
  push(stack_a, first_element);
  while (i++ < (stack_len - 1))
    push(stack_a, tmp[(stack_len - 2) - i]);
  free(tmp);
  return (true);
}

bool rotate_b(t_stack *stack_b)
{
  int stack_len;
  int *tmp;
  int first_element;
  int i;

  i = 0;
  stack_len = stack_b->size;
  if (stack_len < 2)
    return (true);
  pop(stack_a, &first_element);
  tmp = malloc(sizeof(int) * (stack_len - 1));
  if (!tmp)
    return (false);
  while (i++ < (stack_len - 1))
    pop(stack_b, &tmp[i]);
  i = 0;
  push(stack_a, first_element);
  while (i++ < (stack_len - 1))
    push(stack_b, tmp[(stack_len - 2) - i]);
  free(tmp);
  return (true);
}

bool rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
  rotate_a(stack_a);
  rotate_b(stack_b);
  return (true);
}

bool  reverse_rotate_a(t_stack *stack_a)
{
  int stack_len;
  int *tmp;
  int last_element;
  int i;

  i = 0;
  stack_len = stack_a->size;
  if (stack_len < 2)
    return (true);
  tmp = malloc(sizeof(int) * (stack_len - 1));
  if (!tmp)
    return (false);
  while (i++ < (stack_len - 1))
    pop(stack_a, &tmp[i]);
  pop(stack_a, &last_element);
  i = 0;
  while (i++ < (stack_len - 1))
    push(stack_a, tmp[(stack_len - 2) - i]);
  push(stack_a, last_element);
  free(tmp);
  return (true);
}

bool  reverse_rotate_b(t_stack *stack_b)
{
  int stack_len;
  int *tmp;
  int last_element;
  int i;

  i = 0;
  stack_len = stack_b->size;
  if (stack_len < 2)
    return (true);
  tmp = malloc(sizeof(int) * (stack_len - 1));
  if (!tmp)
    return (false);
  while (i++ < (stack_len - 1))
    pop(stack_b, &tmp[i]);
  pop(stack_b, &last_element);
  i = 0;
  while (i++ < (stack_len - 1))
    push(stack_b, tmp[(stack_len - 2) - i]);
  push(stack_b, last_element);
  free(tmp);
  return (true);
}

bool  reverse_rotate_ab(t_stack *stack_a, t_stack *stack_b)
{
  reverse_rotate_a(stack_a);
  reverse_rotate_b(stack_b);
  return (false);
}

int main(void)
{
  /*---Creating stacks---*/
  t_stack *stack_a = create_stack(5);
  t_stack *stack_b = create_stack(5);
  /*---Populatig stack_a---*/
  push(stack_a, 5);
  push(stack_a, 4);
  push(stack_a, 3);
  push(stack_a, 2);
  push(stack_a, 1);
  /*---Showing our stack---*/
  int peek_val = 0;
  int i = 0;
  int stack_len = stack_a->size;
  printf("----------Our Stack----------\n");
  printf("Init a and b:\n");
  while (i < stack_len)
  {
    peek(stack_a, &peek_val);
    printf("%d", peek_val);
    pop
    /*The main would be quit some time to do, maybe a next time*/
  }
}
