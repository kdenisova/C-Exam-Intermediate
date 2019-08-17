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

static char c;

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

void	flood_fill(char **arr, int size, int len, int x, int y)
{
	arr[y][x] = c;
	if (y + 1 < size && arr[y + 1][x] == 'X')
		flood_fill(arr, size, len, x, y + 1);
	if (y - 1 >= 0 && arr[y - 1][x] == 'X')
		flood_fill(arr, size, len, x, y - 1);
	if (x + 1 < len && arr[y][x + 1] == 'X')
		flood_fill(arr, size, len, x + 1, y);
	if (x - 1 >= 0 && arr[y][x - 1] == 'X')
		flood_fill(arr, size, len, x - 1, y);
}

void	count_island(char **arr, int size)
{
	int x;
	int y;
	int len;

	c = '0';
	len = 0;
	while (arr[0][len])
		len++;
	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < len)
		{
			if (arr[y][x] == 'X')
			{
				flood_fill(arr, size, len, x, y);
				c++;
			}
			x++;
		}
		y++;
	}
	y = 0;
	while (arr[y])
	{
		ft_putstr(arr[y]);
		y++;
	}
	free(arr);
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
	{
		write(1, "\n", 1);
		return (-1);
	}
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
	close(fd);
	if (ret < 0)
	{
		write(1, "\n", 1);
		return (-1);
	}
	i++;
	arr[i] = NULL;
	count_island(arr, i);
	return (0);
}

int main(int argc, char *argv[])
{
	if (argc == 2)
		create_island(argv[1]);
	else
		write(1, "\n", 1);
	return 0;
}

