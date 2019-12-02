/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_connected_to_end_bfs.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:04:10 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/01 15:11:52 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_handle_error(t_params **params)
{
	(*params)->error_line = 0;
	ft_strdel(&((*params)->error_type));
	(*params)->error_type = ft_strdup("No path detected between start and end");
	(*params)->fatal_error = 1;
}

static void		ft_add_path_history(t_node **son, t_node **father)
{
	t_list *link;

	if (father != NULL && son != NULL)
	{
		link = ft_lstnew_revisited(*father, sizeof(*father));
		ft_lstadd(&((*son)->father), link);
	}
}

static void		ft_stack_virgin_neighbours(t_node **queue, int *i, int *j)
{
	t_list	*tmp;
	t_node	*node;

	if (queue[*i]->next)
	{
		tmp = queue[*i]->next;
		*j = (*i != 0) ? *j - 1 : *j;
		while (tmp)
		{
			node = (t_node *)tmp->content;
			if (node->passed_flag == 0)
			{
				node->passed_flag = 1;
				queue[*i + *j] = node;
				ft_add_path_history(&(queue[*i + *j]), &(queue[*i]));
				(*j)++;
			}
			tmp = tmp->next;
		}
	}
}

int				ft_check_start_connected_to_end_bfs(t_params **params,
		t_node *start)
{
	t_node	**queue;
	int		i;
	int		j;

	i = 0;
	queue = (t_node **)malloc(sizeof(t_node *) * (*params)->rooms_count);
	if (!queue)
		return (-1);
	ft_init_queue(queue, (*params)->rooms_count);
	queue[0] = start;
	j = 1;
	while (queue[i] && queue[i] != NULL)
	{
		(queue[i])->passed_flag = 1;
		if (queue[i]->is_end == 1 && ft_handle_end(queue, params, i))
			return (1);
		ft_stack_virgin_neighbours(queue, &i, &j);
		i++;
	}
	ft_handle_error(params);
	free(queue);
	return (-1);
}
