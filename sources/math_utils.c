#include "push_swap.h"

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	else
		return (a);
}

int	approx_sqrt(double n)
{
	double	i;
	double	j;

	i = 0;
	j = 0;
	while (i * i < n)
	{
		j = i;
		i++;
	}
	if ((i + j) * (i + j) <= 4 * n)
		return ((int)i);
	else
		return ((int)j);
}
