/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 10:41:14 by kdenisov          #+#    #+#             */
/*   Updated: 2019/04/09 12:04:47 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct	s_node {
		void	*content;
		struct	s_node *next;
};

struct	s_stack {
		struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack *stack;

	stack = malloc(sizeof(*stack));
	stack->top = NULL;
	return (stack);
}

void	*pop(struct s_stack *stack)
{
	struct s_node *node;
	void	*content;

	if (!stack->top)
		return (NULL);
	else
	{
		content = stack->top->content;
		node = stack->top;
		stack->top = node->next;
		free(node);
		node = NULL;
	}
	return (content);
}

void	push(struct s_stack *stack, void *content)
{
	struct s_node *node;
	
	node = malloc(sizeof(node));
	if (!node)
		return ;
	node->content = content;
	node->next = stack->top;
	stack->top = node;
}

void	*peek(struct s_stack *stack)
{
	if (!stack->top)
		return (NULL);
	return (stack->top->content);
}

int		isEmpty(struct s_stack *stack)
{
	if (!stack->top)
		return (1);
	return (0);
}
