/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:32:10 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 19:22:59 by theonewhokn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	aux_first_sort(t_dlist **lst, t_stack *stack)
{
	stack->b_n++;
	stack->b_p[(stack->b_n) - 1] = (*lst)->content;
}

void	first_sort(t_dlist **a, t_dlist **b, int median, t_stack *stack)
{	
	int	i;
	int	partition_set;

	partition_set = 0;
	if (ft_dlstsize(*a) <= 3)
		return ;
	i = 0;
	while (i < ft_dlstsize(*a))
	{	
		while (ft_dlstlast(*a)->content <= median)
			reverse_a(a);
		if ((*a)->content <= median)
		{
			push_b(a, b);
			if (!partition_set)
			{	
				aux_first_sort(b, stack);
				partition_set = 1;
			}
			median = get_half_median(*a, ft_dlstsize(*a));
		}
		else if ((*a)->next->content <= median && (*a)->content < ft_dlstlast(*a)->content)
			swap_a(*a);
		else
			rotate_a(a);
		i++;
	}
	first_sort(a, b, get_half_median(*a, ft_dlstsize(*a)), stack);
}

void	quicksort_a(t_dlist **a, t_dlist **b, int n, t_stack *stack)
{	
	int	rotated;

	rotated = operate_a(a, b, n, stack);
	while (rotated)
	{
		reverse_a(a);
		rotated--;
	}
	if (elements_after_sorted(*a, sorted_up_to(*a, *b)) <= 3)
		sort_a(a, elements_after_sorted(*a, sorted_up_to(*a, *b)));
	else
		quicksort_a(a, b, elements_after_sorted(*a, sorted_up_to(*a, *b)),
			stack);
}

void	quicksort_b(t_dlist **a, t_dlist **b, int n, t_stack *stack)
{	
	int	pushed;

	pushed = operate_b(a, b, n);
	if (pushed <= 3)
	{	
		sort_a(a, elements_after_sorted(*a, sorted_up_to(*a, *b)));
		stack->a_n = 1;
		stack->a_p[0] = sorted_up_to(*a, *b);
	}
	else if (pushed > 3)
		quicksort_a(a, b, elements_after_sorted(*a, sorted_up_to(*a, *b)),
			stack);
}

void	sort_stack(t_dlist *a, t_dlist *b)
{	
	t_stack	stack;
	int median;

	median = get_half_median(a, ft_dlstsize(a));
	stack.a_n = 0;
	stack.b_n = 0;
	first_sort(&a, &b, median, &stack);
	sort_a(&a, ft_dlstsize(a));
	while (is_sorted_both(&a, &b) != 1)
		quicksort_b(&a, &b, get_partition(&stack, b), &stack);
	return ;
}
