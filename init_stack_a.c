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

t_dlist *init_stack_a(int argc, char *argv[])
{	
	int i;
	t_dlist *head;
	t_dlist *tail;
	int *arr;
	int j;

	head = NULL;
	tail = NULL;
	i = 1;
	j = 0;
	arr = create_array(argc, argv);
	if (!arr)
		return (NULL);
	while (i < argc)
	{	
		ft_dlstadd_back(&head, &tail, ft_dlstnew((void *)&arr[j]));
		i++;
		j++;
	}
	return (head);
}