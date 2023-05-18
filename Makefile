NAME = pushswap

LIBFT_DIR = libft

LIBFT =  $(LIBFT_DIR)/libft.a

L_SRCS = $(addprefix $(LIBFT_DIR)/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c ft_strmapi.c ft_striteri.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putadd.c ft_putunbr.c ft_puthexnbr.c ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
		ft_lstmap_bonus.c)
		
L_OBJS =  $(L_SRCS:.c=.o)



SRCS = push_swap.c 

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT) ./push_swap.h
	gcc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

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