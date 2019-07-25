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

#include <string.h>
#include <stdlib.h>

int find_len(char *str, int i)
{
    int len;
    int ev;
    int od;
    
    ev = 0;
    od = 0;
    len = 0;
    while (str[i])
    {
        if ((str[i] - '0') % 2 == 0)
            ev++;
        else
            od++;
        if (ev == od)
            len = ev + od;
        i++;
    }
    return (len);
}

char    *longest_subarray(char *arr)
{
    int i;
    int max;
    int pos;
    int *total;
    char *new;

    if (!arr)
        return (NULL);
    total = (int *)malloc(sizeof(int) * strlen(arr));
    i = 0;
    max = 0;
    while (arr[i])
    {
        total[i] = find_len(arr, i);
        if (total[i] > max)
        {
            max = total[i];
            pos = i;
        } 
        i++;
    }
    i = 0;
    new = (char *)malloc(sizeof(char) * max + 1);
    while (i < max)
    {
        new[i] = arr[pos];
        i++;
        pos++;
    }
    new[max] = '\0';
    free(total);
    return (new);
}
