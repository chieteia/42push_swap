#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	exec_ra(t_admin *master, int print_flag)
{
	if (master->stack_a)
	{
		master->stack_a = master->stack_a->next;
		if (print_flag == PRINT_OK)
			write(1, "ra\n", 4);
	}
}

void	exec_rb(t_admin *master, int print_flag)
{
	if (master->stack_b)
	{
		master->stack_b = master->stack_b->next;
		if (print_flag == PRINT_OK)
			write(1, "rb\n", 4);
	}
}

void	exec_rr(t_admin *master, int print_flag)
{
	exec_ra(master, NOT_PRINT);
	exec_rb(master, NOT_PRINT);
	if (print_flag == PRINT_OK)
		write(1, "rr\n", 4);
}
