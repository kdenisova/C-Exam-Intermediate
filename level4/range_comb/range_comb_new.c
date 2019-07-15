/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range_comb_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:04:27 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/15 15:04:29 by kdenisov         ###   ########.fr       */
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

void	permitation(int **arr, int *temp, int *tab, int n, int pos)
{
	int i;
    int j;
    static int nbr;

	if (pos == n)
	{
		i = 0;
        while (i < n)
        {
            arr[nbr][i] = temp[i];
            i++;
        }
        nbr++;
	}
	else
    {
        j = 0;
        while (j < n)
        {
            if (!tab[j])
            {
                temp[pos] = j;
                tab[j] = 1;
                permitation(arr, temp, tab, n, pos + 1);
                tab[j] = 0;
            }
            j++;
        }
    }
}

int    **range_comb(int n)
{
	int fact;
	int i;
	int **arr;
    int tab[n];
    int temp[n];

    if (n < 1)
        return (0);
	i = 0;
	fact = ft_fact(n);
	arr = (int **)malloc(sizeof(int *) * fact);
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
	arr[fact] = NULL;
    i = 0;
	while (i < fact)
	{
		arr[i] = (int *)malloc(sizeof(int) * n);
		i++;
	}
    permitation(arr, temp, tab, n, 0);
	return (arr);
}

int main(void)
{
	int n;
    int i;
    int fact;
    int **arr;

	n = 3;
	arr = range_comb(n);
    i = 0;
    fact = ft_fact(n);
	while (i < fact)
	{
		put_arr(arr[i], n);
		i++;
	}
	return 0;
}
