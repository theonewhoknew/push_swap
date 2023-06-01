#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void sort_a(t_dlist **a, int elements)
{	
	if (!elements)
		return ;
	if (elements == 2)
	{
		if ((*a)->content > (*a)->next->content)
			swap_a(*a);
		return ;
	}
	if ((*a)->content > (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
		do_3_2_1(a);
	else if ((*a)->content < (*a)->next->content && (*a)->content > (*a)->next->next->content)
		do_2_3_1(a);
	else if ((*a)->content > (*a)->next->next->content && (*a)->next->content < (*a)->next->next->content)
		do_3_1_2(a);
	else if ((*a)->content < (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
		do_1_3_2(a);
	else if ((*a)->content > (*a)->next->content && (*a)->content < (*a)->next->next->content)
		do_2_1_3(a);		
}

int get_number_partition_b(t_stack *stack, t_dlist *list)
{
	int c;

	c = 1;
	if (stack->b_n == 0 || stack->b_n == 1)
	 	return (ft_dlstsize(list));
	while (list->content != stack->b_p[(stack->b_n) - 1])
	{
		list = list->next;
		c++;
	}
	stack->b_n--;
	return (c);
}

void first_sort(t_dlist **a, t_dlist **b, int n, t_stack *stack)
{	
	int median;
	int i;
	int partition_set;
	
	partition_set = 0;
	if (ft_dlstsize(*a) <= 3)
		return ;	
	median = get_median(*a, n);
	i = 0;
	while (i < n)
	{	
		if ((*a)->content <= median)
		{
			push_b(a, b);
			if (!partition_set)
			{	
				stack->b_n++;
				stack->b_p[(stack->b_n) - 1] = (*b)->content;
				partition_set = 1;
			}
		}
		else
			rotate_a(a);
		i++;	
	}
	first_sort(a, b, ft_dlstsize(*a), stack);
}

void quicksort_after_a(t_dlist **a, t_dlist **b, int n, t_stack *stack)
{	
	int median;
	int i;
	int *arr;
	int c;
	int rot;
	int partition_set;
	
	partition_set = 0;
	rot = 0;
	c = 0;		
	/* arr = NULL;
	if (arr != NULL)
	{
		free (arr);
		arr = NULL;
	}
	arr = get_array(*a, n);
	sort_array(arr, n); */
	median = get_median(*a, n);
	i = 0;
	while (i < n)
	{	
		if ((*a)->content <= median)
		{
			push_b(a, b);
			if (!partition_set)
			{	
				stack->b_n++;
				stack->b_p[(stack->b_n) - 1] = (*b)->content;
				partition_set = 1;
				//printf("partition nº %d made up to number %d\n", stack->b_n, stack->b_p[(stack->b_n) - 1]);
			}
		}
		else
		{
			rotate_a(a);
			rot++;
		}
		i++;		
	}
	while (rot)
	{
		reverse_a(a);
		rot--;
	}
	if (elements_after_sorted(*a, sorted_up_to(*a, *b)) <= 3)
		sort_a(a, elements_after_sorted(*a, sorted_up_to(*a, *b)));
	else
		quicksort_after_a(a, b, elements_after_sorted(*a, sorted_up_to(*a, *b)), stack);
}

void quicksort_b(t_dlist **a, t_dlist **b, int n, t_stack *stack)
{	
	int median;
	int i;
	int *arr;
	int c;
	int partition_set;
	static int j;

	partition_set = 0;
	median = get_median(*b, n);
	i = 0;
	c = 0;
	while (i < n)
	{	
		if ((*b)->content >= median)
		{	
			push_a(a, b);
			c++;
		}
		else
			rotate_b(b);
		i++;	
	}
	if (c <= 3)
	{	
		sort_a(a, elements_after_sorted(*a, sorted_up_to(*a, *b)));
		stack->a_n = 1;
		stack->a_p[0] = sorted_up_to(*a, *b);
		partition_set = 1;
	}
	else if (c > 3)
		quicksort_after_a(a, b, elements_after_sorted(*a, sorted_up_to(*a, *b)), stack); 
}

void sort_stack(t_dlist *a, t_dlist *b, int *arr, int n)
{	
	t_stack stack;

	stack.a_n = 0;
	stack.b_n = 0;
	first_sort(&a, &b, ft_dlstsize(a), &stack);
	sort_a(&a, ft_dlstsize(a));
	while (is_sorted_both(&a, &b) != 1)
		quicksort_b(&a, &b, get_number_partition_b(&stack, b), &stack);	
	return ;
}