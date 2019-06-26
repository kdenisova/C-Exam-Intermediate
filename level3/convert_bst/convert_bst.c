/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:43:02 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/26 14:43:04 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
};

struct s_node *left_bst(struct s_node *root)
{
	while (root->left)
		root = root->left;
	return (root);
}

struct s_node *right_bst(struct s_node *root)
{
	while (root->right)
		root = root->right;
	return (root);
}

void  traversal_bst(struct s_node *bst, struct s_node *head, struct s_node *tail)
{
	static struct s_node *current;

	if (bst)
	{
		if (bst != head)
			traversal_bst(bst->left, head, tail);
		if (current)
		{
			current->right = bst;
			bst->left = current;
		}
		current = bst;
		if (bst != tail)
			traversal_bst(bst->right, head, tail);
	}
}

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *head;
	struct s_node *tail;

	if (!bst)
		return (0);
	head = left_bst(bst->left);
	tail = right_bst(bst->right);
	head->left = tail;
	tail->right = head;
	traversal_bst(bst, head, tail);
	return (head);
}

struct s_node *create_node(int value)
{
	struct s_node *node;

	node = (struct s_node*)malloc(sizeof(struct s_node));
	node->value = value;
	node->left = 0;
	node->right = 0;
	return (node);
}

int main(void)
{
	struct s_node *root;
	struct s_node *l1;
	int i;

	i = 0;
	root = create_node(20);
	root->left = create_node(15);
	root->left->left = create_node(10);
	root->right = create_node(25);
	root->right->right = create_node(35);
	root->right->left = create_node(21);
	l1 = convert_bst(root);
	while (i < 6)
	{
		printf("%d ", l1->value);
		l1 = l1->right;
		i++;
	}
	return (0);
}
