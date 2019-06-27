/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:48:22 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/27 13:48:26 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
};

void put_left(struct s_node *root)
{
	if (root->left || root->right)
		printf(" %d", root->value);
	if (root->left)
		put_left(root->left);
}

void put_right(struct s_node *root)
{
	if (root->right)
		put_right(root->right);
	if (root->left || root->right)
		printf(" %d", root->value);
}

void put_leaf(struct s_node *root)
{
	if (root->left)
		put_leaf(root->left);
	if (root->right)
		put_leaf(root->right);
	if (!root->left && !root->right)
		printf(" %d", root->value);
}

void perimeter(struct s_node *root)
{
	if (!root)
		return ;
	printf("%d", root->value);
	if (root->left)
	{
		put_left(root->left);
		put_leaf(root->left);
	}
	if (root->right)
	{
		put_leaf(root->right);
		put_right(root->right);
	}
	printf("\n");
}
