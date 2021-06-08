#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	exec_push(t_admin *master, char stack_name, int print_flag)
{
	if (stack_name == 'a')
		exec_pa(master, print_flag);
	else
		exec_pb(master, print_flag);
}

void	exec_rotate(t_admin *master, char stack_name, int print_flag)
{
	if (stack_name == 'a')
		exec_ra(master, print_flag);
	else
		exec_rb(master, print_flag);
}

void	exec_reverse_rotate(t_admin *master, char stack_name, int print_flag)
{
	if (stack_name == 'a')
		exec_rra(master, print_flag);
	else
		exec_rrb(master, print_flag);
}

void	exec_swap(t_admin *master, char stack_name, int print_flag)
{
	if (stack_name == 'a')
		exec_sa(master, print_flag);
	else
		exec_sb(master, print_flag);
}

void	exec_loop(t_admin *master, int command, char stack_name, int count)
{
	if (command == PUSH)
		while (count--)
			exec_push(master, stack_name, PRINT_OK);
	if (command == SWAP)
		while (count--)
			exec_swap(master, stack_name, PRINT_OK);
	if (command == ROTATE)
		while (count--)
			exec_rotate(master, stack_name, PRINT_OK);
	if (command == RROTATE)
		while (count--)
			exec_reverse_rotate(master, stack_name, PRINT_OK);
}
