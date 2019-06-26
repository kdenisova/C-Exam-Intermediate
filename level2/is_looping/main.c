/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 14:09:39 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/26 14:09:42 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node);

struct s_node *create_node(int value)
{
	struct s_node *node;

	node = malloc(sizeof(*node));
	node->value = value;
	node->next = NULL;
	return (node);
}

int main(void)
{
	struct s_node *n1;
	struct s_node *n2;
	struct s_node *n3;
	struct s_node *n4;

	//n1 = NULL; 
	n1 = create_node(1);
	n2 = create_node(2);
	n3 = create_node(3);
	n4 = create_node(4);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n2;
	printf("is looping = %d\n", is_looping(n1));
	return (0);
}
