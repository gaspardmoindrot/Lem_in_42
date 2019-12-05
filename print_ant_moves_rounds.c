/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant_moves_rounds.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 17:21:46 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/03 17:22:47 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_first_round(int *ants_start,
		t_list **ants, t_params **params, t_list **bib)
{
	int		i;

	i = 0;
	while (i < (*params)->index)
	{
		if (ants_start[i] > 0)
		{
			if (ants_start[i] != 0)
			{
				if ((*params)->allow_printing_moves == 1)
					ft_printf("L%i-%s ", (*params)->ants_launched + 1,
							((t_node *)bib[i]->next->content)->name);
				ants[(*params)->ants_launched] = bib[i]->next;
				(*params)->ants_launched++;
				ants_start[i]--;
			}
		}
		i++;
	}
	if ((*params)->allow_printing_moves == 1)
		ft_printf("\n");
}

void	ft_print_other_rounds(int *ants_end, t_list **ants,
		t_params **params)
{
	int		j;

	j = 0;
	while (j < (*params)->ant_count)
	{
		if (ants[j] != NULL && ants[j]->next != NULL)
		{
			if ((*params)->allow_printing_moves == 1)
				ft_printf("L%i-%s ", j + 1,
						((t_node *)ants[j]->next->content)->name);
			ants[j] = ants[j]->next;
			if (ants[j]->next == NULL)
			{
				ants[j] = NULL;
				(*ants_end)++;
			}
		}
		j++;
	}
}
