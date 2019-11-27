/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_adjacent_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:32:05 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/26 10:50:05 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	ft_turn_on_start_or_end(t_params **params, char *str)
{
	if (ft_is_modifier(str) == -1)
		(*params)->next_is_start = 1;
	if (ft_is_modifier(str) == 1)
		(*params)->next_is_end = 1;
}

int			ft_handle_modifier(t_params **params, t_list **list, char **str,
		int *i)
{
	ft_turn_on_start_or_end(params, *str);
	ft_strdel(str);
	get_next_line(0, str);
	if (ft_is_modifier(*str) && (*params)->rooms_ended == 0)
	{
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
		return (-1);
	else
	{
		(*i)++;
		if (ft_add_room(params, list, str) == -1)
			return (-1);
	}
	return (1);
}
