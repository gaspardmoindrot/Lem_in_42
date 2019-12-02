/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bibli.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:20:26 by gmoindro          #+#    #+#             */
/*   Updated: 2019/12/02 17:23:28 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	if (new && alst && *alst)
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

void		ft_put_bibli(t_list **list, t_list ***result, int i)
{
	t_list	*tmp;
	t_list	*tmp_2;
	t_list	*new;
	t_node	*node;
	t_node	*node_2;
	t_node	*end;
	int		j;

	end = ft_find_t_node_with_end(list);
	j = 0;
	node = ft_find_t_node_with_start(list);
	tmp = node->next;
	while (tmp && i >= j && node)
	{
		node = (t_node *)tmp->content;
		if (tmp->arcw == 1 && i >= j)
		{
			result[i][j] = (t_list *)malloc(sizeof(t_list));
			result[i][j]->content = ft_find_t_node_with_start(list);
			result[i][j]->content_size = sizeof(t_node);
			result[i][j]->next = NULL;
			new = ft_lstnew_revisited(node, sizeof(t_node));
			ft_lstadd_back(&result[i][j], new);
			tmp_2 = node->next;
			while (tmp_2)
			{
				node_2 = (t_node *)tmp_2->content;
				if (tmp_2->arcw == 1)
				{
					new = ft_lstnew_revisited(node_2, sizeof(t_node));
					ft_lstadd_back(&result[i][j], new);
					if (node_2->is_end == 1)
						break ;
					tmp_2 = node_2->next;
				}
				else
					tmp_2 = tmp_2->next;
			}
			j++;
		}
		tmp = tmp->next;
	}
}
