#include "push_swap.h"

void	exec_pa(t_admin *master, int print_flag)
{
	if (master->stack_b)
	{
		push_top(master, master->stack_b->num, 'a');
		pop_top(master, 'b');
		if (print_flag == PRINT_OK)
			write(1, "pa\n", 4);
	}
}

void	exec_pb(t_admin *master, int print_flag)
{
	if (master->stack_a)
	{
		push_top(master, master->stack_a->num, 'b');
		pop_top(master, 'a');
		if (print_flag == PRINT_OK)
			write(1, "pb\n", 4);
	}
}
