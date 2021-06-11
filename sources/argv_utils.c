#include "push_swap.h"

static void check_duplicate(t_admin *master)
{
	int index;
	int *array;

	index = -1;
	if (!ft_malloc((void **)&array, sizeof(int), master->args.cnt))
		error_exit(master);
	while (++index < master->args.cnt)
		array[index] = ft_atoi(master->args.vec[index]);
	quick_sort(array, 0, master->args.cnt - 1);
	while (--index > 0)
	{
		if (array[index] == array[index - 1])
		{
			free(array);
			error_exit(master);
		}
	}
	free(array);
}

static int ft_isnumber(char *str)
{
	if (!(str && *str))
		return (FALSE);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (FALSE);
		str++;
	}
	return (OK);
}
//return (!(ft_atoi(num) / 2))は、条件の元で Overflow した時の ft_atoi の返り値を考慮。
static int ft_is_overflow(char *num)
{
	int digits;

	digits = (int)ft_strlen(num);
	if (digits > INT_MAX_DIGIT)
		return (TRUE);
	else if (digits == INT_MAX_DIGIT)
		return (!(ft_atoi(num) / 2));
	else
		return (FALSE);
}

static void chack_argv(t_admin *master, char stack_name)
{
	int index;
	char *argv;
	int argv_num;

	index = 0;
	argv = NULL;
	argv_num = 0;
	while (index < master->args.cnt)
	{
		argv = master->args.vec[index++];
		argv_num = ft_atoi(argv);
		if (*argv == '-' && !ft_isdigit(*(++argv)))
			error_exit(master);
		if (!ft_isnumber(argv))
			error_exit(master);
		if (ft_is_overflow(argv))
			error_exit(master);
		push_end(master, argv_num, stack_name);
	}
	check_duplicate(master);
}

void push_argv_to_stack(t_admin *master, char stack_name)
{
	chack_argv(master, stack_name);
	if (stack_name == 'a')
		master->stack_a_len = stacklen(master, 'a');
	else if (stack_name == 'b')
		master->stack_b_len = stacklen(master, 'b');
}
