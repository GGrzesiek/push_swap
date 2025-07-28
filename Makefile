NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS =  push_swap_utils.c push_swap_list.c push_swap_algorithms.c \
		push_swap_templates.c push_swap_operations.c push_swap_operations2.c\
		push_swap_checkers.c push_swap_parser.c push_swap_calloc.c push_swap.c
		
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
