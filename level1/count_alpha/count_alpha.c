/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:46:08 by exam              #+#    #+#             */
/*   Updated: 2019/04/02 11:13:34 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char *ft_tolower(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

int	not_before(char *str, char c, int pos)
{
	int i;

	i = 0;
	while (i < pos)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

void	ft_count(char *str)
{
	
	int i;
	int j;
	int count;
	int flag;
	
	i = 0;
	flag = 0;
	while (str[i] != '\0')
	{
		if (is_alpha(str[i]) && not_before(str, str[i], i))
		{
			j = i;
			count = 0;
			while (str[j] != '\0')
			{	
				if (str[j] == str[i])
					count++;
				j++;
			}
			if (flag != 0)
				printf(", %d%c", count, str[i]);
			else
			{
				printf("%d%c", count, str[i]);
				flag++;
			}
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_count(ft_tolower(argv[1]));
	}
	printf("\n");
	return (0);
}
