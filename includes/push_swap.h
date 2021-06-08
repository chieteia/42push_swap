#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "struct.h"

# define PRINT_OK 1
# define NOT_PRINT 0

# define PUSH 1
# define SWAP 2
# define ROTATE 3
# define RROTATE 4

# define FIRST 1
# define SECOND 2
# define THIRD 3
# define FOURTH 4
# define HALF_FIRST 5
# define HALF_SECOND 6

void	admin_free(t_admin *master);

void	push_argv_to_stack_a(t_admin *master);

void	error_exit(t_admin *master);

void	exec_pa(t_admin *master, int print_flag);
void	exec_pb(t_admin *master, int print_flag);

void	exec_ra(t_admin *master, int print_flag);
void	exec_rb(t_admin *master, int print_flag);
void	exec_rr(t_admin *master, int print_flag);

void	exec_rra(t_admin *master, int print_flag);
void	exec_rrb(t_admin *master, int print_flag);
void	exec_rrr(t_admin *master, int print_flag);

void	exec_sa(t_admin *master, int print_flag);
void	exec_sb(t_admin *master, int print_flag);
void	exec_ss(t_admin *master, int print_flag);

void	exec_push(t_admin *master, char stack_name, int print_flag);
void	exec_rotate(t_admin *master, char stack_name, int print_flag);
void	exec_reverse_rotate(t_admin *master, char stack_name, int print_flag);
void	exec_swap(t_admin *master, char stack_name, int print_flag);
void	exec_loop(t_admin *master, int command, char stack_name, int count);

t_stack *find_biggest(t_admin *master, char stack_name);
int		find_biggest_move(t_admin *master, char stack_name);
void	biggest_move(t_admin *master, char src_name, char dst_name, int count);

t_stack	*find_smallest(t_admin *master, char stack_name);
int		find_smallest_move(t_admin *master, char stack_name);
void	smallest_move(t_admin *master, char src_name, char dst_name, int count);

int		find_rot_cnt_to_top(t_admin *master, t_stack *node, char stack_name);
int		find_rrot_cnt_to_top(t_admin *master, t_stack *node, char stack_name);
int		find_rot_cnt_to_end(t_admin *master, t_stack *node, char stack_name);
int		find_rrot_cnt_to_end(t_admin *master, t_stack *node, char stack_name);

int		find_rot_cnt_from_top(t_admin *master, char stack_name, int order);
int		find_rrot_cnt_from_end(t_admin *master, char stack_name, int order);

void	get_quartile(t_admin *master, char stack_name);

void	init_stack(t_admin *master, int num, char stack_name);
void	init_admin(t_admin **master, int argc, char **argv);

int		is_asc_sorted(t_admin *master, char stack_name);
int		is_desc_sorted(t_admin *master, char stack_name);

int		min(int a, int b);
int		max(int a, int b);

t_stack	*plug_top_ptr(t_admin *master, char stack_name);
t_stack	*plug_end_ptr(t_admin *master, char stack_name);
int		plug_stack_len(t_admin *master, char stack_name);

void	quick_sort(int *array, int left, int right);

void	push_top(t_admin *master, int num, char stack_name);
void	push_end(t_admin *master, int num, char stack_name);
void	pop_top(t_admin *master, char stack_name);
int		stacklen(t_admin *master, char stack_name);

#endif /* PUSH_SWAP_H */
