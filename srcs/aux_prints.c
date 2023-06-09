/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_prints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:53:48 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/13 11:04:31 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

void	print_array(int *arr, int n)
{
	int	i;

	i = 0;
	ft_printf("array is:\n");
	while (i < n)
	{	
		ft_printf("%d\n", arr[i]);
		i++;
	}
}

void	print_lists(t_dlist *a, t_dlist *b)
{	
	t_dlist	*curr_a;
	t_dlist	*curr_b;

	curr_a = a;
	curr_b = b;
	ft_printf("stack a is:    ");
	ft_printf("stack b is:\n");
	while (curr_a != NULL || curr_b != NULL)
	{	
		if (curr_a != NULL)
		{
			ft_printf("%d\t\t\t", curr_a->content);
			curr_a = curr_a->next;
		}
		else
			ft_printf("\t\t\t");
		if (curr_b != NULL)
		{
			ft_printf("%d\n", curr_b->content);
			curr_b = curr_b->next;
		}
		else
			ft_printf("\n");
	}
}

void print_order(t_dlist *a)
{
	t_dlist *curr;

	curr = a;
	while (curr != NULL)
	{
		ft_printf("%d ", curr->order);
		curr = curr->next;
	}
	ft_printf("\n");
}
