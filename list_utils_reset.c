/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_reset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 17:56:54 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/24 17:57:14 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*static void		ft_reset_arcw(t_node *node)
{
	t_list *tmp;

	tmp = node->next;
	while (tmp)
	{
		tmp->arcw = 1;
		tmp = tmp->next;
	}
}*/

void			ft_reset_passed_flags(t_list **list)
{
	t_list *tmp;
	t_node *node;

	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *) tmp->content;
		node->passed_flag = 0;
		//ft_reset_arcw(node);
		tmp = tmp->next;
	}
}
