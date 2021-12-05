#include "push_swap.h"

static void	fill_array(int *array, t_stack *stack, int stack_len)
{
	int	index;

	index = -1;
	while (++index < stack_len)
	{
		array[index] = stack->num;
		stack = stack->next;
	}
}

void	get_quartile(t_admin *master, char stack_name)
{
	int		*array;
	int		stack_len;
	t_stack	*stack;

	stack = plug_top_ptr(master, stack_name);
	stack_len = stacklen(master, stack_name);
	if (!ft_malloc((void **)&array, sizeof(int), stack_len))
		error_exit();
	fill_array(array, stack, stack_len);
	quick_sort(array, 0, stack_len - 1);
	master->first_quartile = array[stack_len / 4];
	master->median = array[stack_len / 2];
	master->third_quartile = array[(stack_len * 3) / 4];
	free(array);
}

void	get_pivot(t_admin *master, char stack_name, int stack_len)
{
	int		l;
	int		*array;
	t_stack	*stack;

	l = -1;
	stack = plug_top_ptr(master, stack_name);
	if (stack_len <= 6)
		master->div_num = 2;
	else
		master->div_num = approx_sqrt(stack_len / 3) / 2;
	if (!ft_malloc((void **)&array, sizeof(int), stack_len))
		error_exit();
	fill_array(array, stack, stack_len);
	quick_sort(array, 0, stack_len - 1);
	if (!ft_malloc((void **)&master->partitions,
			sizeof(int), master->div_num - 1))
		error_exit();
	while (++l < master->div_num - 1)
		master->partitions[l] = array[stack_len * (l + 1) / master->div_num];
	free(array);
}
