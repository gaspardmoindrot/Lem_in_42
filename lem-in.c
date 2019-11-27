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

void        ft_browse_entry(t_list **list, t_params **params)
{
	int i;
	char *str;

	str = NULL;
	get_next_line(0, &str);
	if (ft_check_ants(str, params) == -1)
		return ;
	ft_strdel(&str);
	i = 1;
    while (get_next_line(0, &str))
    {
		i++;
		//ft_printf("{YELLOW}Reading line {EOC}: %i // ", i);
        if (ft_is_comment(&str))
		{
			//ft_printf("Type comment \n");
			i = i * 1;
		}
        else if (ft_is_modifier(str) && (*params)->rooms_ended == 0)
		{
			//ft_printf("Type modifier \n");
			if (ft_is_modifier(str) == -1)
				(*params)->has_start = 1;
			else if (ft_is_modifier(str) == 1)
				(*params)->has_end = 1;
            if (ft_handle_modifier(params, list, &str, &i) == -1)
			{
				(*params)->non_fatal_error_line = i;
				ft_strdel(&str);
				return;
			}
			ft_strdel(&str);
		}
        else if (ft_is_room_type(&str) && (*params)->rooms_ended == 0)
		{
			//ft_printf("Type room \n");
			if (str[0] == 'L' || str[0] == '#')
			{
				ft_strdel(&((*params)->non_fatal_error_type));
				(*params)->non_fatal_error_type = ft_strdup("Rooms cannot start with L or # character");
				ft_strdel(&str);
				return ;
			}
			else if (ft_is_room_type(&str) == -1)
			{
				(*params)->non_fatal_error_line = i;
				ft_strdel(&str);
				return ;
			}
            if (ft_add_room(params, list, &str) == -1)
			{
				(*params)->non_fatal_error_line = i;
				ft_strdel(&str);
				return ;
			}
			ft_strdel(&str);
		}
        else if (ft_is_tunnel_type(&str))
		{
			//ft_printf("Type tunnel \n");
            if (ft_add_tunnel(list, &str, params) == -1)
			{
				(*params)->error_line = i;
				ft_strdel(&str);
				return ;
			}
			(*params)->tunnels_started = 1;
			(*params)->rooms_ended = 1;
			ft_strdel(&str);
		}
        else
        {
			(*params)->non_fatal_error_line = i;
            ft_strdel(&str);
            return ;
        }
    }
	ft_strdel(&str);
}

int    main(void)
{
	t_list		*list;
	t_params	*params;
	t_list		**result;

	ft_initialize_adjacent_list(&list);
	ft_initialize_params(&params);
	ft_browse_entry(&list, &params);
	ft_parse_fatal_errors_check(&params, &list);
	if (params->non_fatal_error_line != -1)
		ft_print_parsing_error_non_fatal(&params);
	if (params->fatal_error == 1)
	{
		ft_print_parsing_error_fatal(&params);
		ft_free_adjacent_list(&list);
		ft_free_params(&params);
		return (0);
	}
	//if (PRINT == 1)
	//	ft_print_general_details(&list, &params);
	ft_algo(&params, &list, &result);
	ft_free_adjacent_list(&list);
	ft_free_params(&params);
    return (0);
}
