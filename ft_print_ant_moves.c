/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ant_moves.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:47:23 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/28 21:32:36 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_bib_len(t_list ***bib)
{
	int i;

	i = 0;
	while (bib[i])
		i++;
	return (i);
}

static void	ft_print_max(t_list ***bib, t_params **params, int size)
{
	
}

void		ft_print_ant_moves(t_list ***bib, t_params **params)
{
	int	nb;
	int	i;

	i = 0;
	nb = (*params)->ant_count;

	if (!bib)
		return ;
	if (nb >= ft_bib_len(bib))
		ft_print_max(bib, params, size);
	else
		ft_print_custom(bib, params, size);
}
