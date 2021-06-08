#include <stdio.h>
#include <stdlib.h>
#include "includes/push_swap.h"
#include "libft/libft.h"

#define PUSH 1
#define SWAP 2
#define ROTATE 3
#define RROTATE 4

#define FIRST 1
#define SECOND 2
#define THIRD 3
#define FOURTH 4
#define HALF_FIRST 5
#define HALF_SECOND 6

//t_stack *plug_top_ptr(t_admin *master, char stack_name)
//{
//	if (stack_name == 'a')
//		return (master->stack_a);
//	else
//		return (master->stack_b);
//}

static void print_stack(t_admin *master, char stack_name)
{
	t_stack *tmp;
	t_stack *end;

	printf("stack %c : ", stack_name);
	tmp = plug_top_ptr(master, stack_name);
	if (!tmp)
	{
		printf("null\n");
		return;
	}
	end = tmp->prev;
	while (1)
	{
		//printf("master->stack_a       : %p\n", master->stack_a);
		//printf("master->stack_a->next : %p\n", master->stack_a->next);
		//printf("master->stack_a->prev : %p\n", master->stack_a->prev);
		printf("%d", tmp->num);
		if (tmp == end)
			break;
		printf(" ");
		tmp = tmp->next;
	}
	printf("\n");
}

//void	exec_push(t_admin *master, char stack_name, int print_flag)
//{
//	if (stack_name == 'a')
//		exec_pa(master, print_flag);
//	else
//		exec_pb(master, print_flag);
//}

//void	exec_swap(t_admin *master, char stack_name, int print_flag)
//{
//	if (stack_name == 'a')
//		exec_sa(master, print_flag);
//	else
//		exec_sb(master, print_flag);
//}

//void	exec_rotate(t_admin *master, char stack_name, int print_flag)
//{
//	if (stack_name == 'a')
//		exec_ra(master, print_flag);
//	else
//		exec_rb(master, print_flag);
//}

//void	exec_reverse_rotate(t_admin *master, char stack_name, int print_flag)
//{
//	if (stack_name == 'a')
//		exec_rra(master, print_flag);
//	else
//		exec_rrb(master, print_flag);
//}

//int		find_rot_dist(t_admin *master, t_stack *dst, char stack_name)
//{
//	t_stack	*top;
//	int 	rot_dist;

//	rot_dist = 0;
//	top = plug_top_ptr(master, stack_name);
//	while (top != dst)
//	{
//		rot_dist++;
//		top = top->next;
//	}
//	return (rot_dist);
//}

//int		find_rrot_cnt(t_admin *master, t_stack *dst, char stack_name)
//{
//	t_stack	*top;
//	int 	rrot_dist;

//	rrot_dist = 0;
//	top = plug_top_ptr(master, stack_name);
//	while (top != dst)
//	{
//		rrot_dist++;
//		top = top->prev;
//	}
//	return (rrot_dist);
//}

//int		find_min_rot(t_admin *master, t_stack *dst, char stack_name)
//{
//	int		rot_dist;
//	int		rrot_dist;

//	rot_dist = find_rot_dist(master, dst, stack_name);
//	rrot_dist = find_rrot_dist(master, dst, stack_name);
//	return (min(rot_dist, rrot_dist));
//}

//void	exec_loop(t_admin *master, int command, char stack_name, int count)
//{
//	if (command == PUSH)
//		while (count--)
//			exec_push(master, stack_name, PRINT_OK);
//	else if (command == SWAP)
//		while (count--)
//			exec_swap(master, stack_name, PRINT_OK);
//	else if (command == ROTATE)
//		while (count--)
//			exec_rotate(master, stack_name, PRINT_OK);
//	else if (command == RROTATE)
//		while (count--)
//			exec_reverse_rotate(master, stack_name, PRINT_OK);
//	else
//		return ;
//}

//char	reverse_name(char stack_name)
//{
//	if (stack_name == 'a')
//		return ('b');
//	else
//		return ('a');
//}

//int	plug_stack_len(t_admin *master, char stack_name)
//{
//	if (stack_name == 'a')
//		return (master->stack_a_len);
//	else
//		return (master->stack_b_len);
//}

//int get_range_half(t_admin *master, char src_name, int chunk)
//{
//	int range;
//	int stack_len;

//	range = 0;
//	stack_len = plug_stack_len(master, src_name);
//	if (chunk == FIRST)
//		range = stack_len / 2;
//	if (chunk == SECOND)
//		range = stack_len - (stack_len / 2);
//	return (range);
//}

//int get_range_quarter(t_admin *master, char src_name, int chunk)
//{
//	int range;
//	int stack_len;

//	range = 0;
//	stack_len = plug_stack_len(master, src_name);
//	if (chunk == FIRST)
//		range = stack_len / 4;
//	if (chunk == SECOND)
//		range = (stack_len / 2) - (stack_len / 4);
//	if (chunk == THIRD)
//		range = (stack_len * 3 / 4) - (stack_len / 2);
//	if (chunk == FOURTH)
//		range = stack_len - (stack_len * 3 / 4);
//	return (range);
//}

//t_stack *plug_end_ptr(t_admin *master, char stack_name)
//{
//	if (stack_name == 'a')
//		return (master->stack_a->prev);
//	else
//		return (master->stack_b->prev);
//}

//int	find_rot_cnt_to_end(t_admin *master, t_stack *node, char stack_name)
//{
//	t_stack	*end;
//	int 	rot_cnt;

//	rot_cnt = 0;
//	end = plug_end_ptr(master, stack_name);
//	while (end != node)
//	{
//		rot_cnt++;
//		end = end->next;
//	}
//	return (rot_cnt);
//}

//int		find_rrot_cnt_to_end(t_admin *master, t_stack *node, char stack_name)
//{
//	t_stack	*end;
//	int 	rrot_cnt;

//	rrot_cnt = 0;
//	end = plug_end_ptr(master, stack_name);
//	while (end != node)
//	{
//		rrot_cnt++;
//		end = end->prev;
//	}
//	return (rrot_cnt);
//}

//int	find_rot_cnt_from_top(t_admin *master, char stack_name, int order)
//{
//	t_stack	*stack;

//	stack = plug_top_ptr(master, stack_name);
//	if (order == FIRST)
//		while (stack->num >= master->first_quartile)
//			stack = stack->next;
//	if (order == SECOND)
//		while ((stack->num < master->first_quartile) || (stack->num >= master->median))
//			stack = stack->next;
//	if (order == THIRD)
//		while ((stack->num < master->median) || (stack->num >= master->third_quartile))
//			stack = stack->next;
//	if (order == FOURTH)
//		while (stack->num < master->third_quartile)
//			stack = stack->next;
//	if (order == HALF_FIRST)
//		while (stack->num >= master->median)
//			stack = stack->next;
//	if (order == HALF_SECOND)
//		while (stack->num < master->median)
//			stack = stack->next;
//	return (find_rot_cnt_to_top(master, stack, stack_name));
//}

//int	find_rrot_cnt_from_end(t_admin *master, char stack_name, int order)
//{
//	t_stack	*stack;

//	stack = plug_end_ptr(master, stack_name);
//	if (order == FIRST)
//		while (stack->num >= master->first_quartile)
//			stack = stack->prev;
//	if (order == SECOND)
//		while ((stack->num < master->first_quartile) || (stack->num >= master->median))
//			stack = stack->prev;
//	if (order == THIRD)
//		while ((stack->num < master->median) || (stack->num >= master->third_quartile))
//			stack = stack->prev;
//	if (order == FOURTH)
//		while (stack->num < master->third_quartile)
//			stack = stack->prev;
//	if (order == HALF_FIRST)
//		while (stack->num >= master->median)
//			stack = stack->prev;
//	if (order == HALF_SECOND)
//		while (stack->num < master->median)
//			stack = stack->prev;
//	return (find_rrot_cnt_to_top(master, stack, stack_name));
//}

//void push_first_chunk_half(t_admin *master, char src_name, char dst_name)
//{
//	//t_stack *stack;
//	int rot_cnt;
//	int rrot_cnt;
//	int range;

//	range = get_range_half(master, src_name, FIRST);
//	while (range--)
//	{
//		//stack = plug_top_ptr(master, src_name);
//		//while (stack->num >= master->first_quartile)
//		//	stack = stack->next;
//		//rot_cnt = find_rot_cnt(master, stack, src_name);
//		//stack = plug_top_ptr(master, src_name);
//		//while (stack->num >= master->first_quartile)
//		//	stack = stack->prev;
//		//rrot_cnt = find_rrot_cnt(master, stack, src_name);
//		rot_cnt = find_rot_cnt_from_top(master, src_name, HALF_FIRST);
//		rrot_cnt = find_rrot_cnt_from_end(master, src_name, HALF_FIRST);
//		if (rot_cnt < rrot_cnt)
//			exec_loop(master, ROTATE, src_name, rot_cnt);
//		else
//			exec_loop(master, RROTATE, src_name, rrot_cnt);
//		exec_push(master, dst_name, PRINT_OK);
//	}
//}

//int find_smallest_move(t_admin *master, char stack_name)
//{
//	t_stack *smallest;
//	int rot_cnt;
//	int rrot_cnt;

//	smallest = find_smallest(master, stack_name);
//	rot_cnt = find_rot_cnt_to_top(master, smallest, stack_name);
//	rrot_cnt = find_rrot_cnt_to_top(master, smallest, stack_name);
//	if (rot_cnt < rrot_cnt)
//	{
//		master->smallest_rot_flag = 1;
//		master->smallest_rrot_flag = 0;
//	}
//	else
//	{
//		master->smallest_rrot_flag = 1;
//		master->smallest_rot_flag = 0;
//	}
//	return (min(rot_cnt, rrot_cnt));
//}

//int	find_biggest_move(t_admin *master, char stack_name)
//{
//	t_stack *biggest;
//	int rot_cnt;
//	int rrot_cnt;

//	biggest = find_biggest(master, stack_name);
//	rot_cnt = find_rot_cnt_to_top(master, biggest, stack_name);
//	rrot_cnt = find_rrot_cnt_to_top(master, biggest, stack_name);
//	if (rot_cnt < rrot_cnt)
//	{
//		master->biggest_rot_flag = 1;
//		master->biggest_rrot_flag = 0;
//	}
//	else
//	{
//		master->biggest_rrot_flag = 1;
//		master->biggest_rot_flag = 0;
//	}
//	return (min(rot_cnt, rrot_cnt));
//}

//void	move_node_to_end(t_admin *master, t_stack *node, char stack_name)
//{
//	int	rot_cnt;
//	int	rrot_cnt;

//	rot_cnt = find_rot_cnt_to_end(master, node, stack_name);
//	rrot_cnt = find_rrot_cnt_to_end(master, node, stack_name);
//	if (rot_cnt < rrot_cnt)
//		exec_loop(master, ROTATE, stack_name, rot_cnt);
//	else
//		exec_loop(master, RROTATE, stack_name, rrot_cnt);
//}

//void	sort_asc_len2(t_admin *master, char stack_name)
//{
//	t_stack *stack;

//	stack = plug_top_ptr(master, stack_name);
//	if (stack->num > stack->next->num)
//		exec_swap(master, stack_name, PRINT_OK);
//}

//void	sort_desc_len2(t_admin *master, char stack_name)
//{
//	t_stack *stack;

//	stack = plug_top_ptr(master, stack_name);
//	if (stack->num < stack->next->num)
//		exec_swap(master, stack_name, PRINT_OK);
//}

//void	sort_asc_len3(t_admin *master, char stack_name)
//{
//	t_stack *stack;
//	t_stack	*biggest;

//	biggest = find_biggest(master, stack_name);
//	while (!is_asc_sorted(master, stack_name))
//	{
//		stack = plug_top_ptr(master, stack_name);
//		if (biggest->num == stack->num)
//			exec_rotate(master, stack_name, PRINT_OK);
//		else if (biggest->num == stack->next->num)
//			exec_reverse_rotate(master, stack_name, PRINT_OK);
//		else if (biggest->num == stack->next->next->num)
//			exec_swap(master, stack_name, PRINT_OK);
//	}
//}

//void	sort_desc_len3(t_admin *master, char stack_name)
//{
//	t_stack *stack;
//	t_stack	*smallest;

//	smallest = find_smallest(master, stack_name);
//	while (!is_desc_sorted(master, stack_name))
//	{
//		stack = plug_top_ptr(master, stack_name);
//		if (smallest->num == stack->num)
//			exec_rotate(master, stack_name, PRINT_OK);
//		else if (smallest->num == stack->next->num)
//			exec_reverse_rotate(master, stack_name, PRINT_OK);
//		else if (smallest->num == stack->next->next->num)
//			exec_swap(master, stack_name, PRINT_OK);
//	}
//}

//void	sort_asc_len4(t_admin *master, char src_name, char dst_name)
//{
//	int smallest_move_cnt;

//	if (stacklen(master, src_name) == 3)
//	{
//		sort_asc_len3(master, src_name);
//		return ;
//	}
//	smallest_move_cnt = find_smallest_move(master, src_name);
//	if (master->smallest_rot_flag)
//		exec_loop(master, ROTATE, src_name, smallest_move_cnt);
//	else if (master->smallest_rrot_flag)
//		exec_loop(master, RROTATE, src_name, smallest_move_cnt);
//	exec_push(master, dst_name, PRINT_OK);
//	sort_asc_len4(master, src_name, dst_name);
//	exec_push(master, src_name, PRINT_OK);
//}

//void	sort_asc_len5(t_admin *master, char src_name, char dst_name)
//{
//	int rot_cnt;
//	int rrot_cnt;
//	int smallest_move_cnt;

//	if (stacklen(master, src_name) == 3)
//	{
//		sort_desc_len2(master, dst_name);
//		sort_asc_len3(master, src_name);
//		return ;
//	}
//	rot_cnt = find_rot_cnt_from_top(master, src_name, HALF_FIRST);
//	rrot_cnt = find_rrot_cnt_from_end(master, src_name, HALF_FIRST);
//	if (rot_cnt < rrot_cnt)
//		exec_loop(master, ROTATE, src_name, rot_cnt);
//	else
//		exec_loop(master, RROTATE, src_name, rrot_cnt);
//	exec_push(master, dst_name, PRINT_OK);
//	sort_asc_len5(master, src_name, dst_name);
//	exec_push(master, src_name, PRINT_OK);
//}

//void	sort_asc_len6(t_admin *master, char src_name, char dst_name)
//{
//	int rot_cnt;
//	int rrot_cnt;
//	int smallest_move_cnt;

//	if (stacklen(master, src_name) == 3)
//	{
//		sort_desc_len3(master, dst_name);
//		sort_asc_len3(master, src_name);
//		return ;
//	}
//	rot_cnt = find_rot_cnt_from_top(master, src_name, HALF_FIRST);
//	rrot_cnt = find_rrot_cnt_from_end(master, src_name, HALF_FIRST);
//	if (rot_cnt < rrot_cnt)
//		exec_loop(master, ROTATE, src_name, rot_cnt);
//	else
//		exec_loop(master, RROTATE, src_name, rrot_cnt);
//	exec_push(master, dst_name, PRINT_OK);
//	sort_asc_len6(master, src_name, dst_name);
//	exec_push(master, src_name, PRINT_OK);
//}

//void	sort_6_or_less(t_admin *master, char src_name, char dst_name)
//{
//	int	stack_len;

//	stack_len = plug_stack_len(master, src_name);
//	if (stack_len == 1)
//		return ;
//	else if (stack_len == 2)
//		sort_asc_len2(master, src_name);
//	else if (stack_len == 3)
//		sort_asc_len3(master, src_name);
//	else if (stack_len == 4)
//		sort_asc_len4(master, src_name, dst_name);
//	else if (stack_len == 5)
//		sort_asc_len5(master, src_name, dst_name);
//	else if (stack_len == 6)
//		sort_asc_len6(master, src_name, dst_name);
//}

// 0~1/4
//range : [min, first_quartile)
//void push_first_chunk(t_admin *master, char src_name, char dst_name)
//{
//	//t_stack *stack;
//	int rot_cnt;
//	int rrot_cnt;
//	int range;

//	range = get_range_quarter(master, src_name, FIRST);
//	while (range--)
//	{
//		//stack = plug_top_ptr(master, src_name);
//		//while (stack->num >= master->first_quartile)
//		//	stack = stack->next;
//		//rot_cnt = find_rot_cnt(master, stack, src_name);
//		//stack = plug_top_ptr(master, src_name);
//		//while (stack->num >= master->first_quartile)
//		//	stack = stack->prev;
//		//rrot_cnt = find_rrot_cnt(master, stack, src_name);
//		rot_cnt = find_rot_cnt_from_top(master, src_name, FIRST);
//		rrot_cnt = find_rrot_cnt_from_end(master, src_name, FIRST);
//		if (rot_cnt < rrot_cnt)
//			exec_loop(master, ROTATE, src_name, rot_cnt);
//		else
//			exec_loop(master, RROTATE, src_name, rrot_cnt);
//		exec_push(master, dst_name, PRINT_OK);
//	}
//}

//void push_second_chunk_half(t_admin *master, char src_name, char dst_name)
//{
//	t_stack *stack;
//	t_stack *old_end;
//	int rot_cnt;
//	int rrot_cnt;
//	int range;

//	range = get_range_half(master, src_name, SECOND);
//	old_end = plug_end_ptr(master, src_name);
//	while (range--)
//	{
//		//stack = plug_top_ptr(master, src_name);
//		//while ((stack->num < master->first_quartile) || (stack->num >= master->median))
//		//	stack = stack->next;
//		//rot_cnt = find_rot_cnt(master, stack, src_name);
//		//stack = plug_top_ptr(master, src_name);
//		//while ((stack->num < master->first_quartile) || (stack->num >= master->median))
//		//	stack = stack->prev;
//		//rrot_cnt = find_rrot_cnt(master, stack, src_name);
//		rot_cnt = find_rot_cnt_from_top(master, src_name, HALF_SECOND);
//		rrot_cnt = find_rrot_cnt_from_end(master, src_name, HALF_SECOND);
//		if (rot_cnt < rrot_cnt)
//			exec_loop(master, ROTATE, src_name, rot_cnt);
//		else
//			exec_loop(master, RROTATE, src_name, rrot_cnt);
//		exec_push(master, dst_name, PRINT_OK);
//	}
//	move_node_to_end(master, old_end, src_name);
//}

//最初にstack_aのendを確保し、開店後に最後尾にもってくる
//void push_second_chunk(t_admin *master, char src_name, char dst_name)
//{
//	t_stack *stack;
//	t_stack *old_end;
//	int rot_cnt;
//	int rrot_cnt;
//	int range;

//	range = get_range_quarter(master, src_name, SECOND);
//	old_end = plug_end_ptr(master, src_name);
//	while (range--)
//	{
//		//stack = plug_top_ptr(master, src_name);
//		//while ((stack->num < master->first_quartile) || (stack->num >= master->median))
//		//	stack = stack->next;
//		//rot_cnt = find_rot_cnt(master, stack, src_name);
//		//stack = plug_top_ptr(master, src_name);
//		//while ((stack->num < master->first_quartile) || (stack->num >= master->median))
//		//	stack = stack->prev;
//		//rrot_cnt = find_rrot_cnt(master, stack, src_name);
//		rot_cnt = find_rot_cnt_from_top(master, src_name, SECOND);
//		rrot_cnt = find_rrot_cnt_from_end(master, src_name, SECOND);
//		if (rot_cnt < rrot_cnt)
//			exec_loop(master, ROTATE, src_name, rot_cnt);
//		else
//			exec_loop(master, RROTATE, src_name, rrot_cnt);
//		exec_push(master, dst_name, PRINT_OK);
//	}
//	move_node_to_end(master, old_end, src_name);
//}

//void push_third_chunk(t_admin *master, char src_name, char dst_name)
//{
//	t_stack *stack;
//	t_stack *old_end;
//	int rot_cnt;
//	int rrot_cnt;
//	int range;

//	range = get_range_quarter(master, src_name, THIRD);
//	old_end = plug_end_ptr(master, src_name);
//	while (range--)
//	{
//		//stack = plug_top_ptr(master, src_name);
//		//while ((stack->num < master->median) || (stack->num >= master->third_quartile))
//		//	stack = stack->next;
//		//rot_cnt = find_rot_cnt(master, stack, src_name);
//		//stack = plug_top_ptr(master, src_name);
//		//while ((stack->num < master->median) || (stack->num >= master->third_quartile))
//		//	stack = stack->prev;
//		//rrot_cnt = find_rrot_cnt(master, stack, src_name);
//		rot_cnt = find_rot_cnt_from_top(master, src_name, THIRD);
//		rrot_cnt = find_rrot_cnt_from_end(master, src_name, THIRD);
//		if (rot_cnt < rrot_cnt)
//			exec_loop(master, ROTATE, src_name, rot_cnt);
//		else
//			exec_loop(master, RROTATE, src_name, rrot_cnt);
//		exec_push(master, dst_name, PRINT_OK);
//	}
//	move_node_to_end(master, old_end, src_name);
//}

//void push_fourth_chunk(t_admin *master, char src_name, char dst_name)
//{
//	t_stack *stack;
//	int rot_cnt;
//	int rrot_cnt;
//	int range;

//	range = get_range_quarter(master, src_name, FOURTH);
//	while (range--)
//	{
//		//stack = plug_top_ptr(master, src_name);
//		//while (stack->num < master->third_quartile)
//		//	stack = stack->next;
//		//rot_cnt = find_rot_cnt(master, stack, src_name);
//		//stack = plug_top_ptr(master, src_name);
//		//while (stack->num < master->third_quartile)
//		//	stack = stack->prev;
//		//rrot_cnt = find_rrot_cnt(master, stack, src_name);
//		rot_cnt = find_rot_cnt_from_top(master, src_name, FOURTH);
//		rrot_cnt = find_rrot_cnt_from_end(master, src_name, FOURTH);
//		if (rot_cnt < rrot_cnt)
//			exec_loop(master, ROTATE, src_name, rot_cnt);
//		else
//			exec_loop(master, RROTATE, src_name, rrot_cnt);
//		exec_push(master, dst_name, PRINT_OK);
//	}
//}

//void	smallest_move(t_admin *master, char src_name, char dst_name, int count)
//{
//	if (master->smallest_rot_flag)
//	{
//		exec_loop(master, ROTATE, dst_name, count);
//		exec_push(master, src_name, PRINT_OK);
//		exec_rotate(master, src_name, PRINT_OK);
//	}
//	if (master->smallest_rrot_flag)
//	{
//		exec_loop(master, RROTATE, dst_name, count);
//		exec_push(master, src_name, PRINT_OK);
//		exec_rotate(master, src_name, PRINT_OK);
//	}
//}

//void	biggest_move(t_admin *master, char src_name, char dst_name, int count)
//{
//	if (master->biggest_rot_flag)
//	{
//		exec_loop(master, ROTATE, dst_name, count);
//		exec_push(master, src_name, PRINT_OK);
//	}
//	if (master->biggest_rrot_flag)
//	{
//		exec_loop(master, RROTATE, dst_name, count);
//		exec_push(master, src_name, PRINT_OK);
//	}
//}

//void	sort_first_chunk_half(t_admin *master, char src_name, char dst_name)
//{
//	t_stack *stack;
//	int smallest_rot_cnt;
//	int biggest_rot_cnt;
//	int biggest_cnt;

//	biggest_cnt = 0;
//	//printf("before 1st\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
//	push_first_chunk_half(master, src_name, dst_name);
//	//printf("after 1st\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
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

//void	sort_first_chunk(t_admin *master, char src_name, char dst_name)
//{
//	t_stack *stack;
//	int smallest_rot_cnt;
//	int biggest_rot_cnt;
//	int biggest_cnt;

//	biggest_cnt = 0;
//	//printf("before 1st\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
//	push_first_chunk(master, src_name, dst_name);
//	//printf("after 1st\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
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

//void	sort_second_chunk_half(t_admin *master, char src_name, char dst_name)
//{
//	t_stack *stack;
//	int smallest_rot_cnt;
//	int biggest_rot_cnt;
//	int biggest_cnt;

//	biggest_cnt = 0;
//	//printf("before 2nd\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
//	push_second_chunk_half(master, src_name, dst_name);
//	stack = plug_top_ptr(master, dst_name);
//	//printf("after 2nd\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
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
//	t_stack *stack;
//	int smallest_rot_cnt;
//	int biggest_rot_cnt;
//	int biggest_cnt;

//	biggest_cnt = 0;
//	//printf("before 2nd\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
//	push_second_chunk(master, src_name, dst_name);
//	stack = plug_top_ptr(master, dst_name);
//	//printf("after 2nd\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
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
//	t_stack *stack;
//	int smallest_rot_cnt;
//	int biggest_rot_cnt;
//	int biggest_cnt;

//	biggest_cnt = 0;
//	//printf("before 3rd\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
//	push_third_chunk(master, src_name, dst_name);
//	stack = plug_top_ptr(master, dst_name);
//	//printf("after 3rd\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
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
//	t_stack *stack;
//	int smallest_rot_cnt;
//	int biggest_rot_cnt;
//	int biggest_cnt;

//	biggest_cnt = 0;
//	//printf("before 4st\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
//	push_fourth_chunk(master, src_name, dst_name);
//	//printf("after 4th\n");
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
//	stack = plug_top_ptr(master, dst_name);
//	//print_stack(master, 'a');
//	//print_stack(master, 'b');
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

//range : [first_quartile, median)

//int	init_stack(t_admin *master)
//{
//	t_stack **top;

//	top = &master->stack_a;
//	if (!ft_malloc((void **)top, sizeof(t_stack), 1))
//	{
//		//error_exit(master);
//		return (FALSE);
//	}
//	(*top)->prev = *top;
//	(*top)->next = *top;
//	(*top)->num = 0;
//	return (OK);
//}

//void init_func(void **str)
//{
//	*str = malloc(10);
//}

//int ft_isdigit(char c)
//{
//	return ('0' <= c && c <= '9');
//}

//int	ft_isnumber(char *str)
//{
//	if (!(str && *str))
//		return (FALSE);
//	while (*str)
//	{
//		if (!ft_isdigit(*str++))
//			return (FALSE);
//	}
//	return (OK);
//}

//void mischief(char **str)
//{
//	char *tmp;

//	tmp = *str;
//	tmp++;
//	str = &tmp;
//}

int main(int argc, char **argv)
{
	//	char *str = "";
	//	char *str2 = NULL;
	//	char *str3 = "1234567";
	//	char *str4 = "123a4567";

	//	if (ft_isnumber(str))
	//		printf ("OK\n");
	//	else
	//		printf ("FALSE\n");

	//	if (ft_isnumber(str2))
	//		printf ("OK\n");
	//	else
	//		printf ("FALSE\n");

	//	if (ft_isnumber(str3))
	//		printf ("OK\n");
	//	else
	//		printf ("FALSE\n");

	//	if (ft_isnumber(str4))
	//		printf ("OK\n");
	//	else
	//		printf ("FALSE\n");

	//printf("%d\n", -1 / 2);
	//printf("%d\n", 0 / 2);

	//char *str = "abcde";

	//if (*str++ == 's' && *str == 'b')
	//	printf("OK");
	//else
	//	printf ("FALSE");
	//printf ("\n%s", str);
	//char *str = malloc(sizeof(char) * 10);
	//str = "abcde";
	//mischief(&str);
	//printf("\n%s\n", str);

	////free_test
	//	t_stack *test = malloc(sizeof(t_stack));
	//	safe_free((void **)&test);

	//t_admin *master;

	//ft_malloc((void **)&master, sizeof(t_admin), 1);
	//master->stack_a = NULL;
	//master->stack_b = NULL;

	//if (init_stack(master))
	//	printf("1");
	//else
	//	printf("0");

	t_admin *master;

	master = NULL;
	init_admin(&master, argc, argv);
	//for (int index = 0; index < argc - 1; index++)
	//	printf("%s ", master->args.vec[index + 1]);
	push_argv_to_stack_a(master);
	get_quartile(master, 'a');
	//printf("first_quartile : %d\n", master->first_quartile);
	//printf("median : %d\n", master->median);
	//printf("third_quartile : %d\n", master->third_quartile);

	//quarter

	sort_first_chunk(master, 'a', 'b');
	sort_second_chunk(master, 'a', 'b');
	sort_third_chunk(master, 'a', 'b');
	sort_fourth_chunk(master, 'a', 'b');

	// half

	//sort_first_chunk_half(master, 'a', 'b');
	//sort_second_chunk_half(master, 'a', 'b');

	// 6 or less

	//sort_6_or_less(master, 'a', 'b');


	print_stack(master, 'a');
	print_stack(master, 'b');

	admin_free(master);
}
