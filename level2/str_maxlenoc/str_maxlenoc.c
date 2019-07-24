/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 11:36:15 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/24 11:36:20 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_strncmp(char *s1, char *s2, int len)
{
	int i;

	i = 0;
	while (i < len && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (i == len)
		return (0);
	return (s1[i] - s2[i]);
}

int		find_sub(char *s1, char *s2, int len)
{
	int i;

	i = 0;
	while (s1[i])
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return (1);
		i++;
	}
	return (0);
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
					if (find_sub(argv[i], &argv[1][j], len))
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

