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

int aux_push(t_dlist **a, t_dlist **b, int chunk, int total)
{
	if ((*a)->order <= chunk)
	{	
		push_b(a, b);
		if(((*b)->order < chunk - get_divider(total) && ft_dlstsize(*b) > 1))
		{	
			rotate_b(b);
			return (1);
		}
	}
	else
	{	
		rotate_a(a);
		return (0);
	}		
}

void sort_big(t_dlist **a, t_dlist **b, int total)
{
	int i;
	int n;
	int chunk;
	int elements_in_chunk;

	elements_in_chunk = 0;
	i = 1;
	n = 0;
	chunk = total / 5;
	elements_in_chunk = chunk;
	while (n < 5)
	{	
		while(i <= elements_in_chunk)
		{	
			if (aux_push(a, b, chunk, total))
				i++;
		}
		i = 1;
		chunk += elements_in_chunk;
		n++;
	}
	chunk = total / 5;
	chunk *= 5;
	while (chunk  < total)
	{
		push_b(a, b);
		chunk++;
	}
}

void first_sort(t_dlist **a, t_dlist **b, int total)
{	
	ft_printf("total is %d\n", total);
	if (total >= 100)
		sort_big(a, b, total);
}

void go_rot(t_dlist **a, t_dlist **b, int rot)
{
	int i;

	i = 0;
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
		reverse_b(b);
		i++;
	}
	push_a(a, b);
}

static t_dlist	*ft_dlstlast_debug(t_dlist *lst, int total)
{
	if (!lst)
	{	
		if (total == 32)
			ft_printf("null list\n");
		return (NULL);
	}
	while (lst != NULL)
	{	
		if (total == 32)
		{	
			ft_printf("list not null\n");
			ft_printf("content is %d\n", lst->content);
			char ch;
			scanf("%c", &ch);
		}	
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void second_sort(t_dlist **a, t_dlist **b, int total)
{
	t_dlist *head;
	t_dlist *tail;
	int rot;
	int rev;

	while (total > 0)
	{	
		if (total == 33)
		{
			print_lists(*a, *b);
			char ch;
			scanf("%c", &ch);
		}
		if (total == 32)
		{	
			char ch;
			scanf("%c", &ch);
			ft_printf("total is %d\n", total);
			head = *b;
			ft_printf("after head\n");
			
			scanf("%c", &ch);
			tail = ft_dlstlast_debug(*b, total);
			ft_printf("after tail\n");
			scanf("%c", &ch);
		}
		else
		{
			head = *b;		
			tail = ft_dlstlast_debug(*b, total);
		}
		rot = get_rot(head, total);
		rev = get_rev(tail, total);
		if (total == 33)
		{	
			ft_printf("rot is %d rev is %d\n", rot, rev);
			char ch;
			scanf("%c", &ch);
		}
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

	total = 0;
	total = ft_dlstsize(a);
	first_sort(&a, &b, total);
	print_lists(a, b);
	char ch;
	scanf("%c", &ch);
	second_sort(&a, &b, total);
	return ;
}
