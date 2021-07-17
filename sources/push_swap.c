#include "push_swap.h"

static void	push_swap(int argc, char **argv)
{
	t_admin	*master;
	int		stack_len;

	init_admin(&master, remake_args(argc, argv));
	push_argv_to_stack(master, 'a');
	get_quartile(master, 'a');
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
