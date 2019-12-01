/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_adjacent_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:18:17 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/27 19:26:21 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_free_node_adj_list(t_list **list)
{
	t_list		*tmp;
	t_list		*nxt;

	if (!(*list))
		return ;
	tmp = *list;
	while (tmp)
	{
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
	list = NULL;
}

static void		ft_free_node_next(t_node *node)
{
	t_list	*list;

	if (!node)
		return ;
	list = node->next;
	ft_free_node_adj_list(&list);
	ft_strdel(&(node->name));
	free(node);
}

void			ft_free_adjacent_list(t_list **list)
{
	t_list		*tmp;
	t_list		*nxt;
	t_node		*node;

	if (!(*list))
		return ;
	tmp = *list;
	while (tmp)
	{
		node = (t_node *)tmp->content;
		ft_free_node_next(node);
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
}

static void		ft_free_node_fathers(t_node *node)
{
	t_list	*list;

	if (!node)
		return ;
	list = node->father;
	ft_free_node_adj_list(&list);
}

void			ft_free_fathers(t_list **list)
{
	t_list		*tmp;
	t_node		*node;

	if (!(*list))
		return ;
	tmp = *list;
	while (tmp)
	{
		node = (t_node *)tmp->content;
		ft_free_node_fathers(node);
		tmp = tmp->next;
	}
}
