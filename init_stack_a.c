#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

t_dlist *init_stack_a(int argc, int *arr)
{	
	int i;
	t_dlist *head;
	t_dlist *tail;
	int j;

	head = NULL;
	tail = NULL;
	i = 1;
	j = 0;
	while (i < argc)
	{	
		ft_dlstadd_back(&head, &tail, ft_dlstnew((void *)&arr[j]));
		i++;
		j++;
	}
	return (head);
}