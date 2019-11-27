/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adjacent_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:32:05 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/25 21:46:19 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	ft_print_node_2(t_node *node)
{
	t_list	*tmp2;
	t_node	*node2;

	tmp2 = node->next;
	if (tmp2 == NULL)
		ft_printf(" nothing!");
	while (tmp2 != NULL)
	{
		node2 = ((t_node *)tmp2->content);
		ft_printf("{YELLOW}%s{EOC} (arcw : %i)", node2->name, tmp2->arcw);
		if (tmp2->next)
			ft_printf(", ");
		tmp2 = tmp2->next;
	}
}

void		ft_print_node(t_node *node)
{
	ft_printf("{YELLOW}Room %-5s{EOC} - Id:%-2i", node->name, node->id);
	ft_printf("Hash: %i -", node->name_hash);
	ft_printf("Passed flag : %i - ", node->passed_flag);
	ft_printf("Position %2i:%-2i linked with: ", node->x_coord, node->y_coord);
	ft_print_node_2(node);
	if (node->is_start == 1)
		ft_printf("\n{GREEN}[START]{EOC}");
	if (node->is_end == 1)
		ft_printf("\n{RED}[END]{EOC}");
	ft_printf("\n-----------------------\n");
}

void		ft_print_adjacent_list(t_list **list)
{
	t_list		*tmp;
	t_node		*node;

	tmp = *list;
	while (tmp != NULL && tmp->content != NULL)
	{
		node = ((t_node *)tmp->content);
		ft_print_node(node);
		tmp = tmp->next;
	}
}
