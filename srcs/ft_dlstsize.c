/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:06:10 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 09:06:13 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	ft_dlstsize(t_dlist *lst)
{
	int	c;

	c = 0;
	while (lst != NULL)
	{
		c++;
		lst = lst->next;
	}
	return (c);
}
