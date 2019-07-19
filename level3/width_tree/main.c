
#include <stdio.h>
#include <stdlib.h>

struct s_node
{
    int value;
    struct s_node *left;
    struct s_node *right;
};

int        width_tree(struct s_node *n);

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

	// root = create_node(1);
	// root->left = create_node(2);
	// root->left->left = create_node(3);
	// root->left->right = create_node(4);
	// root->left->right->left = create_node(6);
	// root->right = create_node(5);
	// root->right->left = create_node(7);
	// root->right->right = create_node(8);

	// root = create_node(1);
	// root->left = create_node(2);
	// root->left->left = create_node(4);
	// root->left->left->left = create_node(5);
	// root->left->left->left->right = create_node(8);
	// root->left->left->right = create_node(6);
	// root->left->right = create_node(7);
	// root->left->right->left = create_node(9);
	// root->left->right->left->left = create_node(11);
	// root->left->right->left->right = create_node(12);
	// root->left->right->right = create_node(10);
	// root->left->right->right->right = create_node(13);
	// root->right = create_node(3);

	// root = create_node(10);
	// root->right = create_node(12);

	// root = create_node(25);
	// root->left = create_node(33);
	// root->left->left = create_node(12);
	// root->left->right = create_node(9);
	// root->left->right->left = create_node(4);

	root = create_node(10);

	printf("%d\n", width_tree(root));
	return 0;
}
