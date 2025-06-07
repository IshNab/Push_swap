NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Iincludes

SRCS = main.c \
		input_check.c \
		stack_init.c \
		ft_split.c \
		push_swap.c \
		small_sort.c \
		swap_operations.c \
		rotate_operations.c \
		push_operations.c \
		push_swap_utils.c \
		push_swap_utils_2.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -Iincludes

#LIBFT_LIB = includes/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS)  -lm -o $@
#$(LIBFT_LIB)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run
