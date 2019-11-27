/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_adjacent_list_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:50:04 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/23 19:03:55 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		ft_check_room_exists(t_list **list, long hash, t_params **params)
{
	t_list	*tmp;
	t_node	*node;

	tmp = *list;
	while (tmp && tmp->content && ((t_node *) tmp->content)->name)
	{
		node = (t_node *) tmp->content;
		if (node->name_hash == hash)
		{
			ft_strdel(&((*params)->non_fatal_error_type));
			(*params)->non_fatal_error_type = ft_strdup("Room already exists");
			return (node->id);
		}
		tmp = tmp->next;
	}
	return (-1);
}

int		ft_check_tunnel_rooms_exist(t_list **list, long hash0, long hash1, t_params **params)
{
	t_list	*tmp;
	t_node	*node;
	int 	count;

	count = 0;
	tmp = *list;
	while (tmp && tmp->content)
	{
		node = (t_node *) tmp->content;
		if (node->name_hash == hash0 || node->name_hash == hash1)
			count++;
		tmp = tmp->next;
	}
	if (count == 2)
		return (1);
	else
	{
		ft_strdel(&((*params)->non_fatal_error_type));
		(*params)->non_fatal_error_type = ft_strdup("One of rooms mentionned in tunnel not found");
		return (-1);
	}
}

int		ft_check_coords_exist(t_list **list, int x, int y, t_params **params)
{
	t_list	*tmp;
	t_node	*node;

	tmp = *list;
	node = (t_node *) tmp->content;
	while (tmp && tmp->content)
	{
		node = (t_node *) tmp->content;
		if (x == node->x_coord && y == node->y_coord)
		{
			ft_strdel(&((*params)->non_fatal_error_type));
			(*params)->non_fatal_error_type = ft_strdup("Room with same coords already exists");
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
