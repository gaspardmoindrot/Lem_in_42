/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_general_details.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:21:41 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/19 17:10:52 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_print_general_details(t_list **list, t_params **params)
{
	ft_printf("-----------------------\n");
	ft_printf("Welcome to lem-in by gmoindro && rbeaufre\n");
	ft_printf("-----------------------\n");
	ft_printf("There are [{YELLOW}%i{EOC}] ants in the game, going to find their way in up to [{YELLOW}%i{EOC}] different rooms\n", (*params)->ant_count, (*params)->rooms_count);
	ft_printf("-----------------------\n");
	ft_printf("Here is the rooms map [{GREEN}Start in green{EOC}] [{RED}End in red{EOC}]\n");
	ft_printf("-----------------------\n");
	ft_print_adjacent_list(list);
}

void	ft_print_parsing_error_fatal(t_params **params)
{
	ft_printf("-----------------------\n");
	ft_printf("ERROR\n");
	ft_printf("{RED}WARNING{EOC}\nError was found at line {YELLOW}%i{EOC}\nError_type could be '{YELLOW}%s{EOC}'\n", (*params)->error_line, (*params)->error_type);
	ft_printf("Error is fatal, algorithm {RED}will not{EOC} to proceed on previous selection\n");
	ft_printf("-----------------------\n");
}

void	ft_print_parsing_error_non_fatal(t_params **params)
{
	ft_printf("-----------------------\n");
	ft_printf("{YELLOW}WARNING{EOC} - Error was found at line {YELLOW}%i{EOC}\nError_type could be '{YELLOW}%s{EOC}'\n", (*params)->error_line, (*params)->error_type);
	ft_printf("However, algorithm {GREEN}will{EOC} still try to proceed on previous selection\n");
}
