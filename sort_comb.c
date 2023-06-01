#include "libft/libft.h"
#include "push_swap.h"

void do_3_2_1(t_dlist **a)
{
	swap_a(*a);
	rotate_a(a);
	swap_a(*a);
	reverse_a(a);
	swap_a(*a);
}

void do_2_3_1(t_dlist **a)
{
	rotate_a(a);
	swap_a(*a);
	reverse_a(a);
	swap_a(*a);
}

void do_3_1_2(t_dlist **a)
{
	swap_a(*a);
	rotate_a(a);
	swap_a(*a);
	reverse_a(a);
}

void do_1_3_2(t_dlist **a)
{
	rotate_a(a);
	swap_a(*a);
	reverse_a(a);
}

void do_2_1_3(t_dlist **a)
{
	swap_a(*a);
}