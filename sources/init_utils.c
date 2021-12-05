#include "push_swap.h"

void	init_stack(t_admin *master, int num, char stack_name)
{
	t_stack	**stack;

	if (stack_name == 'a')
		stack = &master->stack_a;
	else
		stack = &master->stack_b;
	if (!ft_malloc((void **)stack, sizeof(t_stack), 1))
		error_exit();
	(*stack)->prev = *stack;
	(*stack)->next = *stack;
	(*stack)->num = num;
}

void	init_admin(t_admin **master, t_args arg)
{
	if (!ft_malloc((void **)master, sizeof(t_admin), 1))
		error_exit();
	(*master)->stack_a = NULL;
	(*master)->stack_b = NULL;
	(*master)->args = arg;
	(*master)->arg_cnt = 0;
	(*master)->stack_a_len = 0;
	(*master)->stack_b_len = 0;
	(*master)->smallest_rot_flag = 0;
	(*master)->smallest_rrot_flag = 0;
	(*master)->biggest_rot_flag = 0;
	(*master)->biggest_rrot_flag = 0;
	(*master)->rot_flag = 0;
	(*master)->rrot_flag = 0;
	(*master)->first_quartile = 0;
	(*master)->median = 0;
	(*master)->third_quartile = 0;
	(*master)->partitions = NULL;
	(*master)->div_num = 0;
}
