CC = gcc
CFLAGS = -Wall -Wextra -Werror
C_PRECOMPILE_FLAGS = -c
C_DEBUG_FLAG = -g

LIBFT_DIR = ./libft
LIBFT_NAME = libdmoroz.a
LIBFT = $(addprefix $(LIBFT_DIR)/, $(LIBFT_NAME))

NAME = push_swap
SRCS = operation_swap.c \
       sort_ez.c \
       sort_ez_pz.c \
       sort_bubble_min.c \
       sort_bubble_max.c \
       get_stack_extremum.c \
       validate_args.c \
       push_swap.c \
       operation_push.c \
       operation_reverse_rotate.c \
       rotate_stack_to_n.c \
       get_stack_edge.c \
       is_empty_stack.c \
       operation_rotate.c \
       parse_args.c \
       is_sorted.c \
       repeat.c \
       check_malloc.c
OBJS = $(SRCS:.c=.o)
INCS = push_swap.h \
       $(LIBFT_DIR)/libft/libft.h \
       $(LIBFT_DIR)/ftgnl/get_next_line_bonus.h \
       $(LIBFT_DIR)/ftprintf/ft_printf.h \
       $(LIBFT_DIR)/ftprintf/print_single_format/print_single_format.h
INCS_DIR = $(dir $(INCS))
INC_FLAGS = $(addprefix -I, $(INCS_DIR))
LIB_FLAGS = -L$(LIBFT_DIR)/ -ldmoroz

all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) $(C_PRECOMPILE_FLAGS) $(INC_FLAGS) $(LIB_FLAGS) $< -o $@ 

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(OBJS) $(LIB_FLAGS) -o $(NAME)

debug: $(LIBFT)
	$(CC) $(CFLAGS) $(C_DEBUG_FLAG) $(INC_FLAGS) $(SRCS) $(LIB_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all # change if bonus will be made

$(LIBFT):
	$(MAKE) all bonus clean -C $(LIBFT_DIR)

.PHONY: all clean fclean re bonus