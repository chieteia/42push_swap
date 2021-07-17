#include "push_swap.h"

void	free_str_array(char ***array)
{
	int		index;
	char	**tmp;

	index = 0;
	tmp = *array;
	while (tmp[index])
		safe_free((void **)&tmp[index++]);
	free(*array);
	*array = NULL;
}

static void	stack_free(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*del;

	if (!stack)
		return ;
	tmp = stack->next;
	while (tmp != stack)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	free(stack);
}

void	admin_free(t_admin *master)
{
	if (!master)
		return ;
	stack_free(master->stack_a);
	stack_free(master->stack_b);
	if (master->args.is_malloc)
		free_str_array(&(master->args.vec));
	free(master);
}
