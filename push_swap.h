#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int check_range(int argc, char *argv[]);
int check_digits(int argc, char *argv[]);
int	check_argv(int argc, char *argv[]);
int check_duplicates(int argc, char *argv[]);
t_dlist *init_stack_a(int argc, char *argv[]);

#endif