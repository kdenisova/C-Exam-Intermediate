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

#include <stdlib.h>
#include <string.h>

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
	while (nbr)
	{
		f = f * nbr;
		nbr--;
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
		return (0);
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

int    **range_comb(int n)
{
	int fact;
	int **arr;
	int i;

	if (n <= 0)
		return (NULL);
	fact = ft_fact(n);
	arr = (int **)malloc(sizeof(int *) * fact * n);
	arr[0] = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
	{
		arr[0][i] = i;
		i++;
	}
	i = 1;
	while (i < fact)
	{
		arr[i] = (int *)malloc(sizeof(int) * n);
		memcpy(arr[i], arr[i - 1], sizeof(int) * n);
		permitation(arr[i], n);
		i++;
	}
	arr[fact] = NULL;
	return (arr);
}
