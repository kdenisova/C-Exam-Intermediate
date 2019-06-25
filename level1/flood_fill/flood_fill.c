#include "flood_fill.h"
#include <stdio.h>//DELETE
#include <stdlib.h>//DELETE

void	print_flood(char **tab, t_point size)//DELETE
{
	int i;
	int j;

	j = 0;
	while (j < size.y)
	{
		i = 0;
		while (i < size.x)
		{
			printf("%c ", tab[j][i]);
			i++;
		}
		printf("\n");
		j++;
	}
}

char	**make_area(char *zone[])//DELETE
{
	int i;
	int j;
	int k;
	char **area;

	i = 0;
	area = (char **)malloc(sizeof(char *) * 5 * 8);
	while (zone[i])
	{
		j = 0;
		k = 0;
		area[i] = (char *)malloc(sizeof(char) * 8 + 1);
		while (zone[i][j] != '\0')
		{
			if (zone[i][j] != ' ')
			{
				area[i][k] = zone[i][j];
				k++;
			}
			j++;
		}
		i++;
	}
	return (area);
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c;

	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	if (begin.y - 1 > 0 && tab[begin.y - 1][begin.x] == c)
		flood_fill(tab, size, (t_point){begin.x, begin.y - 1});
	if (begin.y + 1 < size.y && tab[begin.y + 1][begin.x] == c)
		flood_fill(tab, size, (t_point){begin.x, begin.y + 1});
	if (begin.x - 1 > 0 && tab[begin.y][begin.x - 1] == c)
		flood_fill(tab, size, (t_point){begin.x - 1, begin.y});
	if (begin.x + 1 < size.x && tab[begin.y][begin.x + 1] == c)
		flood_fill(tab, size, (t_point){begin.x + 1, begin.y});
}

int main(void)//DELETE
{
	t_point size = {8, 5};
	t_point begin = {2, 2};
	char **area;
	char *zone[] = {
						"1 1 1 1 1 1 1 1",
						"1 0 0 0 1 0 0 1",
						"1 0 0 0 0 0 0 1",
						"1 0 1 1 0 0 0 1",
						"1 1 1 0 0 0 0 1",
	};

	area = make_area(zone);
	print_flood(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_flood(area, size);
	return (0);
}
