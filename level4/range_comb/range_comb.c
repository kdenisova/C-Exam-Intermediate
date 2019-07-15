/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_comb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 13:00:54 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/15 13:00:56 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// void	swap(int *arr, int i, int j)
// {
// 	int c;

// 	c = arr[i];
// 	arr[i] = arr[j];
// 	arr[j] = c;
// 	//put_arr(arr, 2);
// 	//return (arr);
// }

void	swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

int		ft_fact(int nbr)
{
	int f;

	f = 1;
	if (nbr > 12 || nbr < 0)
		return (0);
	else
	{
		while (nbr)
		{
			f = f * nbr;
			nbr--;
		}
	}
	return (f);
}

void	fill_arr(int *ar1, int *ar2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ar2[i] = ar1[i];
		i++;
	}
}

void	permitation(int *arr, int size, int n)
{
	int i;

	if (size == 1)
		return ;
	i = 0;
	while (i < size)
	{
		permitation(arr, size - 1, n);
		if (size % 2 == 0)
				swap(&arr[0], &arr[n - 1]);
			else
				swap(&arr[i], &arr[n - 1]);
		i++;
	}
}

int    **range_comb(int n)
{
	int fact;
	int i;
	int j;
	int k;
	int nbr;
	int **arr;

	i = 0;
	k = 2;
	fact = ft_fact(n);
	arr = (int **)malloc(sizeof(int *) * fact);
	arr[0] = (int *)malloc(sizeof(int) * n);
	while (i < n)
	{
		arr[0][i] = i;
		i++;
	}
	i = 1;
	while (i < fact)
	{
		arr[i] = (int *)malloc(sizeof(int) * n);
		j = 0;
		fill_arr(arr[i - 1], arr[i], n);
		nbr = 1;
		//permitation(arr[i], n, n);
		while (j < n)
		{
				if (nbr % 2 == 0)
					swap(&arr[i][0], &arr[i][n - 1]);
				else
					swap(&arr[i][j], &arr[i][n - 1]);
			nbr++;
			j++;
		}
		
		i++;
	}
	i = 0;
	while (i < fact)
	{
		put_arr(arr[i], n);
		i++;
	}
	return (arr);
}

void heapPermutation(int a[], int size, int n) 
{ 
    // if size becomes 1 then prints the obtained 
    // permutation 
    if (size == 1) 
    { 
        put_arr(a, n); 
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heapPermutation(a,size-1,n); 
  
        // if size is odd, swap first and last 
        // element 
        if (size%2==1) 
            swap(&a[0], &a[size-1]); 
  
        // If size is even, swap ith and last 
        // element 
        else
            swap(&a[i], &a[size-1]); 
    } 
} 

int main(void)
{
	int n;

	n = 3;
	//heapPermutation(a, n, n);
	range_comb(n);
	//printf("%d\n", ft_fact(n));
	return 0;
}

