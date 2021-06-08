#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	push_top(t_admin *master, int num, char stack_name)
{
	t_stack		**stack;
	t_stack		*new;

	if (stack_name == 'a')
		stack = &master->stack_a;
	else
		stack = &master->stack_b;
	if (!*stack)
		init_stack(master, num, stack_name);
	else
	{
		if (!ft_malloc((void **)&new, sizeof(t_stack), 1))
			error_exit(master);
		new->next = *stack;
		new->prev = (*stack)->prev;
		(*stack)->prev->next = new;
		(*stack)->prev = new;
		new->num = num;
		*stack = new;
	}
}

void	push_end(t_admin *master, int num, char stack_name)
{
	t_stack		**stack;
	t_stack		*new;

	if (stack_name == 'a')
		stack = &master->stack_a;
	else
		stack = &master->stack_b;
	if (!*stack)
		init_stack(master, num, stack_name);
	else
	{
		if (!ft_malloc((void **)&new, sizeof(t_stack), 1))
			error_exit(master);
		new->next = *stack;
		new->prev = (*stack)->prev;
		(*stack)->prev->next = new;
		(*stack)->prev = new;
		new->num = num;
	}
}

void	pop_top(t_admin *master, char stack_name)
{
	t_stack **stack;
	t_stack *tmp;

	if (stack_name == 'a')
		stack = &master->stack_a;
	else
		stack = &master->stack_b;
	if (*stack)
	{
		if ((*stack)->next == *stack)
			safe_free((void **)stack);
		else
		{
			tmp = *stack;
			(*stack)->prev->next = (*stack)->next;
			(*stack)->next->prev = (*stack)->prev;
			*stack = (*stack)->next;
			free(tmp);
		}
	}
}

int		stacklen(t_admin* master, char stack_name)
{
	int		stack_len;
	t_stack *tmp;
	t_stack	*end;

	stack_len = 0;
	tmp = plug_top_ptr(master, stack_name);
	if (!tmp)
		return (stack_len);
	end = tmp->prev;
	while (tmp)
	{
		stack_len++;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
	return (stack_len);
}
