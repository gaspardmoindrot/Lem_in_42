/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_adjacent_list_add_tunnel.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:45:19 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/03 13:59:45 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_handle_non_two_error(t_params **params)
{
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_type = ft_strdup("Tunnel room not found");
	return (1);
}

static void	ft_handle_add_adj(long hash, t_node *node, int *count,
		t_list **list)
{
	t_node *node3;
	t_list *adj;

	node3 = ft_find_t_node_with_name_hash(list, hash);
	if (node3 != NULL)
	{
		adj = ft_lstnew_revisited(node3, sizeof(t_node));
		ft_lstadd(&(node->next), adj);
		(*count)++;
	}
}

static void	ft_handle_loop(t_list *tmp, long *hash, int *count, t_list **list)
{
	t_node *node;

	node = (t_node *)tmp->content;
	if (node->name_hash == hash[0])
		ft_handle_add_adj(hash[1], node, count, list);
	else if (node->name_hash == hash[1])
		ft_handle_add_adj(hash[0], node, count, list);
}

int			ft_add_tunnel(t_list **list, char **str, t_params **params)
{
	char		**split;
	t_list		*tmp;
	long		hash[2];
	int			count;

	count = 2;
	split = ft_strsplit(*str, '-');
	tmp = *list;
	hash[0] = ft_hash(split[0]);
	hash[1] = ft_hash(split[1]);
	if (!ft_is_neighbor_with_name_hash(
				ft_find_t_node_with_name_hash(list, hash[0]), hash[1]))
	{
		count = 0;
		while (tmp && tmp->content && ((t_node *)tmp->content)->name)
		{
			ft_handle_loop(tmp, hash, &count, list);
			tmp = tmp->next;
		}
	}
	ft_free_split_special(1, split);
	if (count != 2 && ft_handle_non_two_error(params) == 1)
		return (-1);
	ft_tunnel_add_success(params, str);
	return (1);
}
