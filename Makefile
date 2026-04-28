NAME= push_swap
CC= gcc
CFLAGS= -Wall -Wextra -Werror

SRCS= push_swap.c

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
	$(CC) $(CFLAGS) $(INCLUDES -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

