/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 14:48:09 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/24 14:48:11 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int i;
	int j;
	int f;

	i = 0;
	j = 0;
	f = 0;
	while (i < na && j < nb)
	{
		if (a[i] == b[j])
		{
			if (f == 1)
				printf(" %d", a[i]);
			else
			{
				printf("%d", a[i]);
				f = 1;
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
