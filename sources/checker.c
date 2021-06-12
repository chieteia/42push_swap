#include "push_swap.h"

static void	check_command(t_admin *master, char *line)
{
	if (!(ft_strncmp("sa", line, 3)))
		exec_sa(master, NOT_PRINT);
	else if (!(ft_strncmp("sb", line, 3)))
		exec_sb(master, NOT_PRINT);
	else if (!(ft_strncmp("ss", line, 3)))
		exec_ss(master, NOT_PRINT);
	else if (!(ft_strncmp("pa", line, 3)))
		exec_pa(master, NOT_PRINT);
	else if (!(ft_strncmp("pb", line, 3)))
		exec_pb(master, NOT_PRINT);
	else if (!(ft_strncmp("ra", line, 3)))
		exec_ra(master, NOT_PRINT);
	else if (!(ft_strncmp("rb", line, 3)))
		exec_rb(master, NOT_PRINT);
	else if (!(ft_strncmp("rr", line, 3)))
		exec_rr(master, NOT_PRINT);
	else if (!(ft_strncmp("rra", line, 4)))
		exec_rra(master, NOT_PRINT);
	else if (!(ft_strncmp("rrb", line, 4)))
		exec_rrb(master, NOT_PRINT);
	else if (!(ft_strncmp("rrr", line, 4)))
		exec_rrr(master, NOT_PRINT);
	else
		error_exit();
	safe_free((void **)&line);
}

static void	print_result(t_admin *master)
{
	if (is_asc_sorted(master, 'a') && !master->stack_b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

static void	checker(int argc, char **argv)
{
	char	*line;
	int		res;
	t_admin	*master;
	char	**new_argv;
	int		new_argc;

	line = NULL;
	remake_args(argc, argv, &new_argc, &new_argv);
	init_admin(&master, new_argc, new_argv);
	push_argv_to_stack(master, 'a');
	res = get_next_line(0, &line);
	while (res >= 0)
	{
		if (*line)
			check_command(master, line);
		if (res == 0)
			break ;
		res = get_next_line(0, &line);
	}
	if (res == -1)
		error_exit();
	print_result(master);
	admin_free(master);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
		checker(argc, argv);
	return (0);
}
