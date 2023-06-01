#include "libft/libft.h"
#include "push_swap.h"

int operate_a(t_dlist **a, t_dlist **b, int n, t_stack *stack)
{	
	int partition_set;
	int rot;
	int median;

	median = get_median(*a, n);
	rot = 0;
	partition_set = 0;
	while (n)
	{	
		if ((*a)->content <= median)
		{
			push_b(a, b);
			if (!partition_set)
			{	
				stack->b_n++;
				stack->b_p[(stack->b_n) - 1] = (*b)->content;
				partition_set = 1;
				
			}
		}
		else
		{
			rotate_a(a);
			rot++;
		}
		n--;		
	}
	return (rot);
}

int operate_b(t_dlist **a, t_dlist **b, int n, t_stack *stack)
{	
	int c;
	int i;
	int median;

	median = get_median(*b, n);
	i = 0;
	c = 0;
	while (i < n)
	{	
		if ((*b)->content >= median)
		{	
			push_a(a, b);
			c++;
		}
		else
			rotate_b(b);
		i++;	
	}
	return (c);
}