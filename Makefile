CC = gcc
CFLAGS = -Wall -Wextra -Werror
C_PRECOMPILE_FLAGS = -c
C_DEBUG_FLAG = -g

LIBFT_DIR = ./libft
LIBFT_NAME = libdmoroz.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

NAME = push_swap
SRCS = push_swap.c \
       parse_args.c \
       validate_args.c \
       operation_push.c \
       operation_swap.c \
       operation_rotate.c \
       operation_reverse_rotate.c \
       sort_bubble_min.c \
       sort_bubble_max.c \
       sort_ez.c \
       sort_ez_pz.c \
       sort_cost_based.c \
       estimate_n_update_cost.c \
       do_cost_based_move.c \
       is_sorted.c \
       is_empty_stack.c \
       get_stack_size.c \
       get_stack_edge.c \
       get_stack_extremum.c \
       try_strategy.c \
       move_stack_to_closest_swap.c \
       rotate_stack_to_n.c \
       repeat.c \
       check_malloc.c \
       free_solution.c
OBJS = $(SRCS:.c=.o)
INCS = push_swap.h \
       $(LIBFT_DIR)/libft/libft.h \
       $(LIBFT_DIR)/ftgnl/get_next_line_bonus.h
INCS_DIR = $(dir $(INCS))
INC_FLAGS = $(addprefix -I, $(INCS_DIR))
LIB_FLAGS = -L$(LIBFT_DIR)/ -ldmoroz

BONUS_NAME = checker
BONUS_SRCS = checker_bonus.c \
             parse_args.c \
             validate_args.c \
             operation_push.c \
             operation_swap.c \
             operation_rotate.c \
             operation_reverse_rotate.c \
             get_stack_edge.c \
             is_sorted.c \
             check_malloc.c \
             free_solution.c
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) $(C_PRECOMPILE_FLAGS) $(INC_FLAGS) $(LIB_FLAGS) $< -o $@ 

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIB_FLAGS) -o $(NAME)

debug: $(LIBFT)
	$(CC) $(CFLAGS) $(C_DEBUG_FLAG) $(INC_FLAGS) $(SRCS) $(LIB_FLAGS) -o $(NAME)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(INC_FLAGS) $(LIB_FLAGS) -o $(BONUS_NAME)

$(LIBFT):
	$(MAKE) all bonus clean -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus