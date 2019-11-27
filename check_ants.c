/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:24:27 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/25 19:40:04 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void	ft_cast_error_empty(t_params **params)
{
	(*params)->non_fatal_error_line = 1;
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_type = ft_strdup("Empty number of ants");
}

static void	ft_cast_error_bad(t_params **params)
{
	(*params)->non_fatal_error_line = 1;
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_type = ft_strdup("Bad number of ants");
}

static void	ft_cast_error_negative(t_params **params)
{
	(*params)->non_fatal_error_line = 1;
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_type = ft_strdup("Negative number of ants");
}

int			ft_check_ants(char *str, t_params **params)
{
	int i;

	if (!str)
	{
		ft_cast_error_empty(params);
		return (-1);
	}
	i = ft_is_plus_minus(str[0]) ? 1 : 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
		{
			ft_cast_error_bad(params);
			return (-1);
		}
	}
	if (ft_atoi(str) < 0)
	{
		ft_cast_error_negative(params);
		return (-1);
	}
	else
		(*params)->ant_count = ft_atoi(str);
	return (1);
}
