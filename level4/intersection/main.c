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


// void print_lst(struct s_node *l)
// {
//     struct s_node *t;

//     t = l;

//     while(t)
//     {
//         printf("%d ", (int)(long long)(t->content));
//         t = t->next;
//     }
//     printf("\n");
// }

// void test2()
// {
// 	struct s_node *res;
//     struct s_node
//     l11 = {(void *)11, 0},
//     l12 = {(void *)12, 0},
//     l13 = {(void *)13, 0},
//     l14 = {(void *)14, 0},
//     l15 = {(void *)15, 0},
//     l21 = {(void *)21, 0},
//     l22 = {(void *)22, 0};

//     l11.next = &l12,
//     l12.next = &l13,
//     l13.next = &l14,
//     l14.next = &l15,

//     l21.next = &l22;

//     print_lst(&l11);
//     print_lst(&l21);
// 	res = intersection(&l11, &l21);
//     printf ("test 2 no %d\n", (int)res);
// }

// int main()
// {
//    // test1();
//     test2();
// 	//test0();
//     return (0);
// }