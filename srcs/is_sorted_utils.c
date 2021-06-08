#include "../includes/push_swap.h"
#include "../libft/libft.h"

int	is_asc_sorted(t_admin *master, char stack_name)
{
	t_stack *top;
	t_stack *tmp;

	top = plug_top_ptr(master, stack_name);
	tmp = top;
	while (tmp->next != top)
	{
		if (tmp->num > tmp->next->num)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}

int	is_desc_sorted(t_admin *master, char stack_name)
{
	t_stack *top;
	t_stack *tmp;

	top = plug_top_ptr(master, stack_name);
	tmp = top;
	while (tmp->next != top)
	{
		if (tmp->num < tmp->next->num)
			return (FALSE);
		tmp = tmp->next;
	}
	return (TRUE);
}