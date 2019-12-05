/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bibli.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:20:26 by gmoindro          #+#    #+#             */
/*   Updated: 2019/12/03 16:38:29 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	if (new && alst && *alst)
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

static void	init_result(t_list ***result, t_list **list, int i, int j)
{
	result[i][j] = (t_list *)malloc(sizeof(t_list));
	result[i][j]->content = ft_find_t_node_with_start(list);
	result[i][j]->content_size = sizeof(t_node);
	result[i][j]->next = NULL;
}

static void	ft_put_bibli_next(t_list *tmp_2, t_list *result)
{
	t_list	*new;
	t_node	*node;

	while (tmp_2)
	{
		node = (t_node *)tmp_2->content;
		if (tmp_2->arcw == 1)
		{
			new = ft_lstnew_revisited(node, sizeof(t_node));
			ft_lstadd_back(&result, new);
			if (node->is_end == 1)
				break ;
			tmp_2 = node->next;
		}
		else
			tmp_2 = tmp_2->next;
	}
}

void		ft_put_bibli(t_list **list, t_list ***result, int i)
{
	t_list	*tmp;
	t_list	*tmp_2;
	t_list	*new;
	t_node	*node[2];
	int		j;

	node[0] = ft_find_t_node_with_end(list);
	j = 0;
	node[1] = ft_find_t_node_with_start(list);
	tmp = node[1]->next;
	while (tmp && i >= j && node[1])
	{
		node[1] = (t_node *)tmp->content;
		if (tmp->arcw == 1 && i >= j)
		{
			init_result(result, list, i, j);
			new = ft_lstnew_revisited(node[1], sizeof(t_node));
			ft_lstadd_back(&(result[i][j]), new);
			tmp_2 = node[1]->next;
			ft_put_bibli_next(tmp_2, result[i][j]);
			j++;
		}
		tmp = tmp->next;
	}
}
