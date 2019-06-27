/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:27:40 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/26 13:27:42 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node {
		int           value;
		struct s_node **nodes;
};

int height_tree(struct s_node *root);

struct s_node *create_node(int value)
{
	struct s_node *node;
	int i;

	i = 0;
	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->value = value;
	node->nodes = malloc(sizeof(node->nodes) * 3);
	while (i < 3)
	{
		node->nodes[i] = NULL;
		i++;
	}
	return (node);
}

int main(void)
{
	struct s_node *root;
	int i;

	i = 0;
	//root = NULL;
	root = create_node(1);
	root->nodes[0] = create_node(3);
	root->nodes[1] = create_node(3);
	root->nodes[0]->nodes[0] = create_node(3);
	root->nodes[0]->nodes[0]->nodes[0] = create_node(54);
	printf("%d\n", root->nodes[0]->nodes[0]->nodes[0]->value);
	printf("%d\n", height_tree(root));
	return (0);
}
