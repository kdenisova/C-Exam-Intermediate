/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 14:00:58 by kdenisov          #+#    #+#             */
/*   Updated: 2019/08/01 14:01:00 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	put_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char *inf_mult(char *a, char *b, int len1, int len2)
{
	int ia;
	int ib;
	int i;
	int pos;
	int total;
	int *left;
	char *res;
	
	total = len1 + len2;
	left = (int *)malloc(sizeof(int) * total);
	res = (char *)malloc(sizeof(char) * total + 1);
	res[total] = '\0';
	i = 0;
	while (i < total)
	{
		left[i] = 0;
		res[i] = 0;
		i++;
	}
	len1--;
	len2--;
	total--;
	ia = len1;
	pos = 0;
	while (ia >= 0)
	{
		i = total;
		ib = len2;
		while (ib >= 0)
		{
			left[i - pos] = left[i - pos] + (a[ia] - '0') * (b[ib] - '0');
			ib--;
			i--;
		}
		pos++;
		ia--;
	}
	pos = 0;
	while (total >= 0)
	{
		pos = pos + left[total];
		res[total] = '0' + (pos % 10);
		pos = pos / 10;
		total--;
	}
	while (*res == '0')
		res++;
	return (res);
}

int main(int argc, char *argv[])
{
	int s1;
	int s2;
	int len1;
	int len2;
	char *res;

	if (argc == 3)
	{
		len1 = ft_strlen(argv[1]);
		len2 = ft_strlen(argv[2]);
		if (argv[1][0] == '-')
		{
			s1 = -1;
			len1--;
			argv[1]++;
		}
		else
			s1 = 1;
		if (argv[2][0] == '-')
		{
			s2 = -1;
			len2--;
			argv[2]++;
		}
		else
			s2 = 1;
		res = inf_mult(argv[1], argv[2], len1, len2);
		if (*res)
		{
			if ((s1 * s2) < 0)
				write(1, "-", 1);
			put_str(res);
		}
		else
			write(1, "0", 1);
		
		write(1, "\n", 1);
	}
	return 0;
}

