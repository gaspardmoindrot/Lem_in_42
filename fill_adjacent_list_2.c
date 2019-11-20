/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_adjacent_list_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:50:04 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/19 17:24:44 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_check_room_exists(t_list **list, char *str, t_params **params, int i)
{
	t_list	*tmp;
	t_node	*node;

	tmp = *list;
	while (tmp && tmp->content && ((t_node *) tmp->content)->name)
	{
		node = (t_node *) tmp->content;
		if (ft_strcmp(node->name, str) == 0)
		{
			if (i == 1)
			{
				(*params)->error_type = ft_strdup("Room already exists");
				ft_strdel(&((*params)->error_type));
			}
			return (node->id);
		}
		tmp = tmp->next;
	}
	if (i == 2)
	{
		ft_strdel(&((*params)->error_type));
		(*params)->error_type = ft_strdup("Room mentionned in tunnel not found");
	}
	return (-1);
}

int		ft_check_coords_exist(t_list **list, int x, int y, t_params **params)
{
	t_list	*tmp;

	tmp = *list;
	while (tmp && tmp->content && ((t_node *) tmp->content)->x_coord &&
			((t_node *) tmp->content)->y_coord)
	{
		if (x == ((t_node *) tmp->content)->x_coord &&
				y == ((t_node *) tmp->content)->y_coord)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	ft_strdel(&((*params)->error_type));
	(*params)->error_type = ft_strdup("Room with same coords already exists");
	return (0);
}
