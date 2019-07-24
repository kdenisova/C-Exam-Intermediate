/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 11:35:22 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/11 11:35:24 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack *stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	struct s_node *node;
	void *content;

	if (!stack || !stack->top)
		return (NULL);
	content = stack->top->content;
	node = stack->top;
	stack->top = node->next;
	free(node);
	return (content);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *node;

	if (!stack)
		return ;
	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->content = content;
	node->next = stack->top;
	stack->top = node;
}

void *peek(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}
