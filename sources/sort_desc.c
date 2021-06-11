#include "push_swap.h"

void	sort_desc_len2(t_admin *master, char stack_name)
{
	t_stack *stack;

	stack = plug_top_ptr(master, stack_name);
	if (stack->num < stack->next->num)
		exec_swap(master, stack_name, PRINT_OK);
}

void	sort_desc_len3(t_admin *master, char stack_name)
{
	t_stack *stack;
	t_stack	*smallest;

	smallest = find_smallest(master, stack_name);
	while (!is_desc_sorted(master, stack_name))
	{
		stack = plug_top_ptr(master, stack_name);
		if (smallest->num == stack->num)
			exec_rotate(master, stack_name, PRINT_OK);
		else if (smallest->num == stack->next->num)
			exec_reverse_rotate(master, stack_name, PRINT_OK);
		else if (smallest->num == stack->next->next->num)
			exec_swap(master, stack_name, PRINT_OK);
	}
}
