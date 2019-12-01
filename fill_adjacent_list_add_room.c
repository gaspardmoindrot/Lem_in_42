/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_adjacent_list_add_room.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:44:20 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/28 19:14:59 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_reset_next_is_start_end(t_params **params, t_node *node)
{
	if ((*params)->next_is_start == 1)
		(*params)->next_is_start = 0;
	if ((*params)->next_is_end == 1)
		(*params)->next_is_end = 0;
	node->passed_flag = 0;
	node->next = NULL;
	node->father = NULL;
}

static void	ft_set_rooms_count_started(t_params **params, char **str)
{
	(*params)->rooms_count += 1;
	(*params)->rooms_started = 1;
	ft_strdel(str);
}

static void	ft_set_is_start_is_end(t_params **params, t_node *node)
{
	node->is_start = (*params)->next_is_start;
	node->is_end = (*params)->next_is_end;
}

static void	ft_add_to_map_output(t_params **params, char *str)
{
	char *str2;

	str2 = (*params)->map;
	(*params)->map = ft_strjoin(str2, str);
	ft_strdel(&str2);
	ft_add_return_line(params);
}

int			ft_add_room(t_params **params, t_list **list, char **str)
{
	char	**split;
	t_node	*node;
	t_list	*new;

	split = ft_strsplit(*str, ' ');
	if ((ft_check_room_exists(list, ft_hash(split[0]), params) != -1) ||
		ft_check_coords_exist(list, ft_atoi(split[1]), ft_atoi(split[2]),
			params) == 1)
		return (-1);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->id = (*params)->rooms_count;
	node->name = ft_strdup(split[0]);
	node->name_hash = ft_hash(split[0]);
	ft_set_is_start_is_end(params, node);
	ft_reset_next_is_start_end(params, node);
	node->x_coord = ft_atoi(split[1]);
	node->y_coord = ft_atoi(split[2]);
	new = ft_lstnew_revisited(node, sizeof(t_node));
	ft_lstadd(list, new);
	ft_add_to_map_output(params, *str);
	ft_set_rooms_count_started(params, str);
	ft_free_split(2, split);
	return (1);
}
