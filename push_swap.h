#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int check_range(int argc, char *argv[]);
int check_digits(int argc, char *argv[]);
int	check_argv(int argc, char *argv[]);
int check_duplicates(int argc, char *argv[]);
int *create_array(int argc, char *argv[]);
t_dlist *init_stack_a(int argc, char *argv[]);
void swap_a(t_dlist *head);
void swap_b(t_dlist *head);
void swap_s(t_dlist *a, t_dlist *b);
void push_a(t_dlist **a, t_dlist **b);
void push_b(t_dlist **a, t_dlist **b);
void rotate_a(t_dlist **a);
void rotate_b(t_dlist **b);
void rotate_r(t_dlist **a, t_dlist **b);
void reverse_a(t_dlist **a);
void reverse_b(t_dlist **b);
void reverse_r(t_dlist **a, t_dlist **b);
void sort_array(int *arr, int argc);
void print_array(int *arr, int argc);
void print_lists(t_dlist *a, t_dlist *b);
void sort_array(int *arr, int argc);
void sort_stack(t_dlist *a, t_dlist *b, int *arr, int n);
int is_sorted(t_dlist **a, t_dlist **b);
int empty_a(t_dlist **a, t_dlist **b, int sum, int *n);
char **parse_argv(char *argv);
int count_argv(int argc, char *argv[]);


#endif