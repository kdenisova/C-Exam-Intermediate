
#include <stdio.h>
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
	struct s_node *copy;

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
	copy = NULL;
	head = node;
	while (head)
	{
		if (copy)
		{
			current->next = head->next;
			current = current->next; 
		}
		else
		{
			copy = head->next;
			current = copy;
		}
		head->next = head->next->next;
		head = head->next;
	}
	return (copy);
}

struct s_node *create_node(int data)
{
	struct s_node *node;

	node = (struct s_node *)malloc(sizeof(struct s_node));
	node->data = data;
	node->next = NULL;
	node->other = NULL;
	return (node);
}

int main(void)
{
	struct s_node *n1;
	struct s_node *n2;
	struct s_node *n3;
	struct s_node *n4;
	struct s_node *n5;

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
	n4->other = n2;
	n5->next = NULL;
	n5->other = n3;
	return 0;
}
