/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:32:05 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/02 17:59:59 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_if_forest(char **str, t_params **params, int *i,
		t_list **list)
{
	if (ft_is_modifier(*str) && (*params)->rooms_ended == 0)
	{
		if (ft_mod(params, list, str, i) == -1 && ft_lin(params, *i, str))
			return (-1);
	}
	else if (ft_is_room_type(str) && (*params)->rooms_ended == 0)
	{
		if ((((*str)[0] == 'L') && ft_lsharp(params, str, *i)) ||
			(ft_is_room_type(str) == -1 && ft_lin(params, *i, str) == 1)
			|| (ft_add_room(params, list, str) == -1 &&
			ft_lin(params, *i, str)))
			return (-1);
	}
	else if (ft_is_tunnel_type(str))
	{
		if (ft_add_tunnel(list, str, params) == -1 && ft_lin(params, *i, str))
			return (-1);
	}
	else if (ft_handle_other_error_cases(str, params, i) == 1)
		return (-1);
	return (1);
}

int				ft_browse_entry(t_list **list, t_params **params)
{
	int		i;
	char	*str;

	str = NULL;
	if (ft_check_ants(params) == -2)
		return (-2) ;
	i = 1;
	while (get_next_line(0, &str) && i++ > 0)
	{
		if (ft_is_comment(&str))
			i = i * 1;
		else if (ft_is_modifier(str) || ft_is_room_type(&str) ||
				ft_is_tunnel_type(&str))
		{
			if (ft_if_forest(&str, params, &i, list) == -1)
				return (-1);
		}
		else if (ft_handle_other_error_cases(&str, params, &i) &&
				ft_lin(params, i, &str))
			return (-1);
	}
	ft_strdel(&str);
	return (1);
}

static int		ft_beginning(t_params **params, t_list **list)
{
	ft_initialize_adjacent_list(list);
	ft_initialize_params(params);
	if (ft_browse_entry(list, params) == -2)
	{
		ft_free_adjacent_list(list);
		ft_free_params(params);
		return (-2);
	}
	ft_parse_fatal_errors_check(params, list);
	return (1);
}

static int		ft_handle_fatal(t_params **params, t_list **list)
{
	ft_printf("ERROR\n");
	ft_print_parsing_error_fatal(params);
	ft_free_adjacent_list(list);
	ft_free_params(params);
	return (1);
}

int				main(void)
{
	t_list		*list;
	t_params	*params;

	if (ft_beginning(&params, &list) == -2)
		return (0);
	if (params->non_fatal_error_line != -1)
		ft_print_parsing_error_non_fatal(&params);
	if (params->fatal_error == 1 && ft_handle_fatal(&params, &list) == 1)
		return (0);
	if (PRINT == 1)
		ft_print_general_details(&list, &params);
	ft_print_map(&params);
	ft_algo(&params, &list);
	// ft_print_ant_moves
	ft_free_adjacent_list(&list);
	ft_free_params(&params);
	return (0);
}
