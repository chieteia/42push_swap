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

int	approx_sqrt(int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i * i < n)
	{
		j = i;
		i++;
	}
	if (2 * n < i * i + j * j)
		return (j);
	else
		return (i);
}
