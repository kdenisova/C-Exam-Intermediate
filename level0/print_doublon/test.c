/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 13:11:15 by kdenisov          #+#    #+#             */
/*   Updated: 2019/04/02 13:18:57 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int i;
	int j;
	int flag;

	i = 0;
	j = 0;
	flag = 0;
	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (flag != 0)
			   printf(" %d", a[i]);
			else
			{
				printf("%d", a[i]);
				flag++;
			}
			i++;
			j++;
		}
		else if (a[i] > b[j])
			j++;
		else
			i++;
	}
	printf("\n");
}

int	main(void)
{
	int a[11] = {-5,  2, 10, 15, 50, 70, 100, 200, 300, 1200, 5000};
	int b[8] = {2,  4,  5,  6,  7, 10,  40,  70};

	print_doublon(a, 11, b, 8);
	return (0);
}
