#include "push_swap.h"

t_stack	*plug_top_ptr(t_admin *master, char stack_name)
{
	if (stack_name == 'a')
		return (master->stack_a);
	else
		return (master->stack_b);
}

t_stack *plug_end_ptr(t_admin *master, char stack_name)
{
	if (stack_name == 'a')
		return (master->stack_a->prev);
	else
		return (master->stack_b->prev);
}

int	plug_stack_len(t_admin *master, char stack_name)
{
	if (stack_name == 'a')
		return (master->stack_a_len);
	else
		return (master->stack_b_len);
}
