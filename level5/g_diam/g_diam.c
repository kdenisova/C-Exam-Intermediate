/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_diam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:21:46 by kdenisov          #+#    #+#             */
/*   Updated: 2019/08/12 16:21:48 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int i;
	int buf[10];

	i = 0;
	while (n)
	{
		buf[i] = n % 10;
		n = n / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(buf[i] + '0');
		i--;
	}
}

int ft_atoi(char **str)
{
	int at;

	at = 0;
	while ((**str) >= '0' && (**str) <= '9')
	{
		at = at * 10 + (**str) - '0';
		(*str)++;
	}
	if (**str)
		(*str)++;
	return (at);
}

static int ret;

void find_path(int max, int y, int len, unsigned char grid[max][max], unsigned char path[max])
{
	int x;

	path[y] = 1;
	x = 0;
	while (x < max)
	{
		if (grid[y][x] && !path[x])
		{
			if (ret < len + 1)
				ret = len + 1;
			find_path(max, x, len + 1, grid, path);
		}
		x++;
	}
	path[y] = 0;
}

void	create_graph(char *str, int max)
{
	unsigned char grid[max][max];
	unsigned char path[max];
	int x;
	int y;

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			grid[y][x] = 0;
			x++;
		}
		y++;
	}
	y = 0;
	while (y < max)
	{
		path[y] = 0;
		y++;
	}
	while (*str)
	{
		y = ft_atoi(&str);
		x = ft_atoi(&str);
		grid[y][x] = 1;
		grid[x][y] = 1;
	}
	ret = 2;
	y = 0;
	while (y < max)
	{
		find_path(max, y, 1, grid, path);
		y++;
	}
}

int main(int argc, char **argv)
{
	int max;
	int temp;
	char *str;

	max = 0;
	if (argc == 2)
	{
		str = &argv[1][0];
		while (*str)
		{
			temp = ft_atoi(&str);
			if (temp > max)
				max = temp;
		}
		max++;
		create_graph(&argv[1][0], max);
		ft_putnbr(ret);
	}
	ft_putchar('\n');
	return 0;
}

