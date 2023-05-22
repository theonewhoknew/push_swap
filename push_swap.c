#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void print_lists(t_dlist *a, t_dlist *b)
{	
	t_dlist *curr_a;
	t_dlist *curr_b;

	curr_a = a;
	curr_b = b;
	printf("stack a is:    ");
	printf("stack b is:\n");
	while (curr_a != NULL)
	{
		printf("%d\t\t\t", *(int*) curr_a->content);
		curr_a = curr_a->next;
		if (curr_b != NULL)
		{
			printf("%d\n", *(int*) curr_b->content);
			curr_b = curr_b->next;
		}
		else
			printf("\n");
	}
}

int main(int argc, char *argv[])
{	
	t_dlist *a;
	t_dlist *b;
	int *arr;

	b = NULL;
	if (check_argv(argc, argv) == 1)
		return (1);
	arr = create_array(argc, argv);
	if (!arr)
		return (1);
	a = init_stack_a(argc, arr);
	print_lists(a, b);
	//free (arr);
	//free (stack_a);
	return (0);
}