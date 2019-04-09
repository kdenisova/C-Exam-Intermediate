/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:00:06 by kdenisov          #+#    #+#             */
/*   Updated: 2019/04/09 10:27:03 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_split(int n)
{
	int count;

	count = 0;
	while (n)
	{
		if (n % 10 == 2)
			count++;
		n = n / 10;
	}
	return (count);
}

int	count_of_2(int n)
{
	int i;
	int count;

	if (n <= 1)
		return (0);
	i = 2;
	count = 0;
	while (i <= n)
	{
		count = count + ft_split(i);
		i++;
	}
	return (count);
}
