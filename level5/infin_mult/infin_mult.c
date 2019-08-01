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
#include <stdio.h>

struct s_inf
{
	int len;
	int sign;
	char *val;
};

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

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

struct s_inf *init(char *str)
{
	struct s_inf *a;

	a = (struct s_inf *)malloc(sizeof(struct s_inf));
	a->len = ft_strlen(str);
	if (str[0] == '-')
	{
		a->val = (char *)malloc(sizeof(char) * a->len);
		a->val = &str[1];
		a->len--;
		a->sign = 1;
	}
	else
	{
		a->val = (char *)malloc(sizeof(char) * a->len + 1);
		a->val = str;
		a->sign = 0;
	}
	return (a);
}

char *inf_mult(struct s_inf *a, struct s_inf *b)
{
	int i;
	int j;
	int pos;
	int left;
	int *temp;
	int total;
	char *res;
	
	total = a->len + b->len;
	temp = (int *)malloc(sizeof(int) * total);
	res = (char *)malloc(sizeof(char) * total + 1);
	res[total] = '\0';
	i = 0;
	while (i < total)
	{
		res[i] = 0;
		temp[i] = 0;
		i++;
	}
	pos = 0;
	a->len--;
	b->len--;
	total--;
	while (a->len >= 0)
	{
		i = total;
		j = b->len;
		while (j >= 0)
		{
			temp[i - pos] = temp[i - pos] + (a->val[a->len] - '0') * (b->val[j] - '0');
			i--;
			j--;
		}
		pos++;
		a->len--;
	}
	i = total;
	left = 0;
	while (i >= 0)
	{
		j = temp[i] + left;
		res[i] = j % 10 + '0';
		left = j / 10;
		i--;
	}
	while (*res == '0')
		res++;
	return (res);
}

int main(int argc, char **argv)
{
	struct s_inf *a;
	struct s_inf *b;
	char *res;

	if (argc == 3)
	{
		a = init(argv[1]);
		b = init(argv[2]);
		res = inf_mult(a, b);
		if (*res && ((!a->sign && b->sign) || (a->sign && !b->sign)))
			write(1, "-", 1);
		if (*res)
			put_str(res);
		else
			write(1, "0", 1);
		write(1, "\n", 1);
	}
	return (0);
}
