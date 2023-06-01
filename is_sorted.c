#include "libft/libft.h"

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