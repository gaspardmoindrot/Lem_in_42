/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:29:15 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/03 17:44:38 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_initialize_params_other(t_params **params)
{
	(*params)->length_path_start_end = 0;
	(*params)->cycle_number = 0;
	(*params)->ants_launched = 0;
	(*params)->index = -1;
	(*params)->index_max = -1;
	(*params)->best_index = -1;
	(*params)->best_cycle_number = -1;
	(*params)->allow_printing_moves = 0;
	(*params)->print = 0;
	(*params)->print_list = 0;
}

int			ft_initialize_params(t_params **params)
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
	(*params)->map = ft_strdup("");
	ft_initialize_params_other(params);
	return (1);
}
