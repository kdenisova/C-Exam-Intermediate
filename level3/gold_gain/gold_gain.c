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

#include <stdio.h>

int	gold_gain(int **mine, int n)
{
	int i;
	int j;
	int ret;
	int temp;
	
	i = 0;
	ret = 0;
	return (ret);
}

int main(void)
{
	int mine[3][3] = {
		{1, 0, 0},
		{0, 3, 4},
		{0, 0, 0}
	};
	printf("%d\n", gold_gain(mine, 3));
	return (0);
}
