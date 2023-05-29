#include "libft/libft.h"
#include <stdlib.h>

int *get_array(t_dlist *stack, int n)
{	
	int *new_arr;
	int i;

	i = 0;
	new_arr = (int *)malloc(sizeof (int) * n);
	if (!new_arr)
		return (NULL);
	while(n)
	{
		new_arr[i] = stack->content;
		i++;
		stack = stack->next;
		n--;
	}
	return (new_arr);
}