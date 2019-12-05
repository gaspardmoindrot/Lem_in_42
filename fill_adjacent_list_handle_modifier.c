/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_adjacent_list_handle_modifier.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:13:51 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/03 13:58:41 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_turn_on_start_or_end(t_params **params, char *str, int i)
{
	if (ft_is_modifier(str) == -1)
	{
		if ((*params)->has_start == 1 && ft_handle_double_start(params, i) == 1)
			return (-1);
		(*params)->next_is_start = 1;
	}
	if (ft_is_modifier(str) == 1)
	{
		if ((*params)->has_end == 1 && ft_handle_double_end(params, i) == 1)
			return (-1);
		(*params)->next_is_end = 1;
	}
	ft_set_has_start_or_end(params, str);
	return (1);
}

int			ft_mod(t_params **params, t_list **list, char **str,
		int *i)
{
	if (ft_turn_on_start_or_end(params, *str, *i) == -1)
		return (-1);
	ft_add_to_map_output(params, *str);
	ft_strdel(str);
	get_next_line(0, str);
	if (ft_is_modifier(*str) && (*params)->rooms_ended == 0 && (*i)++ > 0)
	{
		if (ft_mod(params, list, str, i) == -1 && ft_lin(params, *i, str))
			return (-1);
	}
	else if (!ft_is_room_type(str) && ft_lin(params, *i, str))
		return (-1);
	else
	{
		(*i)++;
		if ((str[0][0] && str[0][0] == 'L' && ft_lsharp(params, str, *i)) ||
			ft_add_room(params, list, str) == -1)
			return (-1);
	}
	ft_strdel(str);
	return (1);
}
