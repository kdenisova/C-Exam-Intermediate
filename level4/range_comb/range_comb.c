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

void	swap(int *arr, int i, int j)
{
	int c;

	c = arr[i];
	arr[i] = arr[j];
	arr[j] = c;
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

int	*permitation(int *num, int n)
{
	int i;
	int j;
	int right;
	int left;

	i = n - 2;
	while (i >= 0 && num[i] > num[i + 1])
		i--;
	if (i < 0)
	{
		printf("return 0\n");
		return (0);
	}
		
	j = n - 1;
	while (num[i] > num[j])
		j--;
	swap(num, i, j);
	left = i + 1;
	right = n - 1;
	while (left < right)
	{
		swap(num, left, right);
		left++;
		right--;
	}
	return (num);
}

void copy_arr(int *dst, int *src, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		i++;
	}
}

int    **range_comb(int n)
{
	int fact;
	int **arr;
	int i;
	int *num;

	fact = ft_fact(n);
	arr = (int **)malloc(sizeof(int *) * fact);
	num = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		num[i] = i;
		i++;
	}
	arr[0] = (int *)malloc(sizeof(int) * n);
	copy_arr(arr[0], num, n);
	i = 1;
	while (i < fact)
	{
		arr[i] = (int *)malloc(sizeof(int) * n);
		copy_arr(arr[i], arr[i - 1], n);
		permitation(arr[i], n);
		i++;
	}
	free(num);
	arr[fact] = NULL;
	return (arr);
}

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

