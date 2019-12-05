/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bib.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 16:38:03 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/03 17:11:39 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_free_list_again(t_list *bib)
{
	t_list	*tmp;
	t_list	*nxt;

	tmp = bib->next;
	while (tmp)
	{
		nxt = tmp->next;
		free(tmp);
		tmp = nxt;
	}
}

static void		ft_free_list(t_list ***bib, int i)
{
	int j;

	j = 0;
	while (j <= i)
	{
		ft_free_list_again(bib[i][j]);
		free(bib[i][j]);
		j++;
	}
}

void			ft_free_bib(t_list ***bib, t_params **params)
{
	int i;

	i = 0;
	while (i < (*params)->index_max)
	{
		ft_free_list(bib, i);
		free(bib[i]);
		i++;
	}
	free(bib);
}
