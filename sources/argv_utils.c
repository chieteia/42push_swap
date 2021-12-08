#include "push_swap.h"

static void	check_duplicate(t_admin *master)
{
	int	index;
	int	*array;

	index = -1;
	if (!ft_malloc((void **)&array, sizeof(int), master->args.cnt))
		error_exit();
	while (++index < master->args.cnt)
		array[index] = ft_atoi(master->args.vec[index]);
	quick_sort(array, 0, master->args.cnt - 1);
	while (--index > 0)
	{
		if (array[index] == array[index - 1])
			error_exit();
	}
	free(array);
}

static int	ft_isnumber(char *str)
{
	if (!(str && *str))
		return (FALSE);
	if (*str == '-')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (OK);
}

static int	ft_is_overflow(char *num)
{
	int	digits;

	digits = (int)ft_strlen(num) - (*num == '-');
	if (digits > INT_MAX_DIGIT)
		return (TRUE);
	else if (digits == INT_MAX_DIGIT)
		return (!(ft_atoi(num) / 2));
	else
		return (FALSE);
}

static void	chack_argv(t_admin *master, char stack_name)
{
	int		index;
	char	*argv;
	int		argv_num;

	index = 0;
	argv = NULL;
	argv_num = 0;
	while (index < master->args.cnt)
	{
		argv = master->args.vec[index++];
		if (!ft_isnumber(argv))
			error_exit();
		if (ft_is_overflow(argv))
			error_exit();
		argv_num = ft_atoi(argv);
		push_end(master, argv_num, stack_name);
	}
	check_duplicate(master);
}

void	push_argv_to_stack(t_admin *master, char stack_name)
{
	chack_argv(master, stack_name);
	if (stack_name == 'a')
		master->stack_a_len = stacklen(master, 'a');
	else if (stack_name == 'b')
		master->stack_b_len = stacklen(master, 'b');
}
