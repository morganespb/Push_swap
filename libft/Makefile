NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

LIBFT_SRCS = ft_atoi.c ft_strrchr.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_substr.c ft_tolower.c ft_toupper.c ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_strtrim.c
FT_PRINTF_SRCS= ft_printf/ft_printf.c ft_printf/ft_print_char.c ft_printf/ft_print_hex.c ft_printf/ft_print_nbr.c ft_printf/ft_print_ptr.c ft_printf/ft_print_str.c ft_printf/ft_print_unsigned.c ft_printf/handle_format.c 

SRCS= $(LIBFT_SRCS) $(FT_PRINTF_SRCS)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all

