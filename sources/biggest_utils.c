#include "push_swap.h"

t_stack	*find_biggest(t_admin *master, char stack_name)
{
	int		max_num;
	t_stack	*tmp;
	t_stack	*end;
	t_stack	*res;

	max_num = -2147483648;
	tmp = plug_top_ptr(master, stack_name);
	res = NULL;
	if (tmp)
	{
		end = tmp->prev;
		while (1)
		{
			if (tmp->num >= max_num)
			{
				max_num = tmp->num;
				res = tmp;
			}
			if (tmp == end)
				break ;
			tmp = tmp->next;
		}
	}
	return (res);
}

int	find_biggest_move(t_admin *master, char stack_name)
{
	t_stack	*biggest;
	int		rot_cnt;
	int		rrot_cnt;

	biggest = find_biggest(master, stack_name);
	rot_cnt = find_rot_cnt_to_top(master, biggest, stack_name);
	rrot_cnt = find_rrot_cnt_to_top(master, biggest, stack_name);
	if (rot_cnt < rrot_cnt)
	{
		master->biggest_rot_flag = 1;
		master->biggest_rrot_flag = 0;
	}
	else
	{
		master->biggest_rrot_flag = 1;
		master->biggest_rot_flag = 0;
	}
	return (min(rot_cnt, rrot_cnt));
}

void	biggest_move(t_admin *master, char src_name, char dst_name, int count)
{
	if (master->biggest_rot_flag)
	{
		exec_loop(master, ROTATE, dst_name, count);
		exec_push(master, src_name, PRINT_OK);
	}
	if (master->biggest_rrot_flag)
	{
		exec_loop(master, RROTATE, dst_name, count);
		exec_push(master, src_name, PRINT_OK);
	}
}
