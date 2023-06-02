/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtome-pe <dtome-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 09:04:02 by dtome-pe          #+#    #+#             */
/*   Updated: 2023/06/02 09:05:58 by dtome-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int	count_numbers(char *argv)
{
	int	n;
	int	i;
	int	number_to_start;

	n = 0;
	i = 0;
	number_to_start = 1;
	while (argv[i])
	{
		if ((argv[i] == '\"' || argv[i] == ' ') && number_to_start == 0)
		{	
			number_to_start = 1;
			i++;
		}
		else if (ft_isdigit(argv[i]) == 1 && number_to_start == 1)
		{
			n++;
			number_to_start = 0;
			i++;
		}
		else
			i++;
	}
	return (n);
}

int	count_argv(int argc, char *argv[])
{
	int	i;
	int	n;

	i = 1;
	n = 0;
	while (i < argc)
	{
		n += count_numbers(argv[i]);
		i++;
	}
	return (n);
}

char	**parse_argv(char *argv)
{
	char	**strs;

	strs = ft_split(argv, ' ');
	return (strs);
}

int	*create_array(int argc, char *argv[])
{
	int		i;
	int		*arr;
	int		j;
	int		k;
	char	**strs;

	k = 0;
	arr = malloc(sizeof (int) * count_argv(argc, argv));
	if (!arr)
		return (NULL);
	i = 1;
	j = 0;
	while (i < argc)
	{	
		strs = parse_argv(argv[i]);
		while (strs[j] != NULL)
			arr[k++] = ft_atoi(strs[j++]);
		j = 0;
		free (strs);
		i++;
	}
	return (arr);
}
