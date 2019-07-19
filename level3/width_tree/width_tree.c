
struct s_node
{
    int value;
    struct s_node *left;
    struct s_node *right;
};

static int w;

int travers(struct s_node *n)
{
	int hleft;
	int hright;

	if (!n)
		return (0);
	hleft = travers(n->left);
	hright = travers(n->right);
	if (hleft + hright  + 1 > w)
		w = hleft + hright + 1;
	if (hleft > hright)
		return (hleft + 1);
	return (hright + 1);
}

int        width_tree(struct s_node *n)
{
	w = 0;
	travers(n);
	return (w);
}
