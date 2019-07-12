
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

int *create_arr(char *str, int len)
{
	int *a;
	int i;

	i = 0;
	a = (int *)malloc(sizeof(int) * len);
	while (str[i])
	{
		a[i] = str[i] - '0';
		i++;
	}
	while (i < len)
	{
		a[i] = 0;
		i++;
	}
	return (a);
}

int main(int argc, char **argv)
{
	int *a;
	int *b;
	int i;
	int len1;
	int len2;
	int size;
	int temp;
	int res;
	char *new;

	i = 0;
	temp = 0;
	len1 = ft_strlen(argv[1]);
	len2 = ft_strlen(argv[2]);
	if (len1 > len2)
		size = len1;
	else
		size = len2;
	a = create_arr(strrev(argv[1]), size);
	b = create_arr(strrev(argv[2]), size);
	new = (char *)malloc(sizeof(char) * size + 2);
	while (i < size)
	{
		if (a[i] && b[i])
			res = a[i] + b[i] + temp;
		else if (a[i])
			res = a[i] + temp;
		else if (b[i])
			res = b[i] + temp;
		if (res >= 10)
		{
			res = res - 10;
			temp = 1;
		}
		else
 			temp = 0;
		new[i] = res + '0';	
		i++;
	}
	// if (temp == 1)
	// {
	// 	new[i] = 1;
	// 	i++;
	// }
	new[i] = '\0';
	i--;
	while (i >= 0)
	{
		write(1, &new[i], 1);
		i--;
	}
	write(1, "\n", 1);
	return (0);
}