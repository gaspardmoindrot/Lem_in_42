/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 19:24:27 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/12/03 17:10:10 by rbeaufre         ###   ########.fr       */
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
	char	*str[3];

	str[0] = NULL;
	str[2] = NULL;
	if ((read(0, str[0], 0) < 0 || (get_next_line(0, &(str[0])) == -1) ||
	(!str[0] && ft_cast_error_empty(params, &str[0]))) && ft_free_str(&str[0]))
		return (-2);
	i = ft_is_plus_minus(str[0][0]) ? 1 : 0;
	while (str[0][i])
	{
		if (!ft_isdigit(str[0][i++]) && ft_cast_error_bad(params, &str[0]) &&
			ft_free_str(&str[0]))
			return (-1);
	}
	if (((ft_atoi(str[0]) < 0 && ft_cast_error_negative(params, &str[0])) ||
		(ft_atoi(str[0]) == 0 && ft_cast_error_zero(params, &str[0]))) &&
		ft_free_str(&str[0]))
		return (-1);
	(*params)->ant_count = ft_atoi(str[0]);
	str[1] = ft_itoa(ft_atoi(str[0]));
	str[2] = (*params)->map;
	(*params)->map = ft_strjoin(str[2], str[1]);
	ft_strdel(&str[2]);
	ft_strdel(&str[1]);
	ft_strdel(&str[0]);
	ft_add_return_line(params);
	return (1);
}
