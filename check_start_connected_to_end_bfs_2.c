/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_start_connected_to_end_bfs_2.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 15:12:32 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/03 17:46:01 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		ft_init_queue(t_node **queue, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		queue[i] = NULL;
		i++;
	}
}

void		ft_print_father_list(t_node *end, t_params **params)
{
	t_list	*tmp;
	t_node	*node;

	tmp = end->father;
	if ((*params)->print == 1)
	{
		ft_printf("-----------------------\n{GREEN}[Success]{EOC}");
		ft_printf("A path detected with {YELLOW}B{EOC}FS (iterative) from ");
		ft_printf("start to end\n {GREEN}%s <{EOC}", end->name);
	}
	while (tmp)
	{
		(*params)->length_path_start_end++;
		node = (t_node *)tmp->content;
		if (node->father && (*params)->print == 1)
			ft_printf("{GREEN} %s <{EOC}", node->name);
		else if ((*params)->print == 1)
			ft_printf("{GREEN} %s {EOC}\n", node->name);
		tmp = node->father;
	}
	if ((*params)->print == 1)
	{
		ft_printf(" {YELLOW}%i{EOC}", (*params)->length_path_start_end);
		ft_printf("-long path\n");
	}
}

int			ft_handle_end(t_node **queue, t_params **params, int i)
{
	if ((*params)->print == 1)
		ft_print_father_list(queue[i], params);
	(*params)->length_path_start_end = 0;
	free(queue);
	return (1);
}
