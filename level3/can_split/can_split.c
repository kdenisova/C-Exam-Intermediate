/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   can_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 10:25:19 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/19 10:25:22 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	find_size(struct s_node *n, int size)
{
	if (n)
	{
		size = find_size(n->left, size) + find_size(n->right, size) + 1;
		n->value = size;
	}
	return (size);
} 

int	check_split(struct s_node *n, int size)
{
	if (!n)
		return (0);
	if (size - n->value == n->value)
		return (1);
	if (check_split(n->left, size))
		return (1);
	if (check_split(n->right, size))
		return (1);
	return (0);
}

int	can_split(struct s_node *n)
{
	int size;
	size = 0;

	if (!n)
		return (0);
	size = find_size(n, size);
	if (size == 0 || size % 2 != 0)
		return (0);
	return (check_split(n, size));
}
