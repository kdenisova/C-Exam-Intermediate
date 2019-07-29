#include <stdio.h>
#include <stdlib.h>

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void reverse_tree(struct s_node *root);

void print(struct s_node *root)
{
	while (root)
	{
		printf("%d ", root->value);
		root = root->left;
	}
}

int main(void)
{
	struct s_node a = {94, 0, 0},
	b = {34, 0, 0},
	c = {1, 0, 0},
	d = {20, 0, 0},
	e = {99, 0, 0},
	f = {83, 0, 0},
	g = {61, 0, 0},
	h = {39, 0, 0},
	i = {37, 0, 0},
	j = {67, 0, 0},
	k = {52, 0, 0};

	a.left = &b;
	a.right = &k;
	b.left = &c;
	c.left = &d;
	b.right = &e;
	e.left = &f;
	f.right = &g;
	e.right = &h;
	h.left = &i;
	h.right = &j;
	print(&a);
	printf("\n");
	reverse_tree(&a);
	print(&a);
	return 0;
}

// struct s_node *create_node(int value)
// {
// 	struct s_node *node;

// 	node = (struct s_node *)malloc(sizeof(struct s_node));
// 	node->value = value;
// 	node->left = NULL;
// 	node->right = NULL;
// 	return (node);
// }

// int main()
// {
// 	struct s_node *root;

// 	root = create_node(94);
// 	root->right = create_node(52);
// 	root->left = create_node(34);
// 	root->left->left = create_node(1);
// 	root->left->left->left = create_node(20);
// 	root->left->right = create_node(99);
// 	root->left->right->left = create_node(83);
// 	root->left->right->left->right = create_node(31);
// 	root->left->right->right = create_node(39);
// 	root->left->right->right->left = create_node(37);
// 	root->left->right->right->right = create_node(67);
// 	printf("%d\n", root->left->right->right->right->value);
// 	printf("%d\n", root->left->value);
// 	printf("%d\n", root->right->value);
// 	reverse_tree(root);
// 	printf("\n%d\n", root->right->left->left->left->value);
// 	printf("%d\n", root->left->value);
// 	printf("%d\n", root->right->value);
// 	printf("%d\n",root->right->right->right->value);
// 	return 0;
// }
