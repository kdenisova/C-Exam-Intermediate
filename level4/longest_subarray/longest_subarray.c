/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_subarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:39:41 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/18 13:39:43 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char    *longest_subarray(char *arr)
{
	int i;
	int j;
	int max;
	int sum;
	int len;
	int total;
	int index;
	char *new;

	max = 0;
	i = 0;
	if (!arr)
		return (NULL);
	total = strlen(arr);
	while (i < total)
	{
		len = total;
		while (len <= total && len > 0)
		{
			j = i;
		 	sum = 0;
			while (j < len)
			{
				if ((arr[j] - '0') % 2 == 0)
					sum++;
				else
					sum--;
				j++;
			}
			if (sum == 0 && max < len - i)
			{
				max = len - i;
				index = i;
				break ;
			}
			len--;
		}
		i++; 
	}
	new = (char *)malloc(sizeof(char) * max + 1);
	i = 0;
	while (i < max && arr[index])
	{
		new[i] = arr[index];
		i++;
		index++;
	}
	new[i] = '\0';
	return (new);
}
