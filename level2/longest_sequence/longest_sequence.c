/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   longest_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 12:57:07 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/01 12:57:09 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	travers(struct s_node *node, int len)
{
	int ret;
	int temp;

	temp = 0;
	ret = len;
	if (node->left)
	{
		if (node->left->value - node->value == 1)
			temp = travers(node->left, len + 1);
		else
			temp = travers(node->left, 1);
		if (temp > ret)
			ret = temp;
	}
	if (node->right)
	{
		if (node->right->value - node->value == 1)
			temp = travers(node->right, len + 1);
		else
			temp = travers(node->right, 1);
		if (temp > ret)
			ret = temp;
	}
	return (ret);
}

int	longest_sequence(struct s_node *node)
{
	if (!node)
		return (0);
	return (travers(node, 1));
}
