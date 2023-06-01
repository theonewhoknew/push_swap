#include "push_swap.h"
#include "libft/libft.h"
#include <stdio.h>

int elements_after_sorted(t_dlist *a, int sorted)
{
	int total;
	t_dlist *curr;
	int i;

	i = 0;
	curr = a;
	while (curr->content != sorted)
	{
		i++;
		curr = curr->next;
	}
	return (i);
}

int sorted_up_to(t_dlist *a, t_dlist *b)
{
	t_dlist *sorted;
	t_dlist *curr;
	int *arr;
	int i;
	int max;
	int n;

	n = ft_dlstsize(b);;
	i = 0;
	sorted = a;
	curr = a;
	max = curr->content;
	while (curr != NULL)
	{
		if (curr->content < max)
		{
			curr = curr->next;
			sorted = curr;
		}
		else
		{
			max = curr->content;
			curr = curr->next;
		}
	}
	curr = sorted;
	arr = get_array(b, ft_dlstsize(b));
	while (sorted != NULL)
	{
		while (n)
		{	
			if (arr[i] > sorted->content)
			{
				sorted = sorted->next;
				break;
			}
			i++;
			n--;
		}
		break;
	}
	return (sorted->content);
}