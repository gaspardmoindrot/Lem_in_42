/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_adjacent_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:32:05 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/24 21:16:29 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int 	ft_handle_modifier(t_params **params, t_list **list, char **str, int *i)
{
	if (ft_is_modifier(*str) == -1)
		(*params)->next_is_start = 1;
	if (ft_is_modifier(*str) == 1)
		(*params)->next_is_end = 1;
    ft_strdel(str);
    get_next_line(0, str);
	//ft_printf("{YELLOW}Reading line {EOC}: %i // ", *i);
	if (ft_is_modifier(*str) && (*params)->rooms_ended == 0)
	{
		//ft_printf("Type modifier \n");
		(*i)++;
		if (ft_is_modifier(*str) == -1)
			(*params)->has_start = 1;
		else if (ft_is_modifier(*str) == 1)
			(*params)->has_end = 1;
		if (ft_handle_modifier(params, list, str, i) == -1)
		{
			(*params)->non_fatal_error_line = *i;
			return (-1);
		}
	}
	else if (!ft_is_room_type(str))
    {
        return (-1);
    }
    else
	{
		//ft_printf("Type room \n");
		(*i)++;
		if (ft_add_room(params, list, str) == -1)
			return (-1);
	}
	return (1);
}

static void	ft_reset_next_is_start_end(t_params **params)
{
	if ((*params)->next_is_start == 1)
		(*params)->next_is_start = 0;
	if ((*params)->next_is_end == 1)
		(*params)->next_is_end = 0;
}

int			ft_add_room(t_params **params, t_list **list, char **str)
{
	char	**split;
	t_node	*node;
	t_list	*new;

    split = ft_strsplit(*str, ' ');
	if ((ft_check_room_exists(list, ft_hash(split[0]), params) != -1) ||
		ft_check_coords_exist(list, ft_atoi(split[1]), ft_atoi(split[2]), params) == 1)
		return (-1);
	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->id = (*params)->rooms_count;
	node->name = ft_strdup(split[0]);
	node->name_hash = ft_hash(split[0]);
	node->is_start = (*params)->next_is_start;
	node->is_end = (*params)->next_is_end;
	ft_reset_next_is_start_end(params);
	node->x_coord = ft_atoi(split[1]);
	node->y_coord = ft_atoi(split[2]);
	node->passed_flag = 0;
	node->next = NULL;
	node->father = NULL;
	new = ft_lstnew_revisited(node, sizeof(t_node));
	ft_lstadd(list, new);
	(*params)->rooms_count += 1;
	(*params)->rooms_started = 1;
	ft_free_split(2, split);
	return(1);
}

int     ft_add_tunnel(t_list **list, char **str, t_params **params)
{
	char		**split;
	t_list		*tmp;
	t_list		*adj;
	long		hash0;
	long		hash1;
	t_node		*node;
	t_node		*node3;
	int			count;

	count = 2;
	split = ft_strsplit(*str, '-');
    tmp = *list;
	hash0 = ft_hash(split[0]);
	hash1 = ft_hash(split[1]);
	if (!ft_is_neighbor_with_name_hash(ft_find_t_node_with_name_hash(list, hash0), hash1))
	{
		count = 0;
		while (tmp && tmp->content && ((t_node *) tmp->content)->name)
		{
			node = (t_node *) tmp->content;
			if (node->name_hash == hash0)
			{
				node3 = ft_find_t_node_with_name_hash(list, hash1);
				if (node3 != NULL)
				{
					adj = ft_lstnew_revisited(node3, sizeof(t_node));
					ft_lstadd(&(node->next), adj);
					count++;
				}
			}
			else if (node->name_hash == hash1)
			{
				node3 = ft_find_t_node_with_name_hash(list, hash0);
				if (node3 != NULL)
				{
					adj = ft_lstnew_revisited(node3, sizeof(t_node));
					ft_lstadd(&(node->next), adj);
					count++;
				}
			}
			tmp = tmp->next;
		}
	}
    ft_free_split(1, split);
	if (count != 2)
	{
		ft_strdel(&((*params)->non_fatal_error_type));
		(*params)->non_fatal_error_type = ft_strdup("1-2 of rooms mentionned in tunnel not found, or linked with itself");
		return (-1);
	}
	return (1);
}
