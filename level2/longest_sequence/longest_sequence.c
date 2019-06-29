#include <stdio.h>
#include <stdlib.h>

struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int	travers(struct s_node *node, int len)
{
	int temp;
	int ret;

	temp = 0;
	ret = len;
	if (node->left)
	{
		if (node->left->value - node->value == 1)
			temp = travers(node->left, ++len);
		else
			temp = travers(node->left, 1);
		if (temp > ret)
			ret = temp;
	}
	if (node->right)
	{
		if (node->right->value - node->value == 1)
			temp = travers(node->right, ++len);
		else
			temp = travers(node->right, 1);
		if (temp > ret)
			ret = temp;
	}
	return (ret);
}

int	longest_sequence(struct s_node *node)
{
	if (!node)
		return (0);
	return (travers(node, 1));
}


struct s_node *create_node(int value)
{
	struct s_node *node;

	node = (struct s_node*)malloc(sizeof(struct s_node));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int main(void)
{
	struct s_node *root;

	// root = NULL;
	// root = create_node(10);
	// root->left = create_node(5);
	// root->left->left = create_node(6);
	// root->left->right = create_node(9);
	// root->left->left->left = create_node(7);
	// root->left->left->right = create_node(13);

	// root = create_node(5);
	// root->left = create_node(6);
	// root->right = create_node(4);
	// root->right->left = create_node(9);
	// root->right->right = create_node(3);
	// root->right->left->left = create_node(3);
	// root->right->left->right = create_node(2);
	// root->right->right->right = create_node(2);

	root = create_node(30);
	root->left = create_node(15);
	root->left->right = create_node(17);
	root->left->right->right = create_node(18);
	root->left->left = create_node(61);
	root->right = create_node(41);
	root->right->left = create_node(80);
	printf("%d\n", longest_sequence(root));
	return (0);
}