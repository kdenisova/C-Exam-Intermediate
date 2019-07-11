/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:09:21 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/01 15:09:59 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node {
		int           data;
		struct s_node *next;
		struct s_node *other;
};

struct s_node *clone_list(struct s_node *node)
{
	struct s_node *new;

	new = (struct s_node*)malloc(sizeof(*node));
	new = node;
	return (node);
}

struct s_node *create_node(int data)
{
	struct s_node *node;

	node = (struct s_node*)malloc(sizeof(struct s_node));
	node->data = data;
	node->next = NULL;
	node->other = NULL;
	return (node);
}

int main(void)
{
	struct s_node *head;
	struct s_node *n1;
	struct s_node *n2;
	struct s_node *n3;
	struct s_node *temp;
	int i;

	i = 0;
	head = create_node(10);
	n1 = create_node(20);
	n2 = create_node(30);
	n3 = create_node(40);
	head->next = n1;
	n1->next = n2;
	n2->next = n3;
	head->other = n2;
	n1->other = n3;
	n2->other = n1;
	n3->other = n2;
	temp = head;
	while (temp)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	while (i < 4)
	{
		printf("%d ", head->data);
		head = head->other;
		i++;
	}
	return (0);
}