#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int is_sorted(t_dlist *a, t_dlist *b)
{	
	t_dlist *curr;

	curr = a;
	while (curr != NULL)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	if (b != NULL)
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

int check_rotate(t_dlist **a, t_dlist **b)
{	
	t_dlist *last_a;
	t_dlist *last_b;
	
	last_a = ft_dlstlast(*a);
	last_b = ft_dlstlast(*b);
	if (*a != NULL)
	{
		if ((*b)->content < last_b->content && (*a)->content > last_a->content)
		{	
			rotate_r(a, b);
			return (1);
		}
		else if ((*a)->content > last_a->content)
		{	
			rotate_a(a);
			return (1);
		}
	}
	if ((*b)->content < last_b->content)
	{	
		rotate_b(b);
		return (1);
	}
	return (0);
}	

int empty_a(t_dlist **a, t_dlist **b, int sum, int *n)
{	
	int number_removed;

	if ((*a)->content <= sum / (*n))
	{	
		number_removed = (*a)->content;
		push_b(a, b);
		print_lists(*a, *b);
		if (*b != NULL && (*b)->next != NULL)
		{	
			if (check_rotate(a, b) != 0)
				print_lists(*a, *b);
			if((*b)->next->content > (*b)->content)
			{
				swap_b(*b);
				print_lists(*a, *b);
			}
		} 
		(*n)--;
		return (number_removed);
	}
	else
	{
		rotate_a(a);
		print_lists(*a, *b);
		return (0);
	}
}

void empty_b(t_dlist **a, t_dlist **b)
{	
	/* if ((*b)->next != NULL)
	{
		if ((*b)->content > (*b)->next->content)
		{
			push_a(a, b);
			print_lists(*a, *b);
		}
		else
		{	
			swap_b(*b);
			print_lists(*a, *b);
		}
	}
	else
	{ */
		push_a(a, b);
		print_lists(*a, *b);			
} 

void sort_stack(t_dlist *a, t_dlist *b, int *arr, int argc)
{	
	int sum;
	int n;

	n = argc - 1;
	sort_array(arr, argc);
	sum = sum_array(arr, n);
	print_lists(a, b);
	while (a != NULL)
		sum -= empty_a(&a, &b, sum, &n);
	while (b != NULL)
		empty_b(&a, &b);
}