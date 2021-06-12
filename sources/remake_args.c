#include "push_swap.h"

static int	find_argv_size(char **argv)
{
	int	res;

	res = 0;
	while (argv[res])
		res++;
	return (res);
}

void	remake_args(int argc, char **argv, int *new_argc, char ***new_argv)
{
	if (argc == 2)
	{
		*new_argv = ft_split(argv[1], ' ');
		if (!(*new_argv))
		{
			ft_putstr_fd("Error\n", 2);
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
