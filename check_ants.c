/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:24:27 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/01 13:56:52 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_cast_error_empty(t_params **params, char **str)
{
	(*params)->non_fatal_error_line = 1;
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_type = ft_strdup("Empty number of ants");
	ft_strdel(str);
	return (1);
}

static int	ft_cast_error_bad(t_params **params, char **str)
{
	(*params)->non_fatal_error_line = 1;
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_type = ft_strdup("Bad number of ants");
	ft_strdel(str);
	return (1);
}

static int	ft_cast_error_negative(t_params **params, char **str)
{
	(*params)->non_fatal_error_line = 1;
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_type = ft_strdup("Negative number of ants");
	ft_strdel(str);
	return (1);
}

static int	ft_cast_error_zero(t_params **params, char **str)
{
	(*params)->non_fatal_error_line = 1;
	ft_strdel(&((*params)->non_fatal_error_type));
	(*params)->non_fatal_error_type = ft_strdup("Must be at least one ant");
	ft_strdel(str);
	return (1);
}

int			ft_check_ants(t_params **params)
{
	int		i;
	char	*str;
	char	*str2;

	str = NULL;
	if (read(0, str, 0) < 0 || (get_next_line(0, &str) == -1) ||
			(!str && ft_cast_error_empty(params, &str)))
		return (-2);
	i = ft_is_plus_minus(str[0]) ? 1 : 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i++]) && ft_cast_error_bad(params, &str))
			return (-1);
	}
	if (ft_atoi(str) < 0 && ft_cast_error_negative(params, &str))
		return (-1);
	else if (ft_atoi(str) == 0 && ft_cast_error_zero(params, &str))
		return (-1);
	(*params)->ant_count = ft_atoi(str);
	str2 = ft_itoa(ft_atoi(str));
	(*params)->map = ft_strjoin((*params)->map, str2);
	ft_add_return_line(params);
	ft_strdel(&str2);
	ft_strdel(&str);
	return (1);
}
