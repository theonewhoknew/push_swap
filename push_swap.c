#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

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