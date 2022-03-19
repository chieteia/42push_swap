#include "push_swap.h"

int	find_rot_cnt_from_top(t_admin *master, char stack_name, int pivot)
{
	t_stack	*stack;

	stack = plug_top_ptr(master, stack_name);
	if (stack_name == 'a')
		while (stack->num >= pivot)
			stack = stack->next;
	if (stack_name == 'b')
		while (stack->num < pivot)
			stack = stack->next;
	return (find_rot_cnt_to_top(master, stack, stack_name));
}

int	find_rrot_cnt_from_end(t_admin *master, char stack_name, int pivot)
{
	t_stack	*stack;

	stack = plug_end_ptr(master, stack_name);
	if (stack_name == 'a')
		while (stack->num >= pivot)
			stack = stack->prev;
	if (stack_name == 'b')
		while (stack->num < pivot)
			stack = stack->prev;
	return (find_rrot_cnt_to_top(master, stack, stack_name));
}