/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:46:35 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/25 13:46:42 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node
{
    int value;
    struct s_node *left;
    struct s_node *right;
};

static int w;

int travers(struct s_node *n)
{
	int left;
	int right;

	if (!n)
		return (0);
	left = travers(n->left);
	right = travers(n->right);
	if (left + right + 1 > w)
		w = left + right + 1;
	if (left > right)
		return (left + 1);
	return (right + 1);
}

int        width_tree(struct s_node *n)
{
	w = 0;
	if (!n)
		return (0);
	travers(n);
	return (w);
}