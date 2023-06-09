/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 08:52:37 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 08:53:39 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_range(int *arr, int range, int n)
{
	int	i;
	int	c;

	c = 0;
	i = 0;
	while (i < n)
	{
		if (arr[i] <= range)
			c++;
		i++;
	}
	return (c);
}

int	find_highest(int *arr, int n)
{
	int	i;
	int	highest;

	highest = 0;
	i = 0;
	while (i < n)
	{
		if (arr[i] > highest)
			highest = arr[i];
		i++;
	}
	return (highest);
}

long	sum_array(int *arr, int n)
{
	int		i;
	long	total;

	i = 0;
	total = 0;
	while (i < (n))
	{
		total += arr[i];
		i++;
	}
	return (total);
}
