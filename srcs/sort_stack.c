/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:32:10 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/13 17:17:47 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void sort_big(t_dlist **a, t_dlist **b, int total)
{
	int i;
	int n;
	int chunk;
	int elements_in_chunk;

	elements_in_chunk = 0;
	i = 0;
	n = 0;
	chunk = total / 5;
	elements_in_chunk = chunk;
	while (n < 5)
	{	
		while(i < elements_in_chunk)
		{	
			if ((*a)->order < chunk)
			{	
				push_b(a, b);
				if(((*b)->order < chunk - get_divider(total) && ft_dlstsize(*b) > 1))
					rotate_b(b);
				i++;
			}
			else
				rotate_a(a);
		}
		i = 0;
		chunk += elements_in_chunk;
		n++;
	}
}

void first_sort(t_dlist **a, t_dlist **b, int total)
{	

	if (total > 99)
		sort_big(a, b, total);
}

void second_sort(t_dlist **a, t_dlist **b, int total)
{
	t_dlist *head;
	t_dlist *tail;
	int rot;
	int rev;

	total -= 1;
	while (total >= 0)
	{	
		head = *b;
		tail = ft_dlstlast(*b);
		rot = get_rot(head, total);
		rev = get_rev(tail, total);
		if (rot <= rev)
		{
			while ((*b)->order != total)
				rotate_b(b);
			push_a(a, b);
		}
		else
		{	
			while ((*b)->order != total)
				reverse_b(b);
			push_a(a, b);
		}
		total--;
	}
}

void	sort_stack(t_dlist *a, t_dlist *b)
{	
	int total;

	total = ft_dlstsize(a);
	first_sort(&a, &b, total);
	second_sort(&a, &b, total);
	return ;
}
