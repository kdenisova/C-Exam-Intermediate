/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 13:57:03 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/17 13:57:05 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int ft_strncmp(char *str1, char *str2, int len)
{
	int i;

	i = 0;
	while (i < len && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	if (i == len)
		return (0);
	return (str1[i] - str2[i]);
}

int	find_substr(char *str, char *sub, int len)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_strncmp(str + i, sub, len) == 0)
			return (1);
		i++;
	}
	return (0);
}

void	put_str(char *str, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

int main(int argc, char *argv[])
{
	int i;
	int j;
	int len;
	int total;
	
	if (argc > 2)
	{
		len = ft_strlen(argv[1]);
		total = len;
		while (len > 0)
		{
			j = 0;
			while (j + len <= total)
			{
				i = 2;
				while (i < argc)
				{
					if (find_substr(argv[i], &argv[1][j], len))
					i++;
				else
					break ;
				}
				if (i == argc)
				{
					put_str(&argv[1][j], len);
					write(1, "\n", 1);
					return (0);
				}	
				j++;
			}
			len--;
		}
	}
	else if (argc == 2)
		put_str(argv[1], ft_strlen(argv[1]));
	write(1, "\n", 1);
	return 0;
}
