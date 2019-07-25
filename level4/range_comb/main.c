
#include <stdio.h>

void put_arr(int *arr, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		printf("%d ", arr[i]);
		i++;
	}
	printf("\n");
}

int    **range_comb(int n);

int main(void)
{
	int n;
	int i;
	int **arr;

	i = 0;
	n = 5;
	arr = range_comb(n);
	while (arr[i])
	{
		put_arr(arr[i], n);
		i++;
	}
	return 0;
}

//-g -fsanitize=address