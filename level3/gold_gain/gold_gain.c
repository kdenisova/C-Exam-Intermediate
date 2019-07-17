/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gold_gain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 14:08:30 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/16 14:08:31 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	gold_gain(int **mine, int n)
{
	int i;
	int j;
	int max;
	int temp;
	
	max = 0;
	j = 1;
	while (j < n)
	{
		i = 0;
		while (i <= n - 1)
		{
			if (i == 0)
				mine[i][j] = mine[i][j] + ft_max(mine[i][j - 1], mine[i + 1][j - 1]);
			else if (i == n - 1)
				mine[i][j] = mine[i][j] + ft_max(mine[i][j - 1], mine[i - 1][j - 1]);
			else
			{
				temp = ft_max(mine[i + 1][j - 1], mine[i][j - 1]);
				mine[i][j] = mine[i][j] + ft_max(temp, mine[i - 1][j - 1]);
			}
			i++;
		}
		j++;
	}
	i = 0;
	while (i < n)
	{
		if (mine[i][n - 1] > max)
			max = mine[i][n - 1];
		i++;
	}
	return (max);
}
