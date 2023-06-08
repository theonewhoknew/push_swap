/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:07:26 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 09:07:54 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_sorted_a(t_dlist *stack, int p)
{	
	t_dlist	*curr;

	curr = stack;
	while (curr->content != p)
	{
		if (curr->content > curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_sorted_b(t_dlist *stack)
{	
	t_dlist	*curr;

	curr = stack;
	while (curr->next != NULL)
	{
		if (curr->content < curr->next->content)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int	is_sorted_both(t_dlist **a, t_dlist **b)
{	
	t_dlist	*curr;

	curr = *a;
	if (ft_dlstsize(*a) == 0)
		return (0);
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
