#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void rotate_a(t_dlist **a)
{	
	t_dlist	*head;
	t_dlist	*tail;
	t_dlist *next;

	if (*a != NULL || (*a)->next != NULL)
	{
		head = *a;
		tail = ft_dlstlast(*a);
		ft_dlstadd_back(&head, &tail, ft_dlstnew(head->content));
		next = head->next;
		next->prev = NULL;
		free (head);
		*a = next;

	}
	ft_putstr_fd("ra\n", 1);
}

void rotate_b(t_dlist **b)
{	
	t_dlist	*head;
	t_dlist	*tail;
	t_dlist *next;

	if (*b != NULL || (*b)->next != NULL)
	{
		head = *b;
		tail = ft_dlstlast(*b);
		ft_dlstadd_back(&head, &tail, ft_dlstnew(head->content));
		next = head->next;
		next->prev = NULL;
		free (head);
		*b = next;
	}
	ft_putstr_fd("rb\n", 1);
}

void rotate_r(t_dlist **a, t_dlist **b)
{	
	t_dlist	*head;
	t_dlist	*tail;
	t_dlist *next;

	if (*a != NULL || (*a)->next != NULL)
	{
		head = *a;
		tail = ft_dlstlast(*a);
		ft_dlstadd_back(&head, &tail, ft_dlstnew(head->content));
		next = head->next;
		next->prev = NULL;
		free (head);
		*a = next;
	}
	if (*b != NULL || (*b)->next != NULL)
	{
		head = *b;
		tail = ft_dlstlast(*b);
		ft_dlstadd_back(&head, &tail, ft_dlstnew(head->content));
		next = head->next;
		next->prev = NULL;
		free (head);
		*b = next;;
	}
	ft_putstr_fd("rr\n", 1);
}