#include "push_swap.h"

void	exec_rra(t_admin *master, int print_flag)
{
	if (master->stack_a)
	{
		master->stack_a = master->stack_a->prev;
		if (print_flag == PRINT_OK)
			ft_putstr_fd("rra\n", 1);
	}
}

void	exec_rrb(t_admin *master, int print_flag)
{
	if (master->stack_b)
	{
		master->stack_b = master->stack_b->prev;
		if (print_flag == PRINT_OK)
			ft_putstr_fd("rrb\n", 1);
	}
}

void	exec_rrr(t_admin *master, int print_flag)
{
	exec_rra(master, NOT_PRINT);
	exec_rrb(master, NOT_PRINT);
	if (print_flag == PRINT_OK)
		ft_putstr_fd("rrr\n", 1);
}
