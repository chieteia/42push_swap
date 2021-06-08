#ifndef STRUCT_H
# define STRUCT_H

typedef struct	s_args
{
	int		cnt;
	char	**vec;
}				t_args;

typedef struct	s_stack
{
	int				num;
	struct s_stack	*prev;
	struct s_stack	*next;
}				t_stack;

typedef struct	s_admin
{
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
	struct s_args	args;
	int				stack_a_len;
	int				stack_b_len;
	int				smallest_rot_flag;
	int				smallest_rrot_flag;
	int				biggest_rot_flag;
	int				biggest_rrot_flag;
	int				rot_flag;
	int				rrot_flag;
	int				first_quartile;
	int				median;
	int				third_quartile;
}				t_admin;

#endif