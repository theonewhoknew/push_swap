NAME = push_swap

LIBFT_DIR = libft

LIBFT =  $(LIBFT_DIR)/libft.a

OBJECTS_DIR = objs
	
SRCS = $(addprefix srcs/, aux_array.c aux_prints.c check_argv.c create_array.c ft_dlstsize.c get_partition.c init_stack.c is_sorted.c median.c operate.c push_swap.c push.c reverse.c rotate.c \
		sort_a.c sort_comb.c sort_stack.c sorted_up_to.c swap.c )

OBJS = $(patsubst srcs/%.c,$(OBJECTS_DIR)/%.o, $(SRCS))

CFLAGS = -Wall -Werror -Wextra -I . 

all: make_libft $(NAME) 

$(NAME) : $(OBJS) push_swap.h 
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

objs/%.o : srcs/%.c | $(OBJECTS_DIR)
	gcc -c $(CFLAGS) $< -o $@

$(OBJECTS_DIR) :
	mkdir -p $(OBJECTS_DIR)

make_libft:
	@make -C $(LIBFT_DIR)

clean:
	@rm -rf objs
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME) 
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean all bonus clean fclean re