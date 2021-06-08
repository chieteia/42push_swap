#include "../includes/push_swap.h"
#include "../libft/libft.h"

t_stack	*find_smallest(t_admin *master, char stack_name)
{
	int		min_num;
	t_stack	*tmp;
	t_stack	*end;
	t_stack *res;

	min_num = INT32_MAX;
	tmp = plug_top_ptr(master, stack_name);
	res = NULL;
	if (tmp)
	{
		end = tmp->prev;
		while (1)
		{
			if (tmp->num <= min_num)
			{
				min_num = tmp->num;
				res = tmp;
			}
			if (tmp == end)
				break ;
			tmp = tmp->next;
		}
	}
	return (res);
}

int	find_smallest_move(t_admin *master, char stack_name)
{
	t_stack *smallest;
	int rot_cnt;
	int rrot_cnt;

	smallest = find_smallest(master, stack_name);
	rot_cnt = find_rot_cnt_to_top(master, smallest, stack_name);
	rrot_cnt = find_rrot_cnt_to_top(master, smallest, stack_name);
	if (rot_cnt < rrot_cnt)
	{
		master->smallest_rot_flag = 1;
		master->smallest_rrot_flag = 0;
	}
	else
	{
		master->smallest_rrot_flag = 1;
		master->smallest_rot_flag = 0;
	}
	return (min(rot_cnt, rrot_cnt));
}

void	smallest_move(t_admin *master, char src_name, char dst_name, int count)
{
	if (master->smallest_rot_flag)
	{
		exec_loop(master, ROTATE, dst_name, count);
		exec_push(master, src_name, PRINT_OK);
		exec_rotate(master, src_name, PRINT_OK);
	}
	if (master->smallest_rrot_flag)
	{
		exec_loop(master, RROTATE, dst_name, count);
		exec_push(master, src_name, PRINT_OK);
		exec_rotate(master, src_name, PRINT_OK);
	}
}
