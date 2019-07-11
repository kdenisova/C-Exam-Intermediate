/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 15:01:22 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/11 15:01:24 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2);

struct s_node *create_node(void *content)
{
	struct s_node *node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->content = content;
	node->next = NULL;
	return (node);
}

int main(void)
{
	struct s_node *n1;
	struct s_node *n2;
	struct s_node *n3;
	struct s_node *n4;
	struct s_node *n5;
	struct s_node *n6;
	struct s_node *k1;
	struct s_node *k2;
	struct s_node *in;

	n1 = create_node((void *)1);
	n2 = create_node((void *)2);
	n3 = create_node((void *)3);
	n4 = create_node((void *)4);
	n5 = create_node((void *)5);
	n6 = create_node((void *)6);
	k1 = create_node((void *)7);
	k2 = create_node((void *)8);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	k1->next = k2;
	k2->next = n5;

	in = intersection(n1, k1);
	printf("%d\n", (int)in->content);
    printf("%d\n", (int)n1->content);
	return 0;
}
