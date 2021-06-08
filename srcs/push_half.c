#include "../includes/push_swap.h"
#include "../libft/libft.h"

void push_first_chunk_half(t_admin *master, char src_name, char dst_name)
{
	int rot_cnt;
	int rrot_cnt;
	int range;

	range = get_range_half(master, src_name, FIRST);
	while (range--)
	{
		rot_cnt = find_rot_cnt_from_top(master, src_name, HALF_FIRST);
		rrot_cnt = find_rrot_cnt_from_end(master, src_name, HALF_FIRST);
		if (rot_cnt < rrot_cnt)
			exec_loop(master, ROTATE, src_name, rot_cnt);
		else
			exec_loop(master, RROTATE, src_name, rrot_cnt);
		exec_push(master, dst_name, PRINT_OK);
	}
}

void push_second_chunk_half(t_admin *master, char src_name, char dst_name)
{
	t_stack *stack;
	t_stack *old_end;
	int rot_cnt;
	int rrot_cnt;
	int range;

	range = get_range_half(master, src_name, SECOND);
	old_end = plug_end_ptr(master, src_name);
	while (range--)
	{
		rot_cnt = find_rot_cnt_from_top(master, src_name, HALF_SECOND);
		rrot_cnt = find_rrot_cnt_from_end(master, src_name, HALF_SECOND);
		if (rot_cnt < rrot_cnt)
			exec_loop(master, ROTATE, src_name, rot_cnt);
		else
			exec_loop(master, RROTATE, src_name, rrot_cnt);
		exec_push(master, dst_name, PRINT_OK);
	}
	move_node_to_end(master, old_end, src_name);
}