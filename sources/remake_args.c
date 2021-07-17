#include "push_swap.h"

static int	find_argv_size(char **argv)
{
	int	res;

	res = 0;
	while (argv[res])
		res++;
	return (res);
}

t_args	remake_args(int argc, char **argv)
{
	t_args	arg;

	if (argc == 2)
	{
		arg.vec = ft_split(argv[1], ' ');
		if (!(arg.vec))
			error_exit();
		arg.cnt = find_argv_size(arg.vec);
		arg.is_malloc = TRUE;
	}
	else
	{
		arg.vec = &argv[1];
		arg.cnt = argc - 1;
		arg.is_malloc = FALSE;
	}
	return (arg);
}
