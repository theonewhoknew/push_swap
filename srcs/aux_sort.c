#include "push_swap.h"

int get_divider(int total)
{
	return ((total / 5) / 2);
}

int get_rot(t_dlist *b, int total)
{	
	t_dlist *curr;
	int rot;

	curr = b;
	rot = 0;
	while (curr != NULL)
	{	
		if (curr->order == total)
			break ;
		rot++;
		curr = curr->next;
	}
	return (rot);
}

int get_rev(t_dlist *b, int total)
{	
	t_dlist *curr;
	int rev;

	curr = b;
	rev = 0;
	while (curr != NULL)
	{	
		if (curr->order == total)
			break ;
		rev++;
		curr = curr->prev;
	}
	return (rev);
}