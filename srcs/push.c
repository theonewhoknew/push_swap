/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:27:56 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 09:28:20 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	push_a(t_dlist **a, t_dlist **b)
{	
	t_dlist	*head;
	t_dlist	*next;

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

void	push_b(t_dlist **a, t_dlist **b)
{
	t_dlist	*head;
	t_dlist	*next;

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
