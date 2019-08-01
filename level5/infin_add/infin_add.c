/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 10:55:13 by exam              #+#    #+#             */
/*   Updated: 2019/07/30 10:55:16 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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

char *rev_str(char *str)
{
	int i;
	int j;
	int len;
	char c;

	i = 0;
	len = ft_strlen(str);
	j =  len - 1;
	while (i < len / 2)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

struct s_inf *init(char *str)
{
	struct s_inf *a;

	a = (struct s_inf *)malloc(sizeof(struct s_inf));
	a->len = ft_strlen(str);
	if (str[0] == '-')
	{
		a->val = (char *)malloc(sizeof(char) * a->len);
		a->val = rev_str(&str[1]);
		a->len--;
		a->sign = 1;
	}
	else
	{
		a->val = (char *)malloc(sizeof(char) * a->len + 1);
		a->val = rev_str(str);
		a->sign = 0;
	}
	return (a);
}	

int ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	add_same(struct s_inf *a, struct s_inf *b)
{
	int i;
	int j;
	int k;
	int temp;
	int sum;
	char *res;

	i = 0;
	j = 0;
	k = 0;
	temp = 0;
	res = (char *)malloc(sizeof(char) * ft_max(a->len, b->len) + 2);
	if (a->sign)
		write(1, "-", 1);
	while (a->val[i] && b->val[j])
	{
		sum = (a->val[i] - '0') + (b->val[j] - '0') + temp;
		if (sum > 9)
		{
			sum = sum - 10;
			temp = 1;
		}
		else
			temp = 0;
		res[k] = sum + '0';
		k++;
		i++;
		j++;
	}
	if (i < a->len)
	{
		if (temp == 1)
		{
			while (temp == 1 && a->val[i])
			{
				sum = (a->val[i] - '0') + temp;
				if (sum > 9)
				{
					sum = sum - 10;
					temp = 1;
				}
				else
					temp = 0;
				res[k] = sum + '0';
				i++;
				k++;
			}
		}
		while (a->val[i])
		{
			res[k] = a->val[i];
			i++;
			k++;
		}
	}
	else if (j < b->len)
	{
		if (temp == 1)
		{
			while (temp == 1 && b->val[j])
			{
				sum = (b->val[j] - '0') + temp;
				if (sum > 9)
				{
					sum = sum - 10;
					temp = 1;
				}
				else
					temp = 0;
				res[k] = sum + '0';

				j++;
				k++;
			}
		}
		while (b->val[j])
		{
			res[k] = b->val[j];
			j++;
			k++;
		}
	}
	if (temp == 1)
	{
		res[k] = '1';
		k++;
	}
	res[k] = '\0';
	res = rev_str(res);
	put_str(res);
}

void	add_dif(struct s_inf *a, struct s_inf *b)
{
	int i;
	int j;
	int k;
	int temp;
	int sum;
	char *res;

	i = 0;
	j = 0;
	k = 0;
	temp = 0;
	res = (char *)malloc(sizeof(char) * a->len + 1);
	if (a->sign)
		write(1, "-", 1);
	while (a->val[i] && b->val[j])
	{
		if ((a->val[i] - '0') - temp >= (b->val[j] - '0'))
		{
			sum = (a->val[i] - '0') - (b->val[j] - '0') - temp;
			temp = 0;
		}
		else
		{
			sum = (a->val[i] - '0') + 10 - temp;
			sum = sum - (b->val[j] - '0');
			temp = 1;
		}
		res[k] = sum + '0';
		k++;
		i++;
		j++;
	}
	if (i < a->len)
	{
		if (temp == 1)
		{
			while (temp == 1 && a->val[i])
			{
				sum = (a->val[i] - '0') - temp;
				if (sum == 0 && i + 1 == a->len)
				{
					i++;
					break ;
				}
				else if (sum < 0)
				{
					sum = 10 + sum;
					temp = 1;
				}
				else 
					temp = 0;
				res[k] = sum + '0';
				i++;
				k++;
			}
		}
		while (a->val[i])
		{
			res[k] = a->val[i];
			i++;
			k++;
		}
	}
	res[k] = '\0';
	res = rev_str(res);
	put_str(res);
}

int main(int argc, char **argv)
{
	struct s_inf *a;
	struct s_inf *b;

	if (argc == 3)
	{
		a = init(argv[1]);
		b = init(argv[2]);
		if (a->sign == b->sign)
			add_same(a, b);
		else if (a->len > b->len)
			add_dif(a, b);
		else
			add_dif(b, a);
		write(1, "\n", 1);
	}
	return (0);
}
