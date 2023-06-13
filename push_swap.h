/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:15:52 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/13 17:23:58 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		check_value_range(int argc, char *argv[]);
int		check_digits(int argc, char *argv[]);
int		check_argv(int argc, char *argv[]);
int		check_duplicates(int argc, char *argv[]);
int		*create_array(int argc, char *argv[]);
long	sum_array(int *arr, int n);
t_dlist	*init_stack_a(int argc, char *argv[]);
void	swap_a(t_dlist *head);
void	swap_b(t_dlist *head);
void	swap_s(t_dlist *a, t_dlist *b);
void	push_a(t_dlist **a, t_dlist **b);
void	push_b(t_dlist **a, t_dlist **b);
int		rotate_a(t_dlist **a);
void	rotate_b(t_dlist **b);
void	rotate_r(t_dlist **a, t_dlist **b);
void	reverse_a(t_dlist **a);
void	reverse_b(t_dlist **b);
void	reverse_r(t_dlist **a, t_dlist **b);
void	print_array(int *arr, int argc);
void	print_lists(t_dlist *a, t_dlist *b);
void	sort_stack(t_dlist *a, t_dlist *b);
int		is_sorted_both(t_dlist **a, t_dlist **b);
char	**parse_argv(char *argv);
int		count_argv(int argc, char *argv[]);
void	check_swap(t_dlist **a, t_dlist **b);
int		check_range(int *arr, int range, int n);
int		find_highest(int *arr, int n);
void	first_sort(t_dlist **a, t_dlist **b, int total);
int		elements_after_sorted(t_dlist *a, int sorted);
void	do_3_2_1(t_dlist **a);
void	do_2_3_1(t_dlist **a);
void	do_3_1_2(t_dlist **a);
void	do_1_3_2(t_dlist **a);
void	do_2_1_3(t_dlist **a);
int		ft_dlstsize(t_dlist *lst);
void	sort_a(t_dlist **a, int elements);
void 	put_order(t_dlist *stack, int n);
void 	print_order(t_dlist *a);
int 	get_rev(t_dlist *tail, int total);
int 	get_rot(t_dlist *head, int total);
int 	get_divider(int total);

#endif