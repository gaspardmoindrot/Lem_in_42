/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:29:15 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/28 19:02:46 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_initialize_params(t_params **params)
{
	*params = (t_params *)malloc(sizeof(t_params));
	if (!params)
		return (-1);
	(*params)->ant_count = -1;
	(*params)->rooms_started = 0;
	(*params)->rooms_count = 0;
	(*params)->rooms_ended = 0;
	(*params)->tunnels_started = 0;
	(*params)->tunnels_ended = 0;
	(*params)->next_is_start = 0;
	(*params)->has_start = 0;
	(*params)->next_is_end = 0;
	(*params)->has_end = 0;
	(*params)->fatal_error = 0;
	(*params)->error_line = -1;
	(*params)->non_fatal_error_line = -1;
	(*params)->error_type = ft_strdup("");
	(*params)->non_fatal_error_type = ft_strdup("");
	(*params)->path_start_end = ft_strdup("");
	(*params)->length_path_start_end = 0;
	(*params)->map = ft_strdup("");
	return (1);
}
