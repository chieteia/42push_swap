#include "push_swap.h"

int	find_rot_cnt_from_top(t_admin *master, char stack_name, int order)
{
	t_stack	*stack;

	stack = plug_top_ptr(master, stack_name);
	if (order == FIRST)
		while (stack->num >= master->first_quartile)
			stack = stack->next;
	if (order == SECOND)
		while ((stack->num < master->first_quartile) || (stack->num >= master->median))
			stack = stack->next;
	if (order == THIRD)
		while ((stack->num < master->median) || (stack->num >= master->third_quartile))
			stack = stack->next;
	if (order == FOURTH)
		while (stack->num < master->third_quartile)
			stack = stack->next;
	if (order == HALF_FIRST)
		while (stack->num >= master->median)
			stack = stack->next;
	if (order == HALF_SECOND)
		while (stack->num < master->median)
			stack = stack->next;
	return (find_rot_cnt_to_top(master, stack, stack_name));
}

int	find_rrot_cnt_from_end(t_admin *master, char stack_name, int order)
{
	t_stack	*stack;

	stack = plug_end_ptr(master, stack_name);
	if (order == FIRST)
		while (stack->num >= master->first_quartile)
			stack = stack->prev;
	if (order == SECOND)
		while ((stack->num < master->first_quartile) || (stack->num >= master->median))
			stack = stack->prev;
	if (order == THIRD)
		while ((stack->num < master->median) || (stack->num >= master->third_quartile))
			stack = stack->prev;
	if (order == FOURTH)
		while (stack->num < master->third_quartile)
			stack = stack->prev;
	if (order == HALF_FIRST)
		while (stack->num >= master->median)
			stack = stack->prev;
	if (order == HALF_SECOND)
		while (stack->num < master->median)
			stack = stack->prev;
	return (find_rrot_cnt_to_top(master, stack, stack_name));
}
