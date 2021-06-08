#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	exec_sa(t_admin *master, int print_flag)
{
	int	tmp;

	if (master->stack_a && (master->stack_a != master->stack_a->next))
	{
		tmp = master->stack_a->num;
		master->stack_a->num = master->stack_a->next->num;
		master->stack_a->next->num = tmp;
		if (print_flag == PRINT_OK)
			write(1, "sa\n", 4);
	}
}

void	exec_sb(t_admin *master, int print_flag)
{
	int	tmp;

	if (master->stack_b && (master->stack_b != master->stack_b->next))
	{
		tmp = master->stack_b->num;
		master->stack_b->num = master->stack_b->next->num;
		master->stack_b->next->num = tmp;
		if (print_flag == PRINT_OK)
			write(1, "sb\n", 4);
	}
}

void	exec_ss(t_admin *master, int print_flag)
{
	exec_sa(master, NOT_PRINT);
	exec_sb(master, NOT_PRINT);
	if (print_flag == PRINT_OK)
		write(1, "ss\n", 4);
}
