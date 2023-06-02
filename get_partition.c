/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_partition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:06:24 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 09:06:43 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	get_partition(t_stack *stack, t_dlist *list)
{
	int	c;

	c = 1;
	if (stack->b_n == 0 || stack->b_n == 1)
		return (ft_dlstsize(list));
	while (list->content != stack->b_p[(stack->b_n) - 1])
	{
		list = list->next;
		c++;
	}
	stack->b_n--;
	return (c);
}
