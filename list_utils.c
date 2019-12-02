/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:23:00 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/27 18:34:39 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_is_neighbor_with_name_hash(t_node *node, long hash)
{
	t_node	*node2;
	t_list	*tmp;

	if (node == NULL)
		return (0);
	tmp = node->next;
	while (tmp && tmp->next)
	{
		node2 = (t_node *)tmp->content;
		if (node2->name_hash == hash)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_node		*ft_find_t_node_with_id(t_list **list, int id)
{
	t_node	*node;
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *)tmp->content;
		if (node->id == id)
			return (node);
		tmp = tmp->next;
	}
	return (NULL);
}

t_node		*ft_find_t_node_with_name_hash(t_list **list, long hash)
{
	t_node	*node;
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *)tmp->content;
		if (node->name_hash == hash)
			return (node);
		tmp = tmp->next;
	}
	return (NULL);
}

t_node		*ft_find_t_node_with_start(t_list **list)
{
	t_node	*node;
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *)tmp->content;
		if (node->is_start == 1)
			return (node);
		tmp = tmp->next;
	}
	return (NULL);
}

t_node		*ft_find_t_node_with_end(t_list **list)
{
	t_node	*node;
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *)tmp->content;
		if (node->is_end == 1)
			return (node);
		tmp = tmp->next;
	}
	return (NULL);
}
