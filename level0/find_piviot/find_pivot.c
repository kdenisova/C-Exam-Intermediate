/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:21:34 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/27 15:21:37 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int sum_all(int *arr, int n)
{
    int sum;
    int i;

    sum = 0;
    i = 2;
    while (i < n)
    {
        sum += arr[i];
        i++;
    }
    return (sum);
}

int	find_pivot(int *arr, int n)
{
    int i;
    int sum;
    int sumarr;

    i = 1;
    sum = arr[0];
    sumarr = sum_all(arr, n);
    while (i < n - 1)
    {
        if (sum == sumarr)
            return (i);
        else
        {
            sum = sum + arr[i];
            sumarr = sumarr - arr[i + 1];
        }
        i++;
    }
    return (-1);
}
