NAME = push_swap

LIBFT_DIR = libft

LIBFT =  $(LIBFT_DIR)/libft.a
	
SRCS = aux_array.c aux_prints.c check_argv.c create_array.c ft_dlstsize.c get_partition.c init_stack.c is_sorted.c median.c operate.c push_swap.c push.c reverse.c rotate.c \
		sort_a.c sort_comb.c sort_stack.c sorted_up_to.c swap.c 

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I . 

all: make_libft $(NAME) 

$(NAME) : $(OBJS) push_swap.h 
	gcc $(CFLAGS) $(LIBFT) -o $(NAME) $(OBJS)

%.o : %.c push_swap.h libft/libft.h
	gcc -c  $(CFLAGS) $< -o $@

make_libft:
	@make -C $(LIBFT_DIR)

clean:
	@rm -f *.o
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) 
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean all bonus clean fclean re