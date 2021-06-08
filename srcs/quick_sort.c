#include "../includes/push_swap.h"
#include "../libft/libft.h"

static void print_array(int *array, int left, int right)
{
	for (int index = left; index <= right; index++)
	{
		printf("%d ", array[index]);
	}
	printf("\n");
}

static void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/*
3 4 6 10 9

l=0, r=4
i = 1, j = 4, piv = 0

*/
//static int partition(int *array, int left, int right)
//{
//	int i;
//	int j;
//	int pivot;

//	i = left;
//	j = right;
//	pivot = (left + right) / 2;
//	while (i < j)
//	{
//		while (array[i] < array[pivot])
//			i++;
//		while (array[pivot] < array[j])
//			j--;
//		if (i < j)
//			swap(&array[i], &array[j]);
//	}
//	return (pivot);
//}

// static int partition(int *array, int left, int right)
// {
// 	int i;
// 	int j;
// 	int pivot;

// 	i = left + 1;
// 	j = right;
// 	pivot = left;
// 	while (i < j)
// 	{
// 		while ((i < right) && (array[i] <= array[pivot]))
// 			i++;
// 		while ((left < j) && (array[pivot] <= array[j]))
// 			j--;
// 		if (i < j)
// 			swap(&array[i], &array[j]);
// 	}
// 	swap(&array[pivot], &array[j]);
// 	return (j);
// }

// void quick_sort(int *array, int left, int right)
// {
// 	int pivot;

// 	if (left < right)
// 	{
// 		pivot = partition(array, left, right);
// 		print_array(array, left, right);
// 		printf("pivot : %d\n", pivot);
// 		quick_sort(array, left, pivot - 1);
// 		quick_sort(array, pivot + 1, right);
// 	}
// }

// void quick_sort(int *array, int size)
// {

// 	int left = 0;
// 	int right = size - 1;
// 	int pivot = (left + right) / 2;
// 	if (size <= 1 || (array[left] == array[pivot] && array[right] == array[pivot]))
// 		return;
// 	printf("size : %d\n", size);
// 	printf("before sort : ");
// 	print_array(array, left, right);
// 	printf("\n");
// 	while (left <= right)
// 	{
// 		printf("in\n");
// 		while ((left < right) && array[left] < array[pivot])
// 			left++;
// 		while ((left < right) && array[pivot] < array[right])
// 			right--;
// 		if (left <= right)
// 		{
// 			swap(&array[left], &array[right]);
// 			if (array[left] == array[right])
// 				left++;
// 		}
// 	}
// 	printf("after sort : ");
// 	print_array(array, left, right);
// 	printf("\n");
// 	quick_sort(array, left);
// 	quick_sort(&array[left + 1], size - 1 - left);
// }

/*
   * 軸要素の選択
   * 順に見て、最初に見つかった異なる2つの要素のうち、
   * 大きいほうの番号を返します。
   * 全部同じ要素の場合は -1 を返します。
   */
int find_pivot(int *array, int i, int j)
{
	int k = i + 1;
	while (k <= j && array[i] == array[k])
		k++;
	if (k > j)
		return -1;
	if (array[i] >= array[k])
		return i;
	return k;
}

/*
   * パーティション分割
   * a[i]～a[j]の間で、x を軸として分割します。
   * x より小さい要素は前に、大きい要素はうしろに来ます。
   * 大きい要素の開始番号を返します。
   */
int partition(int *array, int i, int j, int x)
{
	int l = i, r = j;

	// 検索が交差するまで繰り返します
	while (l <= r)
	{

		// 軸要素以上のデータを探します
		while (l <= j && array[l] < x)
			l++;

		// 軸要素未満のデータを探します
		while (r >= i && array[r] >= x)
			r--;

		if (l > r)
			break;
		swap(&array[l], &array[r]);
		// int t = array[l];
		// array[l] = array[r];
		// array[r] = t;
		l++;
		r--;
	}
	return l;
}

/*
   * クイックソート（再帰用）
   * 配列aの、a[i]からa[j]を並べ替えます。
   */
void quick_sort(int *array, int left, int right)
{
	int pivot;

	if (left == right)
		return;
	pivot = find_pivot(array, left, right);
	if (pivot != -1)
	{
		int k = partition(array, left, right, array[pivot]);
		quick_sort(array, left, k - 1);
		quick_sort(array, k, right);
	}
}
