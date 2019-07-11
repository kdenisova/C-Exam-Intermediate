/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_bst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 12:45:28 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/11 12:45:31 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *max_bst(struct s_node *bst)
{
	while (bst->right)
		bst = bst->right;
	return (bst);
}

struct s_node *min_bst(struct s_node *bst)
{
	while (bst->left)
		bst = bst->left;
	return (bst);
}

void	travers_bst(struct s_node *bst, struct s_node *min, struct s_node *max)
{
	static struct s_node *current;

	if (bst)
	{
		if (bst != min)
			travers_bst(bst->left, min, max);
		if (current)
		{
			current->right = bst;
			bst->left = current;
		}
		current = bst;
		if (bst != max)
			travers_bst(bst->right, min, max);
	}
}

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *max;
	struct s_node *min;

	if (!bst)
		return (0);
	max = max_bst(bst);
	min = min_bst(bst);
	min->left = max;
	max->right = min;
	travers_bst(bst, min, max);
	return (min);
}
