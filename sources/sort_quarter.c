#include "push_swap.h"

void	sort_first_chunk(t_admin *master, char src_name, char dst_name)
{
	t_stack *stack;
	int smallest_rot_cnt;
	int biggest_rot_cnt;
	int biggest_cnt;

	biggest_cnt = 0;
	push_first_chunk(master, src_name, dst_name);
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

void	sort_second_chunk(t_admin *master, char src_name, char dst_name)
{
	t_stack *stack;
	int smallest_rot_cnt;
	int biggest_rot_cnt;
	int biggest_cnt;

	biggest_cnt = 0;
	push_second_chunk(master, src_name, dst_name);
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

void	sort_third_chunk(t_admin *master, char src_name, char dst_name)
{
	t_stack *stack;
	int smallest_rot_cnt;
	int biggest_rot_cnt;
	int biggest_cnt;

	biggest_cnt = 0;
	push_third_chunk(master, src_name, dst_name);
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

void	sort_fourth_chunk(t_admin *master, char src_name, char dst_name)
{
	t_stack *stack;
	int smallest_rot_cnt;
	int biggest_rot_cnt;
	int biggest_cnt;

	biggest_cnt = 0;
	push_fourth_chunk(master, src_name, dst_name);
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

void	sort_quarter(t_admin *master, char src_name, char dst_name)
{
	sort_first_chunk(master, src_name, dst_name);
	sort_second_chunk(master, src_name, dst_name);
	sort_third_chunk(master, src_name, dst_name);
	sort_fourth_chunk(master, src_name, dst_name);
}
