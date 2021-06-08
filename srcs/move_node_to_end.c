#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	move_node_to_end(t_admin *master, t_stack *node, char stack_name)
{
	int	rot_cnt;
	int	rrot_cnt;

	rot_cnt = find_rot_cnt_to_end(master, node, stack_name);
	rrot_cnt = find_rrot_cnt_to_end(master, node, stack_name);
	if (rot_cnt < rrot_cnt)
		exec_loop(master, ROTATE, stack_name, rot_cnt);
	else
		exec_loop(master, RROTATE, stack_name, rrot_cnt);
}
