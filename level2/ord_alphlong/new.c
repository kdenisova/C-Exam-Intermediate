/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 11:39:10 by kdenisov          #+#    #+#             */
/*   Updated: 2019/08/23 11:39:11 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char ft_tolow(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;
	char a;
	char b;

	i = 0;
	while (s1[i] && s2[i])
	{
		a = ft_tolow(s1[i]);
		b = ft_tolow(s2[i]);
		if (a != b)
			return (a - b);
		i++;
	}
	return (0);
}

int		ft_wordlen(char *str, int i)
{
	int len;

	len = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\t')
	{
		len++;
		i++;
	}
	return (len);
}

void	ft_sort(char **new)
{

}

void	ord_alphlong(char **arr, int size, int len)
{
	int i;
	int j;
	int max;
	int printed;
	int total[size];
	char **new;

	new = (char **)malloc(sizeof(char *) * len);
	printed = 0;
	i = 0;
	while (i <= size)
	{
		total[i] = ft_strlen(arr[i]);
		i++;
	}
	max = total[0];
	while (printed <= size)
	{
		j = 0;
		while (j <= size)
		{
			if (total[j] < max && total[j] != 0)
				max = total[j];
			j++;
		}
		i = 0;
		j = -1;
		while (i <= size)
		{
			if (total[i] == max)
			{
				j++;
				new[j] = (char *)malloc(sizeof(char) * max + 1);
				new[j] = arr[i];
				printed++;
			}
			i++;
		}
		if (j >= 0)
		{
			new[j + 1] = NULL;
			ft_sort(new);
			free(new);
		}
		max++;
	}
}

void	make_arr(char *str)
{
	int i;
	int j;
	int k;
	int len;
	int len1;
	char **arr;

	len1 = ft_strlen(str);
	arr = (char **)malloc(sizeof(char *) * len1);
	i = 0;
	j = -1;
	while (str[i])
	{
		while (str[i] && (str[i] == '\t' || str[i] == ' '))
			i++;
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
		{
			j++;
			len = ft_wordlen(str, i);
			arr[j] = (char *)malloc(sizeof(char) * len + 1);
			k = 0;
			while (str[i] && str[i] != ' ' && str[i] != '\t')
			{
				arr[j][k] = str[i];
				k++;
				i++;
			}
			arr[j][k] = '\0';
		}
	}
	arr[j + 1] = NULL;
	// j = 0;
	// while (arr[j])
	// {
	// 	ft_putstr(arr[j]);
	// 	write(1, "\n", 1);
	// 	j++;
	// }
	ord_alphlong(arr, j, len);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		make_arr(argv[1]);
	else
		write(1, "\n", 1);
	return 0;
}


