
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

int main()
{
	struct s_node *root;
	struct s_node *root2;
	struct s_node *root3;
	struct s_node *root4;
	struct s_node *root5;

	root = create_node(1);
	root->right = create_node(5);
	root->right->left = create_node(7);
	root->right->right = create_node(8);
	root->left = create_node(2);
	root->left->left = create_node(3);
	root->left->right = create_node(4);
	root->left->right->left = create_node(6);
	printf("%d\n", width_tree(root));

	root2 = create_node(1);
	root2->right = create_node(3);
	root2->left = create_node(2);
	root2->left->left = create_node(4);
	root2->left->left->right = create_node(6);
	root2->left->left->left = create_node(5);
	root2->left->left->left->right = create_node(5);
	root2->left->right = create_node(7);
	root2->left->right->left = create_node(9);
	root2->left->right->left->left = create_node(11);
	root2->left->right->left->right = create_node(12);
	root2->left->right->right = create_node(10);
	root2->left->right->right->right = create_node(13);
	printf("%d\n", width_tree(root2));

	root3 = create_node(10);
	root3->right = create_node(12);
	printf("%d\n", width_tree(root3));

	root4 = create_node(25);
	root4->left = create_node(33);
	root4->left->left = create_node(12);
	root4->left->right = create_node(9);
	root4->left->right->left = create_node(3);
	printf("%d\n", width_tree(root4));

	root5 = create_node(10);
	printf("%d\n", width_tree(root5));

	printf("%d\n", width_tree(NULL));
	return 0;
}
