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

int	count_nodes(struct s_node *root)
{
	int size;

	if (!root)
		return (0);
	size = count_nodes(root->right) + count_nodes(root->left) + 1;
	root->value = size;
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

	if (!n)
		return (0);
	size = count_nodes(n);
	if (size == 0 || size % 2 == 1)
		return (0);
	return (check_split(n, size));
}
