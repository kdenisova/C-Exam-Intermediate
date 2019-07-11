/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:09:35 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/11 12:09:38 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root)
{
	struct s_node *current;

	if (root)
	{
		reverse_tree(root->left);
		reverse_tree(root->right);
		current = root->left;
		root->left = root->right;
		root->right = current;
	}
}
