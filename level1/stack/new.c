#include <stdio.h>
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
	struct s_stack *head;

	head = (struct s_stack *)malloc(sizeof(struct s_stack));
	head->top = NULL;
	return (head);
}

void *pop(struct s_stack *stack)
{
	struct s_node *new;
	void *content;

	if (!stack)
		return (NULL);
	else
	{
		content = stack->top->content;
		new = stack->top;
		stack->top = new->next;
		free(new);
		new = NULL;
	}
	return (content);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node *new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	if (!new)
		return ;
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

void *peek(struct s_stack *stack)
{
	if (!stack)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (!stack->top)
		return (1);
	return (0);
}

int main (void)
{
	struct s_stack *head;

	head = init();
	push(head, (void *)"hello");
	printf("%s\n", (char *)head->top->content);
	push(head, (void *)"apple");
	push(head, (void *)"world");
	printf("%s\n", (char *)head->top->content);
	printf("%s\n", (char *)pop(head));
	printf("%s\n", (char *)peek(head));
	printf("%d\n", isEmpty(head));
	return (0);
}