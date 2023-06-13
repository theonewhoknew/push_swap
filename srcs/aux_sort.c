#include "push_swap.h"

int get_divider(int total)
{
	return ((total / 5) / 2);
}

int get_rot(t_dlist *head, int total)
{	
	int rot;

	rot = 0;
	while (head != NULL)
	{	
		if (head->order == total)
			break ;
		rot++;
		head = head->next;
	}
	return (rot);
}

int get_rev(t_dlist *tail, int total)
{	
	int rev;

	rev = 0;
	while (tail != NULL)
	{	
		if (tail->order == total)
			break ;
		rev++;
		tail = tail->prev;
	}
	return (rev);
}