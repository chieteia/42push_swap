#include "../includes/push_swap.h"
#include "../libft/libft.h"

void	sort_6_or_less(t_admin *master, char src_name, char dst_name)
{
	int	stack_len;

	stack_len = plug_stack_len(master, src_name);
	if (stack_len == 1)
		return ;
	else if (stack_len == 2)
		sort_asc_len2(master, src_name);
	else if (stack_len == 3)
		sort_asc_len3(master, src_name);
	else if (stack_len == 4)
		sort_asc_len4(master, src_name, dst_name);
	else if (stack_len == 5)
		sort_asc_len5(master, src_name, dst_name);
	else if (stack_len == 6)
		sort_asc_len6(master, src_name, dst_name);
}