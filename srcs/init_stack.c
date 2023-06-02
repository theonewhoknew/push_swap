/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:06:51 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 09:07:19 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

t_dlist	*init_stack_a(int argc, char *argv[])
{	
	int		i;
	t_dlist	*head;
	t_dlist	*tail;
	int		j;
	char	**strs;

	head = NULL;
	tail = NULL;
	i = 1;
	j = 0;
	while (i < argc)
	{	
		strs = parse_argv(argv[i]);
		while (strs[j] != NULL)
		{
			ft_dlstadd_back(&head, &tail, ft_dlstnew(ft_atoi(strs[j])));
			j++;
		}
		j = 0;
		free (strs);
		i++;
	}
	return (head);
}
