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
	int size;

	i = 0;
	size = 5;
	node = malloc(sizeof(*node));
	node->value = value;
	node->nodes = malloc(sizeof(*node->nodes) * size);
	while (i < size)
	{
		node->nodes[i] = 0;
		i++;
	}
	return (node);
}

int main(void)
{
	struct s_node *root;
	int i;
	int size;
	
	i = 0;
	size = 4;
	root = create_node(1);
	while (i < size)
	{
		root->nodes[i] = create_node(i + 1);
		i++;
	}
	root->nodes[0]->nodes[0] = create_node(27);
	root->nodes[0]->nodes[1] = create_node(30);
	//root->nodes[0]->nodes[1]->nodes[0] = create_node(10);
	printf("height = %d\n", height_tree(root));
	return (0);
}
