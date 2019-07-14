
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "infin_add.h"

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

char *strrev(char *str)
{
	int size;
	char *temp;
	char *rev;
	char c;
	
	size = ft_strlen(str);
	temp = str;
	rev = temp + size - 1;
	while (temp < rev)
	{
		c = *temp;
		*temp = *rev;
		*rev = c;
		temp++;
		rev--;
	}
	return (str);
}

void create_arr(t_arr *arr, char *str, int len)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(str);
	if (str[size - 1] == '-')
	{
		arr->sign = 1;
		str[size - 1] = '\0';
	}	
	else
		arr->sign = 0;
	arr->arr = (int *)malloc(sizeof(int) * len - arr->sign);
	while (str[i])
	{
		arr->arr[i] = str[i] - '0';
		i++;
	}
	while (i < len)
	{
		arr->arr[i] = 0;
		i++;
	}
}

char *infin_add(t_arr *a, t_arr *b, int size)
{
	int temp;
	int res;
	int flag;
	int i;
	char *new;

	i = 0;
	temp = 0;
	flag = 1;
	new = (char *)malloc(sizeof(char) * size + 2);
	while (i < size)
	{
		if (a->arr[i] && b->arr[i])
			res = a->arr[i] + b->arr[i] + temp;
		else if (a->arr[i])
			res = a->arr[i] + temp;
		else if (b->arr[i])
			res = b->arr[i] + temp;
		if (res >= 10)
		{
			res = res - 10;
			temp = 1;
		}
		else if (temp != 1 && flag == 1 && (i == a->len - 1 || i == b->len - 1))
		{
			temp = 0;
			flag = 0;
		}
		else
			temp = 0;
			
		new[i] = res + '0';
		i++;
	}
	if (temp == 1)
	{
		new[i] = 1 + '0';
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	print_new(char *str, t_arr *a, t_arr *b)
{
	int i;

	i = ft_strlen(str);
	i--;
	if (a->sign == 1 && b->sign == 1)
		write(1, "-", 1);
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	t_arr a;
	t_arr b;
	int len1;
	int len2;
	int size;
	char *result;
	
	len1 = ft_strlen(argv[1]);
	len2 = ft_strlen(argv[2]);
	if (len1 > len2)
		size = len1;
	else
		size = len2;
	create_arr(&a, strrev(argv[1]), size);
	a.len = len1 - a.sign;
	create_arr(&b, strrev(argv[2]), size);
	b.len = len2 - b.sign;
	if (a.sign == 0 && b.sign == 0)
		result = infin_add(&a, &b, size);
	else if (a.sign == 1 || b.sign == 1)
		result = infin_add(&a, &b, size - 1);
	print_new(result, &a, &b);
	return (0);
}