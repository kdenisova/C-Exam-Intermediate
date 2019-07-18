/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:32:18 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/18 15:32:20 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int find_len(char *arr, int i, int len)
{
    int od;
    int ev;
    int total;

    od = 0;
    ev = 0;
    total = 0;
    while (i < len)
    {
        if ((arr[i] - '0') % 2 == 0)
            od++;
        else
            ev++;
        if (od == ev)
            total = od + ev;
        i++;
    }
    return (total);
}

char    *longest_subarray(char *arr)
{
	int i;
    int j;
	int max;
	int len;
	int *total;
	char *new;

    if (!arr)
		return (NULL);
	max = 0;
	i = 0;
	len = strlen(arr);
    total = (int *)malloc(sizeof(int) * len);
	while (i < len)
    {
        total[i] = 0;
        i++;
    }
    i = 0;
    while (i < len)
	{
        total[i] = find_len(arr, i, len);
        if (total[i] > max)
            max = total[i];
        i++;
    }
    new = (char *)malloc(sizeof(char) * max + 1);
    new[max] = '\0';
	if (max > 0)
    {
        i = 0;
        while (i < len)
        {
            if (total[i] == max)
                break ;
            i++;
        }
        j = 0;
	    while (j < max && arr[i])
	    {
		    new[j] = arr[i];
		    i++;
		    j++;
	    }
    }
	return (new);
}

int main()
{
    printf("%s\n", longest_subarray("4"));
    return 0;
}
