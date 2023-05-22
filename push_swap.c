#include "libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

int main(int argc, char *argv[])
{	
	t_dlist *stack_a;
	//t_dlist *curr;

	if (check_argv(argc, argv) == 1)
		return (1);
	stack_a = init_stack_a(argc, argv);
	/* curr = stack_a;
	while (curr != NULL)
	{
		printf("%d\n", *(int*) curr->content);
		curr = curr->next;
	} */
	
	return (0);
}