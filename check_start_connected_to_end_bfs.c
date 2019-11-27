/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_connected_to_end_bfs.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:04:10 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/25 21:13:37 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		ft_handle_error(t_params **params)
{
	(*params)->error_line = 0;
	ft_strdel(&((*params)->error_type));
	(*params)->error_type = ft_strdup("No path detected between start and end");
	(*params)->fatal_error = 1;
}

static void		ft_print_father_list(t_node *end, t_params **params)
{
	t_list	*tmp;
	t_node	*node;

	tmp = end->father;
	if (PRINT == 1)
	{
		ft_printf("-----------------------\n{GREEN}[Success]{EOC}");
		ft_printf("A path detected with {YELLOW}B{EOC}FS (iterative) from");
		ft_printf("start to end\n {GREEN}%s {EOC}<", end->name);
	}
	while (tmp)
	{
		(*params)->length_path_start_end++;
		node = (t_node *)tmp->content;
		if (node->father && PRINT == 1)
			ft_printf("{GREEN} %s {EOC}<", node->name);
		else if (PRINT == 1)
			ft_printf("{GREEN} %s {EOC}\n", node->name);
		tmp = node->father;
	}
	if (PRINT == 1)
	{
		ft_printf("Path size:%i\n", (*params)->length_path_start_end);
		ft_printf("{YELLOW}%i{EOC} rooms\n", (*params)->rooms_count);
	}
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

int				ft_check_start_connected_to_end_bfs(t_params **params,
		t_node *start)
{
	t_node	*queue[(*params)->rooms_count];
	int		i;
	int		j;
	int		a;

	a = 0;
	i = 0;
	queue[0] = start;
	start->passed_flag = 1;
	j = 1;
	while (queue[i] && (j > 1 || (j == 1 && a == 0)))
	{
		a = 1;
		queue[i]->passed_flag = 1;
		if (queue[i]->is_end == 1)
		{
			ft_print_father_list(queue[i], params);
			(*params)->length_path_start_end = 0;
			return (1);
		}
		ft_stack_virgin_neighbours(queue, &i, &j);
		i++;
	}
	ft_handle_error(params);
	return (-1);
}
