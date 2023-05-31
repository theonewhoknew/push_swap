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

int get_median(int *arr, int n)
{	
	if (n % 2 != 0)
	{
		n++;
		return (arr[n / 2 - 1]);
	}
	else
		return ((arr[n / 2 - 1] + arr[n / 2]) / 2);
}

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

int main(int argc, char *argv[])
{	
	t_dlist *a;
	t_dlist *b;
	int *arr;
	int median;
	int n;

	b = NULL;
	if (check_argv(argc, argv) == 1)
		return (1);
	arr = create_array(argc, argv);
	if (!arr)
		return (1);
	a = init_stack_a(argc, argv);
	n = count_argv(argc, argv);
	sort_stack(a, b, arr, n);
	return (0);
}