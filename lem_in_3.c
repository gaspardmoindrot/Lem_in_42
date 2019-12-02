/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:54:21 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/28 19:29:23 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_handle_other_error_cases(char **str, t_params **params, int *i)
{
	if ((ft_is_modifier(*str) || ft_is_room_type(str)) &&
			(*params)->rooms_ended == 1)
	{
		(*params)->non_fatal_error_line = *i;
		ft_strdel(&((*params)->non_fatal_error_type));
		(*params)->non_fatal_error_type = ft_strdup("Room after tunnel");
		ft_strdel(str);
		return (1);
	}
	(*params)->non_fatal_error_line = *i;
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_type = ft_strdup("Bad format (other)");
	ft_strdel(str);
	return (1);
}

int		ft_handle_double_start(t_params **params, int i)
{
	(*params)->non_fatal_error_line = i;
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_type = ft_strdup("Only one start allowed");
	return (1);
}

int		ft_handle_double_end(t_params **params, int i)
{
	(*params)->non_fatal_error_line = i;
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_type = ft_strdup("Only one end allowed");
	return (1);
}
