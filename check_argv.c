#include "libft/libft.h"
#include <limits.h>
#include <stdio.h>

int check_digits(int argc, char *argv[])
{	
	int i;
	
	i = 1;
	while (i < argc)
	{
		if (ft_contains_digit(argv[i]) == 0)
		{
			ft_putstr_fd("Error found a no digit\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int check_range(int argc, char *argv[])
{
	int i;
	
	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) > INT_MAX ||  ft_atoi(argv[i]) < INT_MIN)
		{
			ft_putstr_fd("Error range\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}

int check_duplicates(int argc, char *argv[])
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < argc)
	{
		while (j < (argc - 1))
		{
			if (ft_strncmp(argv[i], argv[j + 1], ft_strlen(argv[i])) == 0)
			{
				ft_putstr_fd("Error duplicate\n", 2);
				return (1);
			}
			j++;
		}
		i++;
		j = i;
	}
	return (0);
}

int	check_argv(int argc, char *argv[])
{	
	if (argc == 1)
		return (1);
	if (check_digits(argc, argv) == 1)
		return (1);
	if (check_range(argc, argv) == 1)
		return (1);
	if (check_duplicates(argc, argv) == 1)
		return (1);
	return (0);
}