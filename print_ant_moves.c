/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ant_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 20:47:23 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/02 14:40:49 by gmoindro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	ft_ants_dispatch(int *length, int *ants_start, t_params **params)
{
	int	ant_i;
	int	i;
	int	cost_select;
	int	cost_i;
	int	i_select;

	ant_i = -1;
	i_select = 0;
	while (++ant_i < (*params)->ant_count)
	{
		i = -1;
		i_select = 0;
		cost_select = ants_start[0] + length[0];
		cost_i = 0;
		while (++i < (*params)->index)
		{
			cost_i = ants_start[i] + length[i];
			if (cost_i < cost_select)
			{
				i_select = i;
				cost_select = cost_i;
			}
		}
		ants_start[i_select]++;
	}
}

t_list		**ft_create_fake_bib(void)
{
	t_list	**bib;
	t_list	*link;
	t_node	*node[7];

	bib = malloc(sizeof(t_list *) * 3);
	bib[0] = NULL;
	bib[1] = NULL;
	bib[2] = NULL;
	node[0] = malloc(sizeof(t_node));
	node[1] = malloc(sizeof(t_node));
	node[2] = malloc(sizeof(t_node));
	node[3] = malloc(sizeof(t_node));
	node[4] = malloc(sizeof(t_node));
	node[5] = malloc(sizeof(t_node));
	node[6] = malloc(sizeof(t_node));
	node[0]->name = ft_strdup("[Node 0]");
	node[1]->name = ft_strdup("[Node 1]");
	node[2]->name = ft_strdup("[Node 2]");
	node[3]->name = ft_strdup("[Node 3]");
	node[4]->name = ft_strdup("[END]");
	node[5]->name = ft_strdup("[Paris]");
	node[6]->name = ft_strdup("[Rome]");
	link = ft_lstnew_revisited(node[4], sizeof(node[0]));
	ft_lstadd(&(bib[0]), link);
	link = ft_lstnew_revisited(node[0], sizeof(node[0]));
	ft_lstadd(&(bib[0]), link);
	link = ft_lstnew_revisited(node[1], sizeof(node[0]));
	ft_lstadd(&(bib[0]), link);
	link = ft_lstnew_revisited(node[4], sizeof(node[0]));
	ft_lstadd(&(bib[1]), link);
	link = ft_lstnew_revisited(node[2], sizeof(node[0]));
	ft_lstadd(&(bib[1]), link);
	link = ft_lstnew_revisited(node[2], sizeof(node[0]));
	ft_lstadd(&(bib[1]), link);
	link = ft_lstnew_revisited(node[4], sizeof(node[0]));
	ft_lstadd(&(bib[2]), link);
	link = ft_lstnew_revisited(node[5], sizeof(node[0]));
	ft_lstadd(&(bib[2]), link);
	link = ft_lstnew_revisited(node[5], sizeof(node[0]));
	ft_lstadd(&(bib[2]), link);
	link = ft_lstnew_revisited(node[5], sizeof(node[0]));
	ft_lstadd(&(bib[2]), link);
	link = ft_lstnew_revisited(node[5], sizeof(node[0]));
	ft_lstadd(&(bib[2]), link);
	link = ft_lstnew_revisited(node[5], sizeof(node[0]));
	ft_lstadd(&(bib[2]), link);
	link = ft_lstnew_revisited(node[6], sizeof(node[0]));
	ft_lstadd(&(bib[2]), link);
	return (bib);
}

static void	ft_print_first_round(int *ants_start,
		t_list **ants, t_params **params, t_list **bib)
{
	int		i;

	i = 0;
	while (i < (*params)->index && ants_start[i] > 0)
	{
		//ft_printf(" (START)Je balaye le chemin %i, avec ants[start] a %i \n",
		//i, ants_start[i]);
		if (ants_start[i] != 0)
		{
			ft_printf("L%i-%s ", (*params)->ants_launched,
					((t_node *)bib[i]->next->content)->name);
			ants[(*params)->ants_launched] = bib[i]->next;
			(*params)->ants_launched++;
			ants_start[i]--;
		}
		//ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

static void	ft_print_other_rounds(int *ants_end, t_list **ants,
		t_params **params)
{
	int		j;

	j = 0;
	while (j < (*params)->ant_count)
	{
		if (ants[j] != NULL && ants[j]->next != NULL)
		{
			//ft_printf(" (SUITE)Je balaye la fourmi %i\n", j);
			ft_printf("L%i-%s ", j, ((t_node *)ants[j]->next->content)->name);
			ants[j] = ants[j]->next;
			if (ants[j]->next == NULL)
			{
				//ft_printf("{RED}Reset ants[%i] to NULL{EOC}\n", j);
				ants[j] = NULL;
				(*ants_end)++;
			}
		}
		j++;
	}
	//if (ants[0] == NULL)
	//	ft_printf("{RED}Ants 0 vaut bien  NULL{EOC}\n", j);
}

void		ft_print_ant_moves(t_list **bib, t_params **params)
{
	t_list	**ants;
	int		*length;
	int		*ants_start;
	int		ants_end;

	ants_end = 0;
	if ((*params)->index == -1)
		return ;
	ants = malloc(sizeof(t_list *) * (*params)->ant_count);
	length = malloc(sizeof(int) * (*params)->index);
	ants_start = malloc(sizeof(int) * (*params)->index);
	ft_init_ants_start(ants_start, (*params)->index);
	ft_init_ants(ants, (*params)->ant_count);
	//ft_print_bibli(bib, (*params)->index);
	ft_fill_length(length, bib, (*params)->index);
	ft_ants_dispatch(length, ants_start, params);
	//ft_printf("Lengths\n");
	//ft_print_tab(length, (*params)->index);
	//ft_printf("[%i] ants total, printing dispatch\n", (*params)->ant_count);
	//ft_printf("Dispatch:\n");
	//ft_print_tab(ants_start, (*params)->index);
	while (ants_end != (*params)->ant_count)
	{
		ft_printf("{YELLOW}Cycle%i -- ants_arrived vaut %i{EOC}\n",
		(*params)->cycle_number, ants_end);
		ft_print_other_rounds(&ants_end, ants, params);
		ft_print_first_round(ants_start, ants, params, bib);
		(*params)->cycle_number++;
	}
	//ft_printf("{YELLOW}Cycle%i -- ants_arrived vaut %i{EOC}\n",
	//(*params)->cycle_number, ants_end);
	free(ants);
	free(length);
	free(ants_start);
}
