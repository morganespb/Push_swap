/*DO BE CARFULL this file have more than 5 functions*/
#include "push_swap.h"

t_stack *create_stack(int capacity)
{
  t_stack *stack;

  if (capacity <= 0)
    return (NULL);
  stack = malloc(sizeof(t_stack));
  if (!stack)
    return (NULL);
  stack->collection = malloc(sizeof(int) * capacity);
  if (stack->collection == NULL)
    return (free(stack), NULL);
  stack->capacity = capacity;
  stack->size = 0;
  return (stack);
}

void  destroy_stack(t_stack *stack)
{
  free(stack->collection);
  free(stack);
}

bool  is_full(t_stack *stack)
{
  if (stack->capacity == stack->size)
    return (true);
  else
    return (false);
}

bool is_empty(t_stack *stack)
{
  if (stack->size == 0)
    return (true);
  else
    return (false);
}

bool  push(t_stack *stack, int item)
{
  if (is_full(stack))
    return (false);
  stack->collection[stack->size] = item;
  stack->size++;
  return (true);
}

bool  peek(t_stack *stack, int *item)
{
  if (is_empty(stack))
    return (false);
  *item = stack->collection[stack->size - 1];
  return (true);
}

bool pop(t_stack *stack, int *item)
{
  if (is_empty(stack))
    return (false);
  stack->size--;
  *item = stack->collection[stack->size];
  return (true);
}

int main(void)
{
  /*Im creating my stack*/
  t_stack *stack = create_stack(5);
  if (!stack)
  {
    printf("Error creating stack.\n");
    return (1);
  }

  /*Im adding element to my stack*/
  if (is_empty(stack)) printf("Stack is empty.\n");
  push(stack, 2);
  printf("Stack size: %d.\n", stack->size);
  if (is_empty(stack) == false) printf("Stack is NOT empty.\n");
  push(stack, 3);
  push(stack, 4);
  push(stack, 5);
  push(stack, 6);
  printf("Stack size: %d.\n", stack->size);
  if (is_full(stack)) printf("Stack is full.\n");
  if (push(stack, 3) == false)
    printf("Push failed.\n");

  /*Im looking at the first element in my stack*/
  int peek_val = 0;
  peek(stack, &peek_val);
  printf("Peek Val: %d.\n", peek_val);

  /*Im poping element from my stack*/
  int pop_val = 0;
  int i = 0;
  while (i++ < 5)
  {
    pop(stack, &pop_val);
    printf("Popped Value; %d.\n", pop_val);
  }
  if (is_empty(stack)) printf("Stack is empty.\n");
  bool try_pop = pop(stack, &pop_val);
  if (try_pop == false) printf("Pop failed.\n");

  /*And freeing my stack at last*/
  destroy_stack(stack);
  return (0);
}
