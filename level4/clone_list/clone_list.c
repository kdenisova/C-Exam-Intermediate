/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:36:52 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/24 12:36:54 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

struct s_node *clone_list(struct s_node *node)
{
	struct s_node *head;
	struct s_node *current;
	struct s_node *clone;

	if (!node)
		return (NULL);
	head = node;
	while (head)
	{
		current = head->next;
		head->next = malloc(sizeof(struct s_node));
		head->next->data = head->data;
		head->next->next = current;
		head->next->other = NULL;
		head = current;
	}
	head = node;
	while (head)
	{
		if (head->other)
			head->next->other = head->other->next;
		head = head->next->next;
	}
	clone = NULL;
	head = node;
	while (head)
	{
		if (clone)
		{
			current->next = head->next;
			current = current->next; 
		}
		else
		{
			clone = head->next;
			current = clone;
		}
		head->next = head->next->next;
		head = head->next;
	}
	return (clone);
}
