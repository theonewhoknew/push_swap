#include "libft/libft.h"
#include "push_swap.h"

void sort_a(t_dlist **a, int elements)
{	
	if (!elements)
		return ;
	if (elements == 2)
	{
		if ((*a)->content > (*a)->next->content)
			swap_a(*a);
		return ;
	}
	if ((*a)->content > (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
		do_3_2_1(a);
	else if ((*a)->content < (*a)->next->content && (*a)->content > (*a)->next->next->content)
		do_2_3_1(a);
	else if ((*a)->content > (*a)->next->next->content && (*a)->next->content < (*a)->next->next->content)
		do_3_1_2(a);
	else if ((*a)->content < (*a)->next->content && (*a)->next->content > (*a)->next->next->content)
		do_1_3_2(a);
	else if ((*a)->content > (*a)->next->content && (*a)->content < (*a)->next->next->content)
		do_2_1_3(a);		
}