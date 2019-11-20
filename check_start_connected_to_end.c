/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_connected_to_end.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:04:10 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/19 19:22:27 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int	ft_check_start_connected_to_end(t_params **params, t_node *start, t_node *fixed_start)
{
	t_list	*tmp;
	t_node	*node;
	char	*str;

	if (start->is_end == 1)
	{
		ft_printf("-----------------------\n");
		ft_printf("{GREEN}[Success]{EOC} A path detected from start to end\n");
		return (1);
	}
	start->passed_flag = 1;
	tmp = start->next;
	while (tmp && tmp->content)
	{
		node = (t_node *) tmp->content;
		//ft_printf("trying to check node %s and, successfuly\n", node->name);
		if (node->passed_flag == 0)
		{
			//ft_printf("Checking recursively node %s\n", node->name);
			node->passed_flag = 1;
			if (ft_check_start_connected_to_end(params, node, fixed_start))
			{
				str = (*params)->path_start_end;
				(*params)->path_start_end  = ft_strjoin((*params)->path_start_end, node->name);
				ft_strdel(&str);
				str = (*params)->path_start_end;
				(*params)->path_start_end  = ft_strjoin((*params)->path_start_end, " < ");
				ft_strdel(&str);
				(*params)->length_path_start_end++;
				if (node == fixed_start->next->content)
				{
					str = (*params)->path_start_end;
					(*params)->path_start_end  = ft_strjoin((*params)->path_start_end, fixed_start->name);
					ft_strdel(&str);
					ft_printf("{GREEN}%s{EOC}\n", (*params)->path_start_end);
					ft_printf("This path has a size {YELLOW}%i{EOC}, for {YELLOW}%i{EOC} rooms, ratio of {YELLOW}%f{EOC}\n", (*params)->length_path_start_end, (*params)->rooms_count, (float) (*params)->length_path_start_end / (float) (*params)->rooms_count);
					ft_strdel(&((*params)->path_start_end));
					(*params)->length_path_start_end = 0;
				}
				return (1);
			}
			node->passed_flag = 0;
		}
		tmp = tmp->next;
	}
	if (ft_strcmp(start->name, fixed_start->name) == 0)
	{
		(*params)->error_line = 0;
		ft_strdel(&((*params)->error_type));
		(*params)->error_type = ft_strdup("No path detected between start and end");
		(*params)->fatal_error = 1;
		return (-1);
	}
	//ft_printf("{RED}Dead End - back UP {EOC}\n");
	return (0);
}
