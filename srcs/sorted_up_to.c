/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted_up_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:33:02 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 10:00:01 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int	elements_after_sorted(t_dlist *a, int sorted)
{
	t_dlist	*curr;
	int		i;

	i = 0;
	curr = a;
	while (curr->content != sorted)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int	aux_sort(t_dlist *sorted, t_dlist *lst)
{	
	int	*arr;
	int	n;
	int	i;

	i = 0;
	n = ft_dlstsize(lst);
	arr = get_array(lst, ft_dlstsize(lst));
	while (sorted != NULL)
	{
		while (n)
		{	
			if (arr[i] > sorted->content)
			{
				sorted = sorted->next;
				break ;
			}
			i++;
			n--;
		}
		break ;
	}
	free (arr);
	return (sorted->content);
}

int	sorted_up_to(t_dlist *a, t_dlist *b)
{
	t_dlist	*sorted;
	t_dlist	*curr;
	int		max;

	sorted = a;
	curr = a;
	max = curr->content;
	while (curr != NULL)
	{
		if (curr->content < max)
		{
			curr = curr->next;
			sorted = curr;
		}
		else
		{
			max = curr->content;
			curr = curr->next;
		}
	}
	return (aux_sort(sorted, b));
}
