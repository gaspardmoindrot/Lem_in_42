/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:32:05 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/26 09:48:35 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int	ft_if_forest(char **str, t_params **params, int *i, t_list **list)
{
	if (ft_is_modifier(*str) && (*params)->rooms_ended == 0)
	{
		if (ft_mod(params, list, str, i) == -1 && ft_lin(params, *i, str))
			return (-1);
	}
	else if (ft_is_room_type(str) && (*params)->rooms_ended == 0)
	{	
		if ((((*str)[0] == 'L') && ft_lsharp(params, str)) || 
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
	return (1);
}


void        ft_browse_entry(t_list **list, t_params **params)
{
	int		i;
	char	*str;

	str = NULL;
	if (ft_check_ants(params) == -1)
		return ;
	i = 1;
    while (get_next_line(0, &str) && i++ > 0)
    {
        if (ft_is_comment(&str))
			i = i * 1;
		else if (ft_is_modifier(str) || ft_is_room_type(&str) ||
				ft_is_tunnel_type(&str))
		{
			if (ft_if_forest(&str, params, &i, list) == -1)
				return ;
		}
        else if (ft_lin(params, i, &str))
            return ;
    }
	ft_strdel(&str);
}

int    main(void)
{
	t_list		*list;
	t_params	*params;

	ft_initialize_adjacent_list(&list);
	ft_initialize_params(&params);
	ft_browse_entry(&list, &params);
	ft_parse_fatal_errors_check(&params, &list);
	if (params->non_fatal_error_line != -1)
		ft_print_parsing_error_non_fatal(&params);
	if (params->fatal_error == 1)
	{
		ft_printf("ERROR\n");
		ft_print_parsing_error_fatal(&params);
		ft_free_adjacent_list(&list);
		ft_free_params(&params);
		return (0);
	}
	if (PRINT == 1)
		ft_print_general_details(&list, &params);
	ft_algo(&params, &list);
	ft_free_adjacent_list(&list);
	ft_free_params(&params);
	return (0);
}
