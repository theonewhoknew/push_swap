#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

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
	else if (*a != NULL)
	{
		/* if ((*a)->content > last_a->content)
			reverse_a(a); */
		if ((*a)->content > last_a->content)
			rotate_a(a);
	}
	else if (*b != NULL)
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
		{	
			push_a(a, b);
			//print_lists(*a, *b);
		}	
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

int empty_a(t_dlist **a, t_dlist **b, int sum, int *n)
{	
	int number_removed;

	
	if ((*a)->content <= (sum / *n))
	{	
		number_removed = (*a)->content;
		push_b(a, b);
		//print_lists(*a, *b);
		check_rotate(a, b);
		//print_lists(*a, *b);
		check_swap(a, b);
		//print_lists(*a, *b);
		(*n)--;
		return (number_removed);
	}
	else
	{
		rotate_a(a);
		//print_lists(*a, *b);
		return (0);
	}
}

void sort_stack(t_dlist *a, t_dlist *b, int *arr, int n)
{	
	int sum;

	sort_array(arr, n);
	sum = sum_array(arr, n);
	if (n == 3)
	{	
		check_swap(&a, &b);
		check_rotate(&a, &b);
		if (is_sorted(&a, &b) == 1)
			return ;
	}
	while (a != NULL)
	{	
		if (is_sorted(&a, &b) == 1)
			return ;
		sum -= empty_a(&a, &b, sum, &n);
	}
	while (b != NULL)
	{
		empty_b(&a, &b);
	}
	return ;
}