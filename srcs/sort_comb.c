/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_comb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:31:19 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 09:32:05 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	do_3_2_1(t_dlist **a)
{
	swap_a(*a);
	rotate_a(a);
	swap_a(*a);
	reverse_a(a);
	swap_a(*a);
}

void	do_2_3_1(t_dlist **a)
{
	rotate_a(a);
	swap_a(*a);
	reverse_a(a);
	swap_a(*a);
}

void	do_3_1_2(t_dlist **a)
{
	swap_a(*a);
	rotate_a(a);
	swap_a(*a);
	reverse_a(a);
}

void	do_1_3_2(t_dlist **a)
{
	rotate_a(a);
	swap_a(*a);
	reverse_a(a);
}

void	do_2_1_3(t_dlist **a)
{
	swap_a(*a);
}
