/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_connected_to_end_dfs.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:04:10 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/28 20:34:32 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_handle_error(t_params **params)
{
	(*params)->error_line = 0;
	ft_strdel(&((*params)->error_type));
	(*params)->error_type = ft_strdup("No path detected between start and end");
	(*params)->fatal_error = 1;
	return (1);
}

static void		ft_handle_joins(t_params **params, t_node *node)
{
	char *str;

	str = (*params)->path_start_end;
	(*params)->path_start_end = ft_strjoin(str, node->name);
	ft_strdel(&str);
	str = (*params)->path_start_end;
	(*params)->path_start_end = ft_strjoin((*params)->path_start_end, " < ");
	ft_strdel(&str);
	(*params)->length_path_start_end++;
}

static void		ft_handle_end_dfs(t_params **params, t_node *fixed_start)
{
	char *str;

	if (PRINT == 1)
	{
		ft_printf("-----------------------\n{GREEN}[Success]{EOC}");
		ft_printf("A path detected with {YELLOW}D{EOC}FS (recursive) from");
		ft_printf(" start to end\n");
	}
	str = (*params)->path_start_end;
	(*params)->path_start_end = ft_strjoin(str, fixed_start->name);
	ft_strdel(&str);
	if (PRINT == 1)
	{
		ft_printf("{GREEN} %s{EOC}\n", (*params)->path_start_end);
		ft_printf(" {YELLOW}%i{EOC}", (*params)->length_path_start_end);
		ft_printf("-long path\n");
	}
	ft_strdel(&((*params)->path_start_end));
	(*params)->length_path_start_end = 0;
}

static	void	ft_handle_joins_and_end(t_params **params, t_node *node,
		t_node *fixed_start)
{
	ft_handle_joins(params, node);
	if (node == fixed_start->next->content)
		ft_handle_end_dfs(params, fixed_start);
}

int				ft_check_start_connected_to_end_dfs(t_params **params,
		t_node *start, t_node *fixed_start)
{
	t_list	*tmp;
	t_node	*node;

	if (start->is_end == 1)
		return (1);
	start->passed_flag = 1;
	tmp = start->next;
	while (tmp && tmp->content)
	{
		node = (t_node *)tmp->content;
		if (node->passed_flag == 0)
		{
			node->passed_flag = 1;
			if (ft_check_start_connected_to_end_dfs(params, node, fixed_start))
			{
				ft_handle_joins_and_end(params, node, fixed_start);
				return (1);
			}
		}
		tmp = tmp->next;
	}
	if (ft_strcmp(start->name, fixed_start->name) == 0 &&
			ft_handle_error(params) == 1)
		return (-1);
	return (0);
}
