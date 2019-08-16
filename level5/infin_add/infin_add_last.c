/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infin_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 10:44:38 by exam              #+#    #+#             */
/*   Updated: 2019/08/13 10:44:39 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void inf_diff(char *a, char *b, int len1, int len2, int s1)
{
	int i;
	int sum;
	int temp;
	int total;
	char *new;
	
	total = len1 + 2;
	new = (char *)malloc(sizeof(char) * total);
	new[total] = '\0';
	i = 0;
	while (i < total)
	{
		new[i] = 0;
		i++;
	}
	temp = 0;
	len1--;
	len2--;
	while (len1 >=0 && len2 >= 0)
	{
		total--;
		if (((a[len1] - '0') - (b[len2] - '0') - temp) < 0)
		{
			sum = (10 + (a[len1] - '0')) - (b[len2] - '0') - temp;
			temp = 1;
		}
		else
		{
			sum = (a[len1] - '0') - (b[len2] - '0') - temp;
			temp = 0;
		}
		new[total] = sum + '0';
		len1--;
		len2--;
	}
	if (len1 >= 0)
	{
		while (len1 >= 0)
		{
			total--;
			if (((a[len1] - '0') - temp) < 0)
			{
				sum = (10 + (a[len1] - '0')) - temp;
				temp = 1;
			}
			else
			{
				sum = (a[len1] - '0') - temp;
				temp = 0;
			}
			new[total] = sum + '0';
			len1--;
		}
	}
	while (new[total] == '0')
	 	total++;
	if (new[total])
	{
		if (s1 < 0 )
			write(1, "-", 1);
		ft_putstr(&new[total]);
	}
	else
		write(1, "0", 1);
}
char *inf_add(char *a, char *b, int len1, int len2)
{
	int i;
	int sum;
	int temp;
	int total;
	char *new;
	
	total = len1 + 2;
	new = (char *)malloc(sizeof(char) * total);
	new[total] = '\0';
	i = 0;
	while (i < total)
	{
		new[i] = 0;
		i++;
	}
	temp = 0;
	len1--;
	len2--;
	while (len1 >=0 && len2 >= 0)
	{
		total--;
		sum = temp + (a[len1] - '0') + (b[len2] - '0');
		if (sum >= 10)
		{
			temp = 1;
			sum = sum - 10;
		}
		else
			temp = 0;
		new[total] = sum + '0';
		len1--;
		len2--;
	}
	if (len1 >= 0)
	{
		while (len1 >= 0)
		{
			total--;
			sum = temp + (a[len1] - '0');
			if (sum >= 10)
			{
				temp = 1;
				sum = sum - 10;
			}
			else
				temp = 0;
			new[total] = sum + '0';
			len1--;
		}
	}
	if (temp == 1)
	{
		total--;
		new[total] = '1';
	}
	return (&new[total]);
}

int		main(int argc, char **argv)
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
		if (s1 == s2)
		{
			if (len1 > len2)
				res = inf_add(argv[1], argv[2], len1, len2);
			else
				res = inf_add(argv[2], argv[1], len2, len1);
			if (s1 < 0)
				write(1, "-", 1);
			ft_putstr(res);
		}
		else
		{
			if (len1 > len2)
				inf_diff(argv[1], argv[2], len1, len2, s1);
			else
				inf_diff(argv[2], argv[1], len2, len1, s2);
		}
		write(1, "\n", 1);
	}
	
	return (0);
}
