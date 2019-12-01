/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:46:21 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/27 18:34:46 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_list_sort_asc_by_name(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_node	*node;
	t_node	*node2;
	t_node	*node3;

	tmp = *list;
	while (tmp)
	{
		tmp2 = *list;
		while (tmp2 && tmp2->content && tmp2->next && tmp2->next->content)
		{
			node = (t_node *)tmp2->content;
			node2 = ((t_node *)tmp2->next->content);
			if (ft_strcmp(node->name, node2->name) > 0)
			{
				node3 = tmp2->content;
				tmp2->content = tmp2->next->content;
				tmp2->next->content = node3;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void		ft_list_sort_adj(t_list **list)
{
	t_list	*tmp;
	t_list	*to_sort;
	t_node	*node;

	tmp = *list;
	while (tmp && tmp->content && ((t_node *)tmp->content)->next)
	{
		node = ((t_node *)tmp->content);
		to_sort = node->next;
		ft_list_sort_asc_by_name(&to_sort);
		tmp = tmp->next;
	}
}
