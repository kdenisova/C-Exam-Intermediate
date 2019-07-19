/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   volume_histogram.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:38:11 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/19 11:38:14 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int    volume_histogram(int *histogram, int size)
{
	int i;
	int h;
	int w;
	int left;
	int right;

	i = 0;
	w = 0;
	left = 0;
	right = 0;
	h = size - 1;
	while (i <= h)
	{
		if (histogram[i] < histogram[h])
		{
			if (histogram[i] > left)
				left = histogram[i];
			else
				w = w + (left - histogram[i]);
			i++;
		}
		else
		{
			if (histogram[h] > right)
				right = histogram[h];
			else
				w = w + (right - histogram[h]);
			h--;
		}
	}
	return (w);
}

int main(void)
{
	int	histogram[] = {1, 0, 2, 0, 2};
	int size;

	size = 5;
	printf("%d\n", volume_histogram(histogram, size));
	return 0;
}
