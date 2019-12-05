/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checks_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:32:05 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/27 18:24:25 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_is_comment(char *str)
{
	if (str[0] && str[0] == '#')
	{
		if (str[1] && str[1] == '#')
			return (0);
		else
			return (1);
	}
	return (0);
}

int			ft_is_modifier(char *str)
{
	if (str[0] && str[0] == '#' && str[1] && str[1] == '#')
	{
		if (ft_strnequ(str + 2, "start\0", 6))
			return (-1);
		else if (ft_strnequ(str + 2, "end\0", 4))
			return (1);
		else
			return (0);
	}
	return (0);
}

int			ft_is_room_type(char **str)
{
	char	**split;
	int		i;

	if (ft_strsplit_get_nb_words(*str, ' ') != 3 ||
			ft_check_char_occurences(*str, ' ') != 2)
		return (0);
	else
	{
		split = ft_strsplit(*str, ' ');
		i = -1;
		while (split[0][++i])
			if (!ft_isprint(split[0][i]) && ft_free_split_special(2, split))
				return (0);
		i = ft_is_plus_minus(split[1][0]) ? 0 : -1;
		while (split[1][++i])
			if (!(ft_isdigit(split[1][i])) && ft_free_split_special(2, split))
				return (0);
		i = ft_is_plus_minus(split[2][0]) ? 0 : -1;
		while (split[2][++i])
			if (!(ft_isdigit(split[2][i])) && ft_free_split_special(2, split))
				return (0);
		ft_free_split_special(2, split);
	}
	return (1);
}

int			ft_is_tunnel_type(char **str)
{
	char	**split;
	int		i;

	if (ft_strsplit_get_nb_words(*str, '-') != 2 ||
			ft_check_char_occurences(*str, '-') != 1)
		return (0);
	else
	{
		split = ft_strsplit(*str, '-');
		i = -1;
		while (split[0][++i])
			if (!ft_isprint(split[0][i]) && ft_free_split_special(2, split))
				return (0);
		i = -1;
		while (split[1][++i])
			if (!ft_isprint(split[1][i]) && ft_free_split_special(2, split))
				return (0);
		ft_free_split_special(1, split);
	}
	return (1);
}
