#include "../includes/push_swap.h"
#include "../libft/libft.h"

int		find_rot_cnt_to_top(t_admin *master, t_stack *node, char stack_name)
{
	t_stack	*top;
	int 	rot_cnt;

	rot_cnt = 0;
	top = plug_top_ptr(master, stack_name);
	while (top != node)
	{
		rot_cnt++;
		top = top->next;
	}
	return (rot_cnt);
}

int		find_rrot_cnt_to_top(t_admin *master, t_stack *node, char stack_name)
{
	t_stack	*top;
	int 	rrot_cnt;

	rrot_cnt = 0;
	top = plug_top_ptr(master, stack_name);
	while (top != node)
	{
		rrot_cnt++;
		top = top->prev;
	}
	return (rrot_cnt);
}

int	find_rot_cnt_to_end(t_admin *master, t_stack *node, char stack_name)
{
	t_stack	*end;
	int 	rot_cnt;

	rot_cnt = 0;
	end = plug_end_ptr(master, stack_name);
	while (end != node)
	{
		rot_cnt++;
		end = end->next;
	}
	return (rot_cnt);
}
int		find_rot_cnt_to_top(t_admin *master, t_stack *node, char stack_name);
int		find_rrot_cnt_to_top(t_admin *master, t_stack *node, char stack_name);
int	find_rot_cnt_to_end(t_admin *master, t_stack *node, char stack_name);
int		find_rrot_cnt_to_end(t_admin *master, t_stack *node, char stack_name)
{
	t_stack	*end;
	int 	rrot_cnt;

	rrot_cnt = 0;
	end = plug_end_ptr(master, stack_name);
	while (end != node)
	{
		rrot_cnt++;
		end = end->prev;
	}
	return (rrot_cnt);
}
