#include "libft/libft.h"
#include <stdio.h>

void swap_a(t_dlist *a)
{
	int temp;

	if(a != NULL || a->next != NULL)
	{
		temp = 0;
		temp = *(int *)a->content;
		*(int *)a->content = *(int *)a->next->content;
		*(int *) a->next->content = temp;
	}
	ft_putstr_fd("sa\n", 1);
}

void swap_b(t_dlist *b)
{
	int temp;

	if(b != NULL || b->next != NULL)
	{
		temp = 0;
		temp = *(int *)b->content;
		*(int *)b->content = *(int *)b->next->content;
		*(int *)b->next->content = temp;
	}
	ft_putstr_fd("sb\n", 1);
}

void swap_s(t_dlist *a, t_dlist *b)
{
	int temp;

	if(a != NULL || a->next != NULL)
	{
		temp = 0;
		temp = *(int *)a->content;
		*(int *)a->content = *(int *)a->next->content;
		*(int *)a->next->content = temp;
	}
	if(b != NULL || b->next != NULL)
	{
		temp = 0;
		temp = *(int *)b->content;
		*(int *)b->content = *(int *)b->next->content;
		*(int *)b->next->content = temp;
	}
	ft_putstr_fd("ss\n", 1);
}