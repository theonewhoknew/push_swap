#include "libft/libft.h"
#include <stdio.h>

void print_array(int *arr, int n)
{
	int i;

	i = 0;
	printf("array is:\n");
	while (i < n)
	{	
		printf("%d\n", arr[i]);
		i++;
	}
}

void print_lists(t_dlist *a, t_dlist *b)
{	
	t_dlist *curr_a;
	t_dlist *curr_b;

	curr_a = a;
	curr_b = b;
	printf("stack a is:    ");
	printf("stack b is:\n");
	while (curr_a != NULL || curr_b != NULL)
	{	
		if (curr_a != NULL)
		{
			printf("%d\t\t\t", curr_a->content);
			curr_a = curr_a->next;
		}
		else
			printf("\t\t\t");
		if (curr_b != NULL)
		{
			printf("%d\n", curr_b->content);
			curr_b = curr_b->next;
		}
		else
			printf("\n");
	}
}