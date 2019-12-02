/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_arcw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoindro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:58:23 by gmoindro          #+#    #+#             */
/*   Updated: 2019/12/02 18:00:48 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_put_arcw_init(t_node *end)
{
	t_list	*tmp;
	t_node	*node;

	tmp = end->father;
	end->passed_flag = 2;
	while (tmp)
	{
		node = (t_node *)tmp->content;
		node->passed_flag = 2;
		tmp = node->father;
	}
}

static void	ft_put_arcw_flag_start(t_list **list)
{
	t_list	*tmp;
	t_node	*node;
	t_node	*start;

	start = ft_find_t_node_with_start(list);
	tmp = start->next;
	start->passed_flag = 3;
	while (tmp)
	{
		node = (t_node *)tmp->content;
		if (node->passed_flag == 2 && tmp->arcw <= 0)
		{
			node->passed_flag = 3;
			if (tmp->arcw == -1)
				tmp->arcw = 0;
			else
				tmp->arcw = 1;
			tmp = node->next;
		}
		else
			tmp = tmp->next;
	}
}

static void	ft_put_arcw_passed(t_node *node, t_list *tmp)
{
	node->passed_flag = 0;
	if (tmp->arcw == 1)
	{
		tmp->arcw = 0;
		ft_test_voisin(node);
	}
	else
	{
		tmp->arcw = -1;
		node->passed_flag = 5;
	}
	tmp = node->next;
}

void		ft_put_arcw(t_node *end, t_list **list)
{
	t_list	*tmp;
	t_node	*node;

	ft_put_arcw_init(end);
	ft_put_arcw_flag_start(list);
	tmp = end->next;
	end->passed_flag = 0;
	while (tmp)
	{
		node = (t_node *)tmp->content;
		if (node->passed_flag == 3 && tmp->arcw >= 0)
			ft_put_arcw_passed(node, tmp);
		else
			tmp = tmp->next;
	}
}

void		ft_test_voisin(t_node *node)
{
	t_list	*tmp;
	int		count;

	count = 0;
	tmp = node->next;
	while (tmp)
	{
		if (tmp->arcw == 1)
			count++;
		tmp = tmp->next;
	}
	if (count < 1)
		node->passed_flag = 0;
	else
		node->passed_flag = 5;
}
