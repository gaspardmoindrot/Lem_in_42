/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:37:48 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/03 14:01:58 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_set_has_start_or_end(t_params **params, char *str)
{
	if (ft_is_modifier(str) == -1)
		(*params)->has_start = 1;
	if (ft_is_modifier(str) == 1)
		(*params)->has_end = 1;
}

int			ft_lin(t_params **params, int i, char **str)
{
	(*params)->non_fatal_error_line = i;
	ft_strdel(str);
	return (1);
}

int			ft_lsharp(t_params **params, char **str, int i)
{
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_line = i;
	(*params)->non_fatal_error_type = ft_strdup("Start with L");
	ft_strdel(str);
	return (1);
}

void		ft_tunnel_add_success(t_params **params, char **str)
{
	(*params)->tunnels_started = 1;
	(*params)->rooms_ended = 1;
	ft_add_to_map_output(params, *str);
	ft_strdel(str);
}
