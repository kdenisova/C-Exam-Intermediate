/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 15:34:54 by kdenisov          #+#    #+#             */
/*   Updated: 2019/08/26 15:34:56 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr(int nbr)
{
	int buf[10];
	int i;

	i = 0;
	while (nbr)
	{
		buf[i] = nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		ft_putchar(buf[i] + '0');
		i--;
	}
}

int     ft_atoi(char **str)
{
	int at;

	at = 0;
	while ((**str) >= '0' && (**str) <= '9')
	{
		at = at * 10 + (**str) - '0';
		(*str)++;
	}
	if ((**str))
		(*str)++;
	return (at);
}

static int ret;

void	find_path(int max, int y, int len, unsigned char diam[max][max], unsigned char path[max])
{
	int x;

	x = 0;
	path[y] = 1;
	while (x < max)
	{
		if (diam[y][x] && !path[x])
		{
			if (ret < len + 1)
				ret = len + 1;
			find_path(max, x, len + 1, diam, path);
		}
		x++;
	}
	path[y] = 0;
}

void    create_giam(char *str, int max)
{
	int x;
	int y;
	unsigned char diam[max][max];
	unsigned char path[max];

	y = 0;
	while (y < max)
	{
		x = 0;
		while (x < max)
		{
			diam[y][x] = 0;
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
		x = ft_atoi(&str);
		y = ft_atoi(&str);
		diam[y][x] = 1;
		diam[x][y] = 1;
	}
	y = 0;
	ret = 2;
	while (y < max)
	{
		find_path(max, y, 1, diam, path);
		y++;
	}
	
}

int main(int argc, char *argv[])
{
	int max;
	int temp;
	char *str;

	if (argc == 2)
	{
		max = 0;
		str = argv[1];
		while (*str)
		{
			temp = ft_atoi(&str);
			if (temp > max)
				max = temp;
		}
		max++;
		create_giam(argv[1], max);
		ft_putnbr(ret);
	}
	write(1, "\n", 1) ;
	return 0;
}

