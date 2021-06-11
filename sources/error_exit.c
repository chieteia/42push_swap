#include "push_swap.h"

void	error_exit(t_admin *master)
{
	write(2, "Error\n", 7);
	admin_free(master);
	exit(1);
}
