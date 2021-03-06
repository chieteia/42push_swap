#include "push_swap.h"

void	sort_asc_len2(t_admin *master, char stack_name)
{
	t_stack	*stack;

	stack = plug_top_ptr(master, stack_name);
	if (stack->num > stack->next->num)
		exec_swap(master, stack_name, PRINT_OK);
}

void	sort_asc_len3(t_admin *master, char stack_name)
{
	t_stack	*stack;
	t_stack	*biggest;

	biggest = find_biggest(master, stack_name);
	while (!is_asc_sorted(master, stack_name))
	{
		stack = plug_top_ptr(master, stack_name);
		if (biggest->num == stack->num)
			exec_rotate(master, stack_name, PRINT_OK);
		else if (biggest->num == stack->next->num)
			exec_reverse_rotate(master, stack_name, PRINT_OK);
		else if (biggest->num == stack->next->next->num)
			exec_swap(master, stack_name, PRINT_OK);
	}
}

void	sort_asc_len4(t_admin *master, char src_name, char dst_name)
{
	int	smallest_move_cnt;

	if (stacklen(master, src_name) == 3)
	{
		sort_asc_len3(master, src_name);
		return ;
	}
	smallest_move_cnt = find_smallest_move(master, src_name);
	if (master->smallest_rot_flag)
		exec_loop(master, ROTATE, src_name, smallest_move_cnt);
	else if (master->smallest_rrot_flag)
		exec_loop(master, RROTATE, src_name, smallest_move_cnt);
	exec_push(master, dst_name, PRINT_OK);
	sort_asc_len4(master, src_name, dst_name);
	exec_push(master, src_name, PRINT_OK);
}

void	sort_asc_len5(t_admin *master, char src_name, char dst_name)
{
	push_pivot_base(master, 'a', 'b');
	sort_desc_len3(master, dst_name);
	sort_asc_len3(master, src_name);
	exec_loop(master, PUSH, 'a', 2);
}

void	sort_asc_len6(t_admin *master, char src_name, char dst_name)
{
	push_pivot_base(master, 'a', 'b');
	sort_desc_len3(master, dst_name);
	sort_asc_len3(master, src_name);
	exec_loop(master, PUSH, 'a', 3);
}
