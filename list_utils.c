/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:23:00 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/19 17:24:16 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			ft_is_neighbor_with_name(t_node *node, char *str)
{
	t_node	*node2;
	t_list	*tmp;

	tmp = node->next;
	while (tmp && tmp->next)
	{
		node2 = (t_node *) tmp->content;
		if (ft_strcmp(node2->name, str) == 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_node 		*ft_find_t_node_with_id(t_list **list, int id)
{
	t_node	*node;
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *) tmp->content;
		if (node->id == id)
			return (node);
		tmp = tmp->next;
	}
	return (NULL);
}

t_node 		*ft_find_t_node_with_name(t_list **list, char *str)
{
	t_node	*node;
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *) tmp->content;
		if (ft_strcmp(node->name, str) == 0)
			return (node);
		tmp = tmp->next;
	}
	return (NULL);
}

t_node 		*ft_find_t_node_with_start(t_list **list)
{
	t_node	*node;
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *) tmp->content;
		if (node->is_start == 1)
			return (node);
		tmp = tmp->next;
	}
	return (NULL);
}

t_node 		*ft_find_t_node_with_end(t_list **list)
{
	t_node	*node;
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *) tmp->content;
		if (node->is_end == 1)
			return (node);
		tmp = tmp->next;
	}
	return (NULL);
}
