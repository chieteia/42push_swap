#include "push_swap.h"

int	push_pivot_base(t_admin *master, char src_name, char dst_name)
{
	int stack_len;
	int	range;
	int	pivot;
	int	rot_cnt;
	int	rrot_cnt;

	stack_len = stacklen(master, src_name);
	range = (stack_len + (src_name == 'b')) / 2;
	pivot = get_pivot(master, src_name, stack_len);
	while (range--)
	{
		rot_cnt = find_rot_cnt_from_top(master, src_name, pivot);
		rrot_cnt = find_rrot_cnt_from_end(master, src_name, pivot);
		if (rot_cnt < rrot_cnt)
			exec_loop(master, ROTATE, src_name, rot_cnt);
		else
			exec_loop(master, RROTATE, src_name, rrot_cnt);
		exec_push(master, dst_name, PRINT_OK);
	}
	return ((stack_len + 1) / 2);
}

static void	push_a_to_b(t_admin *master, int count)
{
	int		i;
	int		*array;
	t_stack	*tmp;

	i = 0;
	tmp = master->stack_a;
	if (!ft_malloc((void **)&array, sizeof(int), count))
		error_exit();
	while (count--)
	{
		array[i++] = tmp->num;
		tmp = tmp->next;
	}
	count = i;
	i = 0;
	quick_sort(array, 0, count - 1);
	while (count--)
		exec_push(master, 'b', PRINT_OK);
	free(array);
}

static void	push_min_or_max(t_admin *master, char src_name, char dst_name)
{
	t_stack	*stack;
	int		smallest_rot_cnt;
	int		biggest_rot_cnt;
	int		biggest_cnt;

	biggest_cnt = 0;
	stack = plug_top_ptr(master, dst_name);
	while (stack)
	{
		smallest_rot_cnt = find_smallest_move(master, dst_name);
		biggest_rot_cnt = find_biggest_move(master, dst_name);
		if (smallest_rot_cnt < biggest_rot_cnt)
			smallest_move(master, src_name, dst_name, smallest_rot_cnt);
		else
		{
			biggest_move(master, src_name, dst_name, biggest_rot_cnt);
			biggest_cnt++;
		}
		stack = plug_top_ptr(master, dst_name);
	}
	exec_loop(master, ROTATE, src_name, biggest_cnt);
}

void	sort_longer(t_admin *master, char src_name, char dst_name, int flag)
{
	int	count;
	int	stack_b_len;

	count = 0;
	stack_b_len = stacklen(master, 'b');
	if (stack_b_len >= 1 && stack_b_len <= 32)
	{
		push_min_or_max(master, src_name, dst_name);
		return ;
	}
	else
	{
		if (flag)
		{
			count = push_pivot_base(master, 'a', 'b');
			flag = 0;
		}
		else
			count = push_pivot_base(master, 'b', 'a');
	}
	sort_longer(master, src_name, dst_name, flag);
	push_a_to_b(master, count);
	sort_longer(master, src_name, dst_name, flag);
}
