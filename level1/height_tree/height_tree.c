/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:54:46 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/26 12:54:49 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
		int           value;
		struct s_node **nodes;
};

int height_tree(struct s_node *root)
{
	int h;
	int i;
	int temp;

	h = 0;
	i = 0;
	if (!root)
		return (-1);
	while (root->nodes[i])
	{
		temp = 1 + height_tree(root->nodes[i]);
		if (temp > h)
			h = temp;
		i++;
	}
	return (h);
}
