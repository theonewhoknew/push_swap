#include <stdlib.h>

void sort_array(int *arr, int argc)
{
	int i;
	int j;
	int temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < (argc - 2))
	{
		while (j < (argc - 2))
		{
			if (arr[j] > arr [j + 1])
			{
				temp = arr[j];
				arr[j] = arr [j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
		j = 0;
	}
}