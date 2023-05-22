NAME = push_swap

LIBFT_DIR = libft

LIBFT =  $(LIBFT_DIR)/libft.a

L_SRCS = $(addprefix $(LIBFT_DIR)/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c ft_strmapi.c ft_striteri.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_putadd.c ft_putunbr.c ft_puthexnbr.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_dlstnew.c ft_dlstadd_back.c ft_dlstlast.c\
		ft_lstmap.c ft_contains_digit.c ft_dlstadd_front.c)
		
L_OBJS =  $(L_SRCS:.c=.o)

SRCS = push_swap.c check_argv.c init_stack_a.c create_array.c swap.c push.c rotate.c reverse.c

OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wextra -I . 

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT) push_swap.h
	gcc $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

$(LIBFT): $(L_OBJS)

%.o : %.c
	gcc -c  $(CFLAGS) $< -o $@

$(LIBFT_DIR)/%.o : $(LIBFT_DIR)/%.c
	@make -C $(LIBFT_DIR)

clean:
	@rm -f *.o
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean all bonus clean fclean re