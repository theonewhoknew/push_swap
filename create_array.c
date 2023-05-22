#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

int *create_array(int argc, char *argv[])
{
	int i;
	int *arr;
	int j;


	arr = malloc(sizeof (int) * (argc - 1));
	if (!arr)
		return (NULL);
	i = 1;
	j = 0;
	while(i < argc)
	{
		arr[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	return (arr);
}