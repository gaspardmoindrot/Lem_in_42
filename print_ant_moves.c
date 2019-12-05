/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:47:23 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/03 17:44:40 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_ants_dispatch(int *length, int *ants_start, t_params **params)
{
	int	ant_i;
	int	i;
	int	cost_select;
	int	cost_i;
	int	i_select;

	ant_i = -1;
	i_select = 0;
	while (++ant_i < (*params)->ant_count)
	{
		i = -1;
		i_select = 0;
		cost_select = length[0] + ants_start[0];
		cost_i = 0;
		while (++i < (*params)->index)
		{
			cost_i = ants_start[i] + length[i];
			if (cost_i < cost_select)
			{
				i_select = i;
				cost_select = cost_i;
			}
		}
		ants_start[i_select]++;
	}
}

static void	ft_handle_comp(t_params **params)
{
	if ((*params)->best_cycle_number == -1 ||
			(*params)->cycle_number < (*params)->best_cycle_number)
	{
		(*params)->best_cycle_number = (*params)->cycle_number;
		(*params)->best_index = (*params)->index;
	}
	(*params)->index = -1;
	(*params)->cycle_number = 0;
	(*params)->ants_launched = 0;
}

static void	ft_handle_loop(t_params **params, int index, t_list ***bib)
{
	t_list	*ants[(*params)->ant_count];
	int		length[index];
	int		ants_start[index];
	int		ants_end;

	ants_end = 0;
	(*params)->index = index;
	ft_init_ants_start(ants_start, index);
	ft_init_ants(ants, (*params)->ant_count);
	ft_init_length(length, index);
	ft_fill_length(length, bib[index - 1], index);
	ft_ants_dispatch(length, ants_start, params);
	while (ants_end != (*params)->ant_count)
	{
		ft_print_other_rounds(&ants_end, ants, params);
		ft_print_first_round(ants_start, ants, params, bib[index - 1]);
		(*params)->cycle_number++;
	}
	ft_handle_comp(params);
	ants_end = 0;
}

void		ft_print_ant_moves(t_list ***bib, t_params **params)
{
	int		index;

	index = 0;
	while (++index <= (*params)->index_max)
		ft_handle_loop(params, index, bib);
	index = (*params)->best_index;
	(*params)->index = (*params)->best_index;
	(*params)->allow_printing_moves = 1;
	ft_handle_loop(params, index, bib);
}
