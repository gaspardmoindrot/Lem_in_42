/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_connected_to_end.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:04:10 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/24 20:24:44 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	ft_handle_error(t_params **params)
{
	(*params)->error_line = 0;
	ft_strdel(&((*params)->error_type));
	(*params)->error_type = ft_strdup("No path detected between start and end");
	(*params)->fatal_error = 1;
}

static void	ft_handle_joins(t_params **params, t_node *node)
{
	char *str;

	str = (*params)->path_start_end;
	(*params)->path_start_end  = ft_strjoin(str, node->name);
	ft_strdel(&str);
	str = (*params)->path_start_end;
	(*params)->path_start_end  = ft_strjoin((*params)->path_start_end, " < ");
	ft_strdel(&str);
	(*params)->length_path_start_end++;
}

static void		ft_handle_end(t_params **params, t_node *fixed_start)
{
	char *str;

	str = (*params)->path_start_end;
	(*params)->path_start_end  = ft_strjoin(str, fixed_start->name);
	ft_strdel(&str);
	ft_printf("{GREEN}%s{EOC}\n", (*params)->path_start_end);
	ft_printf("This path has a size {YELLOW}%i{EOC}, for {YELLOW}%i{EOC} rooms, ratio of {YELLOW}%f{EOC}\n", (*params)->length_path_start_end, (*params)->rooms_count, (float) (*params)->length_path_start_end / (float) (*params)->rooms_count);
	ft_strdel(&((*params)->path_start_end));
	(*params)->length_path_start_end = 0;
}

int				ft_check_start_connected_to_end_dfs(t_params **params, t_node *start, t_node *fixed_start)
{
	t_list	*tmp;
	t_node	*node;

	if (start->is_end == 1)
	{
		ft_printf("-----------------------\n");
		ft_printf("{GREEN}[Success]{EOC} A path detected with {YELLOW}D{EOC}FS (recursive) from start to end\n");
		return (1);
	}
	start->passed_flag = 1;
	tmp = start->next;
	while (tmp && tmp->content)
	{
		node = (t_node *) tmp->content;
		//ft_printf("Scanning node %s\n", node->name);
		if (node->passed_flag == 0)
		{
			//ft_printf("--- Really trying node %s\n", node->name);
			node->passed_flag = 1;
			if (ft_check_start_connected_to_end_dfs(params, node, fixed_start))
			{
				ft_handle_joins(params, node);
				if (node == fixed_start->next->content)
					ft_handle_end(params, fixed_start);
				return (1);
			}
		}
		tmp = tmp->next;
	}
	if (ft_strcmp(start->name, fixed_start->name) == 0)
	{
		ft_handle_error(params);
		return (-1);
	}
	//ft_printf("##################backup\n");
	return (0);
}

/*static void		ft_display_tab(t_node **queue)
{
	int		i;

	i = 0;
	while (queue[i] != NULL)
	{
		//ft_printf(" > %s", queue[i]->name);
		i++;
	}
	//ft_printf("\n");
}*/

int				ft_check_start_connected_to_end_bfs(t_params **params, t_node *start, t_node *fixed_start)
{
	t_list	*tmp;
	t_node	*queue[(*params)->rooms_count];
	int		i;
	int		j;
	t_node	*node;

	(void)fixed_start;
	i = 0;
	while (i < (*params)->rooms_count)
	{
		queue[i] = NULL;
		i++;
	}
	i = 0;
	queue[0] = start;
	start->passed_flag = 1;
	j = 1;
	while (queue[i])
	{
		//ft_printf("Checking node %s\n", queue[i]->name);
		//ft_display_tab(queue);
		//queue[i]->passed_flag = 1;
		if (queue[i]->is_end == 1)
		{
			ft_printf("-----------------------\n");
			ft_printf("{GREEN}[Success]{EOC} A path detected with {YELLOW}B{EOC}FS (iterative) from start to end\n");
			return (1);
		}
		tmp = queue[i]->next;
		if (i != 0)
			j = j - 1;
		while (tmp)
		{
			node = (t_node *) tmp->content;
			//ft_printf("{YELLOW}i: %i, j : %i, i + j: %i {EOC}\n", i, j, i + j);
			//ft_printf("--- Considering to add node %s", node->name);
			if (node->passed_flag == 0)
			{
				//ft_printf("---ADDED\n");
				node->passed_flag = 1;
				queue[i + j] = node;
				j++;
			}
			//else
			//	ft_printf("---NOT ADDED\n");
			tmp = tmp->next;
		}
		i++;
	}
	ft_handle_error(params);
	return (-1);
}
