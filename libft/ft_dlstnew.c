/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:12:28 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/13 11:09:23 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_dlist	*ft_dlstnew(int content, int order)
{
	t_dlist	*node;

	node = (t_dlist *)malloc(sizeof (*node));
	if (!node)
		return (NULL);
	node->content = content;
	node->order = order;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
/*
int main(void)
{   
    t_list *node;
    int x;

    x = 5;
    node = ft_lstnew(&x);
    printf("node content is %d", *(int *)(node->content));
    free (node);
    
}
*/
