#include "push_swap.h"

int g_sig = 0;

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

int	get_pivot(t_admin *master, char stack_name, int stack_len)
{
	int		pivot;
	int		*array;
	t_stack	*stack;

	stack = plug_top_ptr(master, stack_name);
	if (!ft_malloc((void **)&array, sizeof(int), stack_len))
		error_exit();
	fill_array(array, stack, stack_len);
	quick_sort(array, 0, stack_len - 1);
	pivot = array[stack_len / 2];
	free(array);
	return (pivot);
}
