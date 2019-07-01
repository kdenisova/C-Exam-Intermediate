/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:17:20 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/01 13:17:26 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	longest_sequence(struct s_node *node);

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

	//root = NULL;

	// root = create_node(10);
	// root->left = create_node(5);
	// root->left->right = create_node(9);
	// root->left->left = create_node(6);
	// root->left->left->right = create_node(13);
	// root->left->left->left = create_node(7);
	//root->left->left->left->left = create_node(8);

	// root = create_node(5);
	// root->left = create_node(6);
	// root->right = create_node(4);
	// root->right->left = create_node(9);
	// root->right->right = create_node(3);
	// root->right->right->right = create_node(2);
	// root->right->left->left = create_node(3);
	// root->right->left->right = create_node(2);

	root = create_node(30);
	root->left = create_node(15);
	root->right = create_node(41);
	root->right->left = create_node(80);
	root->left->left = create_node(61);
	printf("%d\n", longest_sequence(root));
	return (0);
}
