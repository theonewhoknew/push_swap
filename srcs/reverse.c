/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:28:32 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/13 15:05:49 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	reverse_a(t_dlist **a)
{	
	t_dlist	*tail;
	t_dlist	*next;

	if (*a != NULL && (*a)->next != NULL)
	{
		tail = ft_dlstlast(*a);
		ft_dlstadd_front(a, ft_dlstnew(tail->content, tail->order));
		next = tail->prev;
		next->next = NULL;
		free (tail);
	}
	ft_putstr_fd("rra\n", 1);
}

void	reverse_b(t_dlist **b)
{	
	t_dlist	*tail;
	t_dlist	*next;

	if (*b != NULL && (*b)->next != NULL)
	{
		tail = ft_dlstlast(*b);
		ft_dlstadd_front(b, ft_dlstnew(tail->content, tail->order));
		next = tail->prev;
		next->next = NULL;
		free (tail);
	}
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_r(t_dlist **a, t_dlist **b)
{	
	t_dlist	*tail;
	t_dlist	*next;

	if (*a != NULL && (*a)->next != NULL)
	{
		tail = ft_dlstlast(*a);
		ft_dlstadd_front(a, ft_dlstnew(tail->content, tail->order));
		next = tail->prev;
		if (next != NULL)
			next->next = NULL;
		free (tail);
		tail = NULL;
	}
	if (*b != NULL && (*b)->next != NULL)
	{
		tail = ft_dlstlast(*b);
		ft_dlstadd_front(b, ft_dlstnew(tail->content, tail->order));
		next = tail->prev;
		if (next != NULL)
			next->next = NULL;
		free (tail);
		tail = NULL;
	}
	ft_putstr_fd("rrr\n", 1);
}
