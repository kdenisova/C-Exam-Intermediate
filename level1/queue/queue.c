#include <stdio.h>
#include <stdlib.h>

struct s_node {
	void *content;
	struct s_node *next;
};

struct s_queue {
	struct s_node *first;
	struct s_node *last;
};

struct s_queue *init(void)
{
	struct s_queue *queue;

	queue = (struct s_queue*)malloc(sizeof(struct s_queue));
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->content = content;
	node->next = NULL;
	if (!queue->first)
		queue->first = node;
	else
		queue->last->next = node;
	queue->last = node;
}

void *dequeue(struct s_queue *queue)
{
	struct s_node *node;
	void *content;

	if (!queue || !queue->first)
		return (NULL);
	// if (queue->first == queue->last)
	// 	queue->last = NULL;
	content = queue->first->content;
	node = queue->first;
	queue->first = node->next;
	free(node);
	return (content);
}

void *peek(struct s_queue *queue)
{
	if (!queue->first)
		return (NULL);
	return (queue->first->content);
}

int isEmpty(struct s_queue *queue)
{
	if (!queue->first)
		return (1);
	return (0);
}

int main (void)
{
	struct s_queue *queue;

	queue = init();
	enqueue(queue, (void *)"hello");
	printf("%s\n", (char *)queue->last->content);
	enqueue(queue, (void *)"world");
	enqueue(queue, (void *)"cat");
	printf("%s\n", (char *)queue->last->content);
	printf("%s\n", (char *)dequeue(queue));
	printf("%s\n", (char *)queue->first->content);
	printf("%s\n", (char *)peek(queue));
	printf("%d\n", isEmpty(queue));
	return (0);
}