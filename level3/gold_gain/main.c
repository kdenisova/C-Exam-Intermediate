/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 12:26:32 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/17 12:26:34 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

int	gold_gain(int **mine, int n);

int main(void)
{
	int i;
	int arr[SIZE][SIZE] = {
		{1, 3, 1, 5},
		{2, 2, 4, 1},
		{5, 0, 2, 3},
		{0, 6, 1, 2}
	};
	int **mine;

	mine =  (int **)malloc(sizeof(int *) * SIZE);
	i = 0;
	while (i < SIZE)
	{
		mine[i] = arr[i];
		i++;
	}	
	printf("%d\n", gold_gain(mine, SIZE));
	return (0);
}
