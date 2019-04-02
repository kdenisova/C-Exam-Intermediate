/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:07:04 by exam              #+#    #+#             */
/*   Updated: 2019/04/02 12:43:56 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Works, but need to find an optimized solution*/

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int i;
	int j;
	int flag;

	i = 0;
	flag = 0;
	while (i < na)
	{
		j = 0;
		while (j < nb - 1 && a[i] != b[j])
			j++;
		if (a[i] == b[j])
		{
			if (flag != 0)
				printf(" %d", a[i]);
			else
			{
				printf("%d", a[i]);
				flag++;
			}
		}
		i++;
	}
	printf("\n");
}
