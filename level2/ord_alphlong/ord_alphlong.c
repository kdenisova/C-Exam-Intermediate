/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ord_alphlong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 09:53:41 by exam              #+#    #+#             */
/*   Updated: 2019/07/16 12:03:43 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void put_str(char *str)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

char low(char c)
{
	if (c >= 'A' && c <= 'Z')
		c = c + 32;
	return (c);
}

int ft_strcmp(char *str1, char *str2)
{
	char a;
	char b;

    while (*str1 && *str2)
    {
		a = *str1;
		b = *str2;
		a = low(a);
		b = low(b);
		if (a != b)
			return (a - b);
        str1++;
        str2++;
    }
    return (0);
}

int ft_strlen(char *str)
{
    int len;
    
    len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return (len);
}

int len_w(char *str, int i)
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

void	print_arr(char **arr, int j)
{
	int i;
	int k;
	char *temp;

	i = 0;
	while (i < j)
	{
		k = i + 1;
		while (k < j)
		{
			if(ft_strcmp(arr[k], arr[i]) < 0)
			{
				temp = arr[k];
				arr[k] = arr[i];
				arr[i] = temp;
			}
			k++;
		}
		i++;
	}
	i = 0;
	while (i < j)
	{
		if (i != 0)
			write(1, " ", 1);
		put_str(arr[i]);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_alph(char **arr, int size)
{
	int i;
	int f;
	int min;
	int printed;
	int lenall[size];
	char **new;
	int j;

	i = 0;
	printed = 0;
	while (arr[i])
    {
        lenall[i] = ft_strlen(arr[i]);
        i++;
    }
	i = 0;
	min = lenall[0];
    while (printed < size)
    {
        while (i < size)
        {
            if (lenall[i] < min && lenall[i] != 0)
                min = lenall[i];
			i++;
        }
        i = 0;
		f = 0;
		j = 0;
		new = (char **)malloc(sizeof(char *) * size + 1);
        while (arr[i])
        {
            if (lenall[i] == min)
            {
				new[j] = arr[i];
				f = 1;
                lenall[i] = 0;
                printed++;
				j++;
            }
            i++;
        }
		if (f == 1)
		{
			new[j] = "\0";
			print_arr(new, j);
		}
		free(new);
        min++;
    }
}

void    make_arr(char *str)
{
    char **arr;
    int len;
    int i;
    int j;
    int k;

    len = 0;
    i = 0;
    j = 0;
    arr = (char **)malloc(sizeof(char *) * ft_strlen(str) + 1);
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        if (str[i])
        {
            len = len_w(str, i);
            arr[j] = (char *)malloc(sizeof(char ) * len + 1);
            k = 0;
            while (str[i] && k < len)
            {
                arr[j][k] = str[i];
                k++;
                i++;
            }
            arr[j][k] = '\0';
            j++;
        }
    }
    arr[j] = NULL;
	ft_alph(arr, j);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        make_arr(argv[1]);
    }
    else
        write(1, "\n", 1);
    return (0);
}
