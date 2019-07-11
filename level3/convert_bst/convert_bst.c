/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:23:56 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/01 13:23:57 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
		int           value;
		struct s_node *right;
		struct s_node *left;
};

struct s_node *trav_min(struct s_node *bst)
{
	while (bst->left)
		bst = bst->left;
	return (bst);
}

struct s_node *trav_max(struct s_node *bst)
{
	while (bst->right)
		bst = bst->right;
	return (bst);
}

void trav_bst(struct s_node *bst, struct s_node *root, struct s_node *tail)
{
	static struct s_node *current;

	if (bst)
	{
		if (bst != root)
			trav_bst(bst->left, root, tail);
		if (current)
		{
			current->right = bst;
			bst->left = current;
		}
		current = bst;
		if (bst != tail)
			trav_bst(bst->right, root, tail);
	}
}

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *root;
	struct s_node *tail;

	if (!bst)
		return (0);

	root = trav_min(bst);
	tail = trav_max(bst);
	root->left = tail;
	tail->right = root;
	trav_bst(bst, root, tail);
	return (root);
}
