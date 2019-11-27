/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_general_details.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:21:41 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/25 21:38:17 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

void	ft_print_general_details(t_list **list, t_params **params)
{
	ft_printf("-----------------------\n");
	ft_printf("Welcome to lem-in by gmoindro && rbeaufre\n");
	ft_printf("-----------------------\n");
	ft_printf("There are [{YELLOW}%i{EOC}] ants \n", (*params)->ant_count);
	ft_printf("There are [{YELLOW}%i{EOC}] rooms\n", (*params)->rooms_count);
	ft_printf("-----------------------\n");
	ft_printf("Here is the rooms map [{GREEN}Start{EOC}] [{RED}End{EOC}]\n");
	ft_printf("-----------------------\n");
	ft_print_adjacent_list(list);
}

void	ft_print_parsing_error_fatal(t_params **params)
{
	ft_printf("-----------------------\n");
	ft_printf("ERROR\n");
	ft_printf("{RED}WARNING{EOC}\nError was found at line");
	ft_printf("{YELLOW}%i{EOC}\nError_type could be", (*params)->error_line);
	ft_printf("'{YELLOW}%s{EOC}'\n", (*params)->error_type);
	ft_printf("Error is fatal, algorithm {RED}will not{EOC}");
	ft_printf("proceed on previous selection\n");
	ft_printf("-----------------------\n");
}

void	ft_print_parsing_error_non_fatal(t_params **params)
{
	ft_printf("-----------------------\n");
	ft_printf("{YELLOW}WARNING{EOC} - Error was found at line");
	ft_printf("{YELLOW}%i{EOC}\nError_type could be", (*params)->error_line);
	ft_printf("'{YELLOW}%s{EOC}'\n", (*params)->non_fatal_error_type);
	ft_printf("However, algorithm {GREEN}will{EOC} still try");
	ft_printf("to proceed on previous selection\n");
}
