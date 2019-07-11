/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 10:56:29 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/01 10:56:31 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *to_low(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    return (str);
}

int     met_before(char *str, char c, int pos)
{
    int i;

    i = 0;
    while (i < pos)
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int    count_alpha(char *str, char c)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == c)
            count++;
        i++;
    }
    return (count);
}

int main (int argv, char **argc)
{
    int i;
    int f;
    char *str;

    i = 0;
    f = 0;
    if (argv == 2)
    {
        str = to_low(argc[1]);
        while (str[i])
        {
            if (str[i] >= 'a' && str[i] <= 'z' && !met_before(str, str[i], i))
            {
                if (f != 0)
                    printf(", %d%c", count_alpha(str, str[i]), str[i]);
                else
                {
                    printf("%d%c", count_alpha(str, str[i]), str[i]);
                    f = 1;
                }
            }
            i++;
        }
    }
    printf("\n");
    return (0);
}

