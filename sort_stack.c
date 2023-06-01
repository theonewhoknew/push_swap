#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

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


int is_sorted_a(t_dlist *stack, int p)
{	
	t_dlist *curr;

	curr = stack;
	//printf("p is %d\n", p);
	while (curr->content != p)
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
	if (ft_dlstsize(*b) == 0)
		return (1);
	else
		return (0);
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
	{
		swap_a(*a);
		rotate_a(a);
		swap_a(*a);
		reverse_a(a);
		swap_a(*a);
	}
	else if ((*a)->content < (*a)->next->content && (*a)->content > (*a)->next->next->content)
	{
		rotate_a(a);
		swap_a(*a);
		reverse_a(a);
		swap_a(*a);
	}
	else if ((*a)->content > (*a)->next->next->content && (*a)->next->content < (*a)->next->next->content)
	{
		swap_a(*a);
		rotate_a(a);
		swap_a(*a);
		reverse_a(a);
	}
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
void sort_b(t_dlist **b, int p)
{	
	if (is_sorted_a(*b, p) != 1)
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

int get_number_partition_a(t_stack *stack, t_dlist *list)
{
	int c;

	c = 0;
	while (list->content != stack->a_p[0])
	{
		list = list->next;
		c++;
	}
	return (c);
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

void quicksort_a(t_dlist **a, t_dlist **b, int n, t_stack *stack)
{	
	int median;
	int i;
	int *arr;
	int c;
	static int j;
	int partition_set;
	
	partition_set = 0;
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
			break ;
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
			rotate_a(a);
		i++;
		//print_lists(*a, *b);		
	}
	j++;
	quicksort_a(a, b, ft_dlstsize(*a), stack);
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
		/* printf("number of partitions in a is %d\n", stack->a_n);
		printf("is sorted until %d\n",stack->a_p[(stack->a_n) - 1]); */
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
	quicksort_a(&a, &b, ft_dlstsize(a), &stack);
	sort_a(&a, ft_dlstsize(a));
	while (is_sorted_both(&a, &b) != 1)
		quicksort_b(&a, &b, get_number_partition_b(&stack, b), &stack);
	
	/* printf("sorted up to %d\n", sorted_up_to(a, b));
	printf("sorted up to %d\n", sorted_up_to(a, b));
	printf("elements after sorted %d\n", elements_after_sorted(a, sorted_up_to(a, b))); */
	
	/*quicksort_b(&a, &b, get_number_partition_b(&stack, b), &stack); 
	print_lists(a, b);  */
	
	return ;
}