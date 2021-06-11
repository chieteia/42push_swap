#include "push_swap.h"

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
	free(master);
}
