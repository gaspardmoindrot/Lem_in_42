/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant_moves_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 13:58:18 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/03 17:22:19 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_nb_rooms(t_list **bib, int path_nb)
{
	t_list	*tmp;
	int		i;

	if (!bib)
		return (-1);
	tmp = bib[path_nb];
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i - 1);
}

void	ft_print_tab(int *tab, int index)
{
	int	i;
	int	sum;

	i = 0;
	while (i < index)
	{
		ft_printf("tab[%i] = %i ; ", i, tab[i]);
		sum = sum + tab[i];
		i++;
	}
	ft_printf("\n");
	ft_printf("sum vaut %i\n\n", sum);
}

void	ft_fill_length(int *length, t_list **bib, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		length[i] = ft_nb_rooms(bib, i);
		i++;
	}
	return ;
}

void	ft_print_bibli(t_list **result, int i)
{
	t_node	*node;
	t_list	*tmp;
	int		j;

	j = 0;
	ft_printf("\n");
	while (j < i)
	{
		node = (t_node *)result[j]->content;
		ft_printf("%s ", node->name);
		tmp = result[j]->next;
		while (tmp)
		{
			node = (t_node *)tmp->content;
			ft_printf(" -> %s ", node->name);
			tmp = tmp->next;
		}
		ft_printf("\n");
		j++;
	}
	ft_printf("\n");
}
