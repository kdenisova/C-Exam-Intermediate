/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_looping.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:38:21 by kdenisov          #+#    #+#             */
/*   Updated: 2019/06/26 13:38:23 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
	struct s_node *head;
	struct s_node *current;

	if (!node)
		return (0);
	head = node;
	current = node;
	while (head && current)
	{
		head = head->next;
		current = current->next->next;
		if (head == current)
			return (1);
	}
	return (0);
}