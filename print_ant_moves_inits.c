/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant_moves_inits.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 08:38:26 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/02 10:03:51 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_init_ants(t_list **ants, int ant_count)
{
	int i;

	i = 0;
	while (i < ant_count)
	{
		ants[i] = NULL;
		i++;
	}
}

void	ft_init_ants_start(int *ants_start, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		ants_start[i] = 0;
		i++;
	}
}
