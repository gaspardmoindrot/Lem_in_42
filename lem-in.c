/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:32:05 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/19 19:07:05 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void        ft_browse_entry(t_list **list, t_params **params)
{
	int i;
	char *str;

	i = 0;
	str = NULL;
	get_next_line(0, &str);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			(*params)->error_line = 0;
			return ;
		}
		i++;
	}
	i = 1;
	(*params)->ant_count = ft_atoi(str);
	ft_strdel(&str);
    while (get_next_line(0, &str))
    {
		//ft_printf("{YELLOW}Reading line {EOC}: %i // ", i);
		i++;
        if (ft_is_comment(str))
		{
			//ft_printf("Type comment \n");
            ft_strdel(&str);
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
				(*params)->error_line = i;
				ft_strdel(&str);
				return;
			}
			ft_strdel(&str);
		}
        else if (ft_is_room_type(&str) && (*params)->rooms_ended == 0)
		{
			//ft_printf("Type room \n");
			if (str[0] == 'L' || str[0] == '#' || ft_is_room_type(&str) == -1)
			{
				(*params)->error_line = i;
				ft_strdel(&str);
				return ;
			}
            if (ft_add_room(params, list, &str) == -1)
			{
				(*params)->error_line = i;
				(*params)->fatal_error = 1;
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
			(*params)->error_line = i;
            ft_strdel(&str);
            return ;
        }
    }
	ft_strdel(&str);
}

void	ft_print_test_list(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp_2;
	t_node	*node;
	t_node	*node_2;

	tmp = *list;
	while (tmp && tmp->content)
	{
		node = (t_node *) tmp->content;
		ft_printf("{RED}Name : %s and id : %d :\n{EOC}", node->name, node->id);
		tmp_2 = node->next;
		while (tmp_2 && tmp_2->content)
		{
			node_2 = (t_node *) tmp_2->content;
			ft_printf("Name : %s and id : %d\n", node_2->name, node_2->id);
			tmp_2 = tmp_2->next;
		}
		tmp = tmp->next;
	}
}

void	ft_print_test_params(t_params **params)
{
	ft_printf("ant_count : %d\nrooms_started : %d\nrooms_count : %d\n", (*params)->ant_count, (*params)->rooms_started, (*params)->rooms_count);
	ft_printf("rooms_ended : %d\ntunnels_started : %d\ntunnels_ended : %d\n", (*params)->rooms_ended, (*params)->tunnels_started, (*params)->tunnels_ended);
	ft_printf("next_is_start : %d\nnext_is_end : %d\nhas_start : %d\n", (*params)->next_is_start, (*params)->next_is_end, (*params)->has_start);
	ft_printf("has_end : %d\nfatal_error : %d\nerror_line : %d\n", (*params)->has_end, (*params)->fatal_error, (*params)->error_line);
	ft_printf("error_type : %s\npath_start_end : %s\nlength_path_start_end : %d\n\n", (*params)->error_type, (*params)->path_start_end, (*params)->length_path_start_end);
}

int    main(void)
{
	t_list		*list;
	t_params	*params;

	ft_initialize_adjacent_list(&list);
	ft_initialize_params(&params);
	ft_browse_entry(&list, &params);
	ft_list_sort_asc_by_name(&list);
	ft_list_sort_adj(&list);
	if (params->fatal_error != 1)
	{
		ft_parse_fatal_errors_check(&params, &list);
		ft_reset_passed_flags(&list);
	}
	if (params->fatal_error == 1)
	{
		ft_print_parsing_error_fatal(&params);
		ft_free_adjacent_list(&list);
		ft_free_params(&params);
		return (0);
	}
	if (params->error_line != -1)
		ft_print_parsing_error_non_fatal(&params);
	ft_print_general_details(&list, &params);
	
	//ft_print_test_params(&params);      # Visu params
	//ft_print_test_list(&list);          # Visu lists
	
	//LEM-IN ALGORITHM GOGO **GASPARD_MOINDROT

	ft_free_adjacent_list(&list);
	ft_free_params(&params);
    return (0);
}
