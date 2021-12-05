#include "push_swap.h"

//void	sort_first_chunk(t_admin *master, char src_name, char dst_name)
//{
//	t_stack	*stack;
//	int		smallest_rot_cnt;
//	int		biggest_rot_cnt;
//	int		biggest_cnt;

//	biggest_cnt = 0;
//	push_first_chunk(master, src_name, dst_name);
//	stack = plug_top_ptr(master, dst_name);
//	while (stack)
//	{
//		smallest_rot_cnt = find_smallest_move(master, dst_name);
//		biggest_rot_cnt = find_biggest_move(master, dst_name);
//		if (smallest_rot_cnt < biggest_rot_cnt)
//			smallest_move(master, src_name, dst_name, smallest_rot_cnt);
//		else
//		{
//			biggest_move(master, src_name, dst_name, biggest_rot_cnt);
//			biggest_cnt++;
//		}
//		stack = plug_top_ptr(master, dst_name);
//	}
//	exec_loop(master, ROTATE, src_name, biggest_cnt);
//}

//void	sort_second_chunk(t_admin *master, char src_name, char dst_name)
//{
//	t_stack	*stack;
//	int		smallest_rot_cnt;
//	int		biggest_rot_cnt;
//	int		biggest_cnt;

//	biggest_cnt = 0;
//	push_second_chunk(master, src_name, dst_name);
//	stack = plug_top_ptr(master, dst_name);
//	while (stack)
//	{
//		smallest_rot_cnt = find_smallest_move(master, dst_name);
//		biggest_rot_cnt = find_biggest_move(master, dst_name);
//		if (smallest_rot_cnt < biggest_rot_cnt)
//			smallest_move(master, src_name, dst_name, smallest_rot_cnt);
//		else
//		{
//			biggest_move(master, src_name, dst_name, biggest_rot_cnt);
//			biggest_cnt++;
//		}
//		stack = plug_top_ptr(master, dst_name);
//	}
//	exec_loop(master, ROTATE, src_name, biggest_cnt);
//}

//void	sort_third_chunk(t_admin *master, char src_name, char dst_name)
//{
//	t_stack	*stack;
//	int		smallest_rot_cnt;
//	int		biggest_rot_cnt;
//	int		biggest_cnt;

//	biggest_cnt = 0;
//	push_third_chunk(master, src_name, dst_name);
//	stack = plug_top_ptr(master, dst_name);
//	while (stack)
//	{
//		smallest_rot_cnt = find_smallest_move(master, dst_name);
//		biggest_rot_cnt = find_biggest_move(master, dst_name);
//		if (smallest_rot_cnt < biggest_rot_cnt)
//			smallest_move(master, src_name, dst_name, smallest_rot_cnt);
//		else
//		{
//			biggest_move(master, src_name, dst_name, biggest_rot_cnt);
//			biggest_cnt++;
//		}
//		stack = plug_top_ptr(master, dst_name);
//	}
//	exec_loop(master, ROTATE, src_name, biggest_cnt);
//}

//void	sort_fourth_chunk(t_admin *master, char src_name, char dst_name)
//{
//	t_stack	*stack;
//	int		smallest_rot_cnt;
//	int		biggest_rot_cnt;
//	int		biggest_cnt;

//	biggest_cnt = 0;
//	push_fourth_chunk(master, src_name, dst_name);
//	stack = plug_top_ptr(master, dst_name);
//	while (stack)
//	{
//		smallest_rot_cnt = find_smallest_move(master, dst_name);
//		biggest_rot_cnt = find_biggest_move(master, dst_name);
//		if (smallest_rot_cnt < biggest_rot_cnt)
//			smallest_move(master, src_name, dst_name, smallest_rot_cnt);
//		else
//		{
//			biggest_move(master, src_name, dst_name, biggest_rot_cnt);
//			biggest_cnt++;
//		}
//		stack = plug_top_ptr(master, dst_name);
//	}
//	exec_loop(master, ROTATE, src_name, biggest_cnt);
//}

//void	sort_quarter(t_admin *master, char src_name, char dst_name)
//{
//	sort_first_chunk(master, src_name, dst_name);
//	sort_second_chunk(master, src_name, dst_name);
//	sort_third_chunk(master, src_name, dst_name);
//	sort_fourth_chunk(master, src_name, dst_name);
//}

int	find_range(t_admin *master, int l)
{
	return (master->arg_cnt * (l + 1) / master->div_num
		- master->arg_cnt * l / master->div_num);
}

void	push_chunk(t_admin *master, char src_name, char dst_name, int l)
{
	t_stack	*old_end;
	int		rot_cnt;
	int		rrot_cnt;
	int		range;

	range = find_range(master, l);
	old_end = plug_end_ptr(master, src_name);
	while (range--)
	{
		rot_cnt = find_rot_cnt_from_top(master, src_name, l);
		rrot_cnt = find_rrot_cnt_from_end(master, src_name, l);
		if (rot_cnt < rrot_cnt)
			exec_loop(master, ROTATE, src_name, rot_cnt);
		else
			exec_loop(master, RROTATE, src_name, rrot_cnt);
		exec_push(master, dst_name, PRINT_OK);
	}
	if (l != 0 && l != master->div_num - 1)
		move_node_to_end(master, old_end, src_name);
}

void	sort_chunk(t_admin *master, char src_name, char dst_name, int l)
{
	t_stack	*stack;
	int		smallest_rot_cnt;
	int		biggest_rot_cnt;
	int		biggest_cnt;

	biggest_cnt = 0;
	push_chunk(master, src_name, dst_name, l);
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

void	sort_all(t_admin *master, char src_name, char dst_name)
{
	int	l;

	l = -1;
	while (++l < master->div_num)
		sort_chunk(master, src_name, dst_name, l);
}
