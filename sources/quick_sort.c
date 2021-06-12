#include "push_swap.h"

static void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	find_pivot(int *array, int i, int j)
{
	int	k;

	k = i + 1;
	while (k <= j && array[i] == array[k])
		k++;
	if (k > j)
		return (-1);
	if (array[i] >= array[k])
		return (i);
	return (k);
}

int	partition(int *array, int i, int j, int x)
{
	int	l;
	int	r;

	l = i;
	r = j;
	while (l <= r)
	{
		while (l <= j && array[l] < x)
			l++;
		while (r >= i && array[r] >= x)
			r--;
		if (l > r)
			break ;
		swap(&array[l], &array[r]);
		l++;
		r--;
	}
	return (l);
}

void	quick_sort(int *array, int left, int right)
{
	int	pivot;
	int	k;

	if (left == right)
		return ;
	pivot = find_pivot(array, left, right);
	if (pivot != -1)
	{
		k = partition(array, left, right, array[pivot]);
		quick_sort(array, left, k - 1);
		quick_sort(array, k, right);
	}
}
