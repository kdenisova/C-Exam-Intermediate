/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anagram.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:25:15 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/25 14:25:17 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_anagram(char *a, char *b)
{
    int *temp[127];
    int i;

    i = 0;
    while (i < 127)
        temp[i++] = 0;
    i = 0;
    while (a[i])
        temp[(unsigned)a[i++]]++;
    i = 0;
    while (b[i])
        temp[(unsigned)b[i++]]--;
    i = 0;
    while (i < 127)
        if (temp[i++] != 0)
            return (0);
    return (1);
}