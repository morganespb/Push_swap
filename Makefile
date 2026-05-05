NAME= push_swap
CC= gcc
CFLAGS= -Wall -Wextra -Werror

SRCS= 	main.c operations/op_push.c operations/op_swap.c \
	operations/op_rotate.c operations/op_reverse_rotate.c parsing.c \
	lst_helper.c disorder_metric.c algorithms/radix.c algorithms/chunk.c \
	algorithms/insertion_sort.c bench.c \
	algorithms/insertion_utils.c adaptativ.c \
	lst_helper2.c

OBJS= $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES= -I. -I$(LIBFT_DIR)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

