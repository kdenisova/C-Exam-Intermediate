
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long	ft_atoi(char *str)
{
	long at;
	int sign;

	sign = 1;
	at = 0;
	if (*str == '-')
	{
		str++;
		sign = -sign;
	}
	while (*str)
	{
		at = at * 10 + *str - '0';
		str++;
	}
	return (at * sign);
}

void	put_nbr(long nbr)
{
	int temp[20];
	int i;
	char c;

	i = 0;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	while (nbr)
	{
		temp[i] = nbr % 10;
		nbr = nbr / 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		c = '0' + temp[i];
		write(1, &c, 1);
		i--;
	}
}

int main(int argc, char **argv)
{
	long first;
	long second;
	long sum;

	first = ft_atoi(argv[1]);
	second = ft_atoi(argv[2]);
	sum = first + second;
	printf("%ld %ld\n", first, second);
	printf("%ld\n", sum);
	put_nbr(sum);
	write(1, "\n", 1);
	return (0);
}