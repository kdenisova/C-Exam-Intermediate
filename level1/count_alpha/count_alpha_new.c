/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 11:32:10 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/27 11:32:12 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char    *to_low(char *str)
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

int	count_alpha(char *str, char c)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	met_before(char *str, char c, int k)
{
	int i;

	i = 0;
	while (i < k)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int main(int argv, char **argc)
{
	char *str;
	int i;
	int f;

	i = 0;
	f = 0;
	if (argv == 2)
	{
		str = to_low(argc[1]);
		while (str[i])
		{
			if (f != 0 && str[i] >= 'a' && str[i] <= 'z' && !met_before(str, str[i], i))
				printf(", %d%c", count_alpha(str, str[i]), str[i]);
			else if (str[i] >= 'a' && str[i] <= 'z' && !met_before(str, str[i], i))
			{
				printf("%d%c", count_alpha(str, str[i]), str[i]);
				f = 1;
			}
			i++;
		}
	}
	printf("\n");
	return (0);
}
