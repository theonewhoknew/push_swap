#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int is_sorted_a(t_dlist *stack)
{	
	t_dlist *curr;

	curr = stack;
	while (curr->next != NULL)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int is_sorted_b(t_dlist *stack)
{	
	t_dlist *curr;

	curr = stack;
	while (curr->next != NULL)
	{
		if (curr->content < curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int is_sorted_both(t_dlist **a, t_dlist **b)
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

void sort_a(t_dlist **a)
{	
	while (is_sorted_a(*a) != 1)
	{	
		if ((*a)->content > (*a)->next->content && (*a)->content > ft_dlstlast(*a)->content)
			rotate_a(a);
		else if ((*a)->content > (*a)->next->content)
			swap_a(*a);
		else if (ft_dlstlast(*a)->content < (*a)->content)
			reverse_a(a);
		
		else if ((*a)->next->content > (*a)->next->next->content)
		{
			swap_a(*a);
			rotate_a(a);
			return ;
		}
		else if ((*a)->content > (*a)->next->content)
			rotate_a(a);
	}	
}
void sort_b(t_dlist **b)
{	
	if (is_sorted_a(*b) != 1)
	{	
		if (ft_dlstlast(*b)->content > (*b)->content)
			reverse_a(b);
		if ((*b)->content > (*b)->next->content)
			rotate_a(b);
		else if ((*b)->next->content < (*b)->next->next->content)
		{
			swap_a(*b);
			rotate_a(b);
			return ;
		}
		if ((*b)->content < (*b)->next->content)
			swap_a(*b);
		if ((*b)->content < (*b)->next->content)
			rotate_a(b);
	}	
	else
		return ;
}


void quicksort_a(t_dlist **a, t_dlist **b, int n)
{	
	int median;
	int i;
	int *arr;
	int c;
	
	if (ft_dlstsize(*a) <= 3)
		return ;
	c = 0;		
	arr = NULL;
	if (arr != NULL)
	{
		free (arr);
		arr = NULL;
	}
	arr = get_array(*a, n);
	sort_array(arr, n);
	median = get_median(arr, n);
	i = 0;
	while (i < n)
	{	
		if (ft_dlstsize(*a) <= 3)
			return ;
		if ((*a)->content < median)
		{	
			push_b(a, b);
			//check_swap(a, b);
			//check_rotate(a, b);
			c++;
		}
		else
			rotate_a(a);
		i++;
		//print_lists(*a, *b);		
	}
	quicksort_a(a, b, ft_dlstsize(*a) / 2);
	//quicksort_b(a, b, c / 2);	 
}

void quicksort_b(t_dlist **a, t_dlist **b, int n)
{	
	int median;
	int i;
	int *arr;
	int c;

	arr = NULL;
	if (arr != NULL)
	{
		free (arr);
		arr = NULL;
	}
	arr = get_array(*b, n);
	sort_array(arr, n);
	median = get_median(arr, n);
	i = 0;
	c = 0;
	while (i < n)
	{	
		if (is_sorted_b(*b) == 1)
		{	
			while (ft_dlstsize(*b) > 0)
				push_a(a, b);
			return ;
		}
		if ((*b)->content > median)
		{
			push_a(a, b);
			//check_swap(a, b);
			c++;
		}
		else
			rotate_b(b);
		i++;	
	}
	quicksort_a(a, b, c / 2);
	quicksort_b(a, b, ft_dlstsize(*b) / 2);
}

void sort_stack(t_dlist *a, t_dlist *b, int *arr, int n)
{	
	quicksort_a(&a, &b, ft_dlstsize(a));
	sort_a(&a);
	quicksort_b(&a, &b, ft_dlstsize(b));
	return ;
}