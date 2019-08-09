/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 11:46:34 by kdenisov          #+#    #+#             */
/*   Updated: 2019/08/09 11:46:49 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

static int res;

int ft_nbr(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_putnbr(int n)
{
	int				i;
	char c;
	int				buffer[10];
	unsigned int	unb;

	i = 0;
	unb = n;
	while (unb)
	{
		buffer[i] = unb % 10;
		unb = unb / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		c = '0' + buffer[i];
		write(1, &c, 1);
		i--;
	}
}

int ft_atoi(char **str)
{
	int atoi;

	atoi = 0;
	while (ft_nbr(**str))
	{
		atoi = atoi * 10 + **str - '0';
		(*str)++;
	}
	if (**str)
		(*str)++;
	return (atoi);
}

void	find_path(int max, unsigned graph[max][max], unsigned path[max], int y, int len)
{
	int x;

	path[y] = 1;
	x = 0;
	while (x < max)
	{
		if (graph[y][x] && !path[x])
		{
			if (res < len + 1)
				res = len + 1;
			find_path(max, graph, path, x, len + 1);
		}
		x++;
	}
	path[y] = 0;
}

void	create_graph(int max, char *str)
{
	unsigned graph[max][max];
	unsigned path[max];
	int x;
	int y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			graph[y][x] = 0;
			x++;
		}
		y++;
	}
	x = 0;
	while (x < max)
	{
		path[x] = 0;
		x++;
	}
	while (*str)
	{
		y = ft_atoi(&str);
		x = ft_atoi(&str);
		graph[y][x] = 1;
		graph[x][y] = 1;
	}
	res = 2;
	y = 0;
	while (y < max)
	{
		find_path(max, graph, path, y, 1);
		y++;
	}
}

int main(int argc, char *argv[])
{
	int temp;
	int max;
	char *str;

	if (argc == 2)
	{
		max = 0;
		str = &argv[1][0];
		while (*str)
		{
			temp = ft_atoi(&str);
			if (temp > max)
				max = temp;
		}
		max++;
		create_graph(max, &argv[1][0]);
		ft_putnbr(res);
	}
	write(1, "\n", 1);
	return 0;
}

/* Write a programe that takes a string. This string represents a graph and is
composed of series of links between this graph's nodes. Links are separated by
a single space. Nodes are represented by numbers, and links by two nodes
separated by a '-'. For exemple, if there is a link between nodes 2
and 3, it could be written as "2-3" or "3-2".

The program will display the number of nodes comprised in the longest chain,
followed by a '\n', given it's impossible to pass through a node more than once.

If the number of parameters is different from 1, the program displays a '\n'.

Examples:

$>./g_diam "17-5 5-8 8-2 2-8 2-8 17-21 21-2 5-2 2-6 6-14 6-12 12-19 19-14 14-42" | cat -e
10$
$>./g_diam "1-2 2-3 4-5 5-6 6-7 7-8 9-13 13-10 10-2 10-11 11-12 12-8 16-4 16-11 21-8 21-12 18-10 18-13 21-18" | cat -e
15$ */