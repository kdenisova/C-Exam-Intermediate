/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:35:28 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/27 14:35:29 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
};

void perimeter(struct s_node *root);

struct s_node *create_node(int value)
{
	struct s_node *node;

	node = (struct s_node*)malloc(sizeof(struct s_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int main(void)
{
	struct s_node *root;

	root = create_node(92);
	root->left = create_node(85);
	root->left->left = create_node(79);
	root->left->left->right = create_node(10);
	root->left->left->right->left = create_node(39);
	root->left->left->right->left->left = create_node(35);
	root->left->left->right->left->left->left = create_node(96);
	root->right = create_node(26);
	root->right->right = create_node(64);
	root->right->right->left = create_node(40);
	root->right->right->left->left = create_node(88);
	root->right->right->left->left->left = create_node(12);
	root->right->right->left->left->left->left = create_node(58);
	root->right->right->left->left->right = create_node(55);
	root->right->right->left->left->right->left = create_node(58);
	root->right->right->left->left->right->right = create_node(41);
	root->right->right->left->right = create_node(10);
	root->right->right->left->right->left = create_node(52);
	root->right->right->left->right->left->left = create_node(22);
	root->right->right->left->right->left->right = create_node(35);
	root->right->right->left->right->right = create_node(87);
	root->right->right->left->right->right->right = create_node(31);
	root->right->right->right = create_node(78);
	root->right->right->right->left = create_node(2);
	root->right->right->right->left->left = create_node(33);
	root->right->right->right->left->left->right = create_node(55);
	root->right->right->right->left->right = create_node(11);
	root->right->right->right->left->right->left = create_node(99);
	root->right->right->right->right = create_node(85);
	root->right->right->right->right->right = create_node(51);
	perimeter(root);
	return (0);
}
