#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void check_duplicate(t_admin *master)
{
	int array_len;
	int index;
	int *array;

	index = -1;
	array_len = master->args.cnt - 1;
	if (!ft_malloc((void **)&array, sizeof(int), array_len))
		error_exit(master);
	while (++index < array_len)
		array[index] = ft_atoi(master->args.vec[index + 1]);
	quick_sort(array, 0, array_len - 1);
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

static void chack_argv(t_admin *master)
{
	int index;
	char *argv;
	int argv_num;

	index = 0;
	argv = NULL;
	argv_num = 0;
	while (++index < master->args.cnt)
	{
		argv = master->args.vec[index];
		argv_num = ft_atoi(argv);
		if (*argv == '-' && !ft_isdigit(*(++argv)))
			error_exit(master);
		if (!ft_isnumber(argv))
			error_exit(master);
		if (ft_is_overflow(argv))
			error_exit(master);
		push_end(master, argv_num, 'a');
	}
	check_duplicate(master);
}

void push_argv_to_stack_a(t_admin *master)
{
	chack_argv(master);
	master->stack_a_len = stacklen(master, 'a');
}
