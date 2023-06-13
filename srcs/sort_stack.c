/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:32:10 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/13 20:39:02 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

//static int	check;

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

void go_rot(t_dlist **a, t_dlist **b, int rot)
{
	int i;

	i = 0;
	ft_printf("entra en rot\n");
	while (i < rot)
	{
		/* char ch;
		if (check == 1)
			scanf("%c", &ch); */
		rotate_b(b);
		i++;
	}
	push_a(a, b);
}

void go_rev(t_dlist **a, t_dlist **b, int rev)
{
	int i;

	i = 0;
	while (i <= rev)
	{	
		/* char ch;
		if (check == 1)
			scanf("%c", &ch); */
		reverse_b(b);
		i++;
	}
	push_a(a, b);
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
		/* char ch; */
		ft_printf("total is %d\n", total);
		/* if (total == 13)
		{	
			print_lists(*a, *b);
			scanf("%c", &ch);
			check = 1;
		} */
		head = *b;
		tail = ft_dlstlast(*b);
		rot = get_rot(head, total);
		ft_printf("rot is %d\n", rot);
		rev = get_rev(tail, total);
		if (rot <= rev)
			go_rot(a, b, rot);
		else 
			go_rev(a, b, rev);
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
