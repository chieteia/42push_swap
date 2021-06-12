#include "push_swap.h"

int	get_range_half(t_admin *master, char src_name, int chunk)
{
	int	range;
	int	stack_len;

	range = 0;
	stack_len = plug_stack_len(master, src_name);
	if (chunk == FIRST)
		range = stack_len / 2;
	if (chunk == SECOND)
		range = stack_len - (stack_len / 2);
	return (range);
}

int	get_range_quarter(t_admin *master, char src_name, int chunk)
{
	int	range;
	int	stack_len;

	range = 0;
	stack_len = plug_stack_len(master, src_name);
	if (chunk == FIRST)
		range = stack_len / 4;
	if (chunk == SECOND)
		range = (stack_len / 2) - (stack_len / 4);
	if (chunk == THIRD)
		range = (stack_len * 3 / 4) - (stack_len / 2);
	if (chunk == FOURTH)
		range = stack_len - (stack_len * 3 / 4);
	return (range);
}
