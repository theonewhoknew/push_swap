#include "libft/libft.h"
#include <stdlib.h>

void reverse_a(t_dlist **a)
{	
	t_dlist	*tail;
	t_dlist *next;

	if (*a != NULL && (*a)->next != NULL)
	{
		tail = ft_dlstlast(*a);
		ft_dlstadd_front(a, ft_dlstnew(tail->content));
		next = tail->prev;
		next->next = NULL;
		free (tail);
	}
	ft_putstr_fd("rra\n", 1);
}

void reverse_b(t_dlist **b)
{	
	t_dlist	*tail;
	t_dlist *next;

	if (*b != NULL && (*b)->next != NULL)
	{
		tail = ft_dlstlast(*b);
		ft_dlstadd_front(b, ft_dlstnew(tail->content));
		next = tail->prev;
		next->next = NULL;
		free (tail);
	}
	ft_putstr_fd("rrb\n", 1);
}

void reverse_r(t_dlist **a, t_dlist **b)
{	
	t_dlist	*tail;
	t_dlist *next;

	if (*a != NULL && (*a)->next != NULL)
	{
		tail = ft_dlstlast(*a);
		ft_dlstadd_front(a, ft_dlstnew(tail->content));
		next = tail->prev;
		if (next != NULL)
			next->next = NULL;
		free (tail);
		tail = NULL;
	}
	if (*b != NULL && (*b)->next != NULL)
	{
		tail = ft_dlstlast(*b);
		ft_dlstadd_front(b, ft_dlstnew(tail->content));
		next = tail->prev;
		if (next != NULL)
			next->next = NULL;
		free (tail);
		tail = NULL;
	}
	ft_putstr_fd("rrr\n", 1);
}