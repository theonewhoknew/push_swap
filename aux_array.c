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

int check_range(int *arr, int range, int n)
{
	int i;
	int c;

	c = 0;
	i = 0;
	while (i < n)
	{
		if (arr[i] <= range)
			c++;
		i++;
	}
	return (c);
}

int find_highest(int *arr, int n)
{
	int i;
	int highest;

	highest =0;
	i = 0;
	while (i < n)
	{
		if (arr[i] > highest)
			highest = arr[i];
		i++;
	}
	return (highest);
}