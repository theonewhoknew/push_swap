#include "libft/libft.h"
#include <stdlib.h>

void sort_array(int *arr, int n)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < (n - 1))
	{
		while (j < (n - 1))
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}

int calculate_median(int *arr, int n)
{	
	if (n % 2 != 0)
	{
		n++;
		return (arr[n / 2 - 1]);
	}
	else
		return ((arr[n / 2 - 1] + arr[n / 2]) / 2);
}

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

int get_median(t_dlist *list, int n)
{	
	int *arr;
	int median;

	arr = NULL;
	arr = get_array(list, n);
	sort_array(arr, n);
	median = calculate_median(arr, n);
	free (arr);
	return (median);
}