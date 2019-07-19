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

// void	permitation(int *num, int **arr, int size)
// {
// 	int i;

	
// }


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
		arr[i] = (int *)malloc(sizeof(int) * n);
		i++;
	}
	//permitation(num, arr, fact);
	// i = 0;
	// while (i < fact)
	// {
	// 	put_arr(arr[i], n);
	// 	i++;
	// }
	return (arr);
}

int main(void)
{
	int n;

	n = 3;
	range_comb(n);
	//printf("%d\n", ft_fact(n));
	return 0;
}

