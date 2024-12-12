NAME				= push_swap

LIBFT				= ./libft/libft.a
INC					= -I inc/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

CC					= cc
CFLAGS				= -Wall -Werror -Wextra -I -g3
RM					= rm -f

ALGO_DIR		=	$(SRC_DIR)algo/push.c \
						$(SRC_DIR)algo/rev_rotate.c \
						$(SRC_DIR)algo/rotate.c \
						$(SRC_DIR)algo/sort_stacks.c \
						$(SRC_DIR)algo/sort_stacks_2.c \
						$(SRC_DIR)algo/sort_three.c \
						$(SRC_DIR)algo/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/errors.c \
						$(SRC_DIR)push_swap/init_a_to_b.c \
						$(SRC_DIR)push_swap/init_b_to_a.c \
						$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/split.c \
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/stack_utils.c

SRCS 				= $(ALGO_DIR) $(PUSH_SWAP_DIR)

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) -c $< -o $@

clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re
