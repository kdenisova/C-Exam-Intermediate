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

void    count_alpha(char *str)
{
    int i;
    int f;
    int al[127] = {0};

    i = 0;
    f = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            al[(unsigned)str[i]]++;
        i++;
    }
    i = 0;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z' && al[(unsigned)str[i]] != 0)
        {
            if (f == 1)
                printf(", %d%c", al[(unsigned)str[i]], str[i]);
            else
            {
                printf("%d%c", al[(unsigned)str[i]], str[i]);
                f = 1;
            }
            al[(unsigned)str[i]] = 0;
        }
        i++;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)
       count_alpha(to_low(argv[1]));
    printf("\n");
    return 0;
}
