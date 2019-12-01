/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_output_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:00:25 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/28 19:32:30 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_add_return_line(t_params **params)
{
	char *str;

	str = (*params)->map;
	(*params)->map = ft_strjoin(str, "\n");
	ft_strdel(&str);
}

void	ft_print_map(t_params **params)
{
	ft_printf("%s\n", (*params)->map);
}
