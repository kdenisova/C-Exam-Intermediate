/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:13:36 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/24 13:13:42 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node *clone_list(struct s_node *node);

struct s_node *create_node(int data)
{
	struct s_node *node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->data = data;
	node->next = NULL;
	node->other = NULL;
	return (node);
}

void    print_node(struct s_node *node)
{
    int i;

    i = 0;
    while (node)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

int main(void)
{
	struct s_node *n1;
	struct s_node *n2;
	struct s_node *n3;
	struct s_node *n4;
	struct s_node *n5;
    struct s_node *new;

	n1 = create_node(1);
	n2 = create_node(2);
	n3 = create_node(3);
	n4 = create_node(4);
	n5 = create_node(5);
	n1->next = n2;
	n1->other = n4;
	n2->next = n3;
	n2->other = n4;
	n3->next = n4;
	n3->other = n3;
	n4->next = n5;
	n4->other = n1;
	n5->next = NULL;
	n5->other = n3;
    print_node(n1);
    new = clone_list(n1);
    print_node(clone_list(n1));
    printf("%d\n", n1->other->next->other->data);
    printf("%d\n", new->other->next->other->data);
	return 0;
}


