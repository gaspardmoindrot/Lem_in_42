/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 17:43:58 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/19 17:46:26 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_reset_passed_flags(t_list **list)
{
	t_list *tmp;
	t_node *node;

	tmp = *list;
	while (tmp && tmp->next)
	{
		node = (t_node *) tmp->content;
		node->passed_flag = 0;
		tmp = tmp->next;
	}
}
