/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdenisov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:31:33 by kdenisov          #+#    #+#             */
/*   Updated: 2019/07/11 14:31:35 by kdenisov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node *temp;

	if (lst1 && lst2)
	{
		while (lst1)
		{
			temp = lst2;
			while (temp)
			{
				if (temp == lst1)
					return (temp);
				temp = temp->next;
			}
			lst1 = lst1->next;
		}
	}
	return (0);
}
