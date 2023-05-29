#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int is_sorted(t_dlist **a, t_dlist **b)
{	
	t_dlist *curr;

	curr = *a;
	while (curr->next != NULL)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	if (*b != NULL)
		return (0);
	else
		return (1);
}

long sum_array(int *arr, int n)
{
	int i;
	long total;

	i = 0;
	total = 0;
	while (i < (n))
	{
		total += arr[i];
		i++;
	}
	return (total);
}

void check_swap(t_dlist **a, t_dlist **b)
{
	if (*a != NULL && (*a)->next != NULL && *b != NULL && (*b)->next != NULL)
	{
		if ((*b)->content < (*b)->next->content && (*a)->content > (*a)->next->content)
			swap_s(*a, *b);
	}
	if (*a != NULL && (*a)->next != NULL)
	{		
		if ((*a)->content > (*a)->next->content)	
			swap_a(*a);
	}
	if (*b != NULL && (*b)->next != NULL)
	{
		if ((*b)->content < (*b)->next->content)	
			swap_b(*b);
	}
}

void check_rotate(t_dlist **a, t_dlist **b)
{	
	t_dlist *last_a;
	t_dlist *last_b;
	
	last_a = ft_dlstlast(*a);
	last_b = ft_dlstlast(*b);
	if (*a != NULL && *b != NULL)
	{
		if ((*b)->content < last_b->content && (*a)->content > last_a->content)
			rotate_r(a, b);
		/* else if ((*b)->content > last_b->content && (*a)->content < last_a->content)
			reverse_r(a, b) */;
	}
	if (*a != NULL)
	{
		/* if ((*a)->content > last_a->content)
			reverse_a(a); */
		if ((*a)->content > last_a->content)
			rotate_a(a);
	}
	if (*b != NULL)
	{
		if ((*b)->content < last_b->content)
			rotate_b(b);
		/* else if ((*b)->content > last_b->content)
			reverse_b(b); */
	}
}	

void empty_b(t_dlist **a, t_dlist **b)
{	
	if ((*b)->next != NULL)
	{
		if ((*b)->content > (*b)->next->content)
			push_a(a, b);
		else
		{	
			swap_b(*b);
			//print_lists(*a, *b);
			check_swap(a, b);
			//print_lists(*a, *b);
			push_a(a, b);
			//print_lists(*a, *b);
		}
		if ((*a)->next != NULL)
		{
			if ((*a)->content > (*a)->next->content)
			{	
				check_swap(a, b);
			//	print_lists(*a, *b);
			}	
		}
	}
	else
	{	
		push_a(a, b);
		//print_lists(*a, *b);
		if ((*a)->next != NULL)
		{
			if ((*a)->content > (*a)->next->content)
			{	
				swap_a(*a);
		//		print_lists(*a, *b);
			}	
		}
	}			
} 

/* void	empty_a(t_dlist **a, t_dlist **b, int range)
{	
	
	if ((*a)->content <= range)
	{	
		push_b(a, b);
		//print_lists(*a, *b);
		check_rotate(a, b);
		
		check_swap(a, b);
		
	}
	else
	{	
		if ((*a)->content > ft_dlstlast(*a)->content)
			rotate_a(a);
		else if ((*a)->content > (*a)->next->content)
			swap_a(*a);
		else
			rotate_a(a);
		//print_lists(*a, *b)
	}
} */

/* void operation_stack_a(t_dlist **a, t_dlist **b, int *arr, int n)
{	
	int i;
	int range;

	range = 0;
	i = 0;
	while (*a != NULL)
	{	
		range = (sum_array(arr, n) / n) / 2;
		while (i < check_range(arr, range, n))
			empty_a(a, b, range, &i);
		range = (sum_array(arr, n) / n);
		while (i < check_range(arr, range, n))
			empty_a(a, b, range, &i);
		range = (sum_array(arr, n) / n) + (sum_array(arr, n) / n) / 2;
		while (i < check_range(arr, range, n))
			empty_a(a, b, range, &i);
		range = find_highest(arr, n);
		while (i < check_range(arr, range, n))
			empty_a(a, b, range, &i);
	}
} */

static int	ft_dlstsize(t_dlist *lst)
{
	int	c;

	c = 0;
	while (lst != NULL)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}

void	empty_a(t_dlist **a, t_dlist **b, int range)
{	
	
	if ((*a)->content <= range)
	{	
		push_b(a, b);
		//print_lists(*a, *b);
		/* check_rotate(a, b);
		
		check_swap(a, b); */
		
	}
	else
	{	
	/* 	if ((*a)->content > ft_dlstlast(*a)->content)
			rotate_a(a);
		else if ((*a)->content > (*a)->next->content)
			swap_a(*a);
		else */
			rotate_a(a);
		//print_lists(*a, *b)
	}
}

 void operation_stack_a(t_dlist **a, t_dlist **b, int n)
{	
	int median;
	int i;
	int range;
	int *arr;
	
	arr = NULL;
	n = ft_dlstsize(*a);
	printf("n is %d\n", n);
	if (arr != NULL)
	{
		free (arr);
		arr = NULL;
	}
	arr = get_array(*a, n);
	sort_array(arr, n);
	print_array(arr, n);
	median = get_median(arr, n);
	printf("median is %d\n", median);
	empty_a(a, b, median);
	print_lists(*a, *b);
}

void sort_stack(t_dlist *a, t_dlist *b, int *arr, int n)
{	
	
	/* if (n == 3)
	{	
		check_swap(&a, &b);
		check_rotate(&a, &b);
		if (is_sorted(&a, &b) == 1)
			return ;
	}*/
	while (ft_dlstsize(a) > 3)
		operation_stack_a(&a, &b, n);
	
	/* 
	while (b != NULL)
	{
		empty_b(&a, &b);
	} */
	return ;
}