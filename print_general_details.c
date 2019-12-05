/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_general_details.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:21:41 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/03 17:48:57 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_general_details(t_list **list, t_params **params)
{
	if ((*params)->print == 1)
	{
		ft_printf("-----------------------\n");
		ft_printf("Welcome to lem-in by gmoindro && rbeaufre\n");
		ft_printf("-----------------------\n");
		ft_printf("[{YELLOW}%i{EOC}] ants detected \n", (*params)->ant_count);
		ft_printf("[{YELLOW}%i{EOC}] rooms detected\n", (*params)->rooms_count);
		ft_printf("-----------------------\n");
	}
	if ((*params)->print == 1 && (*params)->print_list == 1)
	{
		ft_printf("Here is the map [{GREEN}Start{EOC}] [{RED}End{EOC}]\n");
		ft_printf("-----------------------\n");
		ft_print_adjacent_list(list);
	}
}

void	ft_print_parsing_error_fatal(t_params **params)
{
	if ((*params)->print == 1)
	{
		ft_printf("-----------------------\n");
		ft_printf("{RED}WARNING{EOC} - Error was found at line ");
		ft_printf("{YELLOW}%i{EOC}\nError_type maybe ", (*params)->error_line);
		ft_printf("'{YELLOW}%s{EOC}'\n", (*params)->error_type);
		ft_printf("Error is fatal, algorithm {RED}will not {EOC}");
		ft_printf("proceed on previous selection\n");
		ft_printf("-----------------------\n");
	}
}

void	ft_print_parsing_error_non_fatal(t_params **params)
{
	if ((*params)->print == 1)
	{
		ft_printf("-----------------------\n");
		ft_printf("{YELLOW}WARNING{EOC} - Error was found at line ");
		ft_printf("{YELLOW}%i{EOC}\nError_type maybe ",
				(*params)->non_fatal_error_line);
		ft_printf("'{YELLOW}%s{EOC}'\n", (*params)->non_fatal_error_type);
		ft_printf("However, algorithm {GREEN}will{EOC} still try ");
		ft_printf("to proceed on previous selection\n");
	}
}
