/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:02:21 by kdenisov          #+#    #+#             */
/*   Updated: 2019/04/09 12:04:52 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_stack(struct s_stack *stack)//DELETE
{
	struct s_node *temp;
	int				i;

	i = 1;
	if (stack->top == NULL)
		printf("Stack is empty\n");
	else
	{
		temp = stack->top;
		while (temp)
		{
			printf("%d. %s\n", i, (char *)temp->content);
			temp = temp->next;
			i++;
		}
	}
}

int		main(void)//DELETE
{
	struct s_stack *stack;

	stack = init();
	push(stack, (void *)"abc");
	push(stack, (void *)"bcd");
	push(stack, (void *)"cde");
	printf("Stack:\n");
	print_stack(stack);
	printf("Top of stack: %s\n", (char *)peek(stack));
	printf("Deleted node: %s\n", (char *)pop(stack));
	printf("Stack:\n");
	print_stack(stack);
	printf("Top of stack: %s\n", (char *)peek(stack));
	if (isEmpty(stack))
		printf("Stack is empty\n");
	else
		printf("Stack is not empty\n");
	return (0);
}
