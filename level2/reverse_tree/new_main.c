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