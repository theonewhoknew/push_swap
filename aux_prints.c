/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_prints.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theonewhoknew <theonewhoknew@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:53:48 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 19:05:16 by theonewhokn      ###   ########.fr       */
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
