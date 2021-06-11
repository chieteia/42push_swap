#include "push_swap.h"

static int	find_argv_size(char **argv)
{
	int res;

	res = 0;
	while(argv[res])
		res++;
	return (res);
}

static void	remake_args(int argc, char **argv, int *new_argc, char ***new_argv)
{
	if (argc == 2)
	{
		*new_argv = ft_split(argv[1], ' ');
		if (!(*new_argv))
		{
			write(2, "Error\n", 7);
			exit(1);
		}
		*new_argc = find_argv_size(*new_argv);
	}
	else
	{
		*new_argv = &argv[1];
		*new_argc = argc - 1;
	}
}

static void	push_swap(t_admin *master)
{
	int	stack_len;

	stack_len = stacklen(master, 'a');
	if (!is_asc_sorted(master, 'a'))
	{
		if (stack_len <= 6)
			sort_6_or_less(master, 'a', 'b');
		else if (stack_len <= 100)
			sort_half(master, 'a', 'b');
		else
			sort_quarter(master, 'a', 'b');
	}
}

int	main(int argc, char **argv)
{
	t_admin *master;
	char	**new_argv;
	int		new_argc;

	if (argc < 2)
		return (1);
	remake_args(argc, argv, &new_argc, &new_argv);
	init_admin(&master, new_argc, new_argv);
	push_argv_to_stack(master, 'a');
	get_quartile(master, 'a');
	push_swap(master);
	admin_free(master);
	return (0);
}
