NAME = libft.a
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c \
		ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
		ft_substr.c ft_tolower.c ft_toupper.c ft_strmapi.c ft_striteri.c \
		ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putadd.c ft_putunbr.c ft_puthexnbr.c
		
OBJS =  ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o \
		ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memchr.o \
		ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_split.o \
		ft_strchr.o ft_strdup.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o \
		ft_strlen.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o \
		ft_substr.o ft_tolower.o ft_toupper.o ft_strmapi.o ft_striteri.o \
		ft_putchar.o ft_putstr.o ft_putendl.o ft_putnbr.o \
		ft_putadd.o ft_putunbr.o ft_puthexnbr.o
		
SRC_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
			ft_lstmap_bonus.c
OBJ_BONUS = ft_lstnew_bonus.o ft_lstadd_front_bonus.o ft_lstsize_bonus.o ft_lstlast_bonus.o \
			ft_lstadd_back_bonus.o ft_lstdelone_bonus.o ft_lstclear_bonus.o ft_lstiter_bonus.o \
			ft_lstmap_bonus.o
CFLAGS = -Wall -Werror -Wextra -I .

all: $(NAME)

$(NAME) : $(OBJS) ./libft.h
	ar rcs $(NAME) $(OBJS) 

bonus: .bonus

.bonus: $(NAME) $(OBJ_BONUS)
	ar rcs $(NAME) $(OBJ_BONUS)
	touch .bonus

%.o : %.c
	gcc -c  $(CFLAGS) $< -o $@

clean:
	rm -f *.o .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all bonus clean fclean re
