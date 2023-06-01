#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_stack
{
	int a_p[20];
	int b_p[20];
	int a_n;
	int b_n;
}				t_stack;

int check_value_range(int argc, char *argv[]);
int check_digits(int argc, char *argv[]);
int	check_argv(int argc, char *argv[]);
int check_duplicates(int argc, char *argv[]);
int *create_array(int argc, char *argv[]);
long sum_array(int *arr, int n);
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
void sort_array(int *arr, int n);
void print_array(int *arr, int argc);
void print_lists(t_dlist *a, t_dlist *b);
void sort_array(int *arr, int argc);
void sort_stack(t_dlist *a, t_dlist *b, int *arr, int n);
int is_sorted(t_dlist *stack);
int is_sorted_both(t_dlist **a, t_dlist **b);
char **parse_argv(char *argv);
int count_argv(int argc, char *argv[]);
void check_swap(t_dlist **a, t_dlist **b);
int check_range(int *arr, int range, int n);
int find_highest(int *arr, int n);
int get_median(t_dlist *list, int n);
int *get_array(t_dlist *stack, int n);
void first_sort(t_dlist **a, t_dlist **b, int n, t_stack *stack_b);
void quicksort_b(t_dlist **a, t_dlist **b, int n, t_stack *stack_a);
int sorted_up_to(t_dlist *a, t_dlist *b);
int elements_after_sorted(t_dlist *a, int sorted);
void do_3_2_1(t_dlist **a);
void do_2_3_1(t_dlist **a);
void do_3_1_2(t_dlist **a);
void do_1_3_2(t_dlist **a);
void do_2_1_3(t_dlist **a);
int	ft_dlstsize(t_dlist *lst);
int get_partition(t_stack *stack, t_dlist *list);
void sort_a(t_dlist **a, int elements);
int operate_a(t_dlist **a, t_dlist **b, int n, t_stack *stack);
int operate_b(t_dlist **a, t_dlist **b, int n, t_stack *stack);

#endif