/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fatal_errors_check.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:00:43 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/28 20:40:30 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_handle_error(t_params **params)
{
	(*params)->error_line = 1;
	ft_strdel(&((*params)->error_type));
	(*params)->fatal_error = 1;
}

static int	ft_ants_rooms_tunnels_start_end(t_params **params)
{
	if (((*params)->ant_count < 0))
	{
		ft_handle_error(params);
		(*params)->error_type = ft_strdup("Bad ant numbers given");
		return (-1);
	}
	if (((*params)->rooms_started) == 0)
	{
		ft_handle_error(params);
		(*params)->error_type = ft_strdup("Need rooms");
		return (-1);
	}
	if (((*params)->has_start == 0 || ((*params)->has_end == 0)))
	{
		ft_handle_error(params);
		(*params)->error_type = ft_strdup("Need both start and end");
		return (-1);
	}
	return (1);
}

static void	ft_handle_error_two(t_params **params)
{
	(*params)->error_line = 0;
	ft_strdel(&((*params)->error_type));
	(*params)->error_type = ft_strdup("Start and end must be unique");
	(*params)->fatal_error = 1;
}

static int	ft_single_start_end(t_list **list, t_params **params)
{
	t_node	*node;
	t_list	*tmp;
	int		count_start;
	int		count_end;

	count_start = 0;
	count_end = 0;
	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *)tmp->content;
		if (node->is_start == 1)
			count_start++;
		if (node->is_end == 1)
			count_end++;
		tmp = tmp->next;
	}
	if (count_start != 1 || count_end != 1)
	{
		ft_handle_error_two(params);
		return (-1);
	}
	return (1);
}

int			ft_parse_fatal_errors_check(t_params **params, t_list **list)
{
	t_node *node;

	if (ft_ants_rooms_tunnels_start_end(params) == -1)
		return (-1);
	if (ft_single_start_end(list, params) == -1)
		return (-1);
	(void)list;
	node = ft_find_t_node_with_start(list);
	if (ft_check_start_connected_to_end_bfs(params, node) == -1)
		return (-1);
	ft_reset_passed_flags(list);
	ft_free_fathers(list);
	if (ft_check_start_connected_to_end_dfs(params, node, node) == -1)
		return (-1);
	ft_reset_passed_flags(list);
	return (1);
}
