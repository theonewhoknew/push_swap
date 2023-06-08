/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:08:47 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 09:22:58 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	set_partition(t_dlist **lst, t_stack *stack)
{
	stack->b_n++;
	stack->b_p[(stack->b_n) - 1] = (*lst)->content;
}

int	operate_a(t_dlist **a, t_dlist **b, int n, t_stack *stack)
{	
	int	partition_set;
	int	rot;
	int	median;

	median = get_median(*a, n);
	rot = 0;
	partition_set = 0;
	while (n)
	{	
		if ((*a)->content <= median)
		{
			push_b(a, b);
			if (!partition_set)
			{	
				set_partition(b, stack);
				partition_set = 1;
			}
		}
		else
			rot += rotate_a(a);
		n--;
	}
	return (rot);
}

int	operate_b(t_dlist **a, t_dlist **b, int n)
{	
	int	c;
	int	i;
	int	median;

	median = get_half_median(*b, n);
	i = 0;
	c = 0;
	while (i < n)
	{	
		if ((*b)->content >= median)
		{	
			push_a(a, b);
			c++;
		}
		else
			rotate_b(b);
		i++;
	}
	return (c);
}
