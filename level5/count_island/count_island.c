/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:15:50 by kdenisov          #+#    #+#             */
/*   Updated: 2019/08/16 11:15:53 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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

char *ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

int	create_island(char *name)
{
	int i;
	int fd;
	int ret;
	char buf[2];
	char **arr;

	fd = 0;
	arr = (char **)malloc(sizeof(char *) * 1024 * 1024);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	arr[i] = (char *)malloc(sizeof(char) * 1024);
	while ((ret = read(fd, buf, 2)) > 0)
	{
		buf[ret] = '\0';
		if (buf[1] == '\n')
		{
			arr[i] = ft_strjoin(arr[i], buf);
			i++;
			arr[i] = (char *)malloc(sizeof(char) * 1024);
		}
		else
			arr[i] = ft_strjoin(arr[i], buf);
	}
	arr[i + 1] = NULL;
	i = 0;
	while (arr[i])
	{
		ft_putstr(arr[i]);
		i++;
	}
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		create_island(argv[1]);
	write(1, "\n", 1);
	return 0;
}

