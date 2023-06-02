/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:15:26 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 09:57:38 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char *argv[])
{	
	t_dlist	*a;
	t_dlist	*b;

	b = NULL;
	if (check_argv(argc, argv) == 1)
		return (1);
	a = init_stack_a(argc, argv);
	sort_stack(a, b);
	return (0);
}
