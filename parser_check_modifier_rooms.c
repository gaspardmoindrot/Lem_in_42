/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_check_modifier_rooms.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbeaufre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 18:31:14 by rbeaufre          #+#    #+#             */
/*   Updated: 2019/11/28 16:34:21 by rbeaufre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
			if (!ft_isprint(split[0][i]))
				return (0);
		i = ft_is_plus_minus(split[1][0]) ? 0 : -1;
		while (split[1][++i])
			if (!(ft_isdigit(split[1][i])))
				return (0);
		i = ft_is_plus_minus(split[2][0]) ? 0 : -1;
		while (split[2][++i])
			if (!(ft_isdigit(split[2][i])))
				return (0);
		ft_free_split(2, split);
	}
	return (1);
}
