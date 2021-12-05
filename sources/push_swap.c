#include "push_swap.h"

static void	push_swap(int argc, char **argv)
{
	t_admin	*master;

	init_admin(&master, remake_args(argc, argv));
	push_argv_to_stack(master, 'a');
	master->arg_cnt = stacklen(master, 'a');
	get_pivot(master, 'a', master->arg_cnt);
	if (!is_asc_sorted(master, 'a'))
	{
		if (master->arg_cnt <= 6)
			sort_6_or_less(master, 'a', 'b');
		else
			sort_all(master, 'a', 'b');
	}
	admin_free(master);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
		push_swap(argc, argv);
	return (0);
}
