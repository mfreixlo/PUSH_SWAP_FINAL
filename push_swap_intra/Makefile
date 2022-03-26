LIBFT = ./libft/libft.a

NAME = libftprintf.a

PUSH = push_swap

SRC_DIR = sources

SRC = $(SRC_DIR)/push_swap.c $(SRC_DIR)/push_swap_lst.c $(SRC_DIR)/push_swap_utils.c $(SRC_DIR)/push_swap_stack.c $(SRC_DIR)/push_swap_lst2.c $(SRC_DIR)/push_swap_utils2.c $(SRC_DIR)/push_swap_utils3.c $(SRC_DIR)/push_swap_moves.c $(SRC_DIR)/push_swap_order.c $(SRC_DIR)/push_swap_print.c

SRC_O = push_swap.o push_swap_lst.o push_swap_utils.o push_swap_stack.o push_swap_lst2.o push_swap_utils2.o push_swap_utils3.o push_swap_moves.o push_swap_order.o push_swap_print.o
 
OBJS = ${SRC:.c=.o}

INCLUDES = -I./includes

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

RM = rm -f


$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES)  $(SRC) 
	ar -rc $(NAME) $(OBJS)
	cc $(OBJS) $(NAME) -o $(PUSH)

all : $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(NAME)
	$(RM) $(SRC_O)
	$(RM) $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)
	$(RM) $(PUSH)
	$(RM) $(OBJS)

re : fclean all
