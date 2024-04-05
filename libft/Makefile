CC = gcc
CFLAGS = -Wall -Wextra -Werror -c

LIBFT_DIR = ./libft
LIBPRINTF_DIR = ./ftprintf

NAME = libdmoroz.a
GNL_DIR = ./ftgnl
SRCS_GNL = get_next_line_bonus.c get_next_line_utils_bonus.c
SRCS = $(addprefix $(GNL_DIR)/, $(SRCS_GNL))
OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(INCS)
	$(CC) $(CFLAGS) $(INC_FLAGS) $(LIB_FLAGS) $< -o $@ 

$(NAME): libprintf $(OBJS)
	cp $(LIBPRINTF_DIR)/libftprintf.a $(NAME)
	ar r $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: all

libprintf:
	$(MAKE) all bonus clean -C $(LIBPRINTF_DIR)

.PHONY: all clean fclean re libft
