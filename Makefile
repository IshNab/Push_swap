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
		push_swap_utils.c

OBJS = $(SRCS:.c=.o)

INCLUDES = -Iincludes

LIBFT_LIB = includes/libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(NAME)
	$(CC) $(CFLAGS) -o main main.c $(NAME)
	./main

push_swap: $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_LIB) -lm -o push_swap

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) main push_swap

re: fclean all

.PHONY: all clean fclean re
