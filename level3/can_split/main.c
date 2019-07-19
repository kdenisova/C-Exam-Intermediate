/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 11:30:24 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/19 11:30:26 by kdenisov         ###   ########.fr       */
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

int	can_split(struct s_node *n);

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

	//1
	root = create_node(28);
	root->left = create_node(51);
	root->left->left = create_node(26);
	root->left->right = create_node(48);
	root->left->left->left = create_node(76);
	root->left->left->right = create_node(13);

	//0
	// root = create_node(30);
	// root->left = create_node(12);
	// root->left->left = create_node(61);
	// root->right = create_node(41);
	// root->right->left = create_node(80);

	// //1
	// root = create_node(10);
	// root->right = create_node(12);

	//0
	// root = create_node(5);
	// root->left = create_node(1);
	// root->right = create_node(6);
	// root->right->left = create_node(7);
	// root->right->right = create_node(4);
	// root->right->right->right = create_node(8);
	// root->right->left->left = create_node(3);
	// root->right->left->right = create_node(2);
	printf("%d\n", can_split(root));
	return 0;
}
