#include "libft/libft.h"
#include <stdlib.h>

void push_a(t_dlist **a, t_dlist **b)
{	
	t_dlist *head;
	t_dlist *next;

	head = *b;
	if (head != NULL)
	{
		ft_dlstadd_front(a, ft_dlstnew(head->content));
		if (head->next != NULL)
		{	
			next = head->next;
			next->prev = NULL;
			*b = next;
		}
		else
			*b = NULL;
		free (head);
	}
	ft_putstr_fd("pa\n", 1);
}

void push_b(t_dlist **a, t_dlist **b)
{
	t_dlist *head;
	t_dlist *next;

	head = *a;
	if (*a != NULL)
	{
		ft_dlstadd_front(b, ft_dlstnew(head->content));
		if (head->next != NULL)
		{	
			next = head->next;
			next->prev = NULL;
			*a = next;
		}
		else
			*a = NULL;
		free (head);
	}
	ft_putstr_fd("pb\n", 1);
}