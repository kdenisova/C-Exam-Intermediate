/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 14:04:59 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/01 14:05:01 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
};

struct s_node *convert_bst(struct s_node *bst);

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
	struct s_node *temp;
	int i;

	i = 0;
	root = create_node(5);
	root->left = create_node(4);
	root->right = create_node(8);
	root->right->left = create_node(7);
	root->right->right = create_node(9);
	root->left->left = create_node(3);
	temp = convert_bst(root);
	while(i < 6)
	{
		printf("%d ", temp->value);
		temp = temp->right;
		i++;
	}
	return (0);
}
